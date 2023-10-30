delNthElmt :: Int -> [Char] -> [Char]
-- REALISASI
delNthElmt n l
   | n == 1    = tail l
   | otherwise = [head l] ++ (delNthElmt (n-1) (tail l))