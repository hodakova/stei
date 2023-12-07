#include "setlist.c"
#include <stdio.h>

int main() {
    Set s;
    printf("-1\n");
    CreateEmpty(&s); printf("0\n");
    Insert(&s, 5); printf("1\n");
    Insert(&s, 3); printf("2\n");
    Delete(&s, 2); printf("3\n");
    Delete(&s, 3); printf("4\n");

    return 0;
}