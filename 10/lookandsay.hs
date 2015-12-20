{-# LANGUAGE TemplateHaskell #-}

lookandsay :: String -> String
lookandsay (a:as) =
  let help i c s
        | s == ""   = show i ++ [c]
        | otherwise = if c == head s
                      then help (i+1) c $ tail s
                      else (show i ++ [c]) ++ (help 1 (head s) (tail s))
  in help 1 a as

iterate_lookandsay :: Int -> String -> String
iterate_lookandsay i x
  | i < 1 = x
  | otherwise = iterate_lookandsay (i-1) $ lookandsay x
