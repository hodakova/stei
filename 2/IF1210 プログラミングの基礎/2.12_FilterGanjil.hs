-- FILTER GANJIL                                         filterGanjil li

-- DEFINISI DAN SPESIFIKASI
filterGanjil :: [Int] -> [Int]
{- filterGanjil(li) menerima sebuah list li (dengan li terdiri dari
   bilangan integer positif, 0, atau kosong) dan memfilternya sehingga
   hanya terdiri atas bilangan ganjil pada li -}

-- REALISASI
filterGanjil li
   | null li       = []
   | odd (head li) = [head li] ++ filterGanjil (tail li)
   | otherwise     = filterGanjil (tail li)