// NIM       : 18222082
// Nama      : Ahmad Habibie Marjan
// Tanggal   : 23年11月17日
// Topik     : Praktikum 10
// Deskripsi : Program implementasi swap.h

#include "swap.h"

address AddressAtIndex(List L, infotype x)
/* 
Mencari address suatu node pada element ke- X
*/
{
    address P = First(L);
    for(int i = 1; i < x; i ++)
        P = Next(P);
    return P;
}

void Swap(List *L1)
/*
Kondisi awal: L1 sudah terisi dengan beberapa node.
Lakukan swap node pada node yang ada di tengah dari suatu List
*/
{
    int a, b, tmp; scanf("%d %d", &a, &b);
    
    if(a > b) {
        tmp = a;
        a = b;
        b = tmp;
    }

    address P = AddressAtIndex(*L1, a), Q = AddressAtIndex(*L1, b);

    address prevP = Prev(P), nextP = Next(P);
    address prevQ = Prev(Q), nextQ = Next(Q);

    if(b - a == 1) {
        Next(prevP) = Q;
        Prev(Q) = prevP;

        Next(Q) = P;
        Prev(P) = Q;

        Next(P) = nextQ;
        Prev(nextQ) = P;
    }

    else {
        Prev(Q) = prevP; Next(Q) = nextP;
        Next(prevP) = Q; Prev(nextP) = Q;

        Prev(P) = prevQ; Next(P) = nextQ;
        Next(prevQ) = P; Prev(nextQ) = P;
    }
}