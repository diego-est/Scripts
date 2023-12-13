#!/usr/bin/env bash
stat -c '%y' norton_anthology.pdf | sed 's/ .*//;s/-//g'
