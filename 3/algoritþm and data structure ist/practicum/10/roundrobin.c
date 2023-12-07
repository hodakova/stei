// NIM       : 18222082
// Nama      : Ahmad Habibie Marjan
// Tanggal   : 23年11月17日
// Topik     : Praktikum 10
// Deskripsi : Program realisasi

#include "listsirkuler.h"
#include <stdio.h>

void deleteRR (List *l, infotype tQ)
/* Jika l tidak kosong, "menghapus" elemen terakhir list l, misal last, sesuai aturan round robin, yaitu:
- jika Info(last)>tQ, maka last "diantrikan" kembali sebagai first elemen dengan Info(last)=Info(last)-tQ
- jika Info(last)<=tQ, maka DelVLast(l,x) dan menampilkan x ke layar */
/* Jika l kosong, cetak "List kosong" */
/* I.S. tQ terdefinisi sebagai nilai time slice pemrosesan.
L terdefinisi, mungkin kosong. */
/* F.S. Elemen terakhir l diproses sesuai aturan round-robin.
l mungkin menjadi kosong. */
{
    if (IsEmpty(*l))
        printf("List kosong\n");
    else {
        infotype t;
        DelVLast(l, &t);

        if (t > tQ) {
            printf("%d\n", tQ);
            InsVFirst(l, t - tQ);
        }
        else
            printf("%d\n", t);
    }
}

float average (List l)
/* Menghasilkan nilai rata-rata elemen l. l tidak kosong. */
{
    if (IsEmpty(l))
        return 0.0;
    else {
        address P = First(l);
        int sum = Info(P);
        int count = 1; 

        P = Next(P);

        while (P != First(l)) {
            sum += Info(P);
            count++;
            P = Next(P);
        }
        return (float)sum / count;
    }
}

/* Pengerjaan Soal */
int main() {
    List l;
    infotype tQ, t;
    char code;

    CreateEmpty(&l);

    do {
        scanf("%d", &tQ);
    } while(tQ <= 0);

    while(true) {
        scanf(" %c", &code);

        if (code == 'A') {
            scanf("%d", &t);
            if (t > 0)
                InsVFirst(&l, t);
        }
        else if (code == 'D')
            deleteRR(&l, tQ);
        else if (code == 'F') {
            if (!IsEmpty(l))
                printf("%.2f\n", average(l));
            else
                printf("Proses selesai\n");
            return 0;
        }
        else
            printf("Kode salah\n");
    }

}