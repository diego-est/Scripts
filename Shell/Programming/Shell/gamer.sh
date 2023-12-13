#!/usr/bin/dash

NUMBER=$(shuf -i '0-32767' -n 1)
COUNT=0
while [ $COUNT -lt "$1" ];do
    ADJECTIVE=$(shuf -n 1 adjectives.txt)
    ADJECTIVE=$(echo "$ADJECTIVE" | sed 's/.*/\u&/')

    NOUN=$(shuf -n 1 nouns.txt)
    NOUN=$(echo "$NOUN" | sed 's/.*/\u&/')

    NUMBER=$(echo "$NUMBER" | sha1sum)
    NUMBER=$(expr "$NUMBER" : '\(...\)' | sed 's/[^0-9]*//g')

    echo "$ADJECTIVE$NOUN$NUMBER"

    COUNT=$(( COUNT + 1))
    NUMBER=$(shuf -i '0-32767' -n 1)
done
