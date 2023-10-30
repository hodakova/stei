isPrima :: Int -> Bool
isPrima x = x>1 && not (isBerfaktor x 2)

isBerfaktor :: Int -> Int -> Bool
isBerfaktor x n =
    if x>n then
        if mod x n == 0 then True
        else isBerfaktor x (n+1)
    else False


isPrimaList :: [Int] -> [Int]
isPrimaList l =
    if isEmpty l then l
    else if isPrima (head l) then konso (head l) (isPrimaList (tail l))
    else isPrimaList (tail l)


isPolindrome :: [Int] -> Bool
isPolindrome l =
    if isEmpty l || isOneElmt l then True
    else if head l == last l then isPolindrome (tail (init l))
    else False

cntElementMin :: [Int] -> (Int, Int)
cntElementMin l =
    if isOneElmt l then (head l, 1)
    else let (x, n) = cntElementMin (tail l) in
        if head l > x then (x,n+1)
        else (head l, 1)


fChartoInt :: Char -> Int
fChartoInt c
    |c==' '= 0|c=='A'= 1|c=='B'=2|c=='C'=3|c=='D'=4|c=='E'=5|c=='F'=6|c=='G'=7|c=='H'=8|c=='I'=9|c=='J'=10|c=='K'=11|c=='L'=12|c=='M'=13|c=='N'=14|c=='O'=15|c=='P'=16|c=='Q'=17|c=='R'=18|c=='S'=19|c=='T'=20|c=='U'=21|c=='V'=22|c=='W'=23|c=='X'=24|c=='Y'=25|c=='Z'=26
fInttoChar :: Int -> Char
fInttoChar n
    |n==0=' '|n==1='A'|n==2='B'|n==3='C'|n==4='D'|n==5='E'|n==6='F'|n==7='G'|n==8='H'|n==9='I'|n==10='J'|n==11='K'|n==12='L'|n==13='M'|n==14='N'|n==15='O'|n==16='P'|n==17='Q'|n==18='R'|n==19='S'|n==20='T'|n==21='U'|n==22='V'|n==23='W'|n==24='X'|n==25='Y'|n==26='Z'

fDeskripsi :: [Char] -> (Char -> Int) -> (Int -> Int) -> (Int -> Char) -> [Char]
fDeskripsi lc f g h =
    if isEmpty lc then lc
    else konso (h(g(f(head lc)))) (fDeskripsi (tail lc) f g h)
{-
   > fDeskripsi ['Z','A','O','D'] fChartoInt (\x -> if odd x then mod (3*x-1) 27 else div x 2) fInttoChar
   > MBQB
   > fDeskripsi ['B','E','T','A'] fChartoInt (\x -> mod (div (2*x) 3) 17) fInttoChar
   > ACM 
-}



konso :: a -> [a] -> [a]
konso e l = [e] ++ l

isEmpty :: [a] -> Bool
isEmpty l = null l

isOneElmt :: [a] -> Bool
isOneElmt l = length l == 1