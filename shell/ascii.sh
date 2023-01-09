#!/usr/bin/bash
#dependencies: lolcat

ASCIIDIR="$HOME/Documents/ascii/"
FILE=$(find "$ASCIIDIR" -type f | shuf | head -n1)

/usr/bin/lolcat -b "$FILE"
