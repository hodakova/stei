-- MENGHITUNG LUAS BUJUR SANGKAR                            luasBS s

-- DEFINISI DAN SPESIFIKASI
luasBS :: Int -> Int
{- luasBS menghitung luas suatu bujur sangkar dengan panjang sisi
   tertentu -}

-- REALISASI
luasBS s
    | s==0      = 0
    | otherwise = luasBS (s-1) + s + s-1