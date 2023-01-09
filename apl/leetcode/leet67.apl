⎕IO ← 0
a1  ← 1 1
b1  ← 1
a2  ← 1 0 1 0
b2  ← 1 0 1 1

solve ← {{((1+⌊2⍟⍵)⍴2)⊤⍵}(2⊥⍺)+2⊥⍵}

a1 solve b1
a2 solve b2
