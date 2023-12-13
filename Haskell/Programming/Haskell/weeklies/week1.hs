import Data.Bits

true :: a -> b -> a
true a b = a

false :: a -> b -> b
false a b = b

if' :: Bool -> a -> a -> a
if' a
    | a = true
    | otherwise = false

suma a b c = if' (a + b == c || a + c == b || b + c == a) "YES" "NO"

populationCount :: (Bits a) => a -> Int
populationCount = popCount

checksum = undefined
