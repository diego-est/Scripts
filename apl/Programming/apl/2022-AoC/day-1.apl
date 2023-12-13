resp ← ⍎⍕⊃⎕NGET'/home/void/Scripts/apl/2022-AoC/day-1.input'
solution1 ← {1↑(⊂∘⍒⌷⊢)+/¨⍵}
solution1 ← {+/3↑(⊂∘⍒⌷⊢)+/¨⍵}
