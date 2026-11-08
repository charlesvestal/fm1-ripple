# Ripple

Ripple turns the M-VAVE FM-1 into an instrument you can reprogram without reflashing. Its instruments are
droplets, which are small programs written in Lua. Fifteen are built in, from a drum machine to generative bells, a
looper and the Game of Life. Droplets make their sounds with currents, which are written in Faust, Pd or C. Any droplet can
load any currents and chain them as it likes, so you can recombine the same voices, drums and effects into a new
instrument in a few lines of Lua. To add your own, put the FM-1 in disk mode. It shows up on your computer as a USB
drive, and you copy your files onto it.

![Ripple's list of droplets on the FM-1's screen](manual/img/list.png "Ripple")

This is version {{VERSION}}. You install it at your own risk, and the installer can put M-VAVE's own firmware back.

- [Try it in the browser](emu/). It runs the same code as the FM-1, with sound, and you don't need an FM-1.
- [Install](install/) from Chrome or Edge, with the FM-1 connected by USB.
- Read the [manual](manual/) to learn the list, the fifteen droplets, disk mode and saving.
- To write your own droplets, see [Writing droplets](https://github.com/charlesvestal/fm1-ripple/blob/main/docs/DROPLETS.md) for the Lua API.
- To write your own currents in Faust, Pd or C, see [Writing currents](https://github.com/charlesvestal/fm1-ripple/blob/main/sdk/README.md) for the SDK.
- [Download {{PKG}}](firmware/{{PKG}}) to install from a terminal: `python3 tools/fm1_install.py {{PKG}}`.
- The [source](https://github.com/charlesvestal/fm1-ripple) is under MPL-2.0, and the SDK and the droplets are
  under MIT. Ripple is built on fm1-base and felucca-bsp, which come from Felucca by Leo Kuroshita, Hügelton
  Instruments. It uses Lua 5.4 by Lua.org, PUC-Rio. Currents are written in Faust, by GRAME, or in Pd, compiled by
  [hvcc](https://github.com/Wasted-Audio/hvcc), which Wasted Audio continues from Enzien Audio's Heavy. Ripple is
  inspired by monome's norns.

M-VAVE and FM-1 are trademarks of their owners. Ripple is not affiliated with M-VAVE or monome.
