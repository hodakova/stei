#include "asteroid.h"
#include "stack.h"
#include <stdio.h>

int main() {
    int i, n;
    scanf("%d", &n);

    infotype asteroids[n];
    for(i = 0; i < n; i ++)
        scanf("%d", &asteroids[i]);

    Stack remaining;
    CreateEmpty(&remaining);

    collision(n, asteroids, &remaining);
    
    displayAsteroids(remaining);
/*
    Stack sAsteroid;
    CreateEmpty(&sAsteroid);
    infotype asteroid;

    for(i = 0; i < n; i ++) {
        scanf("%d", &asteroid);
        Push(&sAsteroid, asteroid);
    }

    displayAsteroids(sAsteroid);
*/

    return 0;
}