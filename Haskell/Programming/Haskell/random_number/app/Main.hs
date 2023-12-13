module Main where
import Numeric (showHex)
import Data.Time

mod255 :: Int -> Int
mod255 = flip mod 255

stoi :: String -> Int
stoi = read :: String -> Int

main :: IO ()
main = do
    -- seed is current time
    now <- getCurrentTime
    let solution = mod255 $ stoi $ formatTime defaultTimeLocale "%M%S" now

    mapM putStr ["What is 0x",  flip showHex " " solution, "in decimal?\n"]

    answer <- getLine
    if stoi answer == solution then print "CORRECT!" else main

