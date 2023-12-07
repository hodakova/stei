#include "remove.c"
#include "listlinier.c"

int main() {
    List L; CreateEmpty(&L);
    infotype X;
    do {
        scanf("%d", &X);
        if(X != 0)
            InsVLast(&L, X);
    } while(X != 0);
    PrintInfo(L);

    RemoveDuplicates(&L);
    PrintInfo(L);

    while(!IsEmpty(L)) {
        DelVLast(&L, &X);
    }
    return 0;
}