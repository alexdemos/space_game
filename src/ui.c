#include "ui.h"
#include "spaceship.h"
#include "enemyWave.h"
#include "world.h"
#include "utilities.h"
#include <stdio.h>

const int UI_Y_POS = 50;
const int HEADER_SIZE = 50;
const int SUB_HEADER_SIZE = 30;
const int UI_FONT_SIZE = 20;
const int UPGRADE_Y = 250;
const int UPGRADE_X = 50;

void drawStartMenu(World *world){
    BeginDrawing();
    ClearBackground(BLACK);
    char *space = "Space Game";
    int width = MeasureText(space, HEADER_SIZE);
    DrawText(space, (GetScreenWidth()/2)-(width/2), GetScreenHeight()/3, HEADER_SIZE, WHITE);
    char *start = "Press Space to Start";
    width = MeasureText(start, SUB_HEADER_SIZE);
    DrawText("Press Space to Start", (GetScreenWidth()/2)-(width/2), \
            (GetScreenHeight()/3)+100, SUB_HEADER_SIZE, WHITE);
    if(IsKeyDown(KEY_SPACE)){
        world->start = 1;
    }
    EndDrawing();
}

void drawUpgradeMenu(Spaceship *spaceship, World *world){
    BeginDrawing();
    ClearBackground(BLACK);
    char *death = "You Died";
    char *upgrade = "Buy Some Upgrades";
    int width = MeasureText(death, HEADER_SIZE);
    DrawText(death, (GetScreenWidth()/2)-(width/2), UI_Y_POS, HEADER_SIZE, WHITE);  
    width = MeasureText(upgrade, SUB_HEADER_SIZE); 
    DrawText(upgrade, (GetScreenWidth()/2)-(width/2), UI_Y_POS+100, SUB_HEADER_SIZE, WHITE); 
    drawPoints(world);

    drawUpgrade("(1)Damage", spaceship->damage, BASE_DAMAGE, DAMAGE_INC, 0);
    drawUpgrade("(2)Speed", spaceship->speed, BASE_SPEED, SPEED_INC, 1);
    drawUpgrade("(3)Fire Rate", spaceship->fire_rate, BASE_FIRE_RATE, FIRE_RATE_INC, 2);
    drawUpgrade("(4)Bullet Speed", spaceship->bullet_speed, BASE_BULLET_SPEED, BULLET_SPEED_INC, 3);
 
    handleUpgrades(spaceship, world);
    EndDrawing();
}

void handleUpgrades(Spaceship *spaceship, World *world){
    if (IsKeyDown(KEY_ONE)){
        int cost = (((spaceship->damage - BASE_DAMAGE)/DAMAGE_INC) + 1) * COST_INC;
        if (world->points >= cost){
            spaceship->damage += DAMAGE_INC;
            world->points -= cost;
            msleep(500);
        }
    }
    if (IsKeyDown(KEY_TWO)){
        spaceship->speed += SPEED_INC;
        msleep(500);
    }
}

void drawUpgrade(char *text, int current, int base, int inc, int pos){
    int y = UPGRADE_Y + (50 * pos);
    int cost = (((current - base)/inc) + 1) * COST_INC;
    char costString[10];
    sprintf(costString, "- %dpts", cost);
    DrawText(text, UPGRADE_X, y, SUB_HEADER_SIZE, WHITE); 
    int width = MeasureText(text, SUB_HEADER_SIZE); 
    DrawText(costString, UPGRADE_X + width + 10, y, SUB_HEADER_SIZE, WHITE);
    int i;
    for (i=0; i<(current-base)/inc; i++){
        DrawCircle(UPGRADE_X+100 + (200 * (i+1)), y+20, 10, RED);
    }
    for (i=((current-base)/inc); i<5; i++){
        DrawCircle(UPGRADE_X+100 + (200 * (i+1)), y+20, 10, WHITE);
    }
}

void drawUI(Spaceship *spaceship, EnemyWave *enemyWave, World *world){
    drawHealthBar(spaceship);
    drawEnemiesRemaining(enemyWave);
    drawPoints(world);
}

void drawHealthBar(Spaceship *spaceship){
    int i;
    for(i=0; i< spaceship->health; i++){
        DrawCircle(80+(30*i),UI_Y_POS, 10, RED);
    }
}

void drawEnemiesRemaining(EnemyWave *enemyWave){
    char enemyAmountString[50];
    sprintf(enemyAmountString, "Current Wave: %d  Enemy Count: %d", \
            enemyWave->wave, enemyWave->currentEnemyAmount);
    DrawText(enemyAmountString, (GetScreenWidth()/2)-150, UI_Y_POS, 20, WHITE);
}

void drawPoints(World *world){
    char pointsString[20];
    sprintf(pointsString, "Points: %d", world->points);
    DrawText(pointsString, GetScreenWidth() - 300, UI_Y_POS, UI_FONT_SIZE, WHITE);
}