#include "enemyWave.h"
#include "enemy.h"
#include "raylib.h"
#include <stdlib.h>

EnemyWave initEnemyWave(int enemyAmount){
    EnemyWave enemyWave;
    enemyWave.active = 1;
    enemyWave.enemyAmount = enemyAmount;
    Enemy **enemies = malloc(sizeof(*enemies) * enemyAmount);
    int i;
    for(i=0; i<enemyAmount; i++){
        Rectangle rectangle;
        rectangle.x = 300;
        rectangle.y = 100;
        rectangle.height = 50;
        rectangle.width = 100;
        Enemy *enemy = initEnemy(10, 10, RED, rectangle);
        enemies[i] = enemy;
    }
    enemyWave.enemies = enemies;
    return enemyWave;
}

void drawEnemyWave(EnemyWave *enemyWave){
    drawEnemies(enemyWave->enemies, enemyWave->enemyAmount);
}

void updateEnemyWave(EnemyWave *enemyWave){
    updateEnemies(enemyWave->enemies, enemyWave->enemyAmount);
}

void freeEnemyWave(EnemyWave *enemyWave){
    free(enemyWave->enemies);
    enemyWave->active = 0;
}