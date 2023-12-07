// NIM       : 18222082
// Nama      : Ahmad Habibie Marjan
// Tanggal   : 23年09月29日
// Topik     : Praktikum 4
// Deskripsi : Program implementasi array.h

#include "arrayMenu.h"
#include <stdio.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MakeEmpty (TabMenu *T)
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
{
    (*T).Neff = 0;
}

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabMenu T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
{
    return T.Neff;
}
/* *** Daya tampung container *** */
int MaxNbEl (TabMenu T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
{
    return IdxMax - IdxMin + 1;
}
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabMenu T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
{   
    return IdxMin;
}
IdxType GetLastIdx (TabMenu T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
{
    return T.Neff;
}
/* *** Menghasilkan sebuah elemen *** */
ElType GetElmt (TabMenu T, IdxType i)
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
{
    return T.TI[i];
}
/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
void SetTab (TabMenu Tin, TabMenu *Tout)
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
/* Assignment THsl -> Tin */
{
    (*Tout).Neff = Tin.Neff;
    for(int i = IdxMin; i <= Tin.Neff; i++)
        (*Tout).TI[i] = Tin.TI[i];
}
void SetEl (TabMenu *T, IdxType i, ElType v)
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
{
    (*T).TI[i] = v;
    if ((*T).Neff < i)
        (*T).Neff = i;
}
void SetNeff (TabMenu *T, IdxType N)
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
{
    (*T).Neff = N;
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabMenu T, IdxType i)
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
{
    return ((i >= IdxMin) && (i <= IdxMax));
}
boolean IsIdxEff (TabMenu T, IdxType i)
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
{
    return ((i >= GetFirstIdx(T)) && (i <= GetLastIdx(T)));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabMenu T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
{
    return (T.Neff == 0);
}
/* *** Test tabel penuh *** */
boolean IsFull (TabMenu T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
/* Untuk membantu pengerjaan praktikum, silahkan gunakan kode berikut untuk fungsi ini */
{
    return (T.Neff == IdxMax);
}






/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void TulisIsi (TabMenu T)
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : elemen tabel ditulis berderet ke bawah dengan format */
/* Nama - Tipe - Harga */
/* Contoh
Nasi goreng - Makanan - Rp.15000
Nasi goreng spesial - Makanan - Rp.20000
Jus Mangga - Minuman - Rp.10000
*/
/* Jika T kosong : Hanya menulis "Tabel kosong" */
{
    if(IsEmpty(T))
        printf("Tabel kosong\n");
    else {
        for(int i = GetFirstIdx(T); i <= GetLastIdx(T); i ++) {
            printf("%s - %s - Rp.%d\n", GetElmt(T, i).nama, GetElmt(T, i).tipe, GetElmt(T, i).harga);
        }
    }
}

/* ********** KONSTRUKTUR MENU ********** */
ElType MakeMenu (char *nama, char *tipe, int harga)
/* Membuat sebuah Menu dengan komponen-komponennya */
/* I.S. Nama, Tipe, dan Harga terdefinisi */
/* F.S. Terbentuk Menu baru */
{
    ElType el;
    el.nama = nama;
    el.tipe = tipe;
    el.harga = harga;
    return el;
}

/* ********** NILAI EKSTREM ********** */
int MenuMax (TabMenu T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai maksimum harga menu */
{
    int i, maks = GetElmt(T, GetFirstIdx(T)).harga;;
    for(i = GetFirstIdx(T)+1; i <= GetLastIdx(T); i ++) {
        if(GetElmt(T, i).harga > maks)
            maks = GetElmt(T, i).harga;
    }
    return maks;
}
int MenuMin (TabMenu T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai minimum harga menu */
{
    int i, mins = GetElmt(T, GetFirstIdx(T)).harga;;
    for(i = GetFirstIdx(T)+1; i <= GetLastIdx(T); i ++) {
        if(GetElmt(T, i).harga < mins)
            mins = GetElmt(T, i).harga;
    }
    return mins;
}
int MakananCount (TabMenu T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan banyaknya menu makanan */
{
    int i, count = 0;
    for(i = GetFirstIdx(T); i <= GetLastIdx(T); i ++) {
        if(GetElmt(T, i).tipe[0] == 'M' && GetElmt(T, i).tipe[1] == 'a')
            count ++;
    }
    return count;
}
int MinumanCount (TabMenu T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan banyaknya menu minuman */
{
    int i, count = 0;
    for(i = GetFirstIdx(T); i <= GetLastIdx(T); i ++) {
        if(GetElmt(T, i).tipe[0] == 'M' && GetElmt(T, i).tipe[1] == 'i')
            count ++;
    }
    return count;
}
void MenuData (TabMenu T)
/* Prekondisi : Tabel T tidak kosong */
/* Menampilkan data menu */
/* Contoh */
/* Jumlah Menu Makanan: 10 */
/* Jumlah Menu Minuman: 3 */
/* Harga Menu Termahal: Rp.30000 */
/* Harga Menu Termurah: Rp.10000 */
{
    printf("Jumlah Menu Makanan: %d\n", MakananCount(T));
    printf("Jumlah Menu Minuman: %d\n", MinumanCount(T));
    printf("Harga Menu Termahal: Rp.%d\n", MenuMax(T));
    printf("Harga Menu Termurah: Rp.%d\n", MenuMin(T));
}
// 5,6,7
// 10