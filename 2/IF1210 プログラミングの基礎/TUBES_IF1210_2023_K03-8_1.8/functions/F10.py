import dt

def formathargacandi(uang):
    # memformat uang, e.g. 15000 -> (Rp 15.000)
    n = len(str(uang))
    format  = ""
    if uang > 0:
        format += "(Rp "
        for i in range(n):
            format += str(uang)[i]
            if (n-i-1)%3 == 0 and i != n-1: format += "."
        format += ")"
    return format

def laporancandi():
    total_candi = 0 # deklarasi total candi
    total_pasir = 0 # deklarasi total pasir
    total_air   = 0 # deklarasi total air
    total_batu  = 0 # deklarasi total batu

    harga_max = 0       # deklarasi harga termahal
    harga_min = 199000  # deklarasi harga termurah
    letak_id_max = "-" # deklarasi letak id max candi
    letak_id_min = "-" # deklarasi letak id min candi

    # menghitung nilai eksaknya
    for i in range (1,dt.Ncandi) :
        if dt.candi[i]  != [None for j in range(5)] :
            total_candi += 1
            total_pasir += dt.candi[i][2]
            total_batu  += dt.candi[i][3]
            total_air   += dt.candi[i][4]

            harga_candi = 10000*dt.candi[i][2] + 15000*dt.candi[i][3] + 7500*dt.candi[i][4]
            # menentukan candi termahal
            if harga_candi > harga_max:
                harga_max = harga_candi
                letak_id_max = dt.candi[i][0]
            # menentukan candi termurah
            if harga_candi < harga_min:
                harga_min = harga_candi
                letak_id_min = dt.candi[i][0]

    if total_candi == 0: harga_min = 0 # jika belum ada candi
    elif total_candi == 1: letak_id_min = letak_id_max

    print() # output
    print("Total Candi : ",total_candi)
    print("Total Pasir yang digunakan : ",total_pasir)
    print("Total Batu yang digunakan : ",total_batu)
    print("Total Air yang digunakan : ",total_air)
    print(f"ID Candi Termahal : {letak_id_max} {formathargacandi(harga_max)}")
    print(f"ID Candi Termurah : {letak_id_min} {formathargacandi(harga_min)}")