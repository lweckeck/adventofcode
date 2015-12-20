module Main where

import Control.Applicative
import Data.List
import System.Environment

parseLine :: String -> (Int, Int, Int)
parseLine str =
  case words (filter (/='.') str) of
  [_, _, _, v, _, _, t, _, _, _, _, _, _, r, _] -> (read v, read t, read r)

velocities :: (Int, Int, Int) -> [Int]
velocities (v, t, r) = cycle $ (take t $ repeat v) ++ (take r $ repeat 0)

positions :: [Int] -> [Int]
positions = scanl1 (+)

scores :: [[Int]] -> [[Int]]
scores ll
  | any (==[]) ll = take (length ll) $ repeat []
  | otherwise = zipWith (:) (score heads) (scores tails)
  where heads = map head ll
        tails = map tail ll
        furthest = maximum heads
        score = map (\x -> if x >= furthest then 1 else 0)

highestScoreAfter :: Int -> [(Int, Int, Int)] -> Int
highestScoreAfter t = maximum . (map sum) . scores . (map (positions . take t . velocities))

main :: IO ()
main = do
  [distance, input] <- getArgs
  s <- readFile input
  print (highestScoreAfter (read distance::Int) (map parseLine $ lines s))
