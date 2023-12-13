#!/usr/bin/dyalogscript
solution ← ⍪(⍸((⊢<{+/¯1↓⍸(⌊=⊢)(⊢÷⍳)⍵}¨)⍳))
⎕ ← solution 200
