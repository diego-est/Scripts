#!/usr/bin/env sh

set -xe

XY="$(xdotool getdisplaygeometry)"
X="$(echo "$XY" | awk '{print $1}')"
Y="$(echo "$XY" | awk '{print $2}')"
X=$((X / 2))
Y=$((Y / 2))
xdotool mousemove "$X" "$Y" && sleep 0.08s

<<EOF pmenu
Terms
	wezterm
	foot
	alacritty
	st
Apps
	firefox-nightly
	gimp
	inkscape
	obs
Power
	systemctl suspend
	systemctl poweroff
	reboot
Utilities
	screenshot.sh
	battery.nu
	date.nu
	weather.nu
EOF
