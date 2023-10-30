def isValid(n):
    if n>0 and n%2==1: return True
    else: return False

def GambarBelahKetupat(n):
    for i in range(n//2): print(" "*(n//2-i)+"*"*(2*i+1))
    for i in range(n//2,-1,-1): print(" "*(n//2-i)+"*"*(2*i+1))

n = int(input()); GambarBelahKetupat(n) if isValid(n) else print("salah")