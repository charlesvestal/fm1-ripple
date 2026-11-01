/* SPDX-License-Identifier: MPL-2.0
 * Copyright (C) 2026 Charles Vestal */
/* Lua's heap: one block of the RAM pool, first fit with boundary tags (blocks merge with free neighbours as they
 * are freed). A droplet starts on an empty heap (heap_reset) and its whole Lua state lives here, so leaving a
 * droplet gives every byte back at once. Included by lua_one.c. */
#include "plat.h"

#ifndef RIPPLE_HEAP_KB
#define RIPPLE_HEAP_KB 112
#endif
#define HEAP_WORDS (RIPPLE_HEAP_KB * 256u)
#define H_USED 1u                           /* header bit 0: this block is in use */
#define H_PREV 2u                           /* header bit 1: the block before is in use (else its size ends it) */
#define H_MIN 16u                           /* the smallest block: header, two links, footer */

static uint32_t heap_mem[HEAP_WORDS] PLAT_POOL;
static uint32_t heap_free_head;             /* the first free block's header, as a word index (0: none) */
static uint32_t heap_used, heap_peak;       /* bytes in use (headers too), the most so far */

/* a block is a header word (its size in bytes, a multiple of 8, and the bits), its payload (8-aligned), and when
 * free: the next and previous free blocks (word indexes) in its first two payload words and its size in its last */
#define HDR(i) heap_mem[i]
#define BSIZE(i) (HDR(i) & ~7u)
#define NEXTF(i) heap_mem[(i) + 1]
#define PREVF(i) heap_mem[(i) + 2]

static void heap_unlink(uint32_t i)
{
    uint32_t n = NEXTF(i), p = PREVF(i);
    if (p) NEXTF(p) = n; else heap_free_head = n;
    if (n) PREVF(n) = p;
}
static void heap_link(uint32_t i)
{
    uint32_t sz = BSIZE(i);
    NEXTF(i) = heap_free_head;
    PREVF(i) = 0;
    if (heap_free_head) PREVF(heap_free_head) = i;
    heap_free_head = i;
    heap_mem[i + sz / 4u - 1u] = sz;        /* the footer */
}

static void heap_reset(void)
{
    /* word 0 is unused; the first header at word 1 (its payload at byte 8: 8-aligned); an end marker in use */
    uint32_t sz = (HEAP_WORDS - 2u) * 4u & ~7u;
    HDR(1) = sz | H_PREV;
    HDR(1u + sz / 4u) = H_USED;             /* the end: a used block of size 0 */
    heap_free_head = 0;
    heap_link(1);
    heap_used = heap_peak = 0;
}

static void *heap_alloc(uint32_t n)
{
    uint32_t want = (n + 4u + 7u) & ~7u, i, best = 0, best_sz = 0xFFFFFFFFu;
    if (want < H_MIN) want = H_MIN;
    /* best fit (the smallest free block that holds it; an exact one at once): first fit took the newest free block
     * that held it, and a droplet's thousands of small objects cut the heap into pieces too small for a table */
    for (i = heap_free_head; i; i = NEXTF(i)) {
        uint32_t sz = BSIZE(i);
        if (sz >= want && sz < best_sz) {
            best = i;
            best_sz = sz;
            if (sz - want < H_MIN)
                break;
        }
    }
    if ((i = best) != 0) {
        uint32_t sz = best_sz;
        heap_unlink(i);
        if (sz - want >= H_MIN) {           /* split: the rest stays free */
            uint32_t r = i + want / 4u;
            HDR(r) = (sz - want) | H_PREV;
            heap_link(r);
            sz = want;
        } else {
            HDR(i + sz / 4u) |= H_PREV;     /* the next block's neighbour is now in use */
        }
        HDR(i) = sz | H_USED | (HDR(i) & H_PREV);
        heap_used += sz;
        if (heap_used > heap_peak) heap_peak = heap_used;
        return &heap_mem[i + 1];
    }
    return 0;
}

static void heap_free(void *p)
{
    uint32_t i, sz, nx;
    if (!p) return;
    i = (uint32_t)((uint32_t *)p - heap_mem) - 1u;
    sz = BSIZE(i);
    heap_used -= sz;
    nx = i + sz / 4u;
    if (!(HDR(nx) & H_USED)) {              /* merge the next block */
        heap_unlink(nx);
        sz += BSIZE(nx);
    }
    if (!(HDR(i) & H_PREV)) {               /* merge the previous one (its footer gives its size) */
        uint32_t psz = heap_mem[i - 1u], pi = i - psz / 4u;
        heap_unlink(pi);
        sz += psz;
        i = pi;
    }
    HDR(i) = sz | H_PREV;                   /* (a free block's neighbour before it is always in use) */
    HDR(i + sz / 4u) &= ~H_PREV;
    heap_link(i);
}

static void *heap_realloc(void *p, uint32_t n)
{
    uint32_t i, sz, want, nx;
    uint8_t *q;
    if (!p) return heap_alloc(n);
    i = (uint32_t)((uint32_t *)p - heap_mem) - 1u;
    sz = BSIZE(i);
    want = (n + 4u + 7u) & ~7u;
    if (want < H_MIN) want = H_MIN;
    if (want <= sz) {                       /* smaller: where it is, the rest given back (Lua shrinks its tables and
                                             * buffers often; kept, the space was lost until the block was freed) */
        if (sz - want >= H_MIN) {
            uint32_t r = i + want / 4u;
            HDR(i) = want | H_USED | (HDR(i) & H_PREV);
            HDR(r) = (sz - want) | H_USED | H_PREV;
            heap_free(&heap_mem[r + 1]);
        }
        return p;
    }
    nx = i + sz / 4u;
    if (!(HDR(nx) & H_USED) && sz + BSIZE(nx) >= want) {   /* grow into the free block after it */
        uint32_t all = sz + BSIZE(nx);
        heap_unlink(nx);
        if (all - want >= H_MIN) {
            uint32_t r = i + want / 4u;
            HDR(r) = (all - want) | H_PREV;
            heap_link(r);
            all = want;
        } else {
            HDR(i + all / 4u) |= H_PREV;
        }
        heap_used += all - sz;
        if (heap_used > heap_peak) heap_peak = heap_used;
        HDR(i) = all | H_USED | (HDR(i) & H_PREV);
        return p;
    }
    q = heap_alloc(n);
    if (!q) return 0;
    memcpy(q, p, sz - 4u);
    heap_free(p);
    return q;
}

void *lp_realloc(void *p, size_t n)
{
    if (!n) { heap_free(p); return 0; }
    return heap_realloc(p, (uint32_t)n);
}
void lp_free(void *p) { heap_free(p); }

/* Lua's allocator */
static void *heap_lua(void *ud, void *p, size_t osize, size_t nsize)
{
    (void)ud;
    (void)osize;
    if (!nsize) { heap_free(p); return 0; }
    return heap_realloc(p, (uint32_t)nsize);
}
