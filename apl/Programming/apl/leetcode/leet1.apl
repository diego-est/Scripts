⎕IO←0
nums1   ← 2 7 11 15
target1 ← 9
nums2   ← 3 2 4
target2 ← 6
nums3   ← 3 3
target3 ← 6

solve ← {1↑⍸⍺=((,∘.+⊢)⍵)×~(,∘.=⊢)⍳⍴⍵}
target1 solve nums1
target2 solve nums2
target3 solve nums3
