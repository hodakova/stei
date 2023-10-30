// NIM       : 18222082
// Nama      : Ahmad Habibie Marjan
// Tanggal   : 23年09月19日
// Topik     : Prapraktikum 3
// Deskripsi : Program implementasi point.h

#include <stdio.h>
#include <math.h>
#include "point.h"

POINT MakePOINT (float X, float Y) {
    POINT P;
    Absis(P)=X;
    Ordinat(P)=Y;
    return P;
}

void BacaPOINT (POINT * P) {
    float X, Y;
    scanf("%f %f", &X, &Y);
    *P = MakePOINT(X, Y);
}

void TulisPOINT (POINT P) {
    printf("(%.2f,%.2f)", P.X, P.Y);
}

boolean EQ (POINT P1, POINT P2) {
    return P1.X==P2.X && P1.Y==P2.Y;
}

boolean NEQ (POINT P1, POINT P2) {
    return P1.X!=P2.X || P1.Y!=P2.Y;
}

boolean IsOrigin (POINT P) {
    return P.X==0 && P.Y==0;
}

boolean IsOnSbX (POINT P) {
    return P.Y==0;
}

boolean IsOnSbY (POINT P) {
    return P.X==0;
}

int Kuadran (POINT P) {
    if(P.X>0) {
        if(P.Y>0) return 1;
        else return 4;
    }
    else {
        if(P.Y>0) return 2;
        else return 3;
    }
}

POINT PlusDelta (POINT P, float deltaX, float deltaY) {
    return MakePOINT(P.X+deltaX, P.Y+deltaY);
}

void Geser (POINT *P, float deltaX, float deltaY) {
    Absis(*P) += deltaX;
    Ordinat(*P) += deltaY;
}

float Jarak0 (POINT P) {
    return sqrt(P.X*P.X + P.Y*P.Y);
}

float Panjang (POINT P1, POINT P2) {
    return sqrt(pow(P2.X-P1.X,2)+pow(P2.Y-P1.Y,2));
}