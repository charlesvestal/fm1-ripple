// SPDX-License-Identifier: MIT
// Copyright (C) 2026 Charles Vestal
// plate: a small reverb for Ripple. Four delay lines (2,048 samples each: 32 KB) feeding each other through a
// Hadamard matrix, damped on every pass, with two allpasses in front to blur the start.
declare name "plate";
import("stdfaust.lib");

size = hslider("size", 0.8, 0.2, 1, 0.01) : si.smoo;
decay = hslider("decay", 0.8, 0, 0.97, 0.01);
damp = hslider("damp", 0.4, 0, 1, 0.01);
mix = hslider("mix", 0.3, 0, 1, 0.01);

N = 2000;                            // under 2048: Faust gives each line the power of two above
lens = (1381, 1637, 1931, 1063);
diffuse = fi.allpass_comb(256, 142, 0.6) : fi.allpass_comb(256, 107, 0.6);
line(i) = de.fdelay(N, ba.take(i + 1, lens) * size) : fi.lowpass(1, 1500 + 14000 * (1 - damp)) * decay;
fdn = (si.bus(8) :> si.bus(4)) ~ (par(i, 4, line(i)) : ro.hadamard(4) : par(i, 4, *(0.5)));
tank(x) = (x, x, x, x : fdn) <: (ba.selector(0, 4) + ba.selector(2, 4)), (ba.selector(1, 4) + ba.selector(3, 4));
process(l, r) = (l + r) * 0.5 : diffuse : tank : par(i, 2, *(mix)) : (+(l * (1 - mix)), +(r * (1 - mix)));
