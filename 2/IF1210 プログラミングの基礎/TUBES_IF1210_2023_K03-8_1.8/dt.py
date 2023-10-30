# module dt.py menyimpan data-data mengenai user, candi, dan bahan bangunan
# KAMUS
  # Nusers : integer (constant)
  # users : array [0..2] of array [0..102] of string/None
  # activeuser : array [0..3] of string/None
  # Ncandi : integer (constant)
  # candi : array [0..4] of array [0..999] of string/integer/None
  # bahan_bangunan : array [0..3] of string/integer

Nusers = 103 # = headline + bandung + roro + 100 jin (jumlah maks jin)
users = [] # deklarasi matrix users
activeuser = [None,None,None] # akan terisi jika sudah login

Ncandi = 1000 # perkiraan batasan id candi maksimal = 999
candi = [] # deklarawsi matrix candi

bahan_bangunan = [] # deklarasi matrix bahan bangunban