import Data.List

s = \a b c d -> a (b d) (c d)
t = "xyzeightwothree"

splitAll [] = []
splitAll (x:xs) = [x] : splitAll xs

prefixes = scanl1 (++) . splitAll
suffixes = scanr1 (++) . splitAll

number "one" = 1
number "two" = 2
number "three" = 3
number "four" = 4
number "five" = 5
number "six" = 6
number "seven" = 7
number "eight" = 8
number "nine" = 9
number _ = 0

getFirstNum = sum . map number . prefixes

-- dotProduct :: [a] -> [a] -> [[a]]
dotProduct first second = map (zip second) first

main = do
    print $ foldl' (\e a -> (mod e 10) * a) 1 [1..10^7]
    -- print $ foldr (\e a -> (mod e 10) * a) 1 [1..10^7]
    -- print $ foldr (\e a -> if mod e 10 == 0 then 0 else (mod e 10) * a) 1 [1..]
