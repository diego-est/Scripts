⎕IO←0
input   ← 0 0 1 1 0 0 0 1 1 1 0 0 0 1 0 1
block1  ← 11↑input
⍝splits input into 11-bit wide blocks

block   ← {4 4 ⍴ 0 0 0,(⊃⍵),0,(1↓4↑⍵),0,4↓⍵}
parity  ← {1↑¨(4|(3-⍵))↓¨4 4 ⍴(2 2 2 2⊤⊢)¨⍳16}
party   ← {2|+/,(parity ⍺)×block ⍵}
⍝computes parity for a given cell ⍺ (out of its corresponding block)

insert  ← {((⊃⍵)↑1↓⍵),⍺,(1+⊃⍵)↓1↓⍵}
⍝inserts a number ⍺ at index (⍵'s first element must be the index)

section ← {(⍺ party block1)insert((2*(1-⍨⍺)),⍵)}
⍝outputs an entire hamming code table

line    ← {0 0 0,(⊃⍵),0,(1↓4↑⍵),0,4↓⍵}
⍝outputs a 16-bit line instead of a 4×4 matrix

4 4 ⍴(4 section(3 section(2 section(1 section line block1))))
