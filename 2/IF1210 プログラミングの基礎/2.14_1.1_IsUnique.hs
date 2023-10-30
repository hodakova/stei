isUnique :: [Char] -> Bool
isin :: Char -> [Char] -> Bool

isUnique lc =
   if null lc then True
   else if isin (head lc) (tail lc) then False
   else isUnique (tail lc)

isin x l =
   if null l then False
   else if x == head l then True
   else isin x (tail l)