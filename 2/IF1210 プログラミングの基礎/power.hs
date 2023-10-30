power :: Int -> Int -> Int
power x y
    | y == 0 = 1
    | otherwise = power x (y-1) *x