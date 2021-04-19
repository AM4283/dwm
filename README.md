# DWM
The Suckless Dynamic Window Manager.

This is my personal build. Utilizes polybar for a bar (ik its bloated, I will make a version using slstatus or dwm blocks soon)

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
combo            | **Select multiple tags by holding down mod+tag**
centeredmaster   | **Centered master layout**
cyclelayouts     | **Cycle through layouts w/ bindings**
deck             | **Deck layout (monocole on stack)**
fibonacci        | **Fibonacci and dwindle layouts**
floatrules       | **Configurable rules for sizing floating windows on spawn**
focusmaster      | **Focus master keybindings**
fullgaps togg    | **Toggleable gaps**
gridmode         | **Grid layout**
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
swallow          | **Allows for windows to swallow when spawned from terminal**

## Keybinds
All of the current keybindings are:
  - **Mod** Super Key
  - **Mod+Enter** Spawn Terminal
  - **Mod+d** Launch rofi
  - **Mod+p** Launch dmenu
  - **Mod+grave** Launch scratchpad
  - **Mod+Shift+d**
    * **E** Launch config rofi prompt
    * **B** Launch search rofi prompt
    * **X** Launch kill rofi prompt
    * **Apostrophe** Launch rofi emoji prompt
  - **Mod+b** Toggle bar
  - **Mod+Control+b** Restart polybar
  - **Mod+j/k** Focus stack up/down
  - **Mod+Shift+j/k or Mod+Control+h/l** Move window up/down entire stack
  - **Mod+Control+j/k** Move window up/down only on master or slave stack
  - **Mod+semicolon** Mark window to be swapped
  - **Mod+leftbracket** Swap focus to marked window
  - **Mod+Shift+leftbracket** Switch window with marked window
  - **Mod+i/o** Increase/decrease number of master windows
  - **Mod+Shift+i** Make window the new master window
  - **Mod+y** Focus master window
  - **Mod+Shift+y** Reset number of master windows
  - **Mod+h/l** Resize window left/right
  - **Mod+Shift+h/l** Resize window up/down
  - **Mod+Shift+o** Reset vertical window size
  - **Mod+Shift+q** Kill window
  - **Mod+t** Toggle master/slave layout
  - **Mod+f** Toggle floating layout
  - **Mod+Shift+f** Toggle fullscreen
  - **Mod+m** Toggle monocle layout
  - **Mod+g** Toggle grid layout
  - **Mod+Shift+g** Toggle deck layout
  - **Mod+c** Toggle centered master layout
  - **Mod+Shift+c** Toggle floating centered master layout
  - **Mod+Shift+r** Toggle dwindle layout
  - **Mod+Control+r** Toggle fibonacci layout
  - **Mod+u** Toggle bottom stack layout
  - **Mod+Shift+u** Toggle bottom stack horizontal layout
  - **Mod+r** Reset placement/sizes of windows in layout
  - **Mod+Space** Toggle previous layout
  - **Mod+Shift+Space** Toggle floating on window
  - **Mod+Control+comma/period** Cycle layout prev/next
  - **Mod+0** View all windows from all tags
  - **Mod+Shift+0** Make window visible on all tags
  - **Mod+Tab** Switch to previous tag
  - **Mod+s** Toggle a window to be sticky
  - **Mod+comma/period** Focus monitor prev/next
  - **Mod+Shift+comma/period** Focus tag on prev/next monitor
  - **Mod+b/n** Focus prev/next tag
  - **Mod+1-9** Focus tag 1-9 *(Hold Mod+1-9 to focus multiple tags at once)*
  - **Mod+Shift+1-9** Move window to tag 1-9
  - **Mod+minus/plus** Decrease/increase gaps 5px
  - **Mod+Shift+minus/plus** Rest/toggle gaps
  - **Mod+z** Rofi logout prompt
  - **Mod+Shift+z** Quit dwm
  - **Brightness up/down** Increase/decrease backlight
  - **Audio up/down/mute** Increase/decrease/mute active speakers
  - **Playpause/Previous/Next** Pause/play/skip back/skip next on current audio application
  - **Mod+Shift+v** Bring up pulseaudio volume control
  - **prntscrn** Take a screenshot (flameshot app)
## Dependencies
*Unfinished List*

Currently, the dependencies include the default dwm dependencies as well as:
```
Rofi, polybar w/dwm module, alacritty, light, flameshot, playerctl, pavucontrol, font awesome, mononoki Nerd Font, Hack font, Noto Color emoji, rofimoji, rofi scripts
```
