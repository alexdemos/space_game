#include "bullet.h"
#include "spaceship.h"
#include <stdlib.h>

void initBullet(Spaceship *spaceship, Bullet** bullets, int bullet_count){
    Bullet *bullet = bullets[bullet_count];
    bullet->rectangle.height = 5;
    bullet->rectangle.width = 10;
    bullet->rectangle.x = spaceship->rectangle.x + \
                          spaceship->rectangle.width -\
                          bullet->rectangle.width;
    bullet->rectangle.y = spaceship->rectangle.y + \
                        (spaceship->rectangle.height/2) - \
                        (bullet->rectangle.height / 2);
    bullet->damage = spaceship->damage;
    bullet->speed = spaceship->bullet_speed;
    bullet->range = spaceship->range;
    bullet->active = 1;
}

Bullet** initBullets(int maxBullets){
    Bullet **bullets = malloc(sizeof(*bullets) * maxBullets);;
    int i;
    for (i=0; i<maxBullets; i++) {
        Bullet *bullet = malloc(sizeof(*bullet));
        bullet->active = 0;
        bullets[i] = bullet;
    }
    return bullets;
}

void fireBullets(Bullet **bullets, Spaceship *spaceship, int maxBullets){
    if (IsKeyDown(KEY_SPACE) && spaceship->cooldown <= 0){
        initBullet(spaceship, bullets, spaceship->bullet_count);
        spaceship->bullet_count = (spaceship->bullet_count + 1) % maxBullets;
        spaceship->cooldown = spaceship->fire_rate;
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
            bullet->rectangle.x += bullet->speed;
            bullet->range -= bullet->speed;
            if (bullet->range <= 0){
                clearBullet(bullet);
            }
        }
}

void drawBullets(Bullet **bullets, int maxBullets){
    int i;
    for (i=0; i<maxBullets; i++) {
        drawBullet(bullets[i]);
    }
}

void drawBullet(Bullet *bullet){
    DrawRectangleRec(bullet->rectangle, GREEN);
}

void clearBullet(Bullet *bullet){
    bullet->active = 0;
    bullet->rectangle.width=0;
    bullet->rectangle.height=0;
    bullet->rectangle.x = -20000;
    bullet->rectangle.y = -20000;
}