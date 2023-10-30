NMax = 100
TabInt = [0 for i in range(NMax)]
N = 2
T = [5,3]

def FindMin(T, N):
    i = 0
    j = i
    MIN = T[i]
    while i<N-1:
        if T[i+1]<MIN:
            j = i+1
            MIN = T[j]
        i = i+1
    return (MIN, j)

MIN, j = FindMin(T, N)
print(MIN, j)