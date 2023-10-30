tinggi = int(input())
berat = int(input())


if tinggi <= 150:
    print(1)
elif tinggi <= 170:
    if berat <= 80:
        print(2)
    else: # berat > 80
        print(3)
else: # tinggi > 170
    if berat > 60 and berat <= 80:
        print(3)
    else:
        print(4)

# 1 = M, 2 = L, 3 = XL, 4 = undefined