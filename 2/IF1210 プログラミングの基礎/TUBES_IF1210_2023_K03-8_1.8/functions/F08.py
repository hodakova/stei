import dt
import random
from functions import F07
from functions import F_additional as F



def batchkumpul():
    # menghitung banyak jin pengumpul
    totpengumpul = F.totalusers("jin_pengumpul")

    if totpengumpul > 0: # ada jin pengumpul
        print(f"Mengerahkan {totpengumpul} jin untuk mengumpulkan bahan.")
        founds = [0,0,0] # deklarasi jumlah bahan yg  terkumpul
        for i in range(totpengumpul): #me-loop sebanyak total pengumpul
            found = F07.rawkumpul() # mengumpulkan bahan
            for i in range(3): founds[i] += found[i] # menjumlahkan bahan yg terkumpul
        print(f"Jin menemukan total {founds[0]} pasir, {founds[1]} batu, dan {founds[2]} air.")
    
    else: # tidak ada jin pengumpul
        print("Kumpul gagal. Anda tidak punya jin pengumpul. Silahkan summon terlebih dahulu.")



def batchbangun():
    # menghitung banyak jin pembangun
    totpembangun = F.totalusers("jin_pembangun")

    if totpembangun > 0: # ada jin pembangun
        tempcandi = [dt.candi[i] for i in range(dt.Ncandi)] # deklarasi awal estimasi candi yg dapat dibuat
        totbahan = [0,0,0] # deklarasi estimasi bahan yg diperlukan
        idxjin = 3 # indeks jin pertama

        for i in range(totpembangun):
            while dt.users[idxjin][2] != "jin_pembangun":  # mencari jin pembangun
                idxjin += 1

            # menentukan banyak bahan candi yg diperlukan
            reqpasir = random.randint(1,5)
            reqbatu = random.randint(1,5)
            reqair = random.randint(1,5)

            # memasukan banyak bahan ke estimasi
            tempcandi[i] = [None,dt.users[idxjin][0],reqpasir,reqbatu,reqair]
            totbahan[0] += reqpasir
            totbahan[1] += reqbatu
            totbahan[2] += reqair

            # mencari jin lain untuk membangun candi
            idxjin += 1

        print(f"Mengerahkan {totpembangun} jin untuk membangun candi dengan total bahan {totbahan[0]} pasir, {totbahan[1]} batu, dan {totbahan[2]} air.")
        
        # kecukupan bahan berdasarkan estimasi
        if dt.bahan_bangunan[1][2] >= totbahan[0] and dt.bahan_bangunan[2][2] >= totbahan[1] and dt.bahan_bangunan[3][2] >= totbahan[2]:
            # membangun candi
            dt.bahan_bangunan[1][2] -= totbahan[0]
            dt.bahan_bangunan[2][2] -= totbahan[1]
            dt.bahan_bangunan[3][2] -= totbahan[2]

            for i in range(totpembangun):
                for id in range(dt.Ncandi):
                    if dt.candi[id] == [None for j in range(5)]: break
                dt.candi[id] = tempcandi[i]
                dt.candi[id][0] = str(id)
            # candi terbangun

            print(f"Jin berhasil membangun total {totpembangun} candi.")

        else: # estimasi bahan tidak cukup
            print("Bangun gagal. Kurang",end=" ")
            kurangbahan = [totbahan[0]-dt.bahan_bangunan[1][2],totbahan[1]-dt.bahan_bangunan[2][2],totbahan[2]-dt.bahan_bangunan[3][2]]
            
            # agar hanya print yg jumlah jenis bahan yang kurang
            countjenisbahan = 0 # deklarasi jumlah jenis bahan yg kurang
            for i in range(3): #
                if kurangbahan[i] > 0: countjenisbahan += 1
            
            i,count = 0,0 # deklarasi indeks loop
            while i<3 and count < countjenisbahan:
                if kurangbahan[i] > 0:
                    count += 1
                    if count < countjenisbahan: # print bahan yg kurang
                        if countjenisbahan > 2: print(f"{kurangbahan[i]} {dt.bahan_bangunan[i+1][0]}",end=", ") # setiap jumlah jenis bahan dipisah ","
                        else: print(f"{kurangbahan[i]} {dt.bahan_bangunan[i+1][0]}",end=" ") # jumlah jenis bahan hanya 2 sehingga tidak memerlukan ","
                    else: # memberi "dan" sebelum bahan terakhir jika jenis bahan yg kurang > 1
                        if countjenisbahan > 1: print("dan",end=" ")
                        print(f"{kurangbahan[i]} {dt.bahan_bangunan[i+1][0]}.")
                i += 1

    else: # tidak ada jin pembangun
        print("Bangun gagal. Anda tidak punya jin pembangun. Silahakn summon terlebih dahulu.")