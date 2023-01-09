#!/usr/bin/sh
#lemonbar clock formatter

while true; do
    echo "%{c}%{B#282828}%{F#ebdbb2}   $(date +"%a %d %H:%M")   %{F-}%{B-}"
    sleep 1m
done
