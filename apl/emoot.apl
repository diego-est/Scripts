#!/usr/bin/dyalogscript
EMTD ← '/storage/Pictures/emotes/'
FILS ← ↑(⎕NINFO⍠1)EMTD,'*'
DMEN ← (⊢,¨↑{((⍴⍵)⍴⊂'\n')}⊢)

name ← ⎕SH ↑,/'echo "',(,/DMEN,/↑1↑¨1↓¨1 ⎕NPARTS¨FILS),'"|dmenu -i'
path ← ↑{↑(⎕NINFO⍠1),/EMTD,⍵,'*'}name
copy ← ⎕SH ↑,/'nohup cat ',path,'|xclip -sel clip -t image/png >/dev/null'
⎕OFF
