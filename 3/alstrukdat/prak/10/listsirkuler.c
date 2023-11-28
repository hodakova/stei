// NIM       : 18222082
// Nama      : Ahmad Habibie Marjan
// Tanggal   : 23年11月17日
// Topik     : Praktikum 10
// Deskripsi : Program implementasi listsirukuler.h

#include "listsirkuler.h"
#include <stdio.h>
#include <stdlib.h>

boolean IsEmpty(List L) {
    return First(L) == Nil;
}

void CreateEmpty(List *L) {
    First(*L) = Nil;
}

address Alokasi(infotype X) {
    address P = (address)malloc(sizeof(ElmtList));
    if (P != Nil) {
        Info(P) = X;
        Next(P) = Nil;
    }
    return P;
}

void Dealokasi(address P) {
    free(P);
}

address Search(List L, infotype X) {
    address P = First(L);
    if (!IsEmpty(L)) {
        do {
            if (Info(P) == X) {
                return P;
            }
            P = Next(P);
        } while (P != First(L));
    }
    return Nil;
}

void InsVFirst(List *L, infotype X) {
    address P = Alokasi(X);
    if (P != Nil) {
        InsertFirst(L, P);
    }
}

void InsVLast(List *L, infotype X) {
    address P = Alokasi(X);
    if (P != Nil) {
        if (IsEmpty(*L)) {
            InsertFirst(L, P);
        } else {
            InsertLast(L, P);
        }
    }
}

void DelVFirst(List *L, infotype *X) {
    if (!IsEmpty(*L)) {
        address P = First(*L);
        *X = Info(P);
        if (Next(P) == First(*L)) {
            CreateEmpty(L);
        } else {
            DelFirst(L, &P);
            Dealokasi(P);
        }
    }
}

void DelVLast(List *L, infotype *X) {
    if (!IsEmpty(*L)) {
        address P = First(*L);
        address Prec = Nil;
        while (Next(P) != First(*L)) {
            Prec = P;
            P = Next(P);
        }
        *X = Info(P);
        if (Prec == Nil)
            CreateEmpty(L);
        else {
            DelLast(L, &P);
            Dealokasi(P);
        }
    }
}

void InsertFirst(List *L, address P) {
    if (IsEmpty(*L))
        Next(P) = P;
    else {
        address Last = First(*L);
        while (Next(Last) != First(*L)) {
            Last = Next(Last);
        }
        Next(P) = First(*L);
        Next(Last) = P;
    }
    First(*L) = P;
}

void InsertLast(List *L, address P) {
    if (IsEmpty(*L))
        InsertFirst(L, P);
    else {
        address Last = First(*L);
        while (Next(Last) != First(*L)) {
            Last = Next(Last);
        }
        Next(P) = First(*L);
        Next(Last) = P;
    }
}

void InsertAfter(List *L, address P, address Prec) {
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void DelFirst(List *L, address *P) {
    *P = First(*L);
    if (Next(First(*L)) == First(*L))
        CreateEmpty(L);
    else {
        address Last = First(*L);
        while (Next(Last) != First(*L)) {
            Last = Next(Last);
        }
        First(*L) = Next(First(*L));
        Next(Last) = First(*L);
    }
}

void DelLast(List *L, address *P) {
    if (Next(First(*L)) == First(*L))
        DelFirst(L, P);
    else {
        address Last = First(*L);
        address PrecLast = Nil;
        while (Next(Last) != First(*L)) {
            PrecLast = Last;
            Last = Next(Last);
        }
        *P = Last;
        Next(PrecLast) = First(*L);
    }
}

void DelAfter(List *L, address *Pdel, address Prec) {
    *Pdel = Next(Prec);
    Next(Prec) = Next(*Pdel);
}

void DelP(List *L, infotype X) {
    if (!IsEmpty(*L)) {
        address P = Search(*L, X);
        while (P != Nil) {
            if (P == First(*L))
                DelFirst(L, &P);
            else {
                address PrecP = First(*L);
                while (Next(PrecP) != P) {
                    PrecP = Next(PrecP);
                }
                DelAfter(L, &P, PrecP);
                Dealokasi(P);
            }
            P = Search(*L, X);
        }
    }
}

void PrintInfo(List L) {
    printf("[");
    if (!IsEmpty(L)) {
        address P = First(L);
        do {
            printf("%d", Info(P));
            if (Next(P) != First(L))
                printf(",");
            P = Next(P);
        } while (P != First(L));
    }
    printf("]");
}