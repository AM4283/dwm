#!/bin/sh
if [ "$(pidof xidlehook)" ]
then
  PID=$(pidof xidlehook)
  kill "$PID" > /dev/null
  /home/albi/.config/scripts/locker
else
  /home/albi/.config/scripts/locker
fi &

xinput set-prop "SynPS/2 Synaptics TouchPad" "libinput Tapping Enabled" 1 &
xrdb -merge ~/.Xresources &
lxpolkit &
dunst &
parcellite -n &
ntfd &
nm-applet &
picom -f &
feh --bg-fill /home/albi/Pictures/backgrounds/wp5504447.jpg &
#/home/albi/.config/scripts/locker &
/home/albi/.config/polybar/launch.sh
