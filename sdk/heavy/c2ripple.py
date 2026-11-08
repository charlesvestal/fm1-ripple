# SPDX-License-Identifier: MIT
# Copyright (C) 2026 Charles Vestal
"""hvcc's external generator for Ripple currents (hvcc PATCH -G c2ripple, with sdk/heavy on PYTHONPATH).

It writes the patch's wrapper, ripple/NAME_current.cc, from templates/current.cc and what hvcc knows of the patch
(ExternInfo), and ripple/ripple.json, what the wrapper was made from, for sdk/tools/currents.py. The wrapper makes
the patch a current (sdk/include/ripple_current.h):
- [r NAME @hv_param MIN MAX DEFAULT] are its parameters, in hvcc's order (by name, as getParameterInfo);
- [notein] takes its notes, or, with the logue SDK's convention (boochow's hvcc_loguesdk), [r pitch] in Hz or
  [r pitch_note], with bangs on [r noteon_trig] and [r noteoff_trig] (these four are then not parameters);
- a [table NAME_r @hv_table] is filled with white noise before each block (the same convention);
- [adc~] makes it an effect (it processes the bus), else it adds its sound to the bus.
The wrapper leaves two things to the file that includes it, ripple_heavy.h: RC_NAME, the current's name, and HEAP,
the arena Heavy is given."""
import json
import time
from pathlib import Path

import jinja2

from hvcc.core.hv2ir.HeavyLangObject import HeavyLangObject
from hvcc.types.compiler import CompilerResp, ExternInfo, Generator
from hvcc.types.meta import Meta

HERE = Path(__file__).resolve().parent
NOTEIN = "__hv_notein"                # where [notein] listens
LOGUE_NOTE = ("pitch", "pitch_note", "noteon_trig", "noteoff_trig")
POOL_KB, IN_QUEUE_KB = 2, 1          # Heavy's message pool and input queue: Ripple's RAM is small (hvcc's default: 10)


class c2ripple(Generator):
    """Writes a Ripple current's wrapper for a patch hvcc has compiled to C."""

    @classmethod
    def compile(cls, c_src_dir: Path, out_dir: Path, externs: ExternInfo, patch_name: str, patch_meta: Meta = Meta(),
                num_input_channels: int = 0, num_output_channels: int = 0, copyright: str | None = None,
                verbose: bool | None = False) -> CompilerResp:
        tick = time.time()
        ins, outs = num_input_channels, num_output_channels
        if ins not in (0, 1, 2) or outs not in (1, 2):
            raise ValueError(f"{patch_name}: {ins} inputs and {outs} outputs; a current has 0 to 2 ([adc~]) "
                             "and 1 or 2 ([dac~])")
        # Each parameter is (name, hash, min, max, default), the hash as Heavy's C writes it (unpadded: 0x9F29F22).
        # The attributes are the patch's numbers, or Heavy's defaults (0, 1, 0.5) for a bare @hv_param.
        params = [(r.display, r.hash, float(r.attributes.get("min", 0.0)),
                   float(r.attributes.get("max", 1.0)), float(r.attributes.get("default", 0.5)))
                  for _name, r in externs.parameters.inParam]
        notein = NOTEIN in externs.midi.inMidi
        logue = {} if notein else {p[0]: p[1] for p in params if p[0] in LOGUE_NOTE}
        params = [p for p in params if p[0] not in logue]
        noise = [(t.display, t.hash) for _name, t in externs.tables if t.display.endswith("_r")]

        out = Path(out_dir, "ripple")
        out.mkdir(parents=True, exist_ok=True)
        env = jinja2.Environment(loader=jinja2.FileSystemLoader(HERE / "templates"), trim_blocks=True,
                                 lstrip_blocks=True, keep_trailing_newline=True, undefined=jinja2.StrictUndefined)
        (out / f"{patch_name}_current.cc").write_text(env.get_template("current.cc").render(
            name=patch_name, params=params, notein=notein, notein_hash=f"0x{HeavyLangObject.get_hash(NOTEIN):08X}",
            logue=logue, noise=noise, ins=ins, outs=outs, pool_kb=POOL_KB, in_queue_kb=IN_QUEUE_KB))
        (out / "ripple.json").write_text(json.dumps({
            "ins": ins, "outs": outs, "notes": bool(notein or logue),
            "params": [list(p) for p in params]}) + "\n")
        return CompilerResp(stage="c2ripple", in_dir=c_src_dir, out_dir=out, compile_time=time.time() - tick)
