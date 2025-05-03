#include "ui.h"
#include "spaceship.h"
#include "enemyWave.h"
#include "world.h"
#include <stdio.h>

const int UI_Y_POS = 50;
const int FONT_SIZE = 20;

void drawStartMenu(World *world){
    BeginDrawing();
    ClearBackground(BLACK);
    DrawText("Space Game", (GetScreenWidth()/2)-135, GetScreenHeight()/3, 50, WHITE);
    DrawText("Press Space to Start", (GetScreenWidth()/2)-150, (GetScreenHeight()/3)+200, 30, WHITE);
    if(IsKeyDown(KEY_SPACE)){
        world->start = 1;
    }
    EndDrawing();
}

void drawDeath(){
    BeginDrawing();
    ClearBackground(BLACK);
    DrawText("Dead", (GetScreenWidth()/2)-54, GetScreenHeight()/3, 50, WHITE);        
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
    DrawText(pointsString, GetScreenWidth() - 300, UI_Y_POS, FONT_SIZE, WHITE);
}