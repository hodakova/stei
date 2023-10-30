n = int(input())

while n<= 0 and n>100:
    print("Masukan salah. Ulangi!"); n = int(input())

arei = [int(input()) for i in range(n)]

x = int(input())

found = -1

if x==0:
    for i in range(n):
        if arei[i] == 0: print(i+1); found = 1
    if found == -1: print("Tidak ada 0")

elif x==-1:
    for i in range(n):
        if arei[i] < 0: print(i+1,arei[i]); found = 1
    if found == -1: print("Tidak ada negatif")

elif x==1:
    for i in range(n):
        if arei[i] < 0: print(i+1,arei[i])
    if found == -1: print("Tidak ada positif")

else:
    print("Tidak diproses")