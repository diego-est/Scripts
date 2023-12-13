#!/usr/bin/env bash
set -e

. $XDG_DATA_HOME/mkpr/templates.bash

STYLE="$(gum choose "C" "C++")"
NAME="$(gum input --placeholder "Project name:")"

[ -d "$PWD/$NAME" ] && echo "Error: The directory $NAME/ already exists. Couldn't initialize project directory." && exit 1
mkdir "$NAME"
cd "$NAME"

function mkc {
	mkdir build src
	cp "$CMAKEFILE"  Makefile
	cp "$CMAIN" src/main.c
	cp "$CLANGF" .clang-format
}

function mkcpp {
	mkdir build src
	cp "$CPPMAKEFILE" Makefile
	cp "$CPPMAIN" src/main.cpp
	cp "$CLANGF" .clang-format
}

case $STYLE in
	C)
		mkc
		;;
	C++)
		mkcpp
		;;
	*)
		;;
esac


