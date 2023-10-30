n = int(input())
luar = str(input())
dalam = str(input())

if n <= 0 and dalam == luar:
    print("kesalahan input")
elif n==1:
    print(luar)
else:
    for i in range(n-1):
        print(luar,end="")
    print(luar)
    for j in range(n-2):
        print(luar,end="")
        for i in range(n-2):
            print(dalam,end="")
        print(luar)
    for i in range(n-1):
        print(luar,end="")
    print(luar)