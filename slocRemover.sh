#!/usr/bin/sh

for f in $(find -type l); do
    if [ -L "$f" ]; then
        temp=$(readlink "$f")
        rm -rf "$f"
        cp -rf "$temp" "$f"
    fi
done
