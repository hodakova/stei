// NIM       : 18222082
// Nama      : Ahmad Habibie Marjan
// Tanggal   : 23年11月03日
// Topik     : Praktikum 8
// Deskripsi : Program implementasi warehouse.h

#include "warehouse.h"
#include <stdio.h>

void manageWareHouse(Map *wareHouse)
/*
I.S. variable wareHouse sudah terisi dengan bahan-bahan

Buatlah program yang melakukan pengelolaan terhadap gudang bahan makanan. Program akan menerima input sebuah integer antara angka 1 hingga 4. Program akan berhenti apabila input yang diterima bernilai 4.

Untuk keterangan input dan bagaimana proses pengelolaan, dapat dilihat dalam soal
*/
{
    int i, j, inp, n;
    valuetype v;
    do {
        scanf("%d", &inp);

        if(inp == 1) {
            for(i = 1; i <= (*wareHouse).Count; i ++)
                printf("Bahan %d: %d\n", i, Value(*wareHouse, i));
        }
        else if(inp == 2) {
            scanf("%d", &n);
            n = reverseint(n);
            while(n > 0) {
                j = n % 10;
                n /= 10;
                v = Value(*wareHouse, j);
                if(v > 0) {
                    v --;
                    Delete(wareHouse, j);
                    Insert(wareHouse, j, v);
                }
                else
                    printf("Stok bahan %d sudah habis\n", j);
            }
        }
        else if(inp == 3) {
            scanf("%d", &n);
            n = reverseint(n);
            while(n > 0) {
                j = n % 10;
                n /= 10;
                v = Value(*wareHouse, j);
                v ++;
                Delete(wareHouse, j);
                Insert(wareHouse, j, v);
            }
        }
    } while(inp != 4);
}

int reverseint(int n) {
    int rev = 0, x = 0, s = n;
    while(s > 0) {
        s /= 10;
        if(x == 0)
            x = 1;
        else
            x *= 10;
    }
    s = n;
    while(s > 0) {
        rev += s % 10 * x;
        s /= 10;
        x /= 10;
    }
    return rev;
}