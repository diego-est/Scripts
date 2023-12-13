
element :: (Eq a) => a -> [a] -> Bool
element _ [] = False
element a (x:xs) = (x == a) || element a xs

nodup :: (Eq a) => [a] -> [a]
nodup [] = []
nodup (x:xs)
    | element x xs = nodup xs
    | otherwise = x : nodup xs

isAsc :: [Int] -> Bool
isAsc [] = True
isAsc ([x]) = True
isAsc (x:y:xs) = (x <= y) && isAsc (y:xs)

productList :: [Int] -> Int
productList [] = 1
productList (x:xs) = x * productList xs

myand :: [Bool] -> Bool
myand [] = True
myand (x:xs) = x && myand xs

concatList :: [[Int]] -> [Int]
concatList [] = []
concatList (x:xs) = x ++ concatList xs

while :: (Int -> Bool) -> [Int] -> [Int]
while pred [] = []
while pred (x:xs) = if pred x then x : while pred xs else []

iSort :: [Int] -> [Int]
iSort [] = []
iSort (x:xs) = ins x (iSort xs)

ins :: Int -> [Int] -> [Int]
ins x [] = [x]
ins x (y:ys)
    | x <= y = x:y:ys
    | otherwise = y : ins x ys

main = do
    print 4
