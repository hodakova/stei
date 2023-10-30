-- FUNGSI NILAI TENGAH									nilaiTengah a b c

-- DEFINISI DAN SPESIFIKASI
nilaiTengah :: Int -> Int -> Int -> Int
{- nilaiTengah(a,b,c) menentukan nilai tengah di antara 3 integer yang
   berlainan nilainya (a!=b, a!=c, dan b!=c) dengan fungsi min3 dan max3
   sebagai funsi antara.
 Nilai tengah didapatkan dengan menjumlahkan
   ketiga angka yang diberikan lalu menguranginya dengan nilai minimum
   dan maksimum dari ketiga angka tersebut.  -}
min3 :: Int -> Int -> Int -> Int
{- min3(a,b,c) menentukan nilai minimum dari 3 integer yang berlainan
   nilainya (a!=b, a!=c, dan b!=c). -}
max3 :: Int -> Int -> Int -> Int
{- min3(a,b,c) menentukan nilai maksimum dari 3 integer yang berlainan
   nilainya (a!=b, a!=c, dan b!=c). -}

-- REALISASI
nilaiTengah a b c = a+b+c - min3 a b c - max3 a b c
min3 a b c
    | (a<b) && (a<c) = a
    | (b<a) && (b<c) = b
    | (c<a) && (c<b) = c
max3 a b c
    | (a>b) && (a>c) = a
    | (b>a) && (b>c) = b
    | (c>a) && (c>b) = c

-- APLIKASI
-- nilaiTengah 1 2 3
-- nilaiTengah (-6) 1 5
-- nilaiTengah (-1) (-4) 10