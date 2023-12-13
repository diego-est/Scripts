{-# LANGUAGE DataKinds            #-}
{-# LANGUAGE GADTs                #-}
{-# LANGUAGE PolyKinds            #-}
{-# LANGUAGE ScopedTypeVariables  #-}
{-# LANGUAGE TypeApplications     #-}
{-# LANGUAGE TypeFamilies         #-}
{-# LANGUAGE TypeOperators        #-}

import Data.Type.Equality

data Peano = Zero | Succ Peano

type family a + b where
  a + Zero   = a          -- (1)
  a + Succ b = Succ (a + b)  -- (2)

sym :: (a :~: b) -> (b :~: a)
sym h = _

equalityZero :: Zero + Zero :~: Zero
equalityZero = Refl

equality :: a + Zero :~: a
equality = Refl

onePlus :: a + Succ Zero :~: Succ a
onePlus = Refl

main = do
    putStrLn "Proof: Success!"
