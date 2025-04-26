#ifndef BULLET_H
#define BULLET_H
#include "spaceship.h"
#include "raylib.h"

typedef struct bullet
{
    Rectangle rectangle;
    float damage;
    float speed;
    int active;
} Bullet;

void initBullet(Spaceship *spaceship, Bullet** bullets, int current);
void initBullets(Bullet **bullets, int maxBullets);
void fireBullets(Bullet **bullets, Spaceship *spaceship, int *current, int maxBullets, int *fireRate);
void updateBullets(Bullet **bullets, int maxBullets);
void updateBullet(Bullet *bullet);

#endif
