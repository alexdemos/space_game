#include "ui.h"
#include "spaceship.h"
#include "enemyWave.h"
#include <stdio.h>

const int UI_Y_POS = 50;

void drawUI(Spaceship *spaceship, EnemyWave *enemyWave){
    drawHealthBar(spaceship);
    drawEnemiesRemaining(enemyWave);
}

void drawHealthBar(Spaceship *spaceship){
    int i;
    for(i=0; i< spaceship->health; i++){
        DrawCircle(80+(30*i),UI_Y_POS, 10, RED);
    }
}

void drawEnemiesRemaining(EnemyWave *enemyWave){
    char enemyAmountString[3];
    sprintf(enemyAmountString, "%d", enemyWave->currentEnemyAmount);
    DrawText(enemyAmountString, GetScreenWidth()-110, UI_Y_POS, 20, WHITE);
}