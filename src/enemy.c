#include "enemy.h"
#include "raylib.h"
#include <stdlib.h>

int updateEnemy(Enemy *enemy){
    if(enemy->health <= 0 && enemy->active == 1){
        clearEnemy(enemy);
        return 1;
    }
    enemy->rectangle.x -= enemy->speed;
    if (enemy->rectangle.x > 0 && enemy->rectangle.x < GetScreenWidth() - enemy->rectangle.width){
        enemy->init = 1;
    }
    if((enemy->rectangle.x < 0 || enemy->rectangle.x > GetScreenWidth() - enemy->rectangle.width) \
       && enemy->init == 1){
        enemy->speed *= -1;
    }
    return 0;
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
        enemy->active = 0;
        enemy->rectangle.width = 0;
        enemy->rectangle.height=0;
        enemy->rectangle.x=-20000;
        enemy->rectangle.y=-20000;
    }
}


Enemy* createBasicEnemy(){
    Enemy *enemy = malloc(sizeof(*enemy));
    Rectangle rectangle;
    rectangle.height = 20;
    rectangle.width = 40;
    enemy->rectangle = rectangle;
    enemy->health = 30;
    enemy->speed = 2;
    enemy->color = PURPLE;
    enemy->active = 1;
    enemy->init = 0;
    return enemy;
}

Enemy* createBeefEnemy(){
    Enemy *enemy = malloc(sizeof(*enemy));
    Rectangle rectangle;
    rectangle.height = 40;
    rectangle.width = 80;
    enemy->rectangle = rectangle;
    enemy->health = 60;
    enemy->speed = 1;
    enemy->color = ORANGE;
    enemy->active = 1;
    enemy->init = 0;
    return enemy;
}

Enemy* createFastEnemy(){
    Enemy *enemy = malloc(sizeof(*enemy));
    Rectangle rectangle;
    rectangle.height = 20;
    rectangle.width = 40;
    enemy->rectangle = rectangle;
    enemy->health = 20;
    enemy->speed = 5;
    enemy->color = BLUE;
    enemy->active = 1;
    enemy->init = 0;
    return enemy;
}