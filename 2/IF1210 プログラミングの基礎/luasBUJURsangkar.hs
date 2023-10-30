bujur :: Int -> Int
bujur s
    | s==1      = 1
    | otherwise = bujur (s-1) + s + s-1