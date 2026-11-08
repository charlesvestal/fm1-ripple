# Ripple

Ripple turns the M-VAVE FM-1 into an instrument you can reprogram without reflashing. It runs droplets. A droplet
is a small program in Lua, and each one is a different instrument, from a drum machine to a generative ambient
piece. Droplets make their sounds with currents, which are written in Faust, Pd or C. Any droplet can load any
currents and chain them as it likes, so the same voices, drums and effects turn up in many instruments, and a new
instrument can take just a few lines of Lua. Fifteen droplets and twenty-five currents are built in, and you can add
your own. In disk mode, the FM-1 shows up on your computer as a USB drive, and you copy your files onto it.

The idea comes from monome's norns, which runs small scripts over compiled sound engines.

![The list of droplets: arp at the top, then awake, beat, bells, chords, drone, euclid, life and loop](img/list.png "The droplets")

---

## Contents

1. Install
2. The list
3. The built-in droplets
4. Disk mode
5. Saving
6. When a droplet stops
7. Writing your own
8. Limits

---

## 1. Install

Connect the FM-1 to your computer by USB, open the installer in Chrome or Edge, and press Install. The first time,
the browser asks to allow MIDI. Allow it. Don't unplug the cable while the installer writes.

Or from a terminal: `python3 tools/fm1_install.py ripple-VERSION.fwsc`.

To put M-VAVE's own firmware back, use the last section of the installer.

---

## 2. The list

Ripple starts on the list of droplets. Built-in droplets have an outlined mark, and droplets on your disk have a
filled one. If a droplet on your disk has the same name as a built-in one, Ripple plays yours instead.

| Control | What it does |
| --- | --- |
| SELECT, OCT− · OCT+ | Move through the list. |
| PLAY or SEL | Start the droplet. |
| Hold HOME for a second | Leave the droplet and come back to the list, from anywhere. |

The last two entries in the list aren't droplets. Choose **Disk mode** to open the disk on a computer. Choose
**Empty the disk** to erase everything on it. Press PLAY, then PLAY again to confirm. The folders stay, and so do
the built-in droplets, because they aren't on the disk.

The list opens on the droplet you started last.

---

## 3. The built-in droplets

While a droplet runs, the keys, knobs and buttons all belong to it. Only holding HOME for a second leaves it. MASTER is always
the volume.

| Droplet | What it is |
| --- | --- |
| arp | Hold keys, and they play one after another. |
| awake | A melody that wanders a scale on its own. |
| beat | A 16-step drum machine on the white keys. |
| bells | FM bells on loops of different lengths that drift in and out of step. |
| chords | A chord on every white key. |
| drone | Three slow FM voices that change color by themselves. |
| euclid | Three drum tracks that spread their hits as evenly as they can. |
| life | Conway's Game of Life, playing a note for each cell born. |
| loop | Play a phrase, and it repeats while you play over it. |
| midi | Use the FM-1 as a USB MIDI controller. It makes no sound of its own. |
| monk | A singing voice. Lean on a key to open the vowel. |
| poly | A six-voice synth through a delay. |
| rack | Build your own instrument from MIDI effects, a voice and two effects. |
| rain | Plucked notes that fall on a scale into a reverb. |
| sophie | Sixteen pads of metallic FM percussion with a 16-step pattern. |

### arp

| Control | What it does |
| --- | --- |
| Keys | Hold them, and they play in turn. |
| ARP | Keeps the notes playing after you let go. The next keys you press replace them. Press ARP again to stop. |
| PRESET | Picks the order: up, down, up and down, random, or as played. |
| ALGORITHM | Switches the sound between saws and FM. |
| K1 · K2 · K3 · K4 | Set the rate (eighths to thirty-seconds), how many octaves it climbs (1 to 3), how long each note lasts, and the brightness. |

### awake

![awake: dots wandering up and down, the step marker under them, wander 2 rest 20%](img/awake.png "awake")

Every sixteenth note, awake moves a few steps up or down the scale and plays the note it lands on, or rests. The
scale is C Dorian, over three octaves. The dots on the screen are the last 16 steps.

| Control | What it does |
| --- | --- |
| PLAY | Stops and starts it. |
| Keys | Play along on the same voice. |
| K1 · K2 · K3 · K4 | Set the tempo, how far it moves each step (1 to 5), how often it rests, and the filter. |

### beat

| Control | What it does |
| --- | --- |
| White keys | Each one is a step of the 16. Press a key to turn its step on or off. |
| ALGORITHM | Picks the drum: kick, snare or hat. |
| PLAY | Starts and stops the pattern. |
| K1 · K2 · K3 · K4 | Set the tempo, the drums' tuning, their decay, and the snare's snap. |

### bells

![bells: four rings, a dot going round each](img/bells.png "bells")

Each bell rings once every 13, 17, 23, 29, 31 or 37 sixteenths, so the bells line up only now and then. Now and
then a bell moves to a neighboring note of the scale.

| Control | What it does |
| --- | --- |
| Keys | Ring a bell. |
| K1 · K2 · K3 · K4 | Set the tempo, how bright the bells are, the reverb's size, and how many bells ring (1 to 6). |

### chords

![chords: C and G held, their notes as dots](img/chords.png "chords")

| Control | What it does |
| --- | --- |
| White keys | Each plays the chord of C major that starts on its note. D plays D minor, and G plays G major. |
| Black keys | Play single notes an octave up, over the chords. |
| PRESET | Picks the kind of chord: triads, sevenths, sus, ninths or open fifths. |
| ALGORITHM | Switches the sound between saws and FM. |
| K1 · K2 · K3 · K4 | Set the brightness, the strum (at 0 the notes play together), close or open voicing, and the echo. |

### drone

| Control | What it does |
| --- | --- |
| Keys | Move the root. The fifth and the octave follow it. |
| K1 · K2 · K3 · K4 | Set how fast the color changes, how bright it is, the FM ratio, and the reverb. |

### euclid

![euclid: three rings of dots, the hits larger](img/euclid.png "euclid")

Each track spreads its hits as evenly as it can over its steps. Four hits in 16 steps give you four on the floor,
and 3 in 8 give you a tresillo. When the tracks have different lengths, they drift against each other.

| Control | What it does |
| --- | --- |
| ALGORITHM | Picks the track: kick, snare or hat. |
| K1 · K2 · K3 | Set the track's steps (1 to 16), its hits, and where it starts. |
| K4 | Sets the tempo. |
| PLAY | Starts and stops it. |
| Keys | Play the track's drum. |

### life

![life: the grid with a few shapes, the cells just born brighter](img/life.png "life")

A cell is born where it has exactly three neighbors, and it lives on while it has two or three. Each birth can play
a note. The cell's column picks the note of the scale, and its row picks the octave. When the grid goes quiet, it
seeds itself again.

| Control | What it does |
| --- | --- |
| Keys | Plant seeds in their column. |
| PLAY | Pauses it. |
| K1 · K2 · K3 · K4 | Set the tempo, how many births can sound at once, how long the strings ring, and the reverb. |

### loop

![loop: a circle with four notes on it and the hand of the clock](img/loop.png "loop")

| Control | What it does |
| --- | --- |
| REC | Starts and stops recording. What you record adds to what's already there. |
| PLAY | Starts and stops the loop. |
| EDIT | Clears the loop. |
| Keys | Play notes. While you record, each note lands on the sixteenth that's playing. |
| K1 · K2 · K3 · K4 | Set the length (1, 2 or 4 bars), the tempo, how long the strings ring, and the reverb. |

### midi

| Control | What it does |
| --- | --- |
| Keys | Send notes over USB, with their velocity. |
| K1 · K2 · K3 · K4 | Send CCs 74, 71, 1 and 7. |
| OCT− · OCT+ | Move the keys an octave. |
| PRESET | Picks the MIDI channel. |

Any MIDI that comes in shows at the bottom of the screen.

### monk

monk plays MonkSynth's singing voice (by Jonathan Taylor) through the delay, the same way MONK-1 does. It sings
one note at a time.

| Control | What it does |
| --- | --- |
| Keys | Sing. The harder you play, the louder it sings. Lean on a key to open the vowel (or bend the note). |
| OCT− · OCT+ | Move the keys an octave. |
| ALGORITHM | Picks what leaning does: open the vowel, bend the note, both, or close the vowel and bend. |
| EDIT | Use K1–K4 for the vowel, head size, breath and level. |
| LFO | Use K1–K4 for the vibrato, its rate, the glide and the tuning. |
| ENV | Use K1–K4 for the attack, decay, sustain and release. |
| GLO | Use K1–K4 for the choir (1 to 4 voices), their detune, their spread, and how far leaning reaches. |
| FX | Use K1–K4 for the delay's time, feedback, tone and mix. |

### poly

| Control | What it does |
| --- | --- |
| Keys | Play up to six notes at once. |
| OCT− · OCT+ | Move the keys an octave. |
| ALGORITHM | Switches the sound between saws and FM. |
| K1 · K2 | Set the filter's cutoff and resonance. With FM, they set its brightness and ratio. |
| K3 · K4 | Set the delay's time and feedback. |

### rack

Use rack to build an instrument on the FM-1 from any currents, built in or on the disk. The keys (or a MIDI
keyboard, over USB or the MIDI jack) go through MIDI effects into a voice, and then through two effects. The MIDI
effects are the RS7000's Play FX, as e16-launcher has them.

| Control | What it does |
| --- | --- |
| ARP | Opens the MIDI effects. Press SELECT to turn their pages (chord, arp, echo, feel, loop), and press ARP again to turn the page's effect on or off. |
| EDIT · FX · GLO | Open the voice, the first effect and the second effect. Use ALGORITHM to pick the current (an effect can be none), and press SELECT to turn its pages of knobs. |
| K1 · K2 · K3 · K4 | Set the page's knobs. |
| Hold SEQ | Loops what you just played, as set by loop and stretch on the loop page. |
| PRESET | Sets the tempo. When MIDI clock comes in, the MIDI effects follow it. |
| OCT− · OCT+ | Move the keys an octave. |
| SAVE | Keeps the rack: its currents, their knobs and the MIDI effects. |

The voices include seventeen macro-oscillator engines (`macro-va`, `macro-modal`, `macro-kick` and the rest), from
Emilie Gillet's open-source Plaits code. On each engine, K1–K3 set its harmonics, timbre and morph. Each release has three
more (`macro-wave`, `macro-sixop`, `macro-speech`). To use them, copy them into `currents` on the disk in disk mode.

Each release also has four droplets that play Pd patches from the community (`robot`, `chip`, `fold`, `mono`), and
the currents they use. For what each one does, see
[Droplets on Pd patches](https://github.com/charlesvestal/fm1-ripple/blob/main/examples/pd/README.md).

The top of the screen shows how busy the sound is and how much room is left for currents. If a current doesn't
fit, the bottom of the screen says so, and its slot stays empty.

### rain

![rain: ripples spreading where notes fell](img/rain.png "rain")

| Control | What it does |
| --- | --- |
| PLAY | Stops and starts the rain. |
| Keys | Play along. |
| K1 · K2 · K3 · K4 | Set how hard it rains, how bright the drops are, the reverb's size, and how long the strings ring. |

### sophie

sophie plays Sophie's sixteen pads of metallic FM percussion (by Matt Estela) through the reverb, the same way
SPH-16 does. Kit 1 is Sophie's own.

| Control | What it does |
| --- | --- |
| Keys | The lowest sixteen play the pads. The harder you play, the louder they sound. The knobs change the pad you played last. |
| PLAY | Starts and stops the pattern. |
| REC | While REC is lit, what you play goes into the pattern. |
| SEQ | Turns the white keys into the steps of the pad you played last. |
| SELECT | Picks the pad. |
| ALGORITHM | Picks the pad's model: fuse, stack, split, shard, pipe or boom. |
| EDIT | Use K1–K4 for the pad's sound: tune, decay, color and metal. |
| ENV | Use K1–K4 for its shape: feedback, sweep, cutoff and resonance. |
| LFO | Use K1–K4 for its ring: time, amount, mix and tone. |
| FX | Use K1–K4 for its grit: drive, crush, level and pan. |
| GLO | Use K1–K4 for the reverb's size, decay, damping and mix. |
| PRESET | Sets the tempo. |

---

## 4. Disk mode

![Disk mode: a drive on the screen, "connect the FM-1 to a computer"](img/disk.png "Disk mode")

Choose **disk mode** at the end of the list. The FM-1 drops off USB for a moment and comes back as a drive called
RIPPLE, with four folders:

| Folder | What goes in it |
| --- | --- |
| `droplets` | Droplets, as `.lua` files. Each one shows up in the list. |
| `currents` | Currents, as `.cur` files made with Ripple's SDK. |
| `data` | What droplets save, in one file per droplet, named after it. Delete a file to give its droplet its defaults back. |
| `lib` | Lua modules that your droplets share. |

Copy files on or off, then eject the drive on your computer. Ripple comes back to the list with what you added. You
can also press HOME to leave without ejecting. If you've changed anything, eject first so the computer finishes
writing.

While the FM-1 is a drive, it has no USB MIDI or USB audio. The disk holds 276 KB.

---

## 5. Saving

In every built-in droplet except poly, press SAVE to keep its settings. beat, euclid, loop and sophie keep their
patterns too, and rack keeps the whole rack. They come back the next time you start the droplet. The sound stops for a moment while the FM-1 writes.

---

## 6. When a droplet stops

![The droplet stopped: the error, the line it came from, what it printed last](img/error.png "A droplet with a mistake")

If a droplet has a mistake, it stops, and the screen shows what went wrong, the line it happened on, and the last
lines the droplet printed. Press HOME to go back to the list. Then fix the file in disk mode and try again.

---

## 7. Writing your own

A droplet is a Lua file. Its functions answer the keys, knobs and buttons, draw the screen and play notes on
currents. For the whole API, see [Writing droplets](https://github.com/charlesvestal/fm1-ripple/blob/main/docs/DROPLETS.md).

A current is a sound. You write it in Faust, Pd or C and build it into a `.cur` file on your computer. For the SDK,
see [Writing currents](https://github.com/charlesvestal/fm1-ripple/blob/main/sdk/README.md).

To change a built-in droplet, copy it from `builtin/droplets` in Ripple's source onto the disk, and edit it there.

---

## 8. Limits

| What | How much |
| --- | --- |
| The disk | 276 KB |
| A droplet's memory (Lua) | 112 KB |
| A droplet's currents, together | 132 KB, of which the reverb takes 38 KB and the delay 16 KB |
| MIDI effects in one droplet | 2 |
| Currents in one droplet | 8 |
| What a droplet saves | 8 KB |
| Droplets in the list | 47 |
