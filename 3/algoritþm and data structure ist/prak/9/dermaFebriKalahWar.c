// NIM       : 18222082
// Nama      : Ahmad Habibie Marjan
// Tanggal   : 23年11月10日
// Topik     : Praktikum 9
// Deskripsi : Program realisasi derma untuk Febri yang kalah war

#include "listlinier.h"
#include <stdio.h>

int main() {
    List lagu, testKejujuran;
    infotype id;
    boolean isPoser;
    int count;
    address P, Q;

    CreateEmpty(&lagu);
    scanf("%d", &id);
    while(id != -99) {
        InsVLast(&lagu, id);
        InsVLast(&testKejujuran, id);
        scanf("%d", &id);
    }



    isPoser = false;
    count = 0;
    scanf("%d", &id);
    while(count < NbElmt(lagu) && !isPoser) {
        P = Search(lagu, id);
        Q = Search(testKejujuran, id);
        if(P != Nil) {
            if(Q != Nil) {
                count ++;
                Info(Q) = -99;
            }
            if(count < NbElmt(lagu))
                scanf("%d", &id);
        }
        else
            isPoser = true;
    }

    if(isPoser)
        printf("Poser! %d tidak ada di dalam album\n", id);
    else
        printf("Berhasil menebak %d lagu\n", count);

    return 0;
}