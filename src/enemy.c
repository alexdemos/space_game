#include "enemy.h"
#include "raylib.h"
#include <stdlib.h>

Enemy* initEnemy(int health, int speed, Color color, Rectangle rectangle){
    Enemy *enemy = malloc(sizeof(*enemy));
    enemy->health = health;
    enemy->speed = speed;
    enemy->color = color;
    enemy->rectangle = rectangle;
    enemy->active = 1;
    return enemy;
}

void updateEnemies(Enemy **enemies, int enemyAmount){
    int i;
    for (i=0; i<enemyAmount; i++){
        updateEnemy(enemies[i]);
    }
}

void updateEnemy(Enemy *enemy){
    if(enemy->health <= 0){
        clearEnemy(enemy);
    }
    enemy->rectangle.x -= enemy->speed;
}

void drawEnemies(Enemy **enemies, int amount){
    int i;  
    for (i=0; i<amount; i++) {
        drawEnemy(enemies[i]);  
    }
}

void drawEnemy(Enemy *enemy){
    DrawRectangleRec(enemy->rectangle, enemy->color);
}

void clearEnemy(Enemy *enemy){
    if(enemy->active == 1){
        free(enemy);
    }
}