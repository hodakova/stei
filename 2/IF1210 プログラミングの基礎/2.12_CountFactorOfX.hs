countFactorOfX :: Int -> [Int] -> Int
-- REALISASI
countFactorOfX n l
   | null l                             = 0
   | mod n (head l) == 0 && head l /= 0 = 1 + countFactorOfX n (tail l)
   | otherwise                          =     countFactorOfX n (tail l)