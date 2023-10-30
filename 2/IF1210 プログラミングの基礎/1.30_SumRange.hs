-- MENJUMLAHKAN SEMUA BILANGAN DALAM RANGE A B          sumRange a b

-- DEFINISI DAN SPESIFIKASI
sumRange :: Int -> Int -> Int
{- sumRange menjumlahkan semua bilangan integer dari a ke b
   dengan syarat a<=b serta a dan b bilangan positif -}

-- REALISASI
sumRange a b
   | a==b      = a
   | otherwise = a + sumRange (a+1) b