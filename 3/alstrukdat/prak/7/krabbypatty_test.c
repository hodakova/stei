#include "krabbypatty.h"
#include "stack.h"
#include <stdio.h>
#include "asteroid.h"

int main() {
    int i, n;
    infotype bahan;
    Stack ingredients, burger;
    
    CreateEmpty(&ingredients);
    CreateEmpty(&burger);

    scanf("%d", &n);
    for(i = 0; i < n; i ++) {
        scanf("%d", &bahan);
        Push(&ingredients, bahan);
    }

    printf("Awal:\n");
    printf("inrdnt -> ");
    displayAsteroids(ingredients);
    printf("burger -> ");
    displayAsteroids(burger);
    
    printf("\n");
    krabbyPatty(&ingredients, &burger);

    printf("Akhir:\n");
    printf("inrdnt -> ");
    displayAsteroids(ingredients);
    printf("burger -> ");
    displayAsteroids(burger);

    return 0;    
}