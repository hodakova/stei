import dt
from functions import F_additional as F

def ubahjin():
    # cek total jin
    if F.totalusers("jin_pembangun") + F.totalusers("jin_pengumpul") > 0:   
        idxjinpertama = 3 # indeks matriks jin pertama
        usernamejin = str(input("Masukkan username jin : "))
        for i in range(idxjinpertama,dt.Nusers):
            if usernamejin == dt.users[i][0]: # ada jin dgn username tsb
                # validasi pengubahan jin
                while True:
                    if dt.users[i][2] == "jin_pengumpul":
                        validate = str(input("Jin ini bertipe \"Pengumpul\". Yakin ingin mengubah ke tipe \"Pembangun\" (Y/N)? "))
                        if validate == 'Y' or validate == 'y':
                            dt.users[i][2] = "jin_pembangun"
                            print("Jin telah berhasil diubah.")
                            break
                    else: # jin_pembangun
                        validate = str(input("Jin ini bertipe \"Pembangun\". Yakin ingin mengubah ke tipe \"Pengumpul\" (Y/N)? "))
                        if validate == 'Y'or validate == 'y':
                            dt.users[i][2] = "jin_pengumpul"
                            print("Jin telah berhasil diubah.")
                            break
                    if validate == 'N' or validate == 'n':
                        print("Jin tidak berhasil diubah.")
                        break
                break
            elif i == dt.Nusers - 1: # tidak ditemukan jin dgn username tsb
                print("Tidak ada jin dengan username tersebut.")
    else: # total jin = 0
        print("Belum ada jin yang di-summon")