#!/usr/bin/env sh
set -xe
maim -o -s  | tee /tmp/image.png | xclip -sel clip -t image/png
