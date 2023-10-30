import dt
from functions import F_additional as F

def hapusjin():
    # cek total jin
    totjin = F.totalusers("jin_pembangun") + F.totalusers("jin_pengumpul")
    if totjin > 0:
        username = input("Masukkan username jin: ")
        for i in range(3,dt.Nusers):
            if dt.users[i][0] == username: # jika username jin ditemukan
                # validasi penghapusan jin
                while True:
                    validate = input("Apakah anda yakin ingin menghapus jin dengan username " + username + " (Y/N)? ")
                    print()
                    if validate == 'Y' or validate == 'y':
                        for j in range(1,dt.Ncandi): # mencari candi yg telah dibuat jin yg akan dihapus
                            if dt.candi[i][1] == username:
                                dt.candi[i] = [None,None,None,None,None]
                        dt.users[i] = [None,None,None]
                        print("Jin telah berhasil dihapus dari alam gaib.")
                        print(f"Jin tersisa : {totjin - 1}")
                        break
                    elif validate == 'N' or validate == 'n':
                        print("Jin tidak berhasil dihapus dari alam gaib.")
                        print(f"Jin tersisa : {totjin}")
                        break
                break
            elif i == dt.Nusers - 1: # username jin tidak ditemukan
                print("Tidak ada jin dengan username tersebut.")
    else: # total jin = 0
        print("Belum ada jin yang di-summon")