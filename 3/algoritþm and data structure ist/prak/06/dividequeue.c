// NIM       : 18222082
// Nama      : Ahmad Habibie Marjan
// Tanggal   : 23年10月20日
// Topik     : Praktikum 6
// Deskripsi : Program implementasi dividequeue.h

#include "dividequeue.h"

// Membagi queue.
void divideQueue(Queue *queue, Queue *oddQueue, Queue *evenQueue)
/* Proses: Membagi isi dari queue ke oddQueue untuk elemen ganjil dan evenQueue untuk elemen genap */
/* I.S. queue mungkin kosong, tabel penampung elemen queue TIDAK penuh */
/* F.S. oddQueue memiliki isi queue elemen ganjil, evenQueue memiliki isi queue elemen genap */
{
    int i, iHead = IDX_HEAD(*queue), l = length(*queue);
    ElType val;
    Queue temp;
    CreateQueue(&temp);

    if(!isEmpty(*queue)) {
        for(i = 0; i < l; i ++) {
            dequeue(queue, &val);
            if(val % 2 == 0)
                enqueue(evenQueue, val);
            else
                enqueue(oddQueue, val);
            enqueue(&temp, val);
        }

        dequeue(&temp, &val);
        IDX_HEAD(*queue) = iHead;
        IDX_TAIL(*queue) = iHead;
        TAIL(*queue) = val;
        for(i = 1; i < l; i ++) {
            dequeue(&temp, &val);
            enqueue(queue, val);
        }
    }
}
/*
    Contoh input:
    queue : [2,3,4,5,6] // 2 adalah head, 6 adalah tail
    oddQueue: queue kosong
    evenQueue: queue kosong

    Contoh output:
    queue:  [2,3,4,5,6]
    oddQueue: [3,5]
    evenQueue: [2,4,6]
*/

/*
    Catatan
    - Hati-hati jangan sampai algoritma Anda mengubah hasil akhir dari queueInput juga.
      Elemen di queueInput harus tetap sama setelah algoritma dijalankan.
    Hint
    - Buat queue baru selain queue, oddQueue, dan evenQueue untuk tempat penyimpanan
      queue sementara.
*/
