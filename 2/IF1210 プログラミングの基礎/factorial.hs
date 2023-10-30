fac :: Int -> Int
fac n
    | n == 0    = 1
    | otherwise = fac (n-1)*n