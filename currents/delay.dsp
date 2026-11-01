// SPDX-License-Identifier: MIT
// Copyright (C) 2026 Charles Vestal
// delay: a dub delay for Ripple. The bus summed into one line (0.37 s at most), darker on each repeat; the left
// hears the time, the right three quarters of it.
declare name "delay";
import("stdfaust.lib");

time = hslider("time", 0.28, 0.01, 0.36, 0.001) : si.smoo;
feedback = hslider("feedback", 0.45, 0, 0.92, 0.01);
tone = hslider("tone", 3500, 300, 12000, 1);
mix = hslider("mix", 0.3, 0, 1, 0.01);

N = 16000;
d = time * ma.SR;
loop = + ~ (de.fdelay(N, d) : fi.lowpass(1, tone) * feedback);
process(l, r) = l * (1 - mix) + wl * mix, r * (1 - mix) + wr * mix
with {
    w = (l + r) * 0.5 : loop;
    wl = w : de.fdelay(N, d);
    wr = w : de.fdelay(N, d * 0.75);
};
