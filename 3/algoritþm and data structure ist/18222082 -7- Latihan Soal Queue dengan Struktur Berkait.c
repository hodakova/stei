/*20231103 - Latihan Soal Priority Queue*/
/*18222082 - Ahmad Habibie Marjan*/

/*Implementasikan prosedur Enqueue dan Dequeue (dalam Bahasa C) pada priority queue
sesuai dengan priorityqueuelist.h*/

#include "priorityqueuelist.h"

/*** Primitif Enqueue/Dequeue ***/
void enqueue(PrioQueue *q, ElType x, int pr)
/* Proses: Mengalokasi x dengan prio pr dan menambahkan x pada q
           jika alokasi berhasil; jika alokasi gagal q tetap */
/* I.S. q mungkin kosong */
/* F.S. x menjadi elemen q sesuai dengan urutan prioritas */
{
    address p = (*q).addrHead, n = newNode(x, pr);
    if(n != Nil) {
        while(p != Nil) {
            if ((*p).next != Nil) {
                if((*(*p).next).prio >= pr)
                    p = (*p).next;
                else
                    break;
            }
            else
                break;
        }
        (*n).next = (*p).next;
        (*p).next = n;
    }
}

void dequeue(PrioQueue *q, ElType *x, int *pr)
/* Proses: Menghapus x pada bagian HEAD dari q dan mendealokasi elemen HEAD */
/* Pada dasarnya operasi deleteFirst */
/* I.S. q tidak mungkin kosong */
/* F.S. x = nilai elemen HEAD pd I.S., HEAD "mundur" */
{
    address p = (*q).addrHead;
    *x = (*p).info;
    *pr = (*p).prio;
    (*q).addrHead = (*p).next;
    delNode(p);
}