fpb :: Int -> Int -> Int
fpb a b
    | mod a b == 0  = b
    | otherwise     = fpb b (mod a b)