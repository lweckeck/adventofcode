module Main where

import Control.Applicative
import Data.List
import System.Environment

parseLine :: String -> (Int, Int, Int)
parseLine str =
  case words (filter (/='.') str) of
  [_, _, _, v, _, _, t, _, _, _, _, _, _, r, _] -> (read v, read t, read r)

distanceAfter :: Int -> (Int, Int, Int) -> Int
distanceAfter steps (v, t, r)
  | steps <= 0 = 0
  | steps >= t = v * t + distanceAfter (steps - t - r) (v, t, r)
  | otherwise = v * steps

furthestDistance :: Int -> [String] -> Int
furthestDistance steps = maximum . map (distanceAfter steps) . map parseLine

main :: IO ()
main = do
  [distance, input] <- getArgs
  s <- readFile input
  print (furthestDistance (read distance::Int) (lines s))
