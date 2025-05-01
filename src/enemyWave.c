#include "enemyWave.h"
#include "enemy.h"
#include "raylib.h"
#include <stdlib.h>

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
        *enemyWave = createNewWave(enemyWave->wave+1);
    }
}

void freeEnemyWave(EnemyWave *enemyWave){
    int i;
    for(i=0; i < enemyWave->enemyAmount; i++){
        free(enemyWave->enemies[i]);
    }
    free(enemyWave->enemies);
}

EnemyWave createNewWave(int wave){
    switch(wave){
        case 1:
            return createEnemnyWaveOne(wave);
            break;
        default:
            return createEnemnyWaveOne(wave);
            break;
    }
}

EnemyWave createEnemnyWaveOne(int wave){
    EnemyWave enemyWave;
    enemyWave.wave = wave;
    enemyWave.enemyAmount = 2;
    enemyWave.currentEnemyAmount = enemyWave.enemyAmount;
    Enemy **enemies = malloc(sizeof(*enemies) * enemyWave.enemyAmount);
    int i;
    for(i=0; i<enemyWave.enemyAmount; i++){
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