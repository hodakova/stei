import dt

def hancurkancandi():
    id_candi = str(input("Masukkan ID Candi : "))
    # mencari candi
    for id in range(1,dt.Ncandi):
        if dt.candi[id][0] == id_candi: # candi ditemukan
            # validasi penghancuran candi
            while True:
                validate = input(f"Apakah anda yakin ingin menghancurkan candi ID : {id_candi} (Y/N)? ")
                if validate == 'Y' or validate == 'y':
                    dt.candi[id] = [None for i in range(5)] # menghancurkan candi
                    print("Candi telah berhasil dihancurkan")
                    break
                elif validate == 'N' or validate == 'n':
                    print("Candi tidak berhasil dihancurkan")
                    break
            break
        elif id == dt.Ncandi - 1: # candi tidak ditemukan
            print("Tidak ada candi dengan ID tersebut")