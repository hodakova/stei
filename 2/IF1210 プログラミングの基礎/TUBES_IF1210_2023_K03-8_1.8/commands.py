import dt
from functions import F01 # Login
from functions import F02 # Logout
from functions import F03 # Summon Jin
from functions import F04 # Hilangkan Jin
from functions import F05 # Ubah Tipe Jin
from functions import F06 # Jin Pembangun
from functions import F07 # Jin Pengumpul
from functions import F08 # Batch Kumpul/Bangun
from functions import F09 # Ambil Laporan Jin
from functions import F10 # Ambil Laporan Candi
from functions import F11 # Hancurkan Candi
from functions import F12 # Ayam Berkokok
from functions import F14 # Save
from functions import F15 # Help
from functions import F16 # Exit
from functions import F_additional as F

def run(masukan):
    # run(masukan) menerima input sebuah masukan dan me-run masukannya secara bersyarat
    if masukan == "login":              #F01 - Login
        F01.login()
    elif masukan == "logout":           #F02 - Logout
        F02.logout()
    elif masukan == "summonjin":        #F03 - Summon Jin
        if dt.activeuser[2] == "bandung_bondowoso":
            F03.summonjin()
        else: F.accessdenied("Summon jin",      dt.users[1][0])
    elif masukan == "hapusjin":         #F04 - Hilangkan Jin
        if dt.activeuser[2] == "bandung_bondowoso":
            F04.hapusjin()
        else: F.accessdenied("Hilangkan jin",   dt.users[1][0])
    elif masukan == "ubahjin":          #F05 - Ubah Tipe Jin
        if dt.activeuser[2] == "bandung_bondowoso":
            F05.ubahjin()
        else: F.accessdenied("Ubah tipe jin",   dt.users[1][0])
    elif masukan == "bangun":           #F06 - Jin Pembangun
        if dt.activeuser[2] == "jin_pembangun":
            F06.bangun()
        else: F.accessdenied("Bangun candi",   "jin pembangun")
    elif masukan == "kumpul":           #F07 - Jin Pengumpul
        if dt.activeuser[2] == "jin_pengumpul":
            F07.kumpul()
        else: F.accessdenied("Kumpul bahan",   "jin pengumpul")
    elif masukan == "batchkumpul":      #F08 - Batch Kumpul
        if dt.activeuser[2] == "bandung_bondowoso":
            F08.batchkumpul()
        else: F.accessdenied("Batch kumpul",    dt.users[1][0])
    elif masukan == "batchbangun":      #F08 - Batch Bangun
        if dt.activeuser[2] == "bandung_bondowoso":
            F08.batchbangun()
        else: F.accessdenied("Batch bangun",    dt.users[1][0])
    elif masukan == "laporanjin":       #F09 - Ambil Laporan Jin
        if dt.activeuser[2] == "bandung_bondowoso":
            F09.laporanjin()
        else: F.accessdenied("Laporan jin",     dt.users[1][0])
    elif masukan == "laporancandi":     #F10 - Ambil Laporan Candi
        if dt.activeuser[2] == "bandung_bondowoso":
            F10.laporancandi()
        else: F.accessdenied("Laporan candi",   dt.users[1][0])
    elif masukan == "hancurkancandi":   #F11 - Hancurkan Candi
        if dt.activeuser[2] == "roro_jonggrang":
            F11.hancurkancandi()
        else: F.accessdenied("Hancurkan candi", dt.users[2][0])
    elif masukan == "ayamberkokok":     #F12 - Ayam Berkokok
        if dt.activeuser[2] == "roro_jonggrang":
            F12.ayamberkokok()
        else: F.accessdenied("Ayam berkokok",   dt.users[2][0])
    elif masukan == "save":             #F14 - Save
        F14.save()
    elif masukan == "help":             #F15 - Help
        F15.help()
    elif masukan == "exit":             #F16 - Exit
        F16.eksit()