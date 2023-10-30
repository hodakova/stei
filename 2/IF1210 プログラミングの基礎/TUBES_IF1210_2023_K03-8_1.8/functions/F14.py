# STEP 1 : buat folder parent(cek dulu folder parent udh ada atau belom, kalau belom ada, bikin pake os.mkdir("save/"+folder)) 
# STEP 2 : buka file user/candi/bahan bangunan di folder yang baru dibuat (user = open("save/"+folder+"/user.csv", "w+"))
# pake 'w' aja cukupp,  buka file dan nulis file kalo udah ada, kalopun filenya belum ada, file bakal dibikin
# STEP 3 : pindahin isi array ke file pake user.write

import os.path
import dt

def rawsave(path,matriks,x,y):
    f = open(path, 'w')
    for i in range(x):
        if matriks[i] != [None for j in range(y)]:
            line = matriks[i][0]
            for j in range(1,y):
                line += ";"+ str(matriks[i][j])
            line += "\n"
            f.write(line)
    f.close()

def save():
    folder = input("Masukkan nama folder : ")
    print()
    print("Saving...")
    print()
    if not os.path.isdir("save") :
        print("Membuat folder save")
        os.mkdir("save")
    if not os.path.isdir("save/"+folder):
        print("Membuat folder save/"+folder)
        os.mkdir("save/"+folder)

    rawsave("save/"+folder+"/user.csv", dt.users, dt.Nusers, 3)
    rawsave("save/"+folder+"/candi.csv", dt.candi, dt.Ncandi, 5)
    rawsave("save/"+folder+"/bahan_bangunan.csv", dt.bahan_bangunan, 4, 3)

    print()
    print("Berhasil menyimpan data di folder save/"+folder)