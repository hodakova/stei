def isValid(n):
    if n>0 and n%2==1: return True
    else: return False

def GambarPita(n):
    for i in range(n//2): print(" "*i+"*"*(n-2*i))
    for i in range(n//2, -1, -1): print(" "*i+"*"*(n-2*i))

n = int(input()); GambarPita(n) if isValid(n) else print("salah")