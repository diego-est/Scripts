#!/usr/bin/env sh
set -xe
cat /dev/random | head -n 2 | highlight -O ansi --syntax haskell
