module Main where
import Control.Applicative

b :: (t1 -> t2) -> (t3 -> t1) -> t3 -> t2
b f1 f2 f3 = f1 (f2 f3)

b1 :: (t3 -> t4) -> (t1 -> t2 -> t3) -> t1 -> t2 -> t4
b1 f1 f2 f3 f4 =  f1 (f2 f3 f4)

c :: (t1 -> t2 -> t3) -> t2 -> t1 -> t3
c f1 f2 f3 = f1 f3 f2

d :: (t3 -> t2 -> t4) -> t3 -> (t1 -> t2) -> t1 -> t4
d f1 f2 f3 f4 = f1 f2 (f3 f4)

e :: (t4 -> t3 -> t5) -> t4 -> (t1 -> t2 -> t3) -> t1 -> t2 -> t5
e f1 f2 f3 f4 f5 = f1 f2 (f3 f4 f5)

f :: t2 -> t1 -> (t1 -> t2 -> t3) -> t3
f f1 f2 f3 = f3 f2 f1

g :: (t3 -> t2 -> t4) -> (t1 -> t2) -> t1 -> t3 -> t4
g f1 f2 f3 f4 = f1 f4 (f2 f3)

h :: (t1 -> t2 -> t1 -> t3) -> t1 -> t2 -> t3
h f1 f2 f3 = f1 f2 f3 f2

i :: t1 -> t1
i f1 = f1

j :: (t1 -> t2 -> t2) -> t1 -> t2 -> t1 -> t2
j f1 f2 f3 f4 = f1 f2 (f1 f4 f3)

k :: t1 -> t2 -> t1
k f1 f2 = f1

-- l :: t1 -> t2 -> t2
-- l f1 f2 = f1 (f2 f2)

(->') :: Int -> Int -> Int
->' a b = a + b

s :: (t1 -> t2 -> t3) -> (t1 -> t2) -> t1 -> t3
s f1 f2 f3 = f1 f3 (f2 f3)

iota :: Int -> [Int]
iota n = [2..n*2]

main :: IO ()
main = do
    print (b1 (iota) (+) (4) (5))
    putStrLn "hi"
