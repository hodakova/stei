un :: Int -> Int
un n
   | mod n 2 == 0 = -1-3*(n-1)
   | mod n 2 == 1 = 1+3*(n-1)