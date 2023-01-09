⍝ part one
input ← ⊃⎕NGET'/home/void/Scripts/apl/2022-AoC/day-2.input'1
input ← ~∘' '¨input
input ← ('(AZ)|(BX)|(CY)' ⎕R '0 &')¨input
input ← ('(AX)|(BY)|(CZ)' ⎕R '3 &')¨input
input ← ('(AY)|(BZ)|(CX)' ⎕R '6 &')¨input
input ← ('.X' ⎕R '1')¨input
input ← ('.Y' ⎕R '2')¨input
input ← ('.Z' ⎕R '3')¨input
solution ← {+/+/¨⊃¨⌽¨⎕VFI¨⍵}
solution input

⍝ part two

⍝AX means AZ
⍝AY means AX
⍝AZ means AY
⍝BX means BZ
⍝BY means BY
⍝BX means BX
⍝BZ means BZ
⍝CX means CY
⍝CY means CZ
⍝CZ means CX

input ← ⊃⎕NGET'/home/void/Scripts/apl/2022-AoC/day-2.input'1
input ← ~∘' '¨input
input ← ('.X' ⎕R '0 &')¨input
input ← ('.Y' ⎕R '3 &')¨input
input ← ('.Z' ⎕R '6 &')¨input
input ← ('(AY)|(BX)|(CZ)' ⎕R '1')¨input
input ← ('(AZ)|(BY)|(CX)' ⎕R '2')¨input
input ← ('(AX)|(BZ)|(CY)' ⎕R '3')¨input
solution ← {+/+/¨⊃¨⌽¨⎕VFI¨⍵}
solution input
