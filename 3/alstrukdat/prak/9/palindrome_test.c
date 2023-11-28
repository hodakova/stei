#include "palindromeListLinier.c"
#include "listlinier.c"
#include <stdio.h>

int main() {
    infotype v;
    List l;

    CreateEmpty(&l);
    scanf("%d", &v);
    while(v != 0) {
        InsVLast(&l, v);
        scanf("%d", &v);
    }

    printf("%d", isPalindromeList(l));
    return 0;
}