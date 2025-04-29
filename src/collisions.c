#include "collisions.h"
#include "bullet.h"
#include "spaceship.h"
#include "enemy.h"
#include "enemyWave.h"
#include "world.h"
#include "raylib.h"
#include "utilities.h"
#include <pthread.h>

void checkCollisions(EnemyWave *enemyWave, Spaceship *spaceship, Bullet **bullets, World *world){
    checkPlayerCollisions(enemyWave, spaceship);
    checkBulletCollisons(bullets, enemyWave, world);
}

void checkPlayerCollisions(EnemyWave *enemyWave, Spaceship *spaceship){
    int i;
    for(i=0; i<enemyWave->enemyAmount; i++){
        Enemy *enemy = enemyWave->enemies[i];
        if(CheckCollisionRecs(enemy->rectangle, spaceship->rectangle)){
            handlePlayerCollison(enemy, spaceship);
        }
    }
}

void handlePlayerCollison(Enemy *enemy, Spaceship *spaceship){
    if(spaceship->isInvincible == 0){
        enemy->speed *= -1;
        spaceship->health -= 1;
        markPlayerHit(spaceship);
    }
}

void *markPlayerHitThread(void *threadArg){
    Spaceship *spaceship;;
    spaceship = (Spaceship*) threadArg;
    int height = spaceship->rectangle.height;
    int width = spaceship->rectangle.width;
    spaceship->isInvincible = 1;
    int i;
    for(i=0; i<3; i++){
        spaceship->rectangle.height=0;
        spaceship->rectangle.width=0;
        msleep(100);
        spaceship->rectangle.height=height;
        spaceship->rectangle.width=width;
        drawSpaceship(spaceship);
        msleep(100);
    }
    spaceship->isInvincible = 0;
    return threadArg;
}

void markPlayerHit(Spaceship *spaceship){
    pthread_t threadId;
    pthread_create(&threadId, NULL, markPlayerHitThread, (void*)spaceship);
    pthread_detach(threadId);
}

void checkBulletCollisons(Bullet **bullets, EnemyWave *enemyWave, World *world){
    int i;
    for(i=0; i<world->maxBullets; i++){
        Bullet *bullet = bullets[i];
        int j;
        for(j=0; j<enemyWave->enemyAmount; j++){
            Enemy *enemy = enemyWave->enemies[j];
            if(CheckCollisionRecs(bullet->rectangle, enemy->rectangle)){
                handleBulletCollision(bullet, enemy);
            } 
        }
    }
}

void handleBulletCollision(Bullet *bullet, Enemy *enemy){
    enemyHit(enemy, bullet);
    clearBullet(bullet);
}

void enemyHit(Enemy *enemy, Bullet *bullet){
    enemy->health -= bullet->damage;
    markEnemyHit(enemy);
}

void *markHitThread(void *threadArg){
    Enemy *enemy;
    enemy = (Enemy*) threadArg;
    Color orignalColor = enemy->color;
    enemy->color = RED;
    msleep(25);
    enemy->color = orignalColor;
    return threadArg;
}

void markEnemyHit(Enemy *enemy){
    pthread_t threadId;
    pthread_create(&threadId, NULL, markHitThread, (void*)enemy);
    pthread_detach(threadId);
}