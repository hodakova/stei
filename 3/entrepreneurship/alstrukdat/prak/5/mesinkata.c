// NIM             : 18222082
// Nama            : Ahmad Habibie Marjan
// Tanggal         : 23-10-06
// Topik praktikum : Prapraktikum 5
// Deskripsi       : Program implementasi mesinkata.h

#include <stdio.h>
#include "mesinkata.h"
#include "boolean.h"
#include "mesinkarakterv2.h"

Word currentWord;
boolean EndWord;

void IgnoreBlanks() {
    while((currentChar==BLANK) && (currentChar!=MARK)) {
        ADV();
    }
}

void STARTWORD() {
    START();
    IgnoreBlanks();
    if(currentChar==MARK) EndWord=true;
    else {
        EndWord = false;
        ADVWORD();
    }
}

void ADVWORD() {
    IgnoreBlanks();
    if(currentChar == MARK) EndWord = true;
    else {
        EndWord = false;
        CopyWord();
        IgnoreBlanks();
    }
}

void CopyWord() {
    int i = 0;
    while((currentChar!=BLANK) && (currentChar!=MARK)) {
        if(i<NMax) {
            currentWord.TabWord[i] = currentChar;
            i++;     
        }
        ADV();
    }
    currentWord.Length = i;
}