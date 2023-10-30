import argparse
import os.path
import dt
from functions import F01
from functions import F16

#buat fungsi split untuk misahin array untuk tiap csv
def splitarray(baris, jumlahkolom):
    variabelsementara = ""

    arr_hasilsplit = [None for i in range (jumlahkolom)]
 
    j=0
    for i in range (len(baris)):
        if ((baris[i]) != ";") and (i != len(baris)-1):
            variabelsementara += baris[i]
        else :
            arr_hasilsplit[j] = variabelsementara
            j+=1
            variabelsementara=""
    return arr_hasilsplit


   



def load():
    #argparse hanya untuk memasukkan nama folder yang ingin dicari (belum dilakukan proses apa apa)
    parser = argparse.ArgumentParser()
    parser.add_argument("foldername", help="Masukkan nama folder yang ingin dicari/ditambahkan",nargs="?")
    args = parser.parse_args()

    print()
    #cari apakah nama folder yang diinput ada ataupun tidak di komputer menggunakan if-else

    #kondisi 1 : nama folder yang diinput ditemukan 
    if os.path.isdir("save/"+args.foldername):
        print("Loading...")
        #untuk pindahin data user dari format csv ke format array
        fusers = open("save/"+args.foldername+"/user.csv", 'r')
        dt.users = [[None for i in range(3)] for j in range(dt.Nusers)]
        i=0
        for line in fusers.readlines():
            dt.users[i] = splitarray(line, 3)
            i+=1
        fusers.close()
        #untuk pindahin data bahanbangunan dari format csv ke format array
        #rawload(, dt.bahan_bangunan, 4, 3)
        fbahan = open("save/"+args.foldername+"/bahan_bangunan.csv", 'r')
        dt.bahan_bangunan = [[None for i in range(3)] for j in range(4)]
        i=0
        for line in fbahan.readlines():
            dt.bahan_bangunan[i] = splitarray(line, 3)
            if i > 0: dt.bahan_bangunan[i][2] = int(dt.bahan_bangunan[i][2]) # mengubah jumlah bahan ke integer
            i+=1
        fbahan.close()

        #untuk pindahin data candi dari format csv ke format array
        #rawload("save/"+args.foldername+"/candi.csv", dt.candi, dt.Ncandi, 5)
        fcandi = open("save/"+args.foldername+"/candi.csv", 'r')
        dt.candi = [[None for i in range(5)] for j in range(dt.Ncandi)]
        i=0
        for line in fcandi.readlines():
            dt.candi[i] = splitarray(line, 5)
            if i > 0:
                dt.candi[i][2] = int(dt.candi[i][2])
                dt.candi[i][3] = int(dt.candi[i][3])
                dt.candi[i][4] = int(dt.candi[i][4])
            i+=1
        fcandi.close()

        print("Selamat datang di program “Manajerial Candi")
        print("Silahkan masukkan username Anda")
        F01.login()
    #kondisi 2 : nama folder yang diinput tidak ditemukan
    elif not os.path.isdir("save/"+args.foldername):
        print(f"Folder {(args.foldername)} tidak ditemukan.")
        F16.eksit()

    # kondisi 3 : tidak memasukkan nama file
    #blm tau caranya gimana
    elif ("save/"+args.foldername) == None:
        parser.error("Tidak ada nama folder yang diberikan!")
        print()
        print("Usage: python main.py <nama_folder>")
        F16.eksit()