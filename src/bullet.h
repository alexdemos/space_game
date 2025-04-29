#ifndef BULLET_H
#define BULLET_H
#include "spaceship.h"
#include "raylib.h"

typedef struct bullet
{
    Rectangle rectangle;
    int damage;
    int speed;
    int range;
    int distance;
    int active;
} Bullet;

void initBullet(Spaceship *spaceship, Bullet** bullets, int bullet_count);
Bullet** initBullets(int maxBullets);
void fireBullets(Bullet **bullets, Spaceship *spaceship, int maxBullets);
void updateBullets(Bullet **bullets, int maxBullets);
void updateBullet(Bullet *bullet);
void drawBullets(Bullet **bullets, int maxBullets);
void drawBullet(Bullet *bullet);
void clearBullet(Bullet *bullet);

#endif
