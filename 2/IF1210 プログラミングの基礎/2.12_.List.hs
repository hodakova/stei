konso :: a -> [a] -> [a]
konso e l = [e] ++ l

konsDot :: [a] -> a -> [a]
konsDot l e = l ++ [e]

isEmpty :: [a] -> Bool
isEmpty l = null l

isOneElmt :: [a] -> Bool
isOneElmt l = length l == 1

nbElmt :: [a] -> Int
nbElmt l = if isEmpty l then 0
           else 1 + nbElmt (tail l)

isMember :: a -> [a] -> Bool
isMember x l
   | isEmpty l   = False
   | head l == x = True
   | otherwise   = isMember x (tail l)

copy :: [a] -> [a]
copy l = if isEmpty l then []
         else konso (head l) (copy (tail l))

isEqual :: [a] -> [a] -> Bool
isEqual l1 l2
   | isEmpty l1 && isEmpty l2       = True
   | isEmpty l1 && not (isEmpty l2) = False
   | not (isEmpty l1) && isEmpty l2 = False
   | not (isEmpty l1) && not (isEmpty l2) = head l1 == head l2 && isEqual (tail l1) (tail l2)

konkat :: [a] -> [a] -> [a]
konkat l1 l2
   | isEmpty l1 = l2
   | otherwise  = konso (head l1) (konkat (tail l1) l2)