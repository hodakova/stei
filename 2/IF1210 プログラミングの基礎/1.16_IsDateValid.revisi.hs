-- APAKAH DATA VALID?									isDateValid d m y

-- DEFINISI DAN SPESIFIKASI
isDateValid :: Int -> Int -> Int -> Bool
{- isDateValid(d,m,y) mengembalikan nilai true jika d, m, y membentuk
   date yang valid dengan aplikasi isLeapYear sebagai fungsi antara.
   Definisi date yang valid adalah jika elemen hari (d) bernilai antara
   1 dan 31, tergantung pada bulan dan apakah tahun kabisat atau bukan,
   elemen bulan (m) bernilai antara 1 dan 12, dan elemen tahun (y)
   bernilai antara 0 dan 99. Nilai y mewakili tahun 1900 s.d. 1999 -}
isLeapYear :: Int -> Bool
{- isLeapYear(y) mengembalikan nilai true jika y merupakan tahun kabisat -}

-- REALISASI
isDateValid y m d = ((y>=0 && y<=99) && d>0) && (((m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12) && d<=31) || ((m==4 || m==6 || m==9 || m==11) && d<=30) || (m==2 && ((isLeapYear y && d<=29) || (not (isLeapYear y) && d<=28))))
isLeapYear y = (1900+y)`mod`400==0 || ((y+1900)`mod`4==0 && y`mod`100/=0)

-- APLIKASI
-- isDateValid 0 2 29