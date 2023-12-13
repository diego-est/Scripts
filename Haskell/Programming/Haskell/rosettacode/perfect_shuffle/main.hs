import Data.List

true :: a -> b -> a
true = \a b -> a

false :: a -> b -> b
false = \a b -> b

if' :: Bool -> (a -> a -> a)
if' x
    | x == True = true
    | otherwise = false

b4 = \a b c -> a (b c) c

iota :: Int -> [Int]
iota n = [1..n]

half :: [a] -> Int
half = flip div 2 . length

join :: (a, a) -> [a]
join p = [fst p, snd p]

perfectShuffle :: [a] -> [a]
perfectShuffle = foldl1 (++) . transpose . join . b4 splitAt half

checkNum :: Int -> Int
checkNum = b4 (checkIter 1) perfectShuffle . iota
    where checkIter c s o = if' (s == o) c (checkIter (c + 1) (perfectShuffle s) o)

main = do
    print $ checkNum 8
    print 8
    print $ checkNum 24
    print 24
    print $ checkNum 52
    print 52
    print $ checkNum 100
    print 100
    print $ checkNum 1020
    print 1020
    print $ checkNum 1024
    print 1024
    print $ checkNum 10000
    print 10000
