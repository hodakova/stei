#include "OddEvenList.h"

int main() {
    List L, Lodd, Leven;
    CreateEmpty(&L); CreateEmpty(&Lodd); CreateEmpty(&Leven);
    infotype v;
    do {
        scanf("%d", &v);
        if(v != -1)
            InsertLast(&L, Alokasi(v));
    } while(v != -1);
    OddEvenList(L, &Lodd, &Leven);
    PrintInfo(L); PrintInfo(Lodd); PrintInfo(Leven);
    return 0;
}