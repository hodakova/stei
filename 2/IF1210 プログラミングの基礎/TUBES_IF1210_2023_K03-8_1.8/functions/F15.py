import dt

def help() :
    if dt.activeuser[2] == "bandung_bondowoso" :
        #Bandung Bondowoso
        print("="*11, "HELP", "="*11)
        print("1. logout\nUntuk keluar dari akun yang digunakan sekarang")
        print("2. summonjin\nUntuk memanggil jin")
        print("3. hapusjin\nUntuk menghapus jin")
        print("4. ubahjin\nUntuk mengubah tipe jin, dari jin tipe pembangun menjadi tipe pengumpul maupun sebaliknya")
        print("5. batchkumpul\nUntuk membuat seluruh jin tipe pengumpul mengumpulkan bahan")
        print("6. batchbangun\nUntuk membuat seluruh jin tipe pembangun membangun candi")
        print("7. laporanjin\nUntuk mengambil laporan kinerja jin yang berisi :\n- Jumalah jin total\n- Jumlah jin pengumpul\n- Jumlah jin pembangun\n- Jin Terajin\n- Jin Termalas\n- Jumlah pasir\n- Jumlah air\n- Jumlah batu")
        print("8. laporancandi\nUntuk mengambil laporan progress pembangunan candi yang berisi \n- Jumlah candi total\n- Jumlah total pasir yang digunakan\n- Jumlah totalbatu yang digunakan\n- Jumlah total air yang digunakan\n- ID candi termahal\n- ID candi termurah")
        print("9. save\nUntuk menjalankan prosedur menyimpan data")
        print("10. exit\nUntuk keluar dari program dan kembali ke terminal")

    elif dt.activeuser[2] == "roro_jonggrang" :
        #Roro Jonggrang
        print("="*11, "HELP", "="*11)
        print("1. logout\nUntuk keluar dari akun yang digunakan sekarang")
        print("2. hancurkancandi\nuntuk menghancurkan candi")
        print("3. ayamberkokok\nUntuk menyelesaikan permainan dengan memalsukan pagi hari")
        print("4. save\nUntuk menjalankan prosedur menyimpan data")
        print("5. exit\nUntuk keluar dari program dan kembali ke terminal")

    elif dt.activeuser[2] == "jin_pengumpul" :
        #Jin Pengumpul
        print("="*11, "HELP", "="*11)
        print("1. logout\nUntuk keluar dari akun yang digunakan sekarang")
        print("2. kumpul\nUntuk mengumpulkan resource candi")
        print("3. save\nUntuk menjalankan prosedur menyimpan data")
        print("4. exit\nUntuk keluar dari program dan kembali ke terminal")

    elif dt.activeuser[2] == "jin_pembangun" :
        #Jin Pembangun 
        print("="*11, "HELP", "="*11)
        print("1. logout\nUntuk keluar dari akun yang digunakan sekarang")
        print("2. bangun\nUntuk membangun candi")
        print("3. save\nUntuk menjalankan prosedur menyimpan data")
        print("4. exit\nUntuk keluar dari program dan kembali ke terminal")

    else:
        # belum login
        print("="*11, "HELP", "="*11)
        print("1. login\nUntuk masuk menggunakan akun")
        print("2. exit\nUntuk keluar dari program dan kembali ke terminal")