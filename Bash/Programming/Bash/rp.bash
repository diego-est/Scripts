#!/usr/bin/env bash
# gum
set -xe

LANG="$(gum choose "C" "CPP")"
TEMPLATES_DIR="$XDG_DATA_HOME"/mkpr
CURR_DIR="$(pwd)"

case $LANG in
	"CPP")
		cp "$TEMPLATES_DIR"/CPP.gitignore "$CURR_DIR"/.gitignore
		;;
	"C")
		cp "$TEMPLATES_DIR"/C.gitignore "$CURR_DIR"/.gitignore
		;;
	*)
		;;
esac

echo "# Title" > README.md
$EDITOR README.md
