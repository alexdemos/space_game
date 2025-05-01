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
            return createEnemyWaveOne(wave);
            break;
        case 2:
            return createEnemyWaveTwo(wave);
            break;
        case 3:
            return createEnemyWaveThree(wave);
            break;
        default:
            return createEnemyWaveTwo(wave);
            break;
    }
}

EnemyWave createEnemyWaveOne(int wave){
    EnemyWave enemyWave;
    enemyWave.wave = wave;
    enemyWave.enemyAmount = 3;
    enemyWave.currentEnemyAmount = enemyWave.enemyAmount;
    Enemy **enemies = malloc(sizeof(*enemies) * enemyWave.enemyAmount);
    int i;
    for(i=0; i<enemyWave.enemyAmount; i++){
        Enemy *enemy = createBasicEnemy();
        enemy->rectangle.x = GetScreenWidth() + enemy->rectangle.width;
        enemy->rectangle.y = (200 * i) + 200;
        enemies[i] = enemy;
    }
    enemyWave.enemies = enemies;
    return enemyWave;
}

EnemyWave createEnemyWaveTwo(int wave){
    EnemyWave enemyWave;
    enemyWave.wave = wave;
    enemyWave.enemyAmount = 2;
    enemyWave.currentEnemyAmount = enemyWave.enemyAmount;
    Enemy **enemies = malloc(sizeof(*enemies) * enemyWave.enemyAmount);
    int i;
    for(i=0; i<enemyWave.enemyAmount; i++){
        Enemy *enemy = createBeefEnemy();
        enemy->rectangle.x = GetScreenWidth() + enemy->rectangle.width;
        enemy->rectangle.y = (200 * i) + 200;
        enemies[i] = enemy;
    }
    enemyWave.enemies = enemies;
    return enemyWave;
}

EnemyWave createEnemyWaveThree(int wave){
    EnemyWave enemyWave;
    enemyWave.wave = wave;
    enemyWave.enemyAmount = 3;
    enemyWave.currentEnemyAmount = enemyWave.enemyAmount;
    Enemy **enemies = malloc(sizeof(*enemies) * enemyWave.enemyAmount);
    int i;
    for(i=0; i<enemyWave.enemyAmount; i++){
        Enemy *enemy = createFastEnemy();
        enemy->rectangle.x = GetScreenWidth() + enemy->rectangle.width;
        enemy->rectangle.y = (200 * i) + 200;
        enemies[i] = enemy;
    }
    enemyWave.enemies = enemies;
    return enemyWave;
}
