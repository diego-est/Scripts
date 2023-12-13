#!/usr/bin/env nu

let weather = (curl https://wttr.in/Puerto+Rico?format=j1 | from json)

let feels_like = $weather.current_condition | format "Feels like: {FeelsLikeF}"
| to text

dunstify $feels_like
