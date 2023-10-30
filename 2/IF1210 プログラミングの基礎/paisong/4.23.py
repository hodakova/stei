import random

Nusers = 103
users = [[None,None,None] for i in range(Nusers)]
users[0] = ["username","password","role"]
users[1] = ["Bondowoso","cintaroro","bandung_bondowoso"]
users[2] = ["Roro","gasukabondo","roro_jonggrang"]
users[3] = ["jin1","jinsatu","jin_pengumpul"]
users[4] = ["jin_kuli","kulisejati","jin_pembangun"]

Ncandi = 1000
candi = [[None,None,None,None,None] for i in range(Ncandi)]
candi[0] = ["id","pembuat","pasir","batu","air"]

bahan_bangunan = [["nama","deskripsi","jumlah"],["pasir","pasir adalah pasir",0],["batu","batu adalah batu",0],["air","air adalah air",0]]

# code
def ubahjin():    
    idxjinpertama = 3
    usernamejin = str(input("Masukkan username jin : "))
    found = False
    for i in range(idxjinpertama,Nusers):
        if usernamejin == users[i][0]:
            found = True
            break
    if found:
        while True:
            if users[i][2] == "jin_pengumpul":
                YorN = str(input("Jin ini bertipe \"Pengumpul\". Yakin ingin mengubah ke tipe \"Pembangun\" (Y/N)? "))
                if YorN == 'Y':
                    users[i][2] = "jin_pembangun"
                    print("Jin berhasil diubah.")
                    break
            else:
                YorN = str(input("Jin ini bertipe \"Pembangun\". Yakin ingin mengubah ke tipe \"Pengumpul\" (Y/N)? "))
                if YorN == 'Y':
                    users[i][2] = "jin_pengumpul"
                    print("Jin berhasil diubah.")
                    break
            if YorN == 'N':
                print("Jin tidak diubah.")
                break
    else: print("Tidak ada jin dengan username tersebut.")

def totalusers(role):
    count = 0
    for i in range(1,Nusers):
        if users[i][2] == role: count += 1
    return count

def rawkumpul():
    foundpasir = random.randint(0,5)
    foundbatu = random.randint(0,5)
    foundair = random.randint(0,5)
    bahan_bangunan[1][2] += foundpasir
    bahan_bangunan[2][2] += foundbatu
    bahan_bangunan[3][2] += foundair
    return [foundpasir,foundbatu,foundair]

def kumpul():
    found = rawkumpul()
    print(f"Jin menemukan {found[0]} pasir, {found[1]} batu, dan {found[2]} air.")

def batchkumpul():
    totpengumpul = totalusers("jin_pengumpul")
    if totpengumpul > 0:
        print(f"Mengerahkan {totpengumpul} jin untuk mengumpulkan bahan.")
        founds = [0,0,0]
        for i in range(totpengumpul):
            found = rawkumpul()
            for i in range(3): founds[i] += found[i]
        print(f"Jin menemukan total {founds[0]} pasir, {founds[1]} batu, dan {founds[2]} air.")
    else: print("Kumpul gagal. Anda tidak punya jin pengumpul. Silahkan summon terlebih dahulu.")

def bangun():
    reqpasir = random.randint(1,5)
    reqbatu = random.randint(1,5)
    reqair = random.randint(1,5)
    if bahan_bangunan[1][2] >= reqpasir and bahan_bangunan[2][2] >= reqbatu and bahan_bangunan[3][2] >= reqair:
        bahan_bangunan[1][2] -= reqpasir
        bahan_bangunan[2][2] -= reqbatu
        bahan_bangunan[3][2] -= reqair
        for id in range(Ncandi):
            if candi[id][0] == None: break
        candi[id] = [id,username,reqpasir,reqbatu,reqair]
        print("Candi berhasil dibangun.")
        totcandi = 0
        for i in range(1,Ncandi):
            if candi[i][0] != None: totcandi += 1
        if totcandi < 100: print(f"Sisa candi yang perlu dibangun : {100-totcandi}")
        else: print("Sisa candi yang perlu dibangun : 0")
    else:
        print("Bahan bangunan tidak mencukupi.")
        print("Candi tidak bisa dibangun!")

def batchbangun():
    totpembangun = totalusers("jin_pembangun")
    if totpembangun > 0:
        tempcandi = [candi[i] for i in range(Ncandi)]
        totbahan = [0,0,0]
        idxjin = 3
        for i in range(totpembangun):
            while users[idxjin][2] != "jin_pembangun": idxjin += 1
            reqpasir = random.randint(1,5)
            reqbatu = random.randint(1,5)
            reqair = random.randint(1,5)
            tempcandi[i] = [None,users[idxjin][0],reqpasir,reqbatu,reqair]
            totbahan[0] += reqpasir
            totbahan[1] += reqbatu
            totbahan[2] += reqair
            idxjin += 1
        print(f"Mengerahkan {totpembangun} jin untuk membangun candi dengan total bahan {totbahan[0]} pasir, {totbahan[1]} batu, dan {totbahan[2]} air.")
        if bahan_bangunan[1][2] >= totbahan[0] and bahan_bangunan[2][2] >= totbahan[1] and bahan_bangunan[3][2] >= totbahan[2]:
            bahan_bangunan[1][2] -= totbahan[0]
            bahan_bangunan[2][2] -= totbahan[1]
            bahan_bangunan[3][2] -= totbahan[2]
            for i in range(totpembangun):
                for id in range(Ncandi):
                    if candi[id][0] == None: break
                candi[id] = tempcandi[i]
                candi[id][0] = id
            print(f"Jin berhasil membangun total {totpembangun} candi.")
        else:
            print("Bangun gagal. Kurang",end=" ")
            kurangbahan = [totbahan[0]-bahan_bangunan[1][2],totbahan[1]-bahan_bangunan[2][2],totbahan[2]-bahan_bangunan[3][2]]
            countbarang = 0
            for i in range(3):
                if kurangbahan[i] > 0: countbarang += 1
            i,count = 0,0
            while i<3 and count < countbarang:
                if kurangbahan[i] > 0:
                    count += 1
                    if count < countbarang:
                        if countbarang > 2: print(f"{kurangbahan[i]} {bahan_bangunan[i+1][0]}",end=", ")
                        else: print(f"{kurangbahan[i]} {bahan_bangunan[i+1][0]}",end=" ")
                    else:
                        if countbarang > 1: print("dan",end=" ")
                        print(f"{kurangbahan[i]} {bahan_bangunan[i+1][0]}.")
                i += 1
    else: print("Bangun gagal. Anda tidak punya jin pembangun. Silahakn summon terlebih dahulu.")

# login
while True:
    username = str(input("username: "))
    for idusers in range(1,Nusers):
        if username == users[idusers][0]:
            break
    if str(input("password: ")) == users[idusers][1]: 
        # access
        while True:
            access = str(input(">>> "))
            if users[idusers][2] == "bandung_bondowoso":
                if access == "ubahjin": ubahjin()
                elif access == "batchkumpul": batchkumpul()
                elif access == "batchbangun": batchbangun()
            elif users[idusers][2] == "jin_pengumpul":
                if access == "kumpul": kumpul()
            elif users[idusers][2] == "jin_pembangun":
                if access == "bangun": bangun()
            if access == "laporan":
                i = 0; print("[",end="")
                while i < Nusers and users[i][0] != None:
                    print(users[i],end=",")
                    i+=1
                print("]")
                i = 0; print("[",end="")
                while i < Ncandi and candi[i][0] != None:
                    print(candi[i],end=",")
                    i+=1
                print("]")
                print(bahan_bangunan)
            if access == "logout": break