import dt
from functions import F_additional as F

def laporanjin():
    jin_pembangun = F.totalusers("jin_pembangun") # total jin pembangun
    jin_pengumpul = F.totalusers("jin_pengumpul") # total jin pengumpul
    total_jin = jin_pembangun + jin_pengumpul     # total jin

    terajin  = 0    # deklarasi total candi yg dibuat jin terajin
    termalas = 9999 # deklarasi total candi yg dibuat jin termalas

    jin_terajin  = "-" # deklarasi username jin terajin
    jin_termalas = "-" # deklarasi username jin termalas

    for i in range (1, dt.Nusers):
        count = 0    # deklarasi untuk menghitung jumlah candi yg telah dibuat suatu jin
        # menghitung total candi yg dibuat suatu jin
        for j in range (1, dt.Ncandi):
            if dt.users[i][0] == dt.candi[j][1] and dt.candi[j][1] != None:
                count += 1
        
        # mengubah siapa jin terajin
        if count > 0 or dt.users[i][2] == "jin_pembangun":
            if count > terajin:
                terajin = count
                jin_terajin = dt.users[i][0]
            
            elif count == terajin: # banyak candi yg dibuat suatu jin sama dengan yg lainnya
                if dt.users[i][0] < jin_terajin: # membandingkan username secara leksikografis terendah
                    jin_terajin = dt.users[i][0]
            
            # mengubah siapa jin termalas
            if count < termalas:
                termalas = count
                jin_termalas = dt.users[i][0]

            elif count == termalas: # banyak candi yg dibuat suatu jin sama dengan yg lainnya
                if dt.users[i][0] > jin_termalas: # membandingkan username secara leksikografis tertinggi
                    jin_termalas = dt.users[i][0]

    if jin_terajin == "-": jin_terajin = jin_termalas
    
    # jumlah bahan
    jumlah_pasir = dt.bahan_bangunan[1][2]
    jumlah_air   = dt.bahan_bangunan[2][2]
    jumlah_batu  = dt.bahan_bangunan[3][2]

    print() # output laporan
    print("> Total Jin : ", total_jin)
    print("> Total Jin Pengumpul : ", jin_pengumpul)
    print("> Total Jin Pembangun : ", jin_pembangun)
    print("> Jin Terajin : ", jin_terajin)
    print("> Jin Termalas : ", jin_termalas)
    print(f"> Jumlah Pasir : {jumlah_pasir} unit")
    print(f"> Jumlah Air : {jumlah_air} unit")
    print(f"> Jumlah Batu : {jumlah_batu} unit")