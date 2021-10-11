# DWM
The Suckless Dynamic Window Manager.

This is my personal build. Able to use polybar as a bar. Currently used with my build of dwmblocks + necessary scripts.

## Patches
This build includes the patches:
| Patch | Functionality |
| :-- |:-- |
| actualfullscreen | **True fullscreen support**
| alpha            | **Default bar transparency, transparent window border fix**
| anybar (with polybar tray fix) | **Alternate bar support**
| attach direction | **Different master/slave behavior support** 
| autostart        | **Autostart script support**
| bottomstack      | **Bottom stack and bottom stack horizontal layouts**
| cfacts           | **Allows for resizing of windows vertically**
| colorbar         | **More configurable default statusbar colors**
| combo            | **Support for selecting multiple tags by holding down mod+tag**
| centeredmaster   | **Centered master layout**
| cyclelayouts     | **Cycle through layouts w/ bindings**
| deck             | **Deck layout (monocole on stack)**
| fibonacci        | **Fibonacci and dwindle layouts**
| floatrules       | **Configurable rules for sizing floating windows on spawn**
| focusadjacenttag | **Focuses or moves window to left/right tag**
| focusmaster      | **Focus master keybindings**
| focusonnetactive | **Makes DWM focus windows requested by NET_ACTIVE_WINDOW (allows skippy-xd to work)**
| gridmode         | **Grid, horizontal grid, nrowgrid, gapless grid, layouts** |
| hide vacant tags | **Hide tags on default statusbar that are empty** |
| inplacerotate    | **Able to move windows only in stack or only in master** |
| ipc              | **ipc functions** |
| keychain         | **Keychord keybinding support** |
| mark-new         | **Allows for windows to be marked and switched focus with** |
| netclientliststacking | **Allows for screensharing in certain applications (zoom)** |
| pertag           | **Per tag layout support** |
| resetlayout      | **Keybinding to reset size of windows in layout** |
| resetnmaster     | **Keybinding to reset number of master windows** |
| restartsig       | **Restart dwm keybinding** |
| rotatestack      | **Rotate window through stack** |
| savefloats       | **Saves size+location of floating window when toggling back to tiling** |
| scratchpad       | **Terminal scratchpad functionality** |
| sendmon_keepfocus| **Keeps window focus when sending to other monitor** |
| statusallmons    | **Draws statusbar on all monitors** |
| steam            | **prevents client focus issues on steam/widows games** |
| sticky           | **Allows for a window to be toggled to be shown on all tags easily** |
| stickyindicator  | **Adds sticky window indicator in default statusbar** |
| shiftview        | **Switch through next/prev tags w/ binding** |
| shiftviewclients | **Switch through next/prev tags w/binding that are not vacant** |
| statuscmd        | **Clickable DWM blocks support** |
| swallow          | **Allows for windows to swallow when spawned from terminal** |
| swapfocus        | **Keybinding to swap focus to last used window** |
| swaptags         | **Keybinding to swap contents of one tag with another** |
| switchcol        | **Keybinding to switch between master/stack columns** |
| tagall           | **Keybinding to move all windows of one tag to another** |
| tagallmonitor    | **Keybinding to move all windows of one monitor to another** |
| tagothermonitor  | **Keybinding to move window to specific tag of other monitor** |
| tagswapmon       | **Keybinding to swap contents of one monitor with another** |
| vanitygaps       | **Highly configurable gaps that work on each layout** |
| viewontag        | **Switches focus to tag when moving window** | 
| warp             | **Warps cursor to center of focused window** |
| Xresources       | **Allows settings to be loaded from an Xresources file** |

## Keybinds

### Program launchers
  - **Mod** Super Key
  - **Mod+Enter** Spawn Terminal
  - **Mod+grave** Launch scratchpad
  - **Mod+Shift+b** Toggle bar
  - **Mod+Control+b** Restart polybar
  - **Mod+Shift+p** Launch trayer
  - **Mod+Shift+v** Bring up pulseaudio volume control
  - **prntscrn** Take a screenshot (flameshot app)

### Rofi/dmenu prompts
  - **Mod+d** Launch rofi
  - **Mod+p** Launch dmenu
  - **Mod+Shift+d**
    * **E** Launch config rofi prompt
    * **S** Launch search rofi prompt
    * **X** Launch kill rofi prompt
    * **Apostrophe** Launch rofi emoji prompt
    * **B** Launch sxiv background selection prompt
    * **T** Launch rofi theme selection prompt

### Window Movement
  - **Mod+j/k** Focus stack up/down
  - **Mod+Shift+j/k** Move window up/down entire stack
  - **Mod+Control+j/k** Move window up/down only on master or slave stack
  - **Mod+i/o** Increase/decrease number of master windows
  - **Mod+Shift+i** Reset number of master windows
  - **Mod+u** Focus master window
  - **Mod+Shift+u** Swap window with master
  - **Mod+y** Switch focus between master column/stack column
  - **Mod+s** Switches to most recent window
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
  - **Mod+f** Toggle fullscreen
  - **Mod+Space** Toggle previous layout
  - **Mod+Shift+Space** Toggle floating on window
  - **Mod+Control+comma/period** Cycle layout prev/next

### Tag Movement
  - **Mod+0** View all windows from all tags
  - **Mod+Shift+0** Make window visible on all tags
  - **Mod+Tab** Switch to previous tags
  - **Mod+Shift+Tab** Open skippy-xd
  - **Mod+Shift+s** Toggle a window to be sticky
  - **Mod+comma/period** Focus monitor prev/next
  - **Mod+Shift+comma/period** Focus tag on prev/next monitor
  - **Mod+b/n** Focus prev/next tag (ignores vacant tags)
  - **Mod+left/right arrow** Focus next/prev tag (including vacant tags)
  - **Mod+Shift+left/right arrow** Move window to left/right tags
  - **Mod+1-9** Focus tag 1-9
  - **Mod+Shift+1-9** Move window to tag 1-9
  - **Mod+Control+1-9** View different tag on current tag
  - **Mod+Shift+Control+1-9** Toggle window to be viewable on certain tag
  - **Mod+Control+Alt+1-9** Swaps contents of current tag with certain tag
  - **Mod+Shift+F1-F9** Moves all content on current tag onto certain tag
  - **Mod+Alt+comma/period** Moves all content on current monitor to other
  - **Mod+Control+comma/period** Swaps current monitor with other monitor

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
  - **Mod+Home** Alternate mute mic
  - **Mod+Pgup** Alternate increase mic volume
  - **Mod+Pgdown** Alternate decrease mic volume
  - **Playpause/Previous/Next** Pause/play/skip back/skip next on current audio application

### Quit DWM
  - **Mod+z** Rofi logout prompt
  - **Mod+Shift+z** Quit DWM
  - **Mod+Shift+Control** Restart DWM

## Dependencies
*Unfinished List*

Currently, the dependencies include the default dwm dependencies as well as:
```
Rofi, polybar w/dwm module, alacritty, light, flameshot, playerctl, pavucontrol, font awesome, mononoki Nerd Font, Hack font, Noto Color emoji, rofimoji, rofi scripts, skippy-xd-git, sxiv, yajl, jsoncpp, trayer
```
