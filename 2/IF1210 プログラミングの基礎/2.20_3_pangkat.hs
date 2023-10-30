pangkat :: Int -> Int -> Float
pangkat a b =
    if b == 0 then 1
    else if b>0 then (fromIntegral a) * (pangkat a (b-1))
    else 1/(pangkat a (-b))