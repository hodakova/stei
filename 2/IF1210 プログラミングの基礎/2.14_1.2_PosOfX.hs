posOfX :: Char -> [Char] -> Int
{-
posOfX e lc = length lc +
   (
   if isEmpty lc then 0
   else if e /= last lc then (-1) - length (init lc) + posOfX e (init lc)
   else 0
   )
-}
posOfX e lc =
   if isEmpty lc then 0
   else if e == last lc then length lc
   else posOfX e (init lc)

isEmpty :: [a] -> Bool
isEmpty l = null l