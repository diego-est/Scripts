#!/usr/bin/env sh

set -xe

cd "$HOME/.local/bin" && ln -sf "$OLDPWD/$1"
