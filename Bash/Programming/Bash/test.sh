#!/usr/bin/env sh


case $1 in
	true)
		GHCUP_USE_XDG_DIRS=true
		shift
		;;
	*)
		unset GHCUP_USE_XDG_DIRS
		shift
		;;
esac

if [ -n "${GHCUP_USE_XDG_DIRS}" ] ; then
	GHCUP_DIR=${XDG_DATA_HOME:=$HOME/.local/share}/ghcup
	GHCUP_BIN=${XDG_BIN_HOME:=$HOME/.local/bin}
fi

echo "$GHCUP_DIR"
