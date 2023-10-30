def isValid(n):
    if n>0 and n%2==1: return True
    else: return False

def GambarBTercermin(n):
    for i in range(n//2): print(" "*2*i+"*"*(n-2*i))
    for i in range(n//2, -1, -1): print(" "*2*i+"*"*(n-2*i))

n = int(input()); GambarBTercermin(n) if isValid(n) else print("salah")