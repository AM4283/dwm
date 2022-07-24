# DWM
The <a href="https://dwm.suckless.org/" target="_blank">Suckless Dynamic Window Manager</a>.

This is my personal build. Able to use <a href="https://polybar.github.io/" target="_blank">polybar</a> as a bar. Currently used with my build of <a href="https://github.com/AM4283/dwmblocks" target="_blank">dwmblocks</a> and <a href="https://github.com/AM4283/st" target="_blank">st</a> + <a href="https://github.com/AM4283/dotfiles" target="_blank">necessary scripts</a>.

## Preview
![2022-06-22_20-27](https://user-images.githubusercontent.com/78922336/175182537-2c2d2b9f-638f-4059-a485-d1fe1a2edfa1.png)

<details><summary><h2>Patches</h2></summary>
<p>
This build includes the patches:

| Patch            | Functionality   |
|:-----------------|:----------------|
| actualfullscreen | **True fullscreen support** |
| alpha            | **Default bar transparency, transparent window border fix** |
| anybar (with polybar tray fix) | **Alternate bar support** |
| attach direction | **Different master/slave behavior support**  |
| autostart        | **Autostart script support** |
| bottomstack      | **Bottom stack and bottom stack horizontal layouts** |
| cfacts           | **Allows for resizing of windows vertically** |
| colorbar         | **More configurable default statusbar colors** |
| combo            | **Support for selecting multiple tags by holding down mod+tag** |
| centeredmaster   | **Centered master layout** |
| cyclelayouts     | **Cycle through layouts w/ bindings** |
| deck             | **Deck layout (monocole on stack)** |
| fibonacci        | **Fibonacci and dwindle layouts** |
| floatrules       | **Configurable rules for sizing floating windows on spawn** |
| focusadjacenttag | **Focuses or moves window to left/right tag** |
| focusmaster      | **Focus master keybindings** |
| focusonnetactive | **Makes DWM focus windows requested by NET_ACTIVE_WINDOW (allows skippy-xd to work)** |
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
</p>
</details>

<details><summary><h2>Keybinds</h2></summary>

<p>

### Program launchers
  - **Mod** Super Key
  - **Mod+Shift+Backspace** Spawn keybind reference pdf
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
    * **N** Launch notes rofi prompt
    * **Apostrophe** Launch rofi emoji prompt
    * **B** Launch sxiv background selection prompt
    * **T** Launch rofi theme selection prompt
    * **C** Launch calculator rofi prompt

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
  - **Mod+F1** Mute mic
  - **Mod+F2** Decease mic volume
  - **Mod+F3** Increase mic volume
  - **Mod+Home** Alternate mute mic
  - **Mod+Pgup** Alternate increase mic volume
  - **Mod+Pgdown** Alternate decrease mic volume
  - **Playpause/Previous/Next** Pause/play/skip back/skip next on current audio application
  - **Stop** Stop currently playing audio

### Quit DWM
  - **Mod+z** Rofi logout prompt
  - **Mod+Shift+z** Quit DWM
  - **Mod+Shift+Control** Restart DWM
</p>
</details>

## Dependencies

Currently, the dependencies include the default dwm dependencies as well as:
```
rofi and/or dmenu, rofi-emoji (optional), rofi-calc (optional), st and/or alacritty, polybar-dwm-module (optional), dwmblocks (optional), light, ttf-fira-code, flameshot, 
playerctl, pavucontrol, nerd-fonts-sans-regular-complete, nerd-fonts-mononoki, noto-fons-cjk, noto-fonts-emoji, skippy-xd-git, libxft-bgra, yajl, jsoncpp, trayer, zathura
```
<a href="https://github.com/dakata1337/polybar-dwm-module/" target="_blank">Up to date polybar-dwm-module</a> (the AUR package is out of date) <br>
The shutdown menu + background switcher + theme switcher + volume notification on up/down/mute keybindings do not work without custom scripts/images from my <a href="https://github.com/AM4283/dotfiles" target="_blank">dotfiles</a> repo (~/Pictures and ~/.config/scripts and ~/themes)

Most of these listed dependencies are uneeded if your usecase does not employ these programs. You can always add/remove bindings/settings for your own needs.

A compositor is needed for transparency effects! I recommend using ```picom```.

Remember to go through the config before using this build!
### Installation
Run these commands in a terminal
```
git clone https://github.com/AM4283/dwm.git
cd dwm
sudo make install
```

## Other Links
Some of my other configurations for programs including scripts needed for parts of this build of dwm can be found on my GitHub:

- <a href="https://github.com/AM4283/dotfiles" target="_blank">dotfiles/scripts</a>
- <a href="https://github.com/AM4283/dwmblocks" target="_blank">dwmblocks</a>
- <a href="https://github.com/AM4283/st" target="_blank">st</a>

Use these builds along with my dotfiles to get (almost) my exact desktop!

## Donate
If you enjoy this rice, or any of my other dots on my GitHub and are feeling extra generous, you can donate money or crypto using the addresses below:

[**Paypal**](https://www.paypal.me/bobwendy1)

[**Venmo**](https://www.venmo.com/u/Bob-Wendy-1)

**XMR**<br>
48bMjDgejjBa5JMLmUXWHfUxxc4VztE9dSxsnJ5STqDcUcjYk9xHoK59ovWgm6BvrzFfbx2kEA3QyUmgcpzYJ4dH9cLWCYV

**Bitcoin**<br>
bc1quaj9206k2ughk8ryh7yq2vqa0esxpkt048ggpx


**Ethereum**<br>
0x5f954056E04a5fc0F0E777409935823e98dC0C83

Make sure to give back to the creators of your favorite FOSS programs too!
