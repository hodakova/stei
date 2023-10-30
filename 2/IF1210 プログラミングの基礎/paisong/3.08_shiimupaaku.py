tinggi = int(input())
berat = int(input())
kategori = int(input())

# tinggi > 100 and berat <= 150 -> k == 1 => FALSE, else TRUE


if berat <= 150:
    if tinggi > 100:
        if kategori == 1:
            print("FALSE")
        else: # kategori != 1
            print("TRUE")
    else: # tinggi < 100
        if kategori == 1:
            print("TRUE")
        else: # kategori != 1
            print("FALSE")
else: # berat > 150
    if tinggi <= 100:
        if kategori == 2:
            print("TRUE")
        else: # kategori != 2
            print("FALSE")
    elif tinggi <= 200:
        if kategori == 2 or kategori == 3:
            print("TRUE")
        else:
            print("FALSE")