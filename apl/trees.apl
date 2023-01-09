⎕IO ← 0

adt ← (0 (1 2) (3 (4 5) 6) (7 (8 9 10) (11 12 13) 14)) ⍝ recursive depth tree

ids ← ∊adt ⍝ ⍳15

d ← 0 1 2 1 2 3 2 1 2 3 3 2 3 3 2

⍝ Path Matrix
0                                 
  1   3       7                   
    2   4   6   8      11       14
          5       9 10    12 13   
⍝ ids with corresponding depth, next step = parents of nodes
0  0  0  0  0  0  0  0  0  0  0  0  0  0  0 
   1  1  3  3  3  3  7  7  7  7  7  7  7  7 
      2     4  4  6     8  8  8  11 11 11 14
               5           9 10     12 13   

⍝ Parent / Sibling
    0  1  2  3  4  5  6  7  8  9 10 11 12 13 14
p ← 0  0  1  0  3  4  3  0  7  8  8  7 11 11  7
l ← 0  1  2  1  4  5  4  3  8  9  9  8 12 13 14

⍝ IDIOMS

⍝ Adding a node:
⍝ ,←

⍝ Deleting a node:
⍝ (⍸M)(⊢-1+⍸)(~M)⌿P

⍝ Updating a node:
⍝ @ []←

⍝ Traversing:
⍝ I@{}⍣≡

⍝ Selection:
⍝ = ∊ ⍳ ⍸


⍝ Depth of a tree:
d⊣{z⊣+←⍵≠z←⍺[⍵]}⍣≡⍨p⊣d←p≠⍳≢p

⍝ Binding Table:
bv ← I@{1=t[⍵]}⍣≡⍨i@(p[i←⍸1=t[p]])⍳≢p
