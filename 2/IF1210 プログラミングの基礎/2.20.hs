ubahArah :: Int -> Int -> Int

-- REALISASI
ubahArah s r = mod (s+r) 360

{- APLIKASI
   > ubahArah 45 (-95)
   > 310
   > ubahArah 120 270
   > 30
-}


-- a PANGKAT b                                               pangkat a b

-- DEFINISI DAN SPESIFIKASI
pangkat :: Int -> Int -> Int
{- pangkat(a,b) menerima 2 buah integer a dan b dan mengeluarkan a^b
   dengan a>0 dan b>=0
 -}

-- REALISASI
pangkat a b
   | b == 0 = 1 -- basis
   | otherwise = a * pangkat a (b-1) 

{- APLIKASI
   > pangkat 3 2
   9
   > pangkat 8 7
   2097152
-}

-- DEFINISI DAN SPESIFIKASI
offsetList :: (Float -> Float) -> (Float -> Float) -> Float -> Float -> [Float]
{- offsetList(f,g,a,b) menerima masukan dua buah fungsi, misalnya f dan g, serta dua buah bilangan riil (float), a dan b.
   Fungsi offsetList akan menghasilkan sebuah list of float yang merupakan penerapan fungsi f terhadap bilangan float antara a dan b, dimulai dari a dengan increment menggunakan fungsi g. -}

-- REALISASI
offsetList f g a b
    | a>b = []
    | otherwise = konso (f a) (offsetList f g (g a) b)

{- APLIKASI
   > offsetlist (\x -> x) (\x -> x+2) (1.2) (7.1)
   > [1.2,3.2,5.2]
   > offsetlist (\x -> if x < 0 then (-999) else x +(3.2)) (\x -> x + (0.5)) (-1.0) (1.0)
   > [-999.0,-999.0,3.2,3.7,4.2]
-}

konso :: a -> [a] -> [a]
konso e l = [e] ++ l