// NIM       : 18222082
// Nama      : Ahmad Habibie Marjan
// Tanggal   : 23年10月27日
// Topik     : Praktikum 7
// Deskripsi : Program implementasi asteroid.h

#include "asteroid.h"
#include "boolean.h"
#include <stdio.h>

boolean isCollision(infotype a, infotype b)
/* Mengirim true jika terjadi tabrakan */
/* yaitu ketika a > 0 dan b < 0 */
{
    return a > 0 && b < 0;
}

void collision(int n, infotype *asteroids, Stack *remaining)
/* Proses: Mengisi stack dengan asteroid yang tersisa setelah tabrakan. 
    Asteroid dengan ukuran lebih besar tidak akan hancur, dan apabila kedua asteroid ukurannya sama maka 
    akan sama-sama hancur.  */
/* I.S Array asteroids pasti terisi dengan elemen positif atau negatif, Stack remaining telah terbentuk */
/* F.S Stack remaining terisi oleh sisa asteroid yang tidak hancur */
{
    int i, j, k;
    boolean isRemaining[n];

    for(i = 0; i < n; i ++)
        isRemaining[i] = true;

    for(i = 0; i < n; i ++) {
        for(j = 0; j < n - 1; j ++) {
            if(isRemaining[j]) {
                k = j + 1;
                while(!isRemaining[k] && k < n)
                    k ++;

                if(isRemaining[k] && isCollision(asteroids[j], asteroids[k])) {
                    if(asteroids[j] <= -asteroids[k])
                        isRemaining[j] = false;

                    if(asteroids[j] >= -asteroids[k])
                        isRemaining[k] = false;
                }
            }
        }
    }

    for(i = 0; i < n; i ++) {
        if(isRemaining[i])
            Push(remaining, asteroids[i]);
    }
}
/*
   Contoh simulasi:
   - Input: [5,10,-5]
     Output: [5,10]
     Penjelasan: 5(->) 10(->) -5(<-) Asteroid 5 dan 10 bergerak ke kanan, -5 ke kiri. Asteroid 10 lebih besar dari -5, sehingga -5 hancur.

   - Input: [-10,10]
     Output: [-10,10]
     Penjelasan: -10(<-) 10(->) Kedua asteroid bergerak ke arah berbeda dan tidak bertemu, jadi tidak ada yang hancur.

   - Input: [1,-2,10,5]
     Output: [-2,10,5]
     Penjelasan: 1(->) -2(<-) akan bertabrakan, namun asteroid -2 lebih besar sehingga asteroid 1 hancur. Lalu, -2(<-) 10(->) tidak akan bertabrakan. 5 tetap melaju karena bergerak ke arah yang sama.
*/

void displayAsteroids(Stack S)
/* Proses : mereverse isi stack dari parameter kemudian mencetak elemen-elemen stack tersebut ke layar. */
/* I.S. S boleh kosong */
/* F.S. Jika S tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen asteroid bernilai 4, 5, -2 akan dicetak: [-2,4,5] */
/* Jika Stack kosong : menulis [] */
/* Terdapat new line setelah kurung tutup */
/* Hint: Buatlah stack baru untuk meng-copy isi dari stack parameter */
{
    printf("[");

    Stack revS;
    CreateEmpty(&revS);

    infotype asteroid;

    while(!IsEmpty(S)) {
        Pop(&S, &asteroid);
        Push(&revS, asteroid);
    }

    while(!IsEmpty(revS)) {
        Pop(&revS, &asteroid);
        printf("%d",asteroid);
        if(!IsEmpty(revS))
            printf(",");
    }

    printf("]\n");
}