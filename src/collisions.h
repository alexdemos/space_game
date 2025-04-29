#ifndef COLLISIONS_H
#define COLLISIONS_H
#include "bullet.h"
#include "spaceship.h"
#include "enemy.h"
#include "enemyWave.h"
#include "world.h"
#include "raylib.h"

void checkCollisions(EnemyWave *enemyWave, Spaceship *spaceship, Bullet **bullets, World *world);
void checkBulletCollisons(Bullet **bullets, EnemyWave *enemyWave, World *world);
void checkEnemyCollisions(EnemyWave wave, Spaceship *spaceship);
void handleBulletCollision(Bullet *bullet, Enemy *enemy);
void enemyHit(Enemy *enemy, Bullet *bullet);
void *markHitThread(void *threadArg);
void markEnemyHit(Enemy *enemy);
void checkPlayerCollisions(EnemyWave *enemyWave, Spaceship *spaceship);
void handlePlayerCollison(Enemy *enemy, Spaceship *spaceship);
void *markPlayerHitThread(void *threadArg);
void markPlayerHit(Spaceship *spaceship);

#endif