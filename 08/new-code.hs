{-# LANGUAGE TemplateHaskell #-}
import System.Environment

countcode :: String -> Int
countcode [] = 0
countcode ('\n':xs) = countcode xs
countcode (_:xs) = 1 + countcode xs

countinc :: String -> Int
countinc "" = 2
countinc ('"':xs) = 1 + countinc xs
countinc ('\\':xs) = 1 + countinc xs
countinc (_:xs) = countinc xs

out :: String -> String
out = (++ "\n") . show . (foldl (+) 0) . (map countinc) . lines

main :: IO ()
main = do
  interact out
--  [filename] <- getArgs
--  s <- readFile filename
--  putStrLn s
--  putStrLn $ show $ countinlines $ lines s
