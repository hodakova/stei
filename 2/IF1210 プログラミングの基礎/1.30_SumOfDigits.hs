-- MENJUMLAHKAN SEMUA DIGIT DALAM SUATU INTEGER        sumOfDigits n

-- DEFINISI DAN SPESIFIKASI
sumOfDigits :: Int -> Int
{- sumOfDigits(n) menjumlahkan setiap digit tunggal dari suatu
   bilangan integer -}

-- REALISASI
sumOfDigits n
   | n<0        = sumOfDigits (-n)
   | n<10       = n
   | otherwise  = sumOfDigits (div n 10) + mod n 10