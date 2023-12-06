// NIM       : 18222082
// Nama      : Ahmad Habibie Marjan
// Tanggal   : 23年10月19日
// Topik     : Prapraktikum 6
// Deskripsi : Program implementasi reverse.h

#include "reverse.h"

void transferReverse(Queue* q1, Queue* q2)
// Proses: Memindahkan tiap elemen q1 ke q2 dengan urutan yang terbalik
// I.S.: q1 tidak kosong, q2 kosong. q1 dan q2 memiliki panjang yang sama
// F.S.: q1 kosong, q2 berisi elemen-elemen yang tadinya milik q1 dengan urutan yang terbalik
{
    int l = Length(*q1);
    for(int i=0;i<l;i++) {
        enqueue(q2,TAIL(*q1));
        IDX_TAIL(*q1)--;
        if(IDX_TAIL(*q1)<0)
            IDX_TAIL(*q1)=IDX_MAX;
    }
    CreateQueue(q1);
}