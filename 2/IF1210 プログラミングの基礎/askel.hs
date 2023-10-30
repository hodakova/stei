isJamValid :: Int -> Int -> Int -> Bool

isJamValid j m d = (j >= 0 && j < 24) && (m >= 0 && m < 60) && (d >= 0 && d < 60)