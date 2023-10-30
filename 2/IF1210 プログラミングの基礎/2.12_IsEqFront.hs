-- IS EQUAL FRONT                                        isEqFront t1 t2

-- DEFINISI DAN SPESIFIKASI
isEqFront :: [Char] -> [Char] -> Bool
{- isEqFront(t1,t2) menerima dua buah list t1 t2 (list dari character,
   tidak kosong, dan panjang t2 >= t1) dan menghasilkan True jika
   potongan awal t2 mengandung t1 (element ke-1 s.d. ke-<panjang t1>
   dari list t2 sama dengan list t1) -}

-- REALISASI
isEqFront t1 t2
   | t1 == t2              = True
   | length t1 > length t2 = False
   | otherwise             = isEqFront t1 (init t2)