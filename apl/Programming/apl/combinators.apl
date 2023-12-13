⍝ I-combinator
    ⊢ Y         ⍝ Y
⍝ K-combinator
    K ⊢ Y       ⍝ Y
⍝ I-combinator
    ⊣ Y         ⍝ Y
⍝ KI-combinator
    X ⊣ Y       ⍝ X
⍝ C-combinator
    X f⍨ Y      ⍝ Y f X
⍝ K-combinator
    Y ⍨ X       ⍝ Y
⍝ W-combinator
    f⍨ Y        ⍝ Y f Y
⍝ D-combinator
    X f∘g Y     ⍝ (X f (g Y))
    (X g h) Y
⍝ Ψ-combinator
    X f⍥g Y     ⍝ (g X) f (g Y)
⍝ B1-combinator
    X f⍤g Y     ⍝ f (X g Y)
    X (f g) Y
⍝ B-combinator
    f∘g Y       ⍝ f (g Y)
    (f g)Y
⍝ S-combinator
    f∘g⍨ Y      ⍝ (Y f (g Y))
⍝ (rvrs) S-combinator
    f⍨∘g⍨ Y     ⍝ ((g Y) f Y)
⍝ D2-combinator
    X g⍨∘f⍨∘h Y ⍝ (f X) g (h Y)
⍝ Q-combinator
    X g⍨∘f⍨ Y   ⍝ ((f X) g Y)
⍝ E-combinator
    X (Z g h) Y ⍝ Z g (X h Y)
⍝ ϕ1-combinator
    X (f g h) Y ⍝ (X f Y)g(X h Y)
⍝ ϕ-combinator
    (f g h) y   ⍝ (f Y)g(h Y)
