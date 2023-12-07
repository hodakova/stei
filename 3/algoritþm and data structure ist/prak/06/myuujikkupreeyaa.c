// NIM       : 18222082
// Nama      : Ahmad Habibie Marjan
// Tanggal   : 23年10月20日
// Topik     : Praktikum 6
// Deskripsi : Program realisasi simulasi pemutar lagu

#include "circular_queue.h"
#include <stdio.h>
#include "boolean.h"

int main() {
    int n, m, i, j, op, p;
    boolean validdo = true, luupu = false;
    Queue kyuu;
    CreateQueue(&kyuu);
    ElType myuujikku;

    scanf("%d %d", &n, &m);
    int pureirisuto[m][3];

    for(i = 0; i < m; i ++) {
        for(j = 0; j < 3; j ++)
            scanf("%d", &pureirisuto[i][j]);
    }

    for(i = 0; i < m; i ++) {
        for(j = 0; j < 3; j ++)
            if(pureirisuto[i][j] < 0 || pureirisuto[i][j] > n-1)
                validdo = false;
    }

    if(validdo) {
        while(true) {
            scanf("%d", &op);

            if(op == 1) /*playnext*/ {
                if(IsEmpty(kyuu))
                    printf("Tidak ada lagu\n");
                
                else {
                    myuujikku = dequeue(&kyuu);
                    printf("Play lagu %d\n", myuujikku);
                    if(luupu)
                        enqueue(&kyuu, myuujikku);
                }
            }

            else if(op == 2) /*loop*/ {
                if(luupu) {
                    luupu = false;
                    printf("Tidak looping lagu\n");
                }

                else {
                    luupu = true;
                    printf("Looping lagu\n");
                }
            }

            else if(op == 3) /*enqueue*/ {
                scanf("%d", &myuujikku);

                if(IsFull(kyuu))
                    printf("Queue penuh\n");

                else {
                    if(myuujikku >= 0 && myuujikku < n)
                        enqueue(&kyuu, myuujikku);

                    else
                        printf("Lagu tidak valid\n");
                }
                    
            }

            else if(op == 4) /*enqueue playlist*/ {
                scanf("%d", &p);

                if(p >=0 && p < m) {
                    for(i = 0; i < 3; i ++) {     
                        if(IsFull(kyuu)) {
                            printf("Queue penuh\n");
                            break;
                        }
                        else
                            enqueue(&kyuu, pureirisuto[p][i]);
                    }
                }

                else
                    printf("Playlist tidak valid\n");
            }

            else if(op == 0) /*leave*/
                break;
        }
    }

    else
        printf("Playlist tidak valid\n");

    return 0;
}