// NIM       : 18222082
// Nama      : Ahmad Habibie Marjan
// Tanggal   : 23年11月16日
// Topik     : Praktikum 10
// Deskripsi : Program implementasi listdp.h

#include "listdp.h"
#include <stdio.h>
#include <stdlib.h>

boolean IsEmpty(List L) {
    return (First(L) == Nil && Last(L) == Nil);
}

void CreateEmpty(List *L) {
    First(*L) = Nil;
    Last(*L) = Nil;
}

address Alokasi(infotype X) {
    address P = (address)malloc(sizeof(ElmtList));
    if (P != Nil) {
        Info(P) = X;
        Next(P) = Nil;
        Prev(P) = Nil;
    }
    return P;
}

void Dealokasi(address P) {
    free(P);
}

address Search(List L, infotype X) {
    address P = First(L);
    while (P != Nil) {
        if (Info(P) == X) {
            return P;
        }
        P = Next(P);
    }
    return Nil;
}

void InsVFirst(List *L, infotype X) {
    address P = Alokasi(X);
    if (P != Nil) {
        if (IsEmpty(*L)) {
            First(*L) = P;
            Last(*L) = P;
        } else {
            Next(P) = First(*L);
            Prev(First(*L)) = P;
            First(*L) = P;
        }
    }
}

void InsVLast(List *L, infotype X) {
    address P = Alokasi(X);
    if (P != Nil) {
        if (IsEmpty(*L)) {
            First(*L) = P;
            Last(*L) = P;
        } else {
            Next(Last(*L)) = P;
            Prev(P) = Last(*L);
            Last(*L) = P;
        }
    }
}

void DelVFirst(List *L, infotype *X) {
    if (!IsEmpty(*L)) {
        address P = First(*L);
        *X = Info(P);

        if (First(*L) == Last(*L)) {
            First(*L) = Nil;
            Last(*L) = Nil;
        } else {
            First(*L) = Next(P);
            Prev(First(*L)) = Nil;
        }
        Dealokasi(P);
    }
}

void DelVLast(List *L, infotype *X) {
    if (!IsEmpty(*L)) {
        address P = Last(*L);
        *X = Info(P);

        if (First(*L) == Last(*L)) {
            First(*L) = Nil;
            Last(*L) = Nil;
        } else {
            Last(*L) = Prev(P);
            Next(Last(*L)) = Nil;
        }
        Dealokasi(P);
    }
}

void InsertFirst(List *L, address P) {
    if (IsEmpty(*L)) {
        First(*L) = P;
        Last(*L) = P;
    } else {
        Next(P) = First(*L);
        Prev(First(*L)) = P;
        First(*L) = P;
    }
}

void InsertLast(List *L, address P) {
    if (IsEmpty(*L)) {
        First(*L) = P;
        Last(*L) = P;
    } else {
        Next(Last(*L)) = P;
        Prev(P) = Last(*L);
        Last(*L) = P;
    }
}

void InsertAfter(List *L, address P, address Prec) {
    if (Next(Prec) != Nil) {
        Next(P) = Next(Prec);
        Prev(Next(Prec)) = P;
    } else {
        Last(*L) = P;
    }

    Prev(P) = Prec;
    Next(Prec) = P;
}

void InsertBefore(List *L, address P, address Succ) {
    if (Prev(Succ) != Nil) {
        Prev(P) = Prev(Succ);
        Next(Prev(Succ)) = P;
    } else {
        First(*L) = P;
    }

    Next(P) = Succ;
    Prev(Succ) = P;
}

void DelFirst(List *L, address *P) {
    *P = First(*L);
    if (Next(First(*L)) == Nil) {
        CreateEmpty(L);
    } else {
        First(*L) = Next(First(*L));
        Prev(First(*L)) = Nil;
    }
}

void DelLast(List *L, address *P) {
    *P = Last(*L);
    if (Prev(Last(*L)) == Nil) {
        CreateEmpty(L);
    } else {
        Last(*L) = Prev(Last(*L));
        Next(Last(*L)) = Nil;
    }
}

void DelP(List *L, infotype X) {
    address P = Search(*L, X);
    if (P != Nil) {
        if (P == First(*L)) {
            DelFirst(L, &P);
        } else if (P == Last(*L)) {
            DelLast(L, &P);
        } else {
            address Prec = Prev(P);
            Next(Prec) = Next(P);
            Prev(Next(P)) = Prec;
        }
        Dealokasi(P);
    }
}

void DelAfter(List *L, address *Pdel, address Prec) {
    *Pdel = Next(Prec);
    Next(Prec) = Next(*Pdel);
    Prev(Next(*Pdel)) = Prec;
    Dealokasi(*Pdel);
}

void DelBefore(List *L, address *Pdel, address Succ) {
    *Pdel = Prev(Succ);
    Prev(Succ) = Prev(*Pdel);
    Next(Prev(*Pdel)) = Succ;
    Dealokasi(*Pdel);
}

void PrintForward(List L) {
    address P = First(L);
    printf("[");
    while (P != Nil) {
        printf("%d", Info(P));
        P = Next(P);
        if (P != Nil) {
            printf(",");
        }
    }
    printf("]\n");
}

void PrintBackward(List L) {
    address P = Last(L);
    printf("[");
    while (P != Nil) {
        printf("%d", Info(P));
        P = Prev(P);
        if (P != Nil) {
            printf(",");
        }
    }
    printf("]\n");
}