// SPDX-License-Identifier: MIT
// Copyright (C) 2026 Charles Vestal
// pluck: a plucked string for Ripple (Karplus-Strong): a short burst of noise around a delay as long as the note's
// period, a little darker on each pass. Notes from 56 Hz up (1,024 samples a voice: 24 KB for six).
declare name "pluck";
declare voices "6";
import("stdfaust.lib");

freq = hslider("freq", 220, 56, 4000, 0.01);
gain = hslider("gain", 0.5, 0, 1, 0.01);
gate = button("gate");
damp = hslider("damp", 0.4, 0, 1, 0.01);
decay = hslider("decay", 0.996, 0.9, 0.9995, 0.0001);
bright = hslider("bright", 0.7, 0, 1, 0.01);

trig = gate : ba.impulsify;
burst = no.noise * en.ar(0.0005, 0.004 + 0.01 * bright, trig) : fi.lowpass(1, 600 + 9000 * bright);
period = ma.SR / freq - 1;
loop = + ~ (de.fdelay(1000, period) : fi.lowpass(1, 1000 + 9000 * (1 - damp)) * decay);
process = burst * gain : loop * 0.6 <: _, _;
