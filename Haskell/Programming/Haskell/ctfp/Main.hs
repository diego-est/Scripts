import Prelude hiding (Monoid, mappend, mempty)
import Data.Char

true = const
false = const id
if' x
    | x == True = true
    | otherwise = false

class Monoid m where
    mempty :: m
    mappend :: m -> m -> m

instance Monoid Bool where
    mempty = True
    mappend = (&&)

type Optional a = (a, Bool)

optId :: a -> Optional a
optId a = (a, mempty)

(>=>) :: (a -> Optional b) -> (b -> Optional c) -> (a -> Optional c)
m1 >=> m2 = \x ->
    let (y, b1) = m1 x
        (z, b2) = m2 y
    in (z, mappend b1 b2)

safeRoot x = if' (x < 0) (x, not mempty) (sqrt x, mempty)

safeReciprocal x =  if' (x == 0) (x, not mempty) (1.0 / x, mempty)

safeRootReciprocal = safeReciprocal >=> safeRoot

main = do
    print $ safeRootReciprocal 0
