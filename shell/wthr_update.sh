#!/usr/bin/sh
curl -s "wttr.in/Puerto+Rico?u&format=3" | sed -E "s/([A-z])\+/\1 /g" > ~/.cache/wthr
