#include "enemyWave.h"
#include "enemy.h"
#include "raylib.h"
#include <stdlib.h>

EnemyWave initEnemyWave(int enemyAmount){
    EnemyWave enemyWave;
    enemyWave.active = 1;
    enemyWave.enemyAmount = enemyAmount;
    enemyWave.currentEnemyAmount = enemyAmount;
    Enemy **enemies = malloc(sizeof(*enemies) * enemyAmount);
    int i;
    for(i=0; i<enemyAmount; i++){
        Rectangle rectangle;
        rectangle.x = 1300;
        rectangle.y = (200 * i) + 200;
        rectangle.height = 20;
        rectangle.width = 40;
        Enemy *enemy = initEnemy(30, 1, PURPLE, rectangle);
        enemies[i] = enemy;
    }
    enemyWave.enemies = enemies;
    return enemyWave;
}

void drawEnemyWave(EnemyWave *enemyWave){
    drawEnemies(enemyWave->enemies, enemyWave->enemyAmount);
}

void updateEnemyWave(EnemyWave *enemyWave){
    int i;
    for (i=0; i<enemyWave->enemyAmount; i++){
        Enemy *enemy = enemyWave->enemies[i];
        enemyWave->currentEnemyAmount -= updateEnemy(enemy); 
    }
    if(enemyWave->currentEnemyAmount == 0){
        freeEnemyWave(enemyWave);
        *enemyWave = initEnemyWave(3);
    }
}

void freeEnemyWave(EnemyWave *enemyWave){
    free(enemyWave->enemies);
    enemyWave->active = 0;
    enemyWave->enemyAmount = 0;
}