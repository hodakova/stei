-- PENJUMLAHAN SELURUH ELEMENT SEBUAH LIST                  sumIsiList l

-- DEFINISI DAN SPESIFIKASI
sumIsiList :: [Int] -> Int
{- sumIsiList(l) menerima sebuah list dari integer (yang tidak kosong)
   dan mengembalikan hasil penjumlahan dari seluruh elementnya -}

-- REALISASI
sumIsiList l
   | length l == 1 = head l
   | otherwise     = head l + sumIsiList (tail l)