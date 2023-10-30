p1 :: Float -> Float
p1 x = x + 1

p2 :: Float -> Float
p2 x = x + 2

konso :: Float -> [Float] -> [Float]
konso e l = [e] ++ l

makelist :: Float -> Float -> [Float]
makelist a b
    | a > b = []
    | otherwise = konso a (makelist (a+1.0) b)

-- Definisi dan Spesifikasi
offsetlist :: (Float -> Float) -> (Float -> Float) -> Float -> Float -> [Float]
-- offsetlist menerima fungsi f dan g, serta menerima float a dan b
-- offsetlist mengeluarkan sebuah list of float yang merupakan penerapan fungsi f terhadap bilangan float antara a dan b, dimulai dari a dengan increment menggunakan fungsi g.
-- Realisasi
offsetlist f g a b
    | a > b =[]
    | otherwise = konso (f a) (offsetlist f g (g a) b)

-- Aplikasi dengan ekspresi lambda
-- offsetlist (\x -> x) (\x -> x+2) (1.2) (7.1)
-- [1.2,3.2,5.2]
-- offsetlist (\x -> if x < 0 then (-999) else x +(3.2)) (\x -> x + (0.5)) (-1.0) (1.0)
-- [-999.0,-999.0,3.2,3.7,4.2]