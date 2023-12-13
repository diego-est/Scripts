#!/usr/bin/bash
#dependencies: lemonbar, mpd, mpc

while true; do
    TIME="$(mpc status "\[%currenttime%/%totaltime%\]")"
    TITLE="$(mpc current -f "%title%")"
    ARTIST="$(mpc current -f "%artist% [(%album%) ]")"

    MESSAGE="$ARTIST- $TITLE"
    MESSAGE=${MESSAGE:0:71}
    MESSAGE="$MESSAGE%{F-}%{F#ebdbb2}...%{F-}"

    STATUS="$(mpc status "%state%")"
    echo "%{c}%{B#282828}%{F#ebdbb2}  Now $STATUS: %{F-}%{F#8ec07c}$MESSAGE%{F-}  %{F#ebdbb2}$TIME%{F-}  %{B-}"

    sleep 1
done
