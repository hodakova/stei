// NIM       : 18222082
// Nama      : Ahmad Habibie Marjan
// Tanggal   : 23年11月10日
// Topik     : Praktikum 9
// Deskripsi : Program implementasi palindromeListLinier.h

#include "palindromeListLinier.h"

boolean isPalindromeList(List l)
/*
    Diberikan sebuah list linier l,
    kembalikan true jika list tersebut merupakan palindrome dan false jika tidak.
*/
{
    List linverse;
    address P, Q;
    boolean found;

    CreateEmpty(&linverse);
    P = First(l);
    while(P != Nil) {
        InsVFirst(&linverse, Info(P));
        P = Next(P);
    }

    P = First(l);
    Q = First(linverse);
    found = false;
    while(P != Nil && !found) {
        if(Info(P) != Info(Q))
            found = true;
        else {
            P = Next(P);
            Q = Next(Q);
        }
    }

    return !found;
}
/*
    Contoh input/output:
    l: [1,2,3,4,5,4,3,2,1]
    expected return: true

    Di atas merupakan palindrome list linier karena jika dibaca dari kiri maupun kanan, tetap sama.

    l: [1,1,2,1]
    expected return: false

    Di atas bukan palindrome list linier karena jika dibaca dari kiri maupun kanan, berbeda. 1,1 dan 1,2.

    P.S. List linier kosong merupakan palindrome.
*/