-- FILTER LIST                                            filterList f l

-- DEFINISI DAN SPESIFIKASI
filterList :: (Int -> Bool) -> [Int] -> [Int]
{- filterList(f,l) menerima fungsi filter f dan list integer l serta
　　mengeluarkan hasil filter dari list l berdasarkan fungsi
　　filternya -}
isPos :: Int -> Bool
{- isPos(x) menerima integer x dan mengeluarkan True jika x positif,
   digunakan untuk memfilter setiap element dari suatu list integer -}
isNeg :: Int -> Bool
{- isNeg(x) menerima integer x dan mengeluarkan True jika x negatif
   digunakan untuk memfilter setiap element dari suatu list integer -}
isKabisat :: Int -> Bool
{- isKabisat(y) menerima integer y (positif y sebagai tahun Masehi,
   dan negatif y sebagai tahun sebelum Masehi) dan mengeluarkan True
   jika y merupakan angka tahun kabisat, digunakan untuk memfilter
   setiap element dari suatu list integer -}

-- REALISASI
filterList f l =
    if isEmpty l then [] -- basis
    else if f (head l) == True then konso (head l) (filterList f (tail l)) -- rekurens
    else filterList f (tail l) -- rekurens
isPos x = x>0
isNeg x = x<0
isKabisat y =
    if isPos y then -- basis
        if mod y 4 == 0 then
            if mod y 100 == 0 then
                if mod y 400 == 0 then True
                else False
            else True
        else False
    else if isNeg y then
        if y == -1 then True
        else isKabisat (-y-1) -- rekurens
    else False -- tidak ada tahun 0

{- APLIKASI
   > filterList isPos [(-5),1,3,(-91),6,8,4,(-456),2077,8217,(-234),443]
   > filterList isNeg [(-7),37,0,(-88),(-666),444,(-34),(-19),45,(-999)]
   > filterList isKabisat [(-401),(-4),(-1),4,32,100,300,1900,2000,2023]
   > filterList (\x -> mod x 5 == 0) [(-10),(-17),0,3,5,20,1000,666,505] -- menggunakan ekspresi lambda
-}


isEmpty :: [a] -> Bool
isEmpty l = null l
konso :: a -> [a] -> [a]
konso e l = [e] ++ l