-- MENGHITUNG JUMLAH DETIK								jumlahDetik j m d

-- DEFINISI DAN SPESIFIKASI
jumlahDetik :: Int -> Int -> Int -> Int
{- jumlahDetik(j,m,d) menghitung jumlah detik suatu variabel waktu j:m:d
   dari 0:0:0 dengan j (jam) bernilai integer [0..23], m (menit) dan
   d (detik) bernilai integer [0..59]. -} 

-- REALISASI
jumlahDetik j m d = ( j * 60 + m ) * 60 + d

-- APLIKASI
-- jumlahDetik 6 8 4