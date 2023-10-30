a = int(input()); b = int(input()); c = int(input()); d = int(input())

def CekInteger(x):
    print("positif") if x>0 else print("negatif") if x<0 else print("nol")

def Max(a,b,c,d):
    return max(a,b,c,d)

def Min(a,b,c,d):
    return min(a,b,c,d)

def IsAllPositif(a,b,c,d):
    if a>0 and b>0 and c>0 and d>0: return True
    else: return False

CekInteger(a); CekInteger(b); CekInteger(c); CekInteger(d)

if IsAllPositif(a,b,c,d):
    Maxabcd = Max(a,b,c,d); Minabcd = Min(a,b,c,d)
    print(Maxabcd); print(Minabcd); print('{:.2f}'.format((a+b+c+d-Maxabcd-Maxabcd)/2))