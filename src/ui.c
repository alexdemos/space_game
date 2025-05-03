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
const int UPGRADE_X = 100;

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
    DrawText("You Died", (GetScreenWidth()/2)-(width/2), UI_Y_POS, HEADER_SIZE, WHITE);  
    width = MeasureText(upgrade, SUB_HEADER_SIZE); 
    DrawText("Buy Some Upgrades", (GetScreenWidth()/2)-(width/2), UI_Y_POS+100, SUB_HEADER_SIZE, WHITE); 
    drawPoints(world);
    char *damage = "Damage (1)";
    DrawText(damage, UPGRADE_X, UPGRADE_Y, SUB_HEADER_SIZE, WHITE); 
    int i;
    for (i=0; i<spaceship->damage/10; i++){
        DrawCircle(UPGRADE_X + (200 * (i+1)), UPGRADE_Y+20, 10, RED);
    }
    for (i=spaceship->damage/10; i<5; i++){
        DrawCircle(UPGRADE_X + (200 * (i+1)), UPGRADE_Y+20, 10, WHITE);
    }
    if (IsKeyDown(KEY_ONE)){
        spaceship->damage += 10;
        msleep(500);
    }
     if (IsKeyDown(KEY_G)){
        spaceship->health = 3;
        return;
     }
    EndDrawing();
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