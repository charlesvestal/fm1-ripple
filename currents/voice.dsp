// SPDX-License-Identifier: MIT
// Copyright (C) 2026 Charles Vestal
// voice: a polyphonic synth voice for Ripple. Two detuned saws through a resonant lowpass, an envelope on both.
// freq, gain and gate are what notes set; the other sliders are the current's parameters.
declare name "voice";
declare voices "6";
import("stdfaust.lib");

freq = hslider("freq", 440, 20, 8000, 0.01);
gain = hslider("gain", 0.5, 0, 1, 0.01);
gate = button("gate");
cutoff = hslider("cutoff", 2400, 60, 12000, 1) : si.smoo;
res = hslider("res", 1.5, 0.5, 8, 0.01) : si.smoo;
detune = hslider("detune", 0.12, 0, 1, 0.01);
attack = hslider("attack", 0.005, 0.001, 2, 0.001);
release = hslider("release", 0.35, 0.01, 4, 0.01);
envamt = hslider("envamt", 0.6, 0, 1, 0.01);

env = en.adsr(attack, 0.25, 0.7, release, gate);
saws = (os.sawtooth(freq * (1 + detune * 0.01)) + os.sawtooth(freq * (1 - detune * 0.01))) * 0.5;
fc = min(16000, cutoff * (1 + envamt * 3 * env));
process = saws : fi.resonlp(fc, res, 1) * env * gain * 0.4 <: _, _;
