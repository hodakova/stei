-- MEMERIKSA SUATU INTEGER ADALAH GANJIL ATAU BUKAN       isGanjil n

-- DEFINISI DAN SPESIFIKASI
isGanjil :: Int -> Bool
{- isGanjil(n) memeriksa apakah suatu bilangan integer >= 0 adalah 
   bilangan ganjil atau bukan -}

-- REALISASI
isGanjil n
   | n==0       = False
   | n==1       = True
   | otherwise  = isGanjil (n-2)