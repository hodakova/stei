splitAlternate :: [Char] -> ([Char],[Char])
iGanjil :: [Char] -> [Char]
iGenap :: [Char] -> [Char]

splitAlternate l = (iGanjil l, iGenap l)
iGanjil l =
    if isEmpty l then []
    else if odd (length l) then konsDot (iGanjil (init l)) (last l)
    else iGanjil (init l)
iGenap l =
    if isEmpty l then []
    else if even (length l) then konsDot (iGenap (init l)) (last l)
    else iGenap (init l)

isEmpty :: [a] -> Bool
isEmpty l = null l
konsDot :: [a] -> a -> [a]
konsDot l e = l ++ [e]