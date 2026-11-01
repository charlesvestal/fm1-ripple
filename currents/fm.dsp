// SPDX-License-Identifier: MIT
// Copyright (C) 2026 Charles Vestal
// fm: a two-operator FM voice for Ripple (after LOOM-8's rayon): a sine modulating a sine, the modulation falling
// away after the note starts, so a note opens bright and settles; feedback on the modulator for grit.
declare name "fm";
declare voices "6";
import("stdfaust.lib");

freq = hslider("freq", 440, 20, 8000, 0.01);
gain = hslider("gain", 0.5, 0, 1, 0.01);
gate = button("gate");
ratio = hslider("ratio", 2, 0.5, 8, 0.5);
index = hslider("index", 3, 0, 12, 0.01);
fall = hslider("fall", 0.4, 0.01, 4, 0.01);
floor_ = hslider("floor", 0.2, 0, 1, 0.01);
feedback = hslider("feedback", 0, 0, 1, 0.01);
attack = hslider("attack", 0.003, 0.001, 2, 0.001);
release = hslider("release", 0.6, 0.01, 6, 0.01);

amp = en.adsr(attack, 0.3, 0.8, release, gate);
idx = index * (floor_ + (1 - floor_) * en.ar(0.001, fall, gate));
phase(f) = (+(f / ma.SR) : ma.frac) ~ _;
op(x) = sin(phase(freq * ratio) * 2 * ma.PI + x * feedback * 1.5);
modulator = op ~ _;
carrier = phase(freq) * 2 * ma.PI + idx * modulator : sin;
process = carrier * amp * gain * 0.35 <: _, _;
