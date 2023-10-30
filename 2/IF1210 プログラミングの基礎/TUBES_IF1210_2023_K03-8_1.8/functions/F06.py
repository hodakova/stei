import dt
import random

def bangun():
    # menentukan banyak bahan candi yg diperlukan
    reqpasir = random.randint(1,5)
    reqbatu = random.randint(1,5)
    reqair = random.randint(1,5)

    # cek kecukupan bahan
    if dt.bahan_bangunan[1][2] >= reqpasir and dt.bahan_bangunan[2][2] >= reqbatu and dt.bahan_bangunan[3][2] >= reqair: # bahan cukup
        dt.bahan_bangunan[1][2] -= reqpasir
        dt.bahan_bangunan[2][2] -= reqbatu
        dt.bahan_bangunan[3][2] -= reqair

        # mencari tempat candi yg kosong
        for id in range(dt.Ncandi):
            if dt.candi[id] == [None for i in range(5)]: break
        # didapatkan id candi
        dt.candi[id] = [str(id),dt.activeuser[0],reqpasir,reqbatu,reqair] # membangun candi
        print("Candi berhasil dibangun.")

        totcandi = 0 # deklarasi total candi
        for i in range(1,dt.Ncandi):
            if dt.candi[i] != [None for i in range(5)]: totcandi += 1 # mencari total candi
        
        if totcandi < 100:
            print(f"Sisa candi yang perlu dibangun : {100-totcandi}")
        else: # total candi >= 100
            print("Sisa candi yang perlu dibangun : 0")
        
    else: # bahan tidak cukup
        print("Bahan bangunan tidak mencukupi.")
        print("Candi tidak bisa dibangun!")