// NIM       : 18222082
// Nama      : Ahmad Habibie Marjan
// Tanggal   : 23年10月06日
// Topik     : Praktikum 5
// Deskripsi : Program simulasi Keyboard Rian

#include "boolean.h"
#include "mesinkata.h"
#include <stdio.h>

Word SKR(Word Kata) {
    Word RIAN, RUXAK;
    int i, j;
    for(i = 0; i < Kata.Length; i ++) {
        RIAN.TabWord[i] = Kata.TabWord[i];
        if(Kata.TabWord[i] == 'q' || Kata.TabWord[i] == 'w' || Kata.TabWord[i] == 'e' || Kata.TabWord[i] == 'r' || Kata.TabWord[i] == 't' || Kata.TabWord[i] == 'y') {
            for(j = 0; j < i; j ++)
                RUXAK.TabWord[j] = RIAN.TabWord[i-j-1];
            RUXAK.Length = i - 1;
            for(j = 0; j < i; j ++)
                RIAN.TabWord[j] = RUXAK.TabWord[j];
        }
    }
    RIAN.Length = Kata.Length;
    return RIAN;
}

void printKata(Word Kata) {
    for(int i = 0; i < Kata.Length; i ++)
        printf("%c", Kata.TabWord[i]);
}

int main() {

    STARTWORD();
    boolean awwaal = true;

    while(!isEndWord()) {
        if(awwaal)
            awwaal = false;
        else
            printf(" ");
        printKata(SKR(currentWord));
        ADVWORD();
    }

    printf(".\n");
    return 0;
}