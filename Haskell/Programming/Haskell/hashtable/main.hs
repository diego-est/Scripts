import System.IO
import Data.List

data FreqKV = FreqKV String Int

data FreqKVs = FreqKVs [FreqKV]

cmpKV :: String -> FreqKV -> Bool
cmpKV str freq = x == str
    where (freqKV x _) = freq

findKey :: String -> FreqKVs -> Maybe Int
findKey str freqs = freqs

main :: IO ()
main = do
    fileHandle <- openFile "shakespeare.txt" ReadMode
    contents <- hGetContents fileHandle
    print $ length $ words contents
    hClose fileHandle
