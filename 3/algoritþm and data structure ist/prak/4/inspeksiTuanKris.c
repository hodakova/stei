// NIM       : 18222082
// Nama      : Ahmad Habibie Marjan
// Tanggal   : 23年09月29日
// Topik     : Praktikum 4
// Deskripsi : Program untuk menginspeksi Toko Kris

#include <stdio.h>
#include "list.h"

int main() {
    int i, j, k, n, q, query, p, x, maks, temp;
    List a = MakeList();
    ElType v;
    scanf("%d %d", &n, &q);
    
    for(i = 0; i < n; i ++) {
        scanf("%d", &v);
        InsertLast(&a, v);
    }

    for(i = 0; i < q; i ++) {
        scanf("%d", &query);
        if(query == 0) {
            scanf("%d", &p);
            scanf("%d", &x);
            if(IsIdxEff(a, p))
                Set(&a, p, x);
        }
        else if(query == 1) {
            for(j = 0; j < Length(a); j ++) {
                printf("%d", Get(a, j));
                if(j < Length(a) -1)
                    printf(" ");
                else
                    printf("\n");
            }
        }
        else if(query == 2) {
            scanf("%d", &p);
            scanf("%d", &x);
            if(FirstIdx(a) <= p && p <= LastIdx(a))
                InsertAt(&a, x, p);
        }
        else if(query == 3) {
            scanf("%d", &p);
            if(IsIdxEff(a, p))
                DeleteAt(&a, p);
        }
        else if(query == 4) {
            if(Length(a) == 1)
                printf("%d\n", Get(a, 0));
            else if(Length(a) > 1) {
                maks = Get(a, 0);
                for(j = 0; j < Length(a); j ++) {
                    temp = 0;
                    for(k = j; k < Length(a); k ++) {
                        temp += Get(a, k);
                        if(temp > maks)
                            maks = temp;
                    }
                }
                printf("%d\n", maks);
            }
        }
    }
    return 0;
}