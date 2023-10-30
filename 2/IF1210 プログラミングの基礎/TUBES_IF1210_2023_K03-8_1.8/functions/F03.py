import dt
from functions import F_additional as F

def summonjin():
    if (F.totalusers("jin_pembangun") + F.totalusers("jin_pengumpul")) < 100:
        # Pilihan jenis-jenis jin
        print("Jenis jin yang dapat dipanggil:")
        print(" (1) Pengumpul - Bertugas mengumpulkan bahan bangunan")
        print(" (2) Pembangun - Bertugas membangun candi")
        print()
        # Input jin yang ingin di-summon
        while True:
            jenis = str(input("Masukkan nomor jenis jin yang ingin dipanggil: "))
            print()
            if jenis == "1" or jenis == "2":
                break
            else:
                print(f"Tidak ada jenis jin bernomor \"{jenis}\"!")
                print()
        if jenis == "1":
            jenis_jin = "Pengumpul"
            role = "jin_pengumpul"
        else:
            jenis_jin = "Pembangun"
            role = "jin_pembangun"
        print(f"Memilih jin \"{jenis_jin}\".")
        print()
        # Mengecek apakah username yang di-input sudah ada atau belum
        while True:
            username = input("Masukkan username jin: ")
            TheUsernameAvailable = True
            for i in range(1, dt.Nusers):
                if username == dt.users[i][0]:
                    TheUsernameAvailable = False
            if not TheUsernameAvailable:
                print()
                print(f"Username \"{username}\" sudah diambil!")
                print()
            else: # username tersedia
                break
        
        # Mengecek apakah password yang di-input sesuai dengan syarat atau tidak
        while True:
            password = input("Masukkan password jin (5-25 karakter): ")
            print() 
            if len(password) < 5 or len(password) > 25:
                print("Password panjangnya harus 5-25 karakter!")
                print()
            else: # password sudah betul
                break
            
        # Proses summon jin
        print("Mengumpulkan sesajen...")
        print("Menyerahkan sesajen...")
        print("Membacakan mantra...")
        print()
        print(f"Jin {username} berhasil dipanggil!")
        
        # Memasukkan username & password jin yang telah di-summon ke dalam database
        for i in range(dt.Nusers):
            if dt.users[i] == [None,None,None]:
                dt.users[i] = [username,password,role]
                break
    
    # Menolak untuk summon jin apabila sudah mencapai limit 100
    else:
        print("Jumlah Jin telah maksimal! (100 jin). Bandung tidak dapat men-summon lebih dari itu")