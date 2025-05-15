#include "enemy.h"
#include "world.h"
#include "raylib.h"
#include <stdlib.h>
#include <math.h>

int updateEnemy(Enemy *enemy, World *world){
    if(enemy->health <= 0 && enemy->active == 1){
        world->points += enemy->points;
        clearEnemy(enemy);
        return 1;
    }
    enemy->rectangle.x -= enemy->speed;
    enemy->rectangle.y += enemy->y_speed;
    updateY(enemy);
    if (enemy->rectangle.x > 0 && enemy->rectangle.x < GetScreenWidth() - enemy->rectangle.width){
        enemy->init = 1;
    }
    if((enemy->rectangle.x < 0 || enemy->rectangle.x > GetScreenWidth() - enemy->rectangle.width) \
       && enemy->init == 1){
        enemy->speed *= -1;
    }
    return 0;
}

void updateY(Enemy *enemy){
    int y_speed;
    switch(enemy->pattern){
        case 1:
            enemy->rectangle.y = ((GetScreenHeight()/2)-30) * \
            (1+sin(enemy->rectangle.x/70));
            break;
        case 2:
            y_speed = (rand() % 21) - 10;
            enemy->rectangle.y  += y_speed;
            if((enemy->rectangle.y < 0 || enemy->rectangle.y > GetScreenHeight() - enemy->rectangle.height) \
                && enemy->init == 1){
                    enemy->rectangle.y -= 2 * y_speed;
                }
        default:
            if((enemy->rectangle.y < 0 || enemy->rectangle.y > GetScreenHeight() - enemy->rectangle.height) \
                && enemy->init == 1){
                enemy->y_speed *= -1;
    }
    }
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
    rectangle.height = 30;
    rectangle.width = 45;
    enemy->rectangle = rectangle;
    enemy->health = 30;
    enemy->points = 10;
    enemy->speed = 8;
    enemy->y_speed = 0;
    enemy->color = PURPLE;
    enemy->active = 1;
    enemy->init = 0;
    enemy->pattern=LINE_PATTERN;
    return enemy;
}

Enemy* createBeefEnemy(){
    Enemy *enemy = malloc(sizeof(*enemy));
    Rectangle rectangle;
    rectangle.height = 40;
    rectangle.width = 80;
    enemy->rectangle = rectangle;
    enemy->health = 60;
    enemy->points=20;
    enemy->speed = 8;
    enemy->y_speed = 0;
    enemy->color = ORANGE;
    enemy->active = 1;
    enemy->init = 0;
    enemy->pattern=LINE_PATTERN;
    return enemy;
}

Enemy* createFastEnemy(){
    Enemy *enemy = malloc(sizeof(*enemy));
    Rectangle rectangle;
    rectangle.height = 30;
    rectangle.width = 45;
    enemy->rectangle = rectangle;
    enemy->health = 20;
    enemy->points=20;
    enemy->speed = 5;
    enemy->y_speed = 0;
    enemy->color = BLUE;
    enemy->active = 1;
    enemy->init = 0;
    enemy->pattern=LINE_PATTERN;
    return enemy;
}