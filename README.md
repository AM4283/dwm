# DWM
The Suckless Dynamic Window Manager.

This is my personal build. Able to use polybar as a bar. Currently used with my build of dwmblocks + necessary scripts.

## Patches
This build includes the patches:
Patch | Functionality
------|------
actualfullscreen | **true fullscreen support**
alpha            | **default bar transparency, transparent window border fix**
anybar (with polybar tray fix) | **Alternate bar support**
attach direction | **different master/slave behavior support** 
autostart        | **autostart script support**
bottomstack      | **Bottom stack and bottom stack horizontal layouts**
cfacts           | **Allows for resizing of windows vertically**
colorbar         | **More configurable default statusbar colors**
combo            | **Support for selecting multiple tags by holding down mod+tag**
centeredmaster   | **Centered master layout**
cyclelayouts     | **Cycle through layouts w/ bindings**
deck             | **Deck layout (monocole on stack)**
fibonacci        | **Fibonacci and dwindle layouts**
floatrules       | **Configurable rules for sizing floating windows on spawn**
focusmaster      | **Focus master keybindings**
gridmode         | **Grid, horizontal grid, nrowgrid, gapless grid, layouts**
hide vacant tags | **Hide tags on default statusbar that are empty**
inplacerotate    | **Able to move windows only in stack or only in master**
ipc              | **ipc functions**
keychain         | **Keychord keybinding support**
mark-new         | **Allows for windows to be marked and switched focus with**
pertag           | **Per tag layout support**
resetlayout      | **Keybinding to reset size of windows in layout**
resetnmaster     | **Keybinding to reset number of master windows**
restartsig       | **Restart dwm keybinding**
rotatestack      | **Rotate window through stack**
savefloats       | **Saves size+location of floating window when toggling back to tiling**
scratchpad       | **Terminal scratchpad functionality**
sticky           | **Allows for a window to be toggled to be shown on all tags easily**
stickyindicator  | **Adds sticky window indicator in default statusbar**
shiftview        | **Switch through next/prev tags w/ binding**
statuscmd        | **Clickable DWM blocks support**
swallow          | **Allows for windows to swallow when spawned from terminal**
vanitygaps       | **Highly configurable gaps that work on each layout**
warp             | **warps cursor to center of focused window**

## Keybinds

### Program launchers
  - **Mod** Super Key
  - **Mod+Enter** Spawn Terminal
  - **Mod+grave** Launch scratchpad
  - **Mod+Shift+b** Toggle bar
  - **Mod+Control+b** Restart polybar
  - **Mod+Shift+v** Bring up pulseaudio volume control
  - **prntscrn** Take a screenshot (flameshot app)

### Rofi/dmenu prompts
  - **Mod+d** Launch rofi
  - **Mod+p** Launch dmenu
  - **Mod+Shift+d**
    * **E** Launch config rofi prompt
    * **B** Launch search rofi prompt
    * **X** Launch kill rofi prompt
    * **Apostrophe** Launch rofi emoji prompt

### Window Movement
  - **Mod+j/k** Focus stack up/down
  - **Mod+Shift+j/k** Move window up/down entire stack
  - **Mod+Control+j/k** Move window up/down only on master or slave stack
  - **Mod+i/o** Increase/decrease number of master windows
  - **Mod+Shift+i** Make window the new master window
  - **Mod+y** Focus master window
  - **Mod+Shift+y** Reset number of master windows
  - **Mod+semicolon** Mark window to be swapped
  - **Mod+leftbracket** Swap focus to marked window
  - **Mod+Shift+leftbracket** Switch window with marked window
  - **Mod+h/l** Resize window left/right
  - **Mod+Shift+h/l** Resize window up/down
  - **Mod+Shift+o** Reset vertical window size
  - **Mod+Shift+q** Kill window

### Layouts
  - Mod+r
    * **T** master/slave layout
    * **F** floating layout
    * **M** monocle layout
    * **D** Deck layout
    * **C** centered master layout
    * **V** centered floating master layout
    * **S** Spiral/fibonacci layout
    * **A** Dwindle layout
    * **B** Bottom stack layout
    * **N** Bottom stack horizontal layout
    * **G** Grid layout
    * **H** Gapless grid layout
    * **K** Nrow grid layout
    * **L** Horizontal grid layout
    * **R** Reset placement/sizes of windows in layout
  - **Mod+Shift+f** Toggle fullscreen
  - **Mod+Space** Toggle previous layout
  - **Mod+Shift+Space** Toggle floating on window
  - **Mod+Control+comma/period** Cycle layout prev/next

### Tag Movement
  - **Mod+0** View all windows from all tags
  - **Mod+Shift+0** Make window visible on all tags
  - **Mod+Tab** Switch to previous tag
  - **Mod+s** Toggle a window to be sticky
  - **Mod+comma/period** Focus monitor prev/next
  - **Mod+Shift+comma/period** Focus tag on prev/next monitor
  - **Mod+b/n** Focus prev/next tag
  - **Mod+1-9** Focus tag 1-9
  - **Mod+Shift+1-9** Move window to tag 1-9
  - **Mod+Control+1-9** View different tag on current tag
  - **Mod+Shift+Control+1-9** Toggle window to be viewable on certain tag

### Gaps
  - **Mod+Alt+u** Increase all gaps 1px
  - **Mod+Shift+Alt+u** Decrease all gaps 1px
  - **Mod+Alt+i** Increase inner gaps 1px
  - **Mod+Shift+Alt+i** Decrease inner gaps 1px
  - **Mod+Alt+o** Increase outer gaps 1px
  - **Mod+Alt+Shift+o** Decrease outer gaps 1px
  - **Mod+Alt+0** Toggle gaps
  - **Mod+Shift+Alt** Reset gaps to default
  
### Media Controls
  - **Brightness up/down** Increase/decrease backlight
  - **Audio up/down/mute** Increase/decrease/mute active speakers
  - **Mod+F6** Mute mic
  - **Mod+F7** Decease mic volume
  - **Mod+F8** Increase mic volume
  - **Playpause/Previous/Next** Pause/play/skip back/skip next on current audio application

### Quit DWM
  - **Mod+z** Rofi logout prompt
  - **Mod+Shift+z** Quit DWM
  - **Mod+Shift+Control** Restart DWM

## Dependencies
*Unfinished List*

Currently, the dependencies include the default dwm dependencies as well as:
```
Rofi, polybar w/dwm module, alacritty, light, flameshot, playerctl, pavucontrol, font awesome, mononoki Nerd Font, Hack font, Noto Color emoji, rofimoji, rofi scripts
```
