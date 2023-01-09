#!/usr/bin/env bash
#Script to generate a bingo card
COUNT="1"
FILL="#6e7d84"

help_text(){ while IFS= read -r line;do
    printf "%s\n" "$line"
done <<-EOF
    Usage: bingo.sh [OPTION]... ENTRIES.txt TEMPLATE OUTPUT-NAME
    Makes a bingo card using random entries from a text file, using the given template.
    -h, --help                  show this help text
    -c, --count NUMBER          The number of random bingo cards to be created
    --color HEX                 [DEFAULT] #6e7d84, blue-gray
EOF
}

while [ "$1" != "" ];do case $1 in
    -h |--help)help_text;exit 0;;
    -c |--count)shift;COUNT="$1";shift;;
    *.txt)ENTRY_FILE="$1";shift;;
    --color)shift;FILL=$1;shift;;
    *)break;;
esac
done

IN="$1" shift
TMPIN="$IN"
OUT="$1" shift
coordinates=(-448-408 -224-408 +0-408 +224-408 +448-408 -448-184 -224-184 +0-184 +224-184 +448-184 -448+40 -224+40 +224+40 +448+40 -448+264 -224+264 +0+264 +224+264 +448+264 -448+488 -224+488 +0+488 +224+488 +448+488)
IFS=$'\n' read -rd '' -a indexes < <( seq 0 23 && printf '\0' )

entry_shuffle () {
IFS=$'\n' read -rd '' -a ENTRY_LIST < <( shuf "$ENTRY_FILE" -n 24 && printf '\0' )
}

while [ "$COUNT" -ge 1 ];do entry_shuffle;for i in "${indexes[@]}";do
        magick -fill "$FILL" -gravity center -size 186x186 caption:"${ENTRY_LIST[$i]}" entry.png
        convert "$IN" entry.png -geometry "${coordinates[$i]}" -gravity center -composite "$OUT"
        IN="$OUT"
    done
    IN="$TMPIN"
    mv "$OUT" "${OUT//\./$COUNT.}"
    COUNT=$(( COUNT-1 ))
done
