a = int(input()); b = int(input())
if a<0 or b<0: print("tidak dapat dihitung")
else:
    if a>b: a,b = b,a
    if a%2==1: a+=1
    result = 0
    while b>=a:
        result+=a; a+=2
    print(result)