// NIM       : 18222082
// Nama      : Ahmad Habibie Marjan
// Tanggal   : 23年10月27日
// Topik     : Praktikum 7
// Deskripsi : Program pemutar musik baru

#include "stack.h"
#include "boolean.h"
#include <stdio.h>

int main() {
    int i, n, x, op, a;

    Stack recently_played;
    CreateEmpty(&recently_played);

    scanf("%d", &n);
    char music[n][20];
    for(i = 0; i < n; i ++)
        scanf("%s", music[i]);
    
    scanf("%d", &x);
    for(i = 0; i < x; i ++) {
        scanf("%d", &op);

        if(op == 1) {
            scanf("%d", &a);
            Push(&recently_played, a);
            printf("Playing: %s\n", music[InfoTop(recently_played)]);
        }

        else if(op == 2) {
            if(!IsEmpty(recently_played)) 
                Pop(&recently_played, &a);
             
            if(IsEmpty(recently_played))
                printf("No music is played\n");
            else
                printf("Playing: %s\n", music[InfoTop(recently_played)]);
        }
    }

    return 0;
}