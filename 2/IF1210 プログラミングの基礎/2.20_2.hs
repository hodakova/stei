-- Definisi dan Spesifikasi
ubahArah :: Int -> Int -> Int
-- Fungsi ubahArah menerima integer r dan s dan menghsilkan integer
-- Nilai s diasumsikan ada di antara 0 hingga 359, nilai r diasumsikan di antara -359 hingga 359
-- Realisasi
ubahArah s r = mod (s+r) 360
-- Aplikasi
-- ubahArah 0 360
-- 0
-- ubahArah 200 (-359)
-- 201

-- Definisi dan Spesifikasi
pangkat :: Int -> Int -> Int
-- Fungsi pangkat menerima dua buah integer a dan b dan menghasilkan a pangkat b
-- a > 0 dan b ≥ 0
-- Realisasi
pangkat a b
    | b == 0 = 1
    | otherwise= a * pangkat a (b-1)
-- Aplikasi
-- pangkat 5 7
-- 78125
-- pangkat 2 3
-- 8


isAllGanjil :: [Int] -> Bool
isAllGanjil l
    | null l = True
    | mod (head l) 2 == 0 = False
    | otherwise = isAllGanjil (tail l)

isOneElmt :: [Int] -> Bool
isOneElmt l = (length l) == 1

konsdot :: [Int] -> Int -> [Int]
konsdot l e = l ++ [e]

konso :: Int -> [Int] -> [Int]
konso e l = [e] ++ l

getSmallest :: [Int] -> Int
getSmallest l
    | isOneElmt l = head l
    | (head (tail l)) >= head l = getSmallest(konso (head l) (tail (tail l))) 
    | otherwise = getSmallest(tail l)

delElement :: Int -> [Int] -> [Int]
delElement x l
    | null l = []
    | head l == x && isOneElmt l == False = konso (head (tail l)) (delElement x (tail (tail l)))
    | head l == x && isOneElmt l == True = []
    | otherwise = konso (head l) (delElement x (tail l))

sortList :: [Int] -> [Int]
sortList l
    | null l = []
    | (head l) == getSmallest l = konso (head l) (sortList(tail l))
    | otherwise = sortList(konsdot (tail l) (head l) )

p1 :: Float -> Float
p1 x = x + 1

makelist :: Float -> Float -> [Float]
makelist a b
    | a > b = []
    | otherwise = konso a (makelist (a+1.0) b)
