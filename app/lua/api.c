/* SPDX-License-Identifier: MPL-2.0
 * Copyright (C) 2026 Charles Vestal */
/* The droplet API: what a droplet's Lua sees (docs/DROPLETS.md), on ripple.h's C. Included by lua_one.c.
 *
 *   screen   clear level color palette font rect frame line pixel circle text text_center text_right text_width
 *            update
 *   current  load(name) -> a current: c:set(param, v), c:note(n, vel), c:params(), c.name, c.voices
 *   flow     set(c, ...) the order on the bus; level(v); peak()
 *   clock    run(fn, ...) sleep(s) sync(beats) cancel(id) set_tempo(bpm) tempo beats()
 *   midi     send(b0, b1, b2)
 *   led      key(k, on) button(name, on)
 *   util     ms() note(k)
 * A droplet defines what it answers: init() key(k, vel) button(name, z) enc(n, d) midi_in(b0, b1, b2) frame()
 * redraw() cleanup(). */
#include "ripple.h"

static lua_State *LS;
static char lr_err[200];
static uint8_t lr_frame_due;

/* --------------------------------------------------------------- screen --- */
static int s_clear(lua_State *L) { (void)L; scr_clear(); return 0; }
static int s_level(lua_State *L) { scr_level((int)luaL_checkinteger(L, 1)); return 0; }
static int s_color(lua_State *L)
{
    scr_color((int)luaL_checkinteger(L, 1), (int)luaL_checkinteger(L, 2), (int)luaL_checkinteger(L, 3));
    return 0;
}
static int s_palette(lua_State *L)
{
    scr_palette((int)luaL_checkinteger(L, 1), (int)luaL_checkinteger(L, 2), (int)luaL_checkinteger(L, 3),
                (int)luaL_checkinteger(L, 4));
    return 0;
}
static int s_font(lua_State *L) { scr_font((int)luaL_checkinteger(L, 1)); return 0; }
static int ci(lua_State *L, int i) { return (int)lp_floor((float)luaL_checknumber(L, i)); }
static int s_rect(lua_State *L) { scr_rect(ci(L, 1), ci(L, 2), ci(L, 3), ci(L, 4)); return 0; }
static int s_frame(lua_State *L) { scr_frame(ci(L, 1), ci(L, 2), ci(L, 3), ci(L, 4)); return 0; }
static int s_line(lua_State *L) { scr_line(ci(L, 1), ci(L, 2), ci(L, 3), ci(L, 4)); return 0; }
static int s_pixel(lua_State *L) { scr_pixel(ci(L, 1), ci(L, 2)); return 0; }
static int s_circle(lua_State *L) { scr_circle(ci(L, 1), ci(L, 2), ci(L, 3), lua_toboolean(L, 4)); return 0; }
static int s_text_a(lua_State *L, int align)
{
    lua_pushinteger(L, scr_text(ci(L, 1), ci(L, 2), luaL_tolstring(L, 3, NULL), align));
    return 1;
}
static int s_text(lua_State *L) { return s_text_a(L, 0); }
static int s_text_center(lua_State *L) { return s_text_a(L, 1); }
static int s_text_right(lua_State *L) { return s_text_a(L, 2); }
static int s_text_width(lua_State *L) { lua_pushinteger(L, scr_text_w(luaL_checkstring(L, 1))); return 1; }
static int s_update(lua_State *L) { (void)L; scr_update(); return 0; }
static const luaL_Reg SCREEN[] = {
    {"clear", s_clear}, {"level", s_level}, {"color", s_color}, {"palette", s_palette}, {"font", s_font},
    {"rect", s_rect}, {"frame", s_frame}, {"line", s_line}, {"pixel", s_pixel}, {"circle", s_circle},
    {"text", s_text}, {"text_center", s_text_center}, {"text_right", s_text_right}, {"text_width", s_text_width},
    {"update", s_update}, {NULL, NULL}};

/* -------------------------------------------------------------- currents --- */
#define CUR_MT "ripple.current"
static int cur_h(lua_State *L, int i)
{
    int h;
    luaL_checktype(L, i, LUA_TTABLE);
    lua_getfield(L, i, "_h");
    lua_getfield(L, i, "_g");
    h = (int)luaL_checkinteger(L, -2);
    if ((uint32_t)luaL_checkinteger(L, -1) != rp_gen())
        luaL_error(L, "current %s: gone (flow.clear)", rp_name(h));
    lua_pop(L, 2);
    return h;
}
static int c_load(lua_State *L)
{
    const char *err = 0, *name = luaL_checkstring(L, 1);
    int h = rp_load(name, &err);
    if (h < 0)
        return luaL_error(L, "current %s: %s", name, err ? err : "failed");
    lua_createtable(L, 0, 5);
    lua_pushinteger(L, h);
    lua_setfield(L, -2, "_h");
    lua_pushinteger(L, (lua_Integer)rp_gen());
    lua_setfield(L, -2, "_g");
    lua_pushstring(L, rp_name(h));
    lua_setfield(L, -2, "name");
    lua_pushinteger(L, rp_voices(h));
    lua_setfield(L, -2, "voices");
    luaL_setmetatable(L, CUR_MT);
    return 1;
}
static int c_param_of(lua_State *L, int h, int i)
{
    int p;
    if (lua_type(L, i) == LUA_TNUMBER)
        return (int)lua_tointeger(L, i) - 1;   /* 1-based, as Lua counts */
    p = rp_param(h, luaL_checkstring(L, i));
    if (p < 0)
        luaL_error(L, "%s has no parameter %s", rp_name(h), lua_tostring(L, i));
    return p;
}
static int c_set(lua_State *L)
{
    int h = cur_h(L, 1);
    rp_set(h, c_param_of(L, h, 2), (float)luaL_checknumber(L, 3));
    return 0;
}
static int c_note(lua_State *L)
{
    int h = cur_h(L, 1);
    rp_note(h, (int)luaL_checkinteger(L, 2), (float)luaL_optnumber(L, 3, 1.0f));
    return 0;
}
static int c_params(lua_State *L)
{
    int h = cur_h(L, 1), n = rp_nparams(h), p;
    lua_createtable(L, n, 0);
    for (p = 0; p < n; p++) {
        float mn, mx, df;
        const char *nm = rp_param_info(h, p, &mn, &mx, &df);
        lua_createtable(L, 0, 4);
        lua_pushstring(L, nm);
        lua_setfield(L, -2, "name");
        lua_pushnumber(L, mn);
        lua_setfield(L, -2, "min");
        lua_pushnumber(L, mx);
        lua_setfield(L, -2, "max");
        lua_pushnumber(L, df);
        lua_setfield(L, -2, "default");
        lua_rawseti(L, -2, p + 1);
    }
    return 1;
}
/* current.list(): {name, kind = "voice" | "effect" | "sound" | "?", voices, kb (code and state)} each */
static int c_list(lua_State *L)
{
    int n = rp_currents(), i;
    lua_createtable(L, n, 0);
    for (i = 0; i < n; i++) {
        int kind = -1, voices = 0;
        uint32_t code = 0, state = 0;
        const char *nm = rp_current_name(i);
        rp_info(nm, &kind, &voices, &code, &state);
        lua_createtable(L, 0, 4);
        lua_pushstring(L, nm);
        lua_setfield(L, -2, "name");
        lua_pushstring(L, kind < 0 ? "?" : kind ? "effect" : voices ? "voice" : "sound");
        lua_setfield(L, -2, "kind");
        lua_pushinteger(L, voices);
        lua_setfield(L, -2, "voices");
        lua_pushinteger(L, (lua_Integer)((code + state + 1023u) / 1024u));
        lua_setfield(L, -2, "kb");
        lua_rawseti(L, -2, i + 1);
    }
    return 1;
}
static int c_fits(lua_State *L) { lua_pushboolean(L, rp_fits(luaL_checkstring(L, 1))); return 1; }
static int c_room(lua_State *L) { lua_pushinteger(L, (lua_Integer)(rp_room() / 1024u)); return 1; }
static int f_clear(lua_State *L) { (void)L; rp_clear(); return 0; }
static const luaL_Reg CURRENT_M[] = {{"set", c_set}, {"note", c_note}, {"params", c_params}, {NULL, NULL}};

static int f_set(lua_State *L)
{
    int hs[8], n = lua_gettop(L), i;
    if (n > 8)
        n = 8;
    for (i = 0; i < n; i++)
        hs[i] = cur_h(L, i + 1);
    rp_route(hs, n);
    return 0;
}
static int f_level(lua_State *L) { rp_level((float)luaL_checknumber(L, 1)); return 0; }
static int f_peak(lua_State *L) { lua_pushnumber(L, rp_peak()); return 1; }
static const luaL_Reg FLOW[] = {{"set", f_set}, {"level", f_level}, {"peak", f_peak}, {"clear", f_clear}, {NULL, NULL}};

/* -------------------------------------------------------- MIDI effects --- */
#define FX_MT "ripple.midifx"
static int fx_i(lua_State *L) { return *(int *)luaL_checkudata(L, 1, FX_MT); }
static int fx_k(lua_State *L, int at)       /* a parameter by name or number (1-based) */
{
    int k;
    if (lua_type(L, at) == LUA_TNUMBER)
        return (int)lua_tointeger(L, at) - 1;
    if ((k = rp_fx_param(luaL_checkstring(L, at))) < 0)
        luaL_error(L, "midifx has no parameter %s", lua_tostring(L, at));
    return k;
}
static int x_new(lua_State *L)
{
    int i = rp_fx_new();
    if (i < 0)
        return luaL_error(L, "midifx: two at most");
    *(int *)lua_newuserdatauv(L, sizeof(int), 0) = i;
    luaL_setmetatable(L, FX_MT);
    return 1;
}
static int x_set(lua_State *L)
{
    int i = fx_i(L), k = fx_k(L, 2), v, mn, mx, df;
    rp_fx_param_info(k, &mn, &mx, &df);
    if (lua_type(L, 3) == LUA_TSTRING) {    /* by what it shows: "1/16", "up", "on" */
        const char *want = lua_tostring(L, 3);
        char t[16];
        for (v = mn; v <= mx; v++) {
            rp_fx_format(k, v, t, sizeof t);
            if (!strcmp(t, want))
                break;
        }
        if (v > mx)
            return luaL_error(L, "midifx %s: no value %s", lua_tostring(L, 2), want);
    } else if (lua_isboolean(L, 3))
        v = lua_toboolean(L, 3);
    else
        v = (int)lp_floor((float)luaL_checknumber(L, 3) + 0.5f);
    rp_fx_set(i, k, v);
    return 0;
}
static int x_get(lua_State *L) { lua_pushinteger(L, rp_fx_get(fx_i(L), fx_k(L, 2))); return 1; }
static int x_text(lua_State *L)             /* fx:text(name [, v]): the value (now, or v) as it shows */
{
    int i = fx_i(L), k = fx_k(L, 2);
    char t[16];
    rp_fx_format(k, (int)luaL_optinteger(L, 3, rp_fx_get(i, k)), t, sizeof t);
    lua_pushstring(L, t);
    return 1;
}
static int x_note(lua_State *L)
{
    int i = fx_i(L), n = (int)luaL_checkinteger(L, 2) & 127, ch = (int)luaL_optinteger(L, 4, 1) - 1;
    float vel = (float)luaL_optnumber(L, 3, 1.0);
    int v = (int)(vel * 127.0f + 0.5f);
    if (v > 127) v = 127;
    rp_fx_midi(i, (v > 0 ? 0x90 : 0x80) | (ch & 15), n, v > 0 ? v : 0);
    return 0;
}
static int x_midi(lua_State *L)
{
    rp_fx_midi(fx_i(L), (int)luaL_checkinteger(L, 2), (int)luaL_optinteger(L, 3, 0), (int)luaL_optinteger(L, 4, 0));
    return 0;
}
static int x_connect(lua_State *L)
{
    int i = fx_i(L);
    rp_fx_connect(i, lua_isnoneornil(L, 2) ? -1 : cur_h(L, 2));
    return 0;
}
static int x_midi_out(lua_State *L) { rp_fx_midi_out(fx_i(L), lua_toboolean(L, 2)); return 0; }
static int x_loop(lua_State *L) { rp_fx_loop(fx_i(L), lua_toboolean(L, 2)); return 0; }
static int x_panic(lua_State *L) { rp_fx_panic(fx_i(L)); return 0; }
static int x_tempo(lua_State *L) { lua_pushnumber(L, (lua_Number)rp_fx_bpm10(fx_i(L)) / 10); return 1; }
static int x_params(lua_State *L)           /* {name, min, max, default} each, in order */
{
    int n = rp_fx_nparams(), k;
    (void)fx_i(L);
    lua_createtable(L, n, 0);
    for (k = 0; k < n; k++) {
        int mn, mx, df;
        const char *nm = rp_fx_param_info(k, &mn, &mx, &df);
        lua_createtable(L, 0, 4);
        lua_pushstring(L, nm);
        lua_setfield(L, -2, "name");
        lua_pushinteger(L, mn);
        lua_setfield(L, -2, "min");
        lua_pushinteger(L, mx);
        lua_setfield(L, -2, "max");
        lua_pushinteger(L, df);
        lua_setfield(L, -2, "default");
        lua_rawseti(L, -2, k + 1);
    }
    return 1;
}
static const luaL_Reg FX_M[] = {{"set", x_set}, {"get", x_get}, {"text", x_text}, {"note", x_note},
                                {"midi", x_midi}, {"connect", x_connect}, {"midi_out", x_midi_out},
                                {"loop", x_loop}, {"panic", x_panic}, {"tempo", x_tempo}, {"params", x_params},
                                {NULL, NULL}};

/* ---------------------------------------------------------- panel, MIDI --- */
static int m_send(lua_State *L)
{
    rp_midi((int)luaL_checkinteger(L, 1), (int)luaL_optinteger(L, 2, 0), (int)luaL_optinteger(L, 3, 0));
    return 0;
}
static int led_key(lua_State *L) { rp_led_key((int)luaL_checkinteger(L, 1), lua_toboolean(L, 2)); return 0; }
static int led_button(lua_State *L)
{
    int b = rp_button_index(luaL_checkstring(L, 1));
    if (b < 0)
        return luaL_error(L, "no button %s", lua_tostring(L, 1));
    rp_led_button(b, lua_toboolean(L, 2));
    return 0;
}
static int d_write(lua_State *L)
{
    size_t n;
    const char *s = luaL_checklstring(L, 1, &n);
    lua_pushboolean(L, rp_data_write(s, n) == 0);
    return 1;
}
static int d_read(lua_State *L)
{
    static char b[8192];
    int n = rp_data_read(b, sizeof b);
    if (n < 0)
        return 0;
    lua_pushlstring(L, b, (size_t)n);
    return 1;
}
static int u_ms(lua_State *L) { lua_pushinteger(L, (lua_Integer)(rp_ms() & 0x7FFFFFFFu)); return 1; }
static int u_cpu(lua_State *L) { lua_pushinteger(L, rp_cpu()); return 1; }
static int u_cores(lua_State *L) { lua_pushinteger(L, rp_cores()); return 1; }
static int t_pressure(lua_State *L) { lua_pushinteger(L, rp_pressure((int)luaL_checkinteger(L, 1))); return 1; }
static int u_note(lua_State *L) { lua_pushinteger(L, 53 + luaL_checkinteger(L, 1)); return 1; }

/* the clocks: coroutines woken by _tick (every millisecond the main loop passes) */
static const char PRELUDE[] =
    "local due_list, jobs, next_id, now = {}, {}, 1, 0\n"
    "clock = {tempo = 120}\n"
    "function clock.set_tempo(bpm) clock.tempo = math.max(20, math.min(300, bpm)) end\n"
    "function clock.beats() return now * clock.tempo / 60000 end\n"
    "function clock.sleep(s) coroutine.yield(1, s) end\n"
    "function clock.sync(b) coroutine.yield(2, b) end\n"
    "function clock.cancel(id) jobs[id] = nil end\n"
    "local function step(id, j)\n"
    "  local ok, kind, v = coroutine.resume(j.co)\n"
    "  if not ok then jobs[id] = nil; error(kind, 0) end\n"
    "  if coroutine.status(j.co) == 'dead' then jobs[id] = nil; return end\n"
    "  if kind == 1 then j.wake = now + math.floor(v * 1000 + 0.5)\n"
    "  elseif kind == 2 then\n"
    "    local per = math.max(1, math.floor(v * 60000 / clock.tempo + 0.5))\n"
    "    j.wake = (now // per + 1) * per\n"
    "  else j.wake = now end\n"
    "end\n"
    "function clock.run(f, ...)\n"
    "  local args = table.pack(...)\n"
    "  local id = next_id; next_id = next_id + 1\n"
    "  local j = {co = coroutine.create(function() f(table.unpack(args, 1, args.n)) end), wake = now}\n"
    "  jobs[id] = j\n"
    "  step(id, j)\n"
    "  return id\n"
    "end\n"
    "function _tick(ms)\n"
    "  now = ms\n"
    "  local n = 0\n"
    "  for id, j in pairs(jobs) do if j.wake <= ms then n = n + 1; due_list[n] = id end end\n"
    "  for i = 1, n do local id = due_list[i]; due_list[i] = nil; local j = jobs[id]; if j then step(id, j) end end\n"
    "end\n"
    "data = {}\n"
    /* a value as Lua source: a table's sequence without its keys, each table joined as it is done (the memory
     * stays small: a kit of a few hundred numbers is a few hundred short strings at a time, not thousands) */
    "local function ser(v, d)\n"
    "  local t = type(v)\n"
    "  if t == 'number' or t == 'boolean' then return tostring(v)\n"
    "  elseif t == 'string' then return string.format('%q', v)\n"
    "  elseif t == 'table' and d < 8 then\n"
    "    local out, n = {}, #v\n"
    "    for i = 1, n do out[i] = ser(v[i], d + 1) end\n"
    "    for k, x in pairs(v) do\n"
    "      local tk, tx = type(k), type(x)\n"
    "      if (tk == 'string' or (tk == 'number' and not (math.type(k) == 'integer' and k >= 1 and k <= n)))\n"
    "          and tx ~= 'function' and tx ~= 'userdata' and tx ~= 'thread' then\n"
    "        out[#out + 1] = '[' .. ser(k, d + 1) .. ']=' .. ser(x, d + 1)\n"
    "      end\n"
    "    end\n"
    "    return '{' .. table.concat(out, ',') .. '}'\n"
    "  else return 'nil' end\n"
    "end\n"
    "function data.save(t)\n"
    "  local s = 'return ' .. ser(t, 0)\n"
    "  if #s > 8192 then error('data.save: more than 8 KB', 2) end\n"
    "  return _data_write(s)\n"
    "end\n"
    "function data.load()\n"
    "  local s = _data_read()\n"
    "  if not s then return nil end\n"
    "  local f = load(s, '=data', 't', {})\n"
    "  if not f then return nil end\n"
    "  local ok, t = pcall(f)\n"
    "  return ok and t or nil\n"
    "end\n"
    "function util.clamp(x, a, b) return math.max(a, math.min(b, x)) end\n"
    "function util.round(x) return math.floor(x + 0.5) end\n"
    "function util.linlin(x, a, b, c, d) return c + (x - a) * (d - c) / (b - a) end\n";

static void lib(lua_State *L, const char *name, const luaL_Reg *r)
{
    luaL_newlib(L, r);
    lua_setglobal(L, name);
}

static int traceback(lua_State *L)
{
    const char *m = lua_tostring(L, 1);
    luaL_traceback(L, L, m ? m : "error", 1);
    return 1;
}

/* a protected call of the function under nargs arguments: the error kept and the droplet stopped */
static int lr_pcall(int nargs)
{
    int base = lua_gettop(LS) - nargs, rc;
    lua_pushcfunction(LS, traceback);
    lua_insert(LS, base);
    rc = lua_pcall(LS, nargs, 0, base);
    lua_remove(LS, base);
    if (rc != LUA_OK) {
        const char *m = lua_tostring(LS, -1);
        uint32_t i;
        for (i = 0; m && m[i] && i < sizeof lr_err - 1u; i++)
            lr_err[i] = m[i];
        lr_err[i] = 0;
        lua_pop(LS, 1);
        return -1;
    }
    return 0;
}

/* call the droplet's global function name with what is on the stack (nargs); none: nothing */
static int lr_call(const char *name, int nargs)
{
    if (!LS)
        return 0;
    if (lua_getglobal(LS, name) != LUA_TFUNCTION) {
        lua_pop(LS, 1 + nargs);
        return 0;
    }
    lua_insert(LS, -1 - nargs);
    if (lr_pcall(nargs) != 0) {
        lua_close(LS);
        LS = 0;
        return -1;
    }
    return 0;
}

static void lr_fail(const char *m)
{
    uint32_t i;
    for (i = 0; m[i] && i < sizeof lr_err - 1u; i++)
        lr_err[i] = m[i];
    lr_err[i] = 0;
}

int lr_start(const char *path)
{
    lr_stop();
    heap_reset();
    lr_err[0] = 0;
    rp_crumb(4, "newstate");
    if (!(LS = lua_newstate(heap_lua, NULL))) {
        lr_fail("no memory for Lua");
        return -1;
    }
    /* the collector early: a cycle when the heap is 10% over what lived after the last (Lua's 200% would let
     * garbage take a droplet of 60 KB past the 112 KB heap before its first cycle) */
    lua_gc(LS, LUA_GCINC, 110, 300, 0);
    rp_crumb(5, "libs");
    luaL_requiref(LS, LUA_GNAME, luaopen_base, 1);
    luaL_requiref(LS, LUA_LOADLIBNAME, luaopen_package, 1);
    luaL_requiref(LS, LUA_COLIBNAME, luaopen_coroutine, 1);
    luaL_requiref(LS, LUA_TABLIBNAME, luaopen_table, 1);
    luaL_requiref(LS, LUA_STRLIBNAME, luaopen_string, 1);
    luaL_requiref(LS, LUA_MATHLIBNAME, luaopen_math, 1);
    luaL_requiref(LS, LUA_UTF8LIBNAME, luaopen_utf8, 1);
    lua_settop(LS, 0);
    lib(LS, "screen", SCREEN);
    lib(LS, "flow", FLOW);
    lua_createtable(LS, 0, 4);
    lua_pushcfunction(LS, c_load);
    lua_setfield(LS, -2, "load");
    lua_pushcfunction(LS, c_list);
    lua_setfield(LS, -2, "list");
    lua_pushcfunction(LS, c_fits);
    lua_setfield(LS, -2, "fits");
    lua_pushcfunction(LS, c_room);
    lua_setfield(LS, -2, "room");
    lua_setglobal(LS, "current");
    luaL_newmetatable(LS, CUR_MT);
    luaL_newlib(LS, CURRENT_M);
    lua_setfield(LS, -2, "__index");
    lua_pop(LS, 1);
    lua_createtable(LS, 0, 1);
    lua_pushcfunction(LS, m_send);
    lua_setfield(LS, -2, "send");
    lua_setglobal(LS, "midi");
    lua_createtable(LS, 0, 2);
    lua_pushcfunction(LS, led_key);
    lua_setfield(LS, -2, "key");
    lua_pushcfunction(LS, led_button);
    lua_setfield(LS, -2, "button");
    lua_setglobal(LS, "led");
    lua_createtable(LS, 0, 6);
    lua_pushcfunction(LS, u_ms);
    lua_setfield(LS, -2, "ms");
    lua_pushcfunction(LS, u_note);
    lua_setfield(LS, -2, "note");
    lua_pushcfunction(LS, u_cpu);
    lua_setfield(LS, -2, "cpu");
    lua_pushcfunction(LS, u_cores);
    lua_setfield(LS, -2, "cores");
    lua_setglobal(LS, "util");
    luaL_newmetatable(LS, FX_MT);
    luaL_newlib(LS, FX_M);
    lua_setfield(LS, -2, "__index");
    lua_pop(LS, 1);
    lua_createtable(LS, 0, 1);
    lua_pushcfunction(LS, x_new);
    lua_setfield(LS, -2, "new");
    lua_setglobal(LS, "midifx");
    lua_createtable(LS, 0, 1);
    lua_pushcfunction(LS, t_pressure);
    lua_setfield(LS, -2, "pressure");
    lua_setglobal(LS, "touch");
    lua_register(LS, "_data_write", d_write);
    lua_register(LS, "_data_read", d_read);
    rp_crumb(6, "prelude");
    if (luaL_loadbuffer(LS, PRELUDE, sizeof PRELUDE - 1u, "=prelude") != LUA_OK || lr_pcall(0) != 0) {
        if (!lr_err[0])
            lr_fail(lua_tostring(LS, -1));
        lr_stop();
        return -1;
    }
    rp_crumb(7, "loadfile");
    if (luaL_loadfilex(LS, path, "t") != LUA_OK) {
        lr_fail(lua_tostring(LS, -1));
        lua_close(LS);
        LS = 0;
        return -1;
    }
    rp_crumb(8, "body");
    if (lr_pcall(0) != 0) {                 /* the droplet's body: its functions defined */
        lua_close(LS);
        LS = 0;
        return -1;
    }
    rp_crumb(10, "init");
    if (lr_call("init", 0) != 0)
        return -1;
    rp_crumb(11, "redraw");
    if (lr_call("redraw", 0) != 0)
        return -1;
    return 0;
}

void lr_stop(void)
{
    if (!LS)
        return;
    lr_call("cleanup", 0);
    if (LS)
        lua_close(LS);
    LS = 0;
}

int lr_running(void) { return LS != 0; }
const char *lr_error(void) { return lr_err; }

void lr_key(int k, int vel)
{
    if (!LS) return;
    lua_pushinteger(LS, k);
    lua_pushinteger(LS, vel);
    lr_call("key", 2);
}
void lr_button(int b, int z)
{
    if (!LS) return;
    lua_pushstring(LS, rp_button_name(b));
    lua_pushinteger(LS, z);
    lr_call("button", 2);
}
void lr_enc(int n, int d)
{
    if (!LS) return;
    lua_pushinteger(LS, n);
    lua_pushinteger(LS, d);
    lr_call("enc", 2);
}
void lr_midi(int b0, int b1, int b2, const char *port)
{
    if (!LS) return;
    lua_pushinteger(LS, b0);
    lua_pushinteger(LS, b1);
    lua_pushinteger(LS, b2);
    lua_pushstring(LS, port);
    lr_call("midi_in", 4);
}
void lr_tick(uint32_t ms)
{
    static uint32_t last_frame;
    if (!LS) return;
    lua_pushinteger(LS, (lua_Integer)(ms & 0x7FFFFFFFu));
    if (lr_call("_tick", 1) != 0 || !LS)
        return;
    if (ms - last_frame >= 33u) {           /* frame() about 30 times a second */
        last_frame = ms;
        lr_call("frame", 0);
    }
    (void)lr_frame_due;
}
uint32_t lr_mem(uint32_t *peak)
{
    if (peak) *peak = heap_peak;
    return heap_used;
}

/* print */
void lp_write(const char *s, size_t n) { rp_print(s, n); }
void lp_writeerr(const char *fmt, const char *p)
{
    (void)fmt;
    rp_print(p, strlen(p));
}
unsigned lp_seed(void) { return (unsigned)rp_ms() * 2654435761u ^ 0x5ADu; }
