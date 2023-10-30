-- FUNGSI KONVERTER KOIN DOLAR					totCoinDollar q d n p

-- DEFINISI DAN SPESIFIKASI
totCoinDollar :: Int -> Int -> Int -> Int -> (Int, Int)
{- totCoinDollar mengubah bentuk dolar dari satuan satuan koin
   (quarter dime nickel penny) menjadi (dolar, sen) dengan fungsi tot
   sebagai fungsi antara -}
tot :: Int -> Int -> Int -> Int -> Int
{- tot mengubah bentuk dolar dari satuan koin (quarter dime nickel penny)
   menjadi sen -}

-- REALISASI
totCoinDollar q d n p = (tot q d n p `div` 100,
    tot q d n p `mod` 100)
tot quarter dime nickel penny = quarter*25 + dime*10 + nickel*5 + penny

-- APLIKASI
-- totCoinDollar 8 20 30 77