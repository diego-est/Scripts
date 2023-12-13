#!/usr/bin/sh

unset I3SOCK

echo "%{c}%{B#282828}     %{B-}" | \
    lemonbar -pdg "50x50+10+10" -f "monospace"-12 &
echo "%{c}%{B#282828}     %{B-}" | \
    lemonbar -pdg "50x50+70+10" -f "monospace"-12 &
echo "%{c}%{B#282828}     %{B-}" | \
    lemonbar -pdg "50x50+130+10" -f "monospace"-12 &
echo "%{c}%{B#282828}     %{B-}" | \
    lemonbar -pdg "50x50+190+10" -f "monospace"-12 &
echo "%{c}%{B#282828}     %{B-}" | \
    lemonbar -pdg "50x50+250+10" -f "monospace"-12 &
echo "%{c}%{B#282828}     %{B-}" | \
    lemonbar -pdg "50x50+310+10" -f "monospace"-12 &
echo "%{c}%{B#282828}     %{B-}" | \
    lemonbar -pdg "50x50+370+10" -f "monospace"-12 &
echo "%{c}%{B#282828}     %{B-}" | \
    lemonbar -pdg "50x50+430+10" -f "monospace"-12 &
echo "%{c}%{B#282828}     %{B-}" | \
    lemonbar -pdg "50x50+490+10" -f "monospace"-12 &
echo "%{c}%{B#282828}     %{B-}" | \
    lemonbar -pdg "50x50+550+10" -f "monospace"-12 &

sleep 1

echo "%{c}%{F#ebdbb2}%{A:i3-msg workspace number 1:}I%{A}%{F-}"     | \
    lemonbar -pdg "50x50+10+10" -f "monospace"-12 &
echo "%{c}%{F#ebdbb2}%{A:i3-msg workspace number 2:}II%{A}%{F-}"    | \
    lemonbar -pdg "50x50+70+10" -f "monospace"-12 &
echo "%{c}%{F#ebdbb2}%{A:i3-msg workspace number 3:}III%{A}%{F-}"   | \
    lemonbar -pdg "50x50+130+10" -f "monospace"-12 &
echo "%{c}%{F#ebdbb2}%{A:i3-msg workspace number 4:}IV%{A}%{F-}"    | \
    lemonbar -pdg "50x50+190+10" -f "monospace"-12 &
echo "%{c}%{F#ebdbb2}%{A:i3-msg workspace number 5:}V%{A}%{F-}"     | \
    lemonbar -pdg "50x50+250+10" -f "monospace"-12 &
echo "%{c}%{F#ebdbb2}%{A:i3-msg workspace number 6:}VI%{A}%{F-}"    | \
    lemonbar -pdg "50x50+310+10" -f "monospace"-12 &
echo "%{c}%{F#ebdbb2}%{A:i3-msg workspace number 7:}VII%{A}%{F-}"   | \
    lemonbar -pdg "50x50+370+10" -f "monospace"-12 &
echo "%{c}%{F#ebdbb2}%{A:i3-msg workspace number 8:}IIX%{A}%{F-}"   | \
    lemonbar -pdg "50x50+430+10" -f "monospace"-12 &
echo "%{c}%{F#ebdbb2}%{A:i3-msg workspace number 9:}IX%{A}%{F-}"    | \
    lemonbar -pdg "50x50+490+10" -f "monospace"-12 &
echo "%{c}%{F#ebdbb2}%{A:i3-msg workspace number 10:}X%{A}%{F-}"    | \
    lemonbar -pdg "50x50+550+10" -f "monospace"-12 &
