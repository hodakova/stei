import dt

def login():
    # Bandung Bondowoso, Roro Jonggrang, dan para jin pekerja bisa melakukan login ke dalam sistem.
    # KAMUS LOKAL
      # username, password : string
      # i : integer
    if dt.activeuser == [None,None,None]:   # belum login
        # Input username & password
        username = input("Username: ")
        password = input("Password: ")

        # cek user
        for i in range(1, dt.Nusers) :
            if (username == dt.users[i][0] and password == dt.users[i][1]) : # username & password benar
                print()
                print(f"Selamat datang, {username}!")
                dt.activeuser = dt.users[i]
                break

            elif username == dt.users[i][0]: # username ada
                print("Password salah!")
                print()
                break

            elif i == dt.Nusers - 1:
                print() # sudah mengecek semua user
                print("Username tidak terdaftar!")

    else:                                   # sudah login
        print("Login gagal!")
        print(f"Anda telah login dengan username {dt.activeuser[0]}, silahkan lakukan \"logout\" sebelum melakukan login kembali.")