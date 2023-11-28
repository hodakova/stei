#include "swap.c"
#include "listdp.c"

int main() {
    List l;
    int n, i, x;
    
    CreateEmpty(&l);
    scanf("%d", &n);

    for(i = 0; i < n; i ++) {
        scanf("%d", &x);
        InsVLast(&l, x);
    }

    PrintForward(l);
    Swap(&l);
    PrintForward(l);
    return 0;
}