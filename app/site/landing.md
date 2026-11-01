# Ripple

Ripple turns the M-VAVE FM-1 into an instrument you can reprogram without reflashing. Droplets, small programs in
Lua, are its instruments: twelve are built in, from a drum machine to generative bells, a looper and the Game of
Life. Their sounds are currents, written in Faust or C, and any droplet can load any currents and chain them as it
likes: the same voices, drums and effects, recombined into new instruments in a few lines of Lua. To add your own,
put the FM-1 in disk mode: it shows up on your computer as a USB drive, and you copy files onto it.

![Ripple's list of droplets on the FM-1's screen](manual/img/list.png "Ripple")

Version {{VERSION}}. Installing is at your own risk; the installer can put M-VAVE's own firmware back.

- [Install](install/): from Chrome or Edge, with the FM-1 connected by USB.
- [Manual](manual/): the list, the twelve droplets, disk mode, saving.
- [Writing droplets](https://github.com/charlesvestal/fm1-ripple/blob/main/docs/DROPLETS.md): the Lua API.
- [Writing currents](https://github.com/charlesvestal/fm1-ripple/blob/main/sdk/README.md): Faust or C, and the SDK.
- [Download {{PKG}}](firmware/{{PKG}}): for the command-line installer, `python3 tools/fm1_install.py {{PKG}}`.
- [Source](https://github.com/charlesvestal/fm1-ripple): MPL-2.0; the SDK and the droplets MIT. Built on fm1-base
  and felucca-bsp, from Felucca by Leo Kuroshita, Hügelton Instruments. Lua 5.4 by Lua.org, PUC-Rio. Currents in
  Faust, by GRAME. Inspired by monome's norns.

M-VAVE and FM-1 are trademarks of their owners. Ripple is not affiliated with M-VAVE or monome.
