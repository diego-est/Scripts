import Combinators

-- types
data Pixel = Pixel Int Int Int | PixelAlpha Int Int Int Int deriving (Show)

data Canvas = Canvas Int Int [Pixel] deriving (Show)


-- Functions
fist (a, _, _) = a

send (_, a, _) = a

thid (_, _, a) = a

toPixel = dunlin Pixel fist send thid

makeList n = [1..n]

pixGen = dove warbler zip3 makeList

bufGen = dove map toPixel pixGen

makeCanvas = weebill Canvas bufGen

main = do
    putStrLn "HAIII"
