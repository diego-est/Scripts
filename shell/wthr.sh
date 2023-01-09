#!/usr/bin/sh

while true; do
    WTHR=$(curl -s "wttr.in/Puerto+Rico?u&format=3" | sed -E "s/([A-z])\+/\1 /g")
    echo "%{c}%{F#ebdbb2}%{B#282828}  $WTHR  %{F-}%{B-}"
    sleep 6h
done
