{-# LANGUAGE TemplateHaskell #-}

import Data.Char
import Data.Set

hasIncreasing :: String -> Bool
hasIncreasing "" = False
hasIncreasing (x:y:z:xs) = (ord x) == (ord y + 1) && (ord y) == (ord z + 1) || hasIncreasing (y:z:xs)
hasIncreasing (_:xs) = hasIncreasing xs

npairs :: [Char] -> String -> Int
npairs cs (x:y:xs) = if x == y && notElem x cs
                     then 1 + (npairs (x:cs) xs)
                     else npairs cs (y:xs)
npairs _ _ = 0

noForbidden :: String -> Bool
noForbidden w = (notElem 'i' w) && (notElem 'o' w) && (notElem 'l' w)

validPassword :: String -> Bool
validPassword w = noForbidden w && hasIncreasing w && npairs "" w > 1

incString :: String -> String
incString "" = ""
incString (x:xs)
  | x == 'z' = 'a' : incString xs
  | otherwise = chr (ord x + 1) : xs

nextPassword :: String -> String
nextPassword = reverse . next . incString . reverse . take 8
  where next w = if validPassword w then w else next . incString $ w

main :: IO ()
main = do interact nextPassword
