// NIM       : 18222082
// Nama      : Ahmad Habibie Marjan
// Tanggal   : 23年10月06日
// Topik     : Prapraktikum 5
// Deskripsi : Program implementasi mesinkarakter.h

#include <stdio.h>
#include "mesinkarakter.h"

char currentChar;
boolean EOP;
static FILE *pita;
static int retval;

void START() {
    pita = stdin;
    ADV();
}

void ADV() {
    retval = fscanf(pita, "%c", &currentChar);
    EOP = currentChar==MARK;
    if(EOP) fclose(pita);
}

char GetCC() {
    return currentChar;
}

boolean IsEOP() {
    return EOP;
}