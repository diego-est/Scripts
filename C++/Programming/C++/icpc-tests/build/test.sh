#!/usr/bin/env sh
set -xe

hyperfine --min-runs 50 --warmup 10 --prepare 'sync;sync;sync' './num_fastscan_printf.out < ../numbers.txt' './num_naive.out < ../numbers.txt'
