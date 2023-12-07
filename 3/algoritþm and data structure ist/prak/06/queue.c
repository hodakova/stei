// NIM       : 18222082
// Nama      : Ahmad Habibie Marjan
// Tanggal   : 23年10月19日 & 23年10月20日
// Topik     : Prapraktikum 6 & Praktikum 6
// Deskripsi : Program implementasi queue.h

#include "queue.h"
#include <stdio.h>

/* *** Kreator *** */
void CreateQueue(Queue *q)
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */
{
    IDX_HEAD(*q)=IDX_UNDEF;
    IDX_TAIL(*q)=IDX_UNDEF;
}


/* ********* Prototype ********* */
boolean isEmpty(Queue q)
/* Mengirim true jika q kosong: lihat definisi di atas */
{
    return IDX_HEAD(q)==IDX_UNDEF && IDX_TAIL(q)==IDX_UNDEF;
}

boolean isFull(Queue q)
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/
{
    boolean res;
    if(IDX_TAIL(q)>=IDX_HEAD(q))
        res = IDX_TAIL(q)-IDX_HEAD(q)==CAPACITY-1;
    else
        res = IDX_HEAD(q)-IDX_TAIL(q)==1;
    return res;
}

int length(Queue q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
{
    int res;
    if(isEmpty(q))
        res = 0;
    else if(IDX_TAIL(q)>=IDX_HEAD(q))
        res = IDX_TAIL(q)-IDX_HEAD(q)+1;
    else
        res = IDX_TAIL(q)-IDX_HEAD(q)+1+CAPACITY;
    return res;
}

/* *** Primitif Add/Delete *** */
/* PRAPRAKTIKUM
void enqueue(Queue *q, ElType val) */
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */ /*
{
    if(isEmpty(*q)) {
        IDX_HEAD(*q)=0;
        IDX_TAIL(*q)=0;
    }
    else {
        IDX_TAIL(*q)++;
        IDX_TAIL(*q)%=CAPACITY;
    }
    TAIL(*q)=val;
}
*/
// PRAKTIKUM
void enqueue(Queue *q, ElType val)
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur".
        Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen q
        menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru  */
{
    if(isEmpty(*q)) {
        IDX_HEAD(*q)=0;
        IDX_TAIL(*q)=0;
    }
    else {
        if(IDX_TAIL(*q) + 1 == CAPACITY) {
            for(int i = 0; i < length(*q); i ++)
                (*q).buffer[i] = (*q).buffer[i+IDX_HEAD(*q)];
            IDX_TAIL(*q) -= IDX_HEAD(*q);
            IDX_HEAD(*q) = 0;
        }
        IDX_TAIL(*q)++;
    }
    TAIL(*q)=val;
}

void dequeue(Queue *q, ElType *val)
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */
{
    *val=HEAD(*q);
    if(IDX_HEAD(*q)==IDX_TAIL(*q)) {
        IDX_HEAD(*q)=IDX_UNDEF;
        IDX_TAIL(*q)=IDX_UNDEF;
    }
    else {
        IDX_HEAD(*q)++;
        IDX_HEAD(*q)%=CAPACITY;
    }
}


/* *** Display Queue *** */
void displayQueue(Queue q)
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */
{
    int i,l=length(q);
    printf("[");
    for(int i=0;i<l;i++) {
        printf("%d",q.buffer[(i+IDX_HEAD(q))%CAPACITY]);
        if(i<l-1)
            printf(",");
    }
    printf("]\n");
}