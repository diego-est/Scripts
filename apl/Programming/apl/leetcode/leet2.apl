l1 ← 2 4 3
l2 ← 5 6 4
l3 ← 0
l4 ← 0
l5 ← 9 9 9 9 9 9 9
l6 ← 9 9 9 9

solve ← {⍎¨,¨⌽⍕(10⊥⌽⍺)+(10⊥⌽⍵)}
l1 solve l2
l3 solve l4
l5 solve l6
