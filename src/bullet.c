#include "bullet.h"
#include "spaceship.h"
#include <stdlib.h>

void initBullet(Spaceship *spaceship, Bullet** bullets, int current){
    Bullet *bullet = bullets[current];
    bullet->rectangle.height = 5;
    bullet->rectangle.width = 15;
    bullet->rectangle.x = spaceship->rectangle.x + \
                          spaceship->rectangle.width -\
                          bullet->rectangle.width;
    bullet->rectangle.y = spaceship->rectangle.y + \
                        (spaceship->rectangle.height/2) - \
                        (bullet->rectangle.height / 2);
    bullet->damage = spaceship->damage;
    bullet->speed = spaceship->bullet_speed;
    bullet->active = 1;
}

void initBullets(Bullet **bullets, int maxBullets){
    int i;
    for (i=0; i<maxBullets; i++) {
        Bullet *bullet = malloc(sizeof(*bullet));
        bullet->active = 0;
        bullets[i] = bullet;
    }
}

void fireBullets(Bullet **bullets, Spaceship *spaceship, int *current, int maxBullets, int *fireRate){
    if (IsKeyDown(KEY_SPACE) && *fireRate <= 0){
        initBullet(spaceship, bullets, *current);
        *current = (*current + 1) % maxBullets;
        *fireRate = 10;
    }
}

void updateBullets(Bullet **bullets, int maxBullets){
    int i;
    for (i=0; i<maxBullets; i++) {
        updateBullet(bullets[i]);
    }
}

void updateBullet(Bullet *bullet){
    if (bullet->active == 1){
            DrawRectangleRec(bullet->rectangle, GREEN);
            bullet->rectangle.x += bullet->speed;
            if (bullet->rectangle.x > GetScreenWidth() + 30){
                bullet->active = 0;
            }
        }
}