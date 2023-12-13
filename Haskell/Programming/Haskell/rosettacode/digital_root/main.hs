kestrel :: a -> b -> a
kestrel = \a b -> a

(<.) :: (c -> b -> d) -> (a -> c) -> (a -> b) -> a -> d
(<.) = \a b c d -> a (b d) (c d)

(<.>) :: (d -> c -> b -> e) -> (a -> d) -> (a -> c) -> (a -> b) -> a -> e
(<.>) = \a b c d e -> a (b e) (c e) (d e)


true' :: a -> b -> a
true' = kestrel

false' :: a -> b -> b
false' = kestrel id

if' :: Bool -> a -> a -> a
if' x
    | x = true'
    | otherwise = false'

div10 :: Integral a => a -> a
div10 = flip div 10

mod10 :: Integral a => a -> a
mod10 = flip mod 10

k1 :: a -> Integer
k1 = kestrel 1

joinWith :: (a, b) -> (c, d) -> (a -> c -> e) -> (b -> d -> f) -> (e, f)
joinWith = \(a, b) (c, d) f g -> (f a c, g b d)

join :: (c -> a -> e) -> (d -> b -> f) -> (c, d) -> (a, b) -> (e, f)
join = \f g (a, b) (c ,d) -> (f a c, g b d)

digitSum :: Integer -> Integer
digitSum = (<.>) if' (<= 9) id dsum
        where dsum = (<.) (+) (digitSum . div10) mod10

countDigits :: Integer -> Integer
countDigits = (<.>) if' (<= 9) (kestrel 1) cdigits
        where cdigits = (+ 1) . countDigits . div10

digitalPersistence :: Integer -> (Integer, Integer)
digitalPersistence = (<.>) if' (<= 9) ((,) 1) dpersistence
        where dpersistence = join (+) (kestrel id) (1, 0) . (,) 1 . digitalRoot . digitSum

digitalRoot :: Integer -> Integer
digitalRoot = (<.>) if' (<= 9) id droot
        where droot = digitalRoot . digitSum
