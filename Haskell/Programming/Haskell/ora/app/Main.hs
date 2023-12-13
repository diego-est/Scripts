module Main where
import Data.Function
import Network.HTTP.Request

--parse = filter (not . eq '+')

parse :: [Char] -> [Char]
parse = let
            repl ' ' = "%20"
            repl x = [x]
        in concat . map repl

search = do
    str <- getLine
    let link = "https://aur.archlinux.org/rpc/?v=5&type=search&arg=" ++ parse str
    resp <- get link


main :: IO ()
main = do
  putStrLn "Hello, Haskell!"
