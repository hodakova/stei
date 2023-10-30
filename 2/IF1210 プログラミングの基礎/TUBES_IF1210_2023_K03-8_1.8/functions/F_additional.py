# F_additional.py merupakan module yang menyimpan fungsi-fungsi tambahan
import dt

def totalusers(role):
    # totalusers(role) menerima input role dari user, dan
    # mengeluarkan output total pemegang role tersebut
    # KAMUS LOKAL
      # role : string
      # count, i : integer
    count = 0
    for i in range(1,dt.Nusers):
        if dt.users[i][2] == role: count += 1
    return count

def efflen(array,nmax,none):
    # efflen(array,nmax,none) menerima input array, nmax (indeks maksimal + 1), dan none (sebagai tanda bahwa elementnya kosong) dan
    # mengeluarkan output nilai effective dari array tersebut
    # KAMUS LOKAL
      # array : array [0...nmax]
      # nmax, count : integer
      # none : None / [None in range(i)] dengan i integer
    count = nmax
    for i in range(nmax-1,0,-1):
        if array[i] == none: count -= 1
        else: break
    return count

def accessdenied(function, allowedaccount):
    # accessdenied(function, allowedaccount) menerima dua string function dan allowedaccount
    # mengeluarkan pesan pernyataan akses ditolak ke layar
    # KAMUS LOKAL
    # function, allowedaccount : string
    print(f"{function} hanya dapat diakses oleh akun {allowedaccount}.")