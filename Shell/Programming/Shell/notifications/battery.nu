#!/usr/bin/env nu

let percentage = (upower -i (upower -e | rg BAT) | rg percentage | parse --regex '(?P<num>\w+)%')

let f1 = ($percentage | format 'int:value:{num}' | to text)
let body = ($percentage | format 'Percentage: {num}' | to text)

dunstify -h $f1 $body
