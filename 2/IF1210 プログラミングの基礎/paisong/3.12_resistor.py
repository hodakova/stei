r1 = float(input()); r2 = float(input()); r3 = float(input()); jenis = str(input())

while not (r1>0 and r2>0 and r3>0 and (jenis == 's' or jenis == 'S' or jenis == 'P' or jenis == 'p')):
    print("Masukan salah"); r1 = float(input()); r2 = float(input()); r3 = float(input()); jenis = str(input())

print('{:.2f}'.format(r1+r2+r3)) if jenis == 's' or jenis == 'S' else print('{:.2f}'.format(1/((1/r1)+(1/r2)+(1/r3))))