import dt
import random

def rawkumpul():
    # menghitung banyak bahan yg ditemukan
    foundpasir = random.randint(0,5)
    foundbatu = random.randint(0,5)
    foundair = random.randint(0,5)

    # menambahkan banyak bahan ke matriks bahan bangunan
    dt.bahan_bangunan[1][2] += foundpasir
    dt.bahan_bangunan[2][2] += foundbatu
    dt.bahan_bangunan[3][2] += foundair
    
    return [foundpasir,foundbatu,foundair]

def kumpul():
    found = rawkumpul()
    print(f"Jin menemukan {found[0]} pasir, {found[1]} batu, dan {found[2]} air.")