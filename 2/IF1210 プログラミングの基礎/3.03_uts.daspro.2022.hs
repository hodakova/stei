fDeretTujuh :: Int -> Int
fDeretTujuh m =
    if m == 1 then 1
    else 1+5*(m-1) + fDeretTujuh (m-1)

fDeretTujuhList :: Int -> Int -> [Int]
fDeretTujuhList d e =
    if e < d then []
    else if d-e == 0 then [fDeretTujuh e]
    else konso (fDeretTujuh d) (fDeretTujuhList (d+1) e)


nbX :: [Int] -> Int -> Int
nbX l x =
    if isEmpty l then 0
    else if head l == x then 1 + (nbX (tail l) x)
    else nbX (tail l) x

isMember :: Int -> [Int] -> Bool
isMember x l =
    if isEmpty l then False
    else if head l == x then True
    else isMember x (tail l)


removeElmt :: [Int] -> Int -> [Int]
removeElmt l x =
    if isEmpty l then []
    else if head l == x then tail l
    else konso (head l) (removeElmt (tail l) x)


listCountN :: [Int] -> Int -> ([Int], Int)
listCountN l n =
    if isEmpty l then
        (l, 0){-
    else ((konso (nbX (head l) == n) (listCountN (tail l) n)),
        if nbX (head l) == n then 1 + listCountN (tail l) n
        else listCountN (tail l) n) -}
    else let (l1, m) = listCountN (tail l) n in
        if nbX (head l) == n then
            (konso (head l) l1, m+1)
        else if isMember (head l) l1 then
            (removeElmt l1 (head l), m-1)
        else -- not (is member (head l) l1)
            (l1, m)


konso :: a -> [a] -> [a]
konso e l = [e] ++ l
isEmpty :: [a] -> Bool
isEmpty l = null l