#!/usr/bin/env nu

let amount = (checkupdates | wc -l)

dunstify ("You have " + $amount + " updates available.")
