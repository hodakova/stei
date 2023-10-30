// NIM       : 18222082
// Nama      : Ahmad Habibie Marjan
// Tanggal   : 23年10月24日
// Topik     : Prapraktikum 7
// Deskripsi : Program implementasi dividestack.h

#include "dividestack.h"

void divideStack(Stack *s, Stack *oddS, Stack *evenS)
/*
Memisahkan nilai genap dan nilai ganjil dari Stack s.

Awal:
s: 1,2,3,4
evenS:
oddS:

Akhir:
s: 
evenS 2,4
oddS: 1,3

Perhatikan order di dalam stacknya

*/
{
    infotype x;
    Stack revS;
    CreateEmpty(&revS);
    CreateEmpty(oddS);
    CreateEmpty(evenS);

    while(!IsEmpty(*s)) {
        Pop(s, &x);
        Push(&revS, x);
    } // terbentuk revS yg merupakan reverse s
    while(!IsEmpty(revS)) {
        Pop(&revS, &x);
        if(x %2 == 0)
            Push(evenS, x);
        else
            Push(oddS, x);
    }
}
/*  //test
#include <stdio.h>

void printS(Stack s) {
    int i, l = Top(s);
    
    for(i = 0; i <= (l+2)*2; i ++)
        printf("-");
    printf("\n");
    
    printf("| ");
    for(i = 0; i <= l; i++)
        printf("%d ", s.T[i]);
    printf("\n");

    for(i = 0; i <= (l+2)*2; i ++)
        printf("-");
    printf("\n");

    printf("\n");
    
}

int main() {
    Stack s, evenS, oddS;
    CreateEmpty(&s);
    int i;

    for(i = 1; i <= 4; i ++)
        Push(&s, i);
    printS(s);

    divideStack(&s, &oddS, &evenS);
    printS(s);
    printS(evenS);
    printS(oddS);

    return 0;
}
*/