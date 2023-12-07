#include "twoSum.c"
#include "listlinier.c"

int main() {
    infotype v;
    List l1, l2;

    CreateEmpty(&l1);
    scanf("%d", &v);
    while(v != 0) {
        InsVLast(&l1, v);
        scanf("%d", &v);
    }

    CreateEmpty(&l2);
    scanf("%d", &v);
    while(v != 0) {
        InsVLast(&l2, v);
        scanf("%d", &v);
    }

    printf("%d", twoSum(l1, l2));
    return 0;
}