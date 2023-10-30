-- JUMLAH INTEGER m - n BERDASARKAN f                   sumInteger m n f

-- DEFINISI DAN SPESIFIKASI
sumInteger :: Int -> Int -> (Int -> Bool) -> Int

-- REALISASI
sumInteger m n f =
    if m > n then 0 -- basis
    else if f m {-&& m <= n-} then m + sumInteger (m+1) n f -- rekurens
    else sumInteger (m+1) n f -- rekurens

{- APLIKASI
   > sumInteger 1 100 (\x -> mod x 100 == 0)
   > sumInteger 1 100 (\x -> (even x && mod x 10 == 0) || (odd x && mod x 5 == 0))
   > sumInteger 25 25 (\x -> x<10)
-}