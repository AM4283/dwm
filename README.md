# DWM
The Suckless Dynamic Window Manager.
This is my personal build. Utilizes polybar for a bar (ik its bloated, I will make a version using slstatus or dwm blocks soon)

## Patches
This build includes the patches:
Patch | Functionality
------|------
actualfullscreen | **true fullscreen support**
anybar (with polybar tray fix) | **Alternate bar support**
attach direction | **different master/slave behavior support** 
autostart        | **autostart script support**
centeredmaster   | **Centered master layout**
cyclelayouts     | **Cycle through layouts w/ bindings**
fibonacci        | **Fibonacci and dwindle layouts**
floatrules       | **Configurable rules for sizing floating windows on spawn**
focusmaster      | **Focus master keybindings**
fullgaps togg    | **Toggleable gaps**
gridmode         | **Grid layout**
ipc              | **ipc functions**
keychain         | **Keychord keybinding support**
pertag           | **Per tag layout support**
restartsig       | **Restart dwm keybinding**
rotatestack      | **Rotate window through stack**
shiftview        | **Switch through next/prev tags w/ binding**

## Keybinds
All of the current keybindings are:
  - **Mod** Super Key
  - **Mod+Enter** Spawn Terminal
  - **Mod+d** Launch rofi
  - **Mod+p** Launch dmenu
  - **Mod+Shift+d**
    * **E** Launch config rofi prompt
    * **B** Launch search rofi prompt
    * **X** Launch kill rofi prompt
    * **Apostrophe** Launch rofi emoji prompt
  - **Mod+b** Toggle bar
  - **Mod+Control+b** Restart polybar
  - **Mod+j/k** Focus stack up/down
  - **Mod+Shift+j/k** Move window up/down stack
  - **Mod+i/o** Make window master/slave
  - **Mod+y** Focus master window
  - **Mod+h/l** Resize window left/right
  - **Mod+Shift+q** Kill window
  - **Mod+t** Toggle master/slave layout
  - **Mod+f** Toggle floating layout
  - **Mod+Shift+f** Toggle fullscreen
  - **Mod+m** Toggle monocle layout
  - **Mod+g** Toggle grid layout
  - **Mod+c** Toggle centered master layout
  - **Mod+Shift+c** Toggle floating centered master layout
  - **Mod+Shift+r** Toggle dwindle layout
  - **Mod+Control+r** Toggle fibonacci layout
  - **Mod+Space** Toggle previous layout
  - **Mod+Shift+Space** Toggle floating on window
  - **Mod+Control+comma/period** Cycle layout prev/next
  - **Mod+0** View all windows from all tags
  - **Mod+Shift+0** Make window visible on all tags
  - **Mod+Tab** Switch to previous tag
  - **Mod+comma/period** Focus monitor prev/next
  - **Mod+Shift+comma/period** Focus tag on prev/next monitor
  - **Mod+b/n** Focus prev/next tag
  - **Mod+1-9** Focus tag 1-9
  - **Mod+Shift+1-9** Move window to tag 1-9
  - **Mod+minus/plus** Decrease/increase gaps 5px
  - **Mod+Shift+minus/plus** Rest/toggle gaps
  - **Mod+z** Rofi logout prompt
  - **Mod+Shift+z** Quit dwm
  - **Audio up/down/mute** Increase/decrease/mute active speakers
  - **Playpause/Previous/Next** Pause/play/skip back/skip next on current audio application
  - **Mod+Shift+v** Bring up pulseaudio volume control
  - **prntscrn** Take a screenshot (flameshot app)
## Dependencies
*Unfinished List*
Currently, the dependencies include the default dwm dependencies as well as:
'Rofi, polybar w/dwm module, alacritty, light, flameshot, playerctl, pavucontrol, font awesome, mononoki Nerd Font, Hack font, Noto Color emoji, rofimoji, rofi scripts'
