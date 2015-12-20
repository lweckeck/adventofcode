{-# LANGUAGE TemplateHaskell #-}
import System.Environment

countcode :: String -> Int
countcode [] = 0
countcode ('\n':xs) = countcode xs
countcode (_:xs) = 1 + countcode xs

countmem :: String -> Int
countmem [] = 0
countmem ('\n':xs) = countmem xs
countmem ('"':xs) = countmem xs
countmem ('\\':xs) = case xs of
  ('x':_) -> 1 + (countmem $ iterate tail xs !! 3)
  _ -> 1 + (countmem $ tail xs)
countmem (x:xs) = 1 + countmem xs

diff :: String -> Int
diff x = (countcode x) - (countmem x)

countinlines :: [String] -> Int
countinlines l = (foldl (+) 0 (map countcode l))
                 -
                 (foldl (+) 0 (map countmem l))

out :: String -> String
out = (++ "\n") . show . countinlines . lines

main :: IO ()
main = do
  interact out
--  [filename] <- getArgs
--  s <- readFile filename
--  putStrLn s
--  putStrLn $ show $ countinlines $ lines s
