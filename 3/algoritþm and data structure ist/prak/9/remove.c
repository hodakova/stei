// NIM       : 18222082
// Nama      : Ahmad Habibie Marjan
// Tanggal   : 23年11月09日
// Topik     : Prapraktikum 9
// Deskripsi : Program implementasi remove.h

#include "remove.h"

void RemoveDuplicates(List *L)
/*
I.S. Variable L sudah terisi dengan nilai
Melakukan penghapusan apabila terdapat nilai yang sama
*/
{
    if(!IsEmpty(*L)) { 
        address P = First(*L), Q, dump;
        while(Next(P) != Nil) {
            Q = P;
            while(Next(Q) != Nil) {
                if(Info(P) == Info(Next(Q))) {
                    DelAfter(L, &dump, Q);
                    Dealokasi(&dump);
                }
                else
                    Q = Next(Q);
            }
            if(Next(P) != Nil)
                P = Next(P);
        }
    }
}
/*
Contoh:
Input: [1,1,2,3]
Output: [1,2,3]

Input: [1,2,3,1]
Output: [1,2,3]
*/