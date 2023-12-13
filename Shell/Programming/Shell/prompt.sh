#!/usr/bin/sh
#dependencies: sha1sum

STRING=$(date +%s | sha1sum)
STRING=$(expr "$STRING" : '\(..\)'|tr '[:lower:]' '[:upper:]')
SOLUTION=$(echo "ibase=16; $STRING" | bc)

echo "What is 0x$STRING in decimal?"
while true; do
    read -r INPUT
    case $INPUT in
        "$SOLUTION")
            exit
            ;;
        *)
            echo "Wrong answer, try again."
            ;;
    esac
done
