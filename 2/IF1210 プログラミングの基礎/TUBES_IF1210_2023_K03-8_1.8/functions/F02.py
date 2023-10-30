import dt

def logout():
    if dt.activeuser != [None,None,None]:   # sudah login
        print(f"Berhasil keluar dari {dt.activeuser[0]}!")
        dt.activeuser = [None,None,None]
    else:                                   # belum login
        print("Logout gagal!")
        print("Anda belum login, silahkan login terlebih dahulu sebelum melakukan logout")