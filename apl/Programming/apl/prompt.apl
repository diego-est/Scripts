#!/usr/bin/dyalogscript
⎕IO     ← 0
hexmap  ← (⍳10),6↑⎕A
test    ← 2?15
⎕ ← prompt  ← ''' in decimal?',⍨'What is ''0x',⊃¨⍕¨(hexmap⌷⍨⊢)¨test
solution← ((1⊃⊢)+16×⊃)test
input   ← ⎕
answers ← {⍵=solution:⎕OFF⋄⍵≠solution:∇ input←⎕}
answers input
