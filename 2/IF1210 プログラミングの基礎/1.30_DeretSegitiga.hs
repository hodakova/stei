-- DERET SEGITIGA                                    deretSegitiga n

-- DEFINISI DAN SPESIFIKASI
deretSegitiga :: Int -> Int
{- deretSegitiga mencari nilai bilangan nilai ke-n dari deret segitiga -}

-- REALISASI
deretSegitiga n
    | n==1      = 1
    | otherwise = deretSegitiga (n-1) + n