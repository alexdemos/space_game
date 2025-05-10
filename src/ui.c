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
const int MAX_UPGRADES = 5;

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

    drawUpgrade("(1)Damage", spaceship, DAMAGE_POS, world);
    drawUpgrade("(2)Speed", spaceship, SPEED_POS, world);
    drawUpgrade("(3)Fire Rate", spaceship, FIRE_RATE_POS, world);
    drawUpgrade("(4)Bullet Speed", spaceship, BULLET_SPEED_POS, world);
 
    handleUpgrades(spaceship, world);
    if (IsKeyDown(KEY_G)){
        spaceship->health = 8;
    }
    EndDrawing();
}

void handleUpgrades(Spaceship *spaceship, World *world){
    if (IsKeyDown(KEY_ONE)){
        int numOfUpgrades = calculateNumberOfUpgrades(spaceship, DAMAGE_POS);
        int cost = (numOfUpgrades + 1) * COST_INC;
        if (world->points >= cost && numOfUpgrades < MAX_UPGRADES){
            spaceship->damage += DAMAGE_INC;
            world->points -= cost;
            msleep(500);
        }
    }
    if (IsKeyDown(KEY_TWO)){
        int numOfUpgrades = calculateNumberOfUpgrades(spaceship, SPEED_POS);
        int cost = (numOfUpgrades + 1) * COST_INC;
        if (world->points >= cost && numOfUpgrades < MAX_UPGRADES){
            spaceship->speed += SPEED_INC;
            world->points -= cost;
            msleep(500);
        }
    }
    if (IsKeyDown(KEY_THREE)){
        int numOfUpgrades = calculateNumberOfUpgrades(spaceship, FIRE_RATE_POS);
        int cost = (numOfUpgrades + 1) * COST_INC;
        if (world->points >= cost && numOfUpgrades < MAX_UPGRADES){
            spaceship->fire_rate += FIRE_RATE_INC;
            world->points -= cost;
            msleep(500);
        }
    }
    if (IsKeyDown(KEY_FOUR)){
        int numOfUpgrades = calculateNumberOfUpgrades(spaceship, BULLET_SPEED_POS);
        int cost = (numOfUpgrades + 1) * COST_INC;
        if (world->points >= cost && numOfUpgrades < MAX_UPGRADES){
            spaceship->bullet_speed += BULLET_SPEED_INC;
            world->points -= cost;
            msleep(500);
        }
    }
}

void drawUpgrade(char *text, Spaceship *spaceship, int pos, World *world){
    int numberOfUpgrades = calculateNumberOfUpgrades(spaceship, pos);
    int y_pos = UPGRADE_Y + (80 * pos);
    DrawText(text, UPGRADE_X, y_pos, SUB_HEADER_SIZE, WHITE); 
    if (numberOfUpgrades < MAX_UPGRADES){
        int cost = (numberOfUpgrades + 1) * COST_INC;
        drawCost(cost, y_pos, world);
    }
    //draw circles
    int i;
    for (i=0; i<numberOfUpgrades; i++){
        DrawCircle(UPGRADE_X+100 + (200 * (i+1)), y_pos+20, 10, RED);
    }
    for (i=(numberOfUpgrades); i<MAX_UPGRADES; i++){
        DrawCircle(UPGRADE_X+100 + (200 * (i+1)), y_pos+20, 10, WHITE);
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

void drawCost(int cost, int y_pos, World *world){
    Color cost_color = getCostColor(world, cost);
    char costString[10];
    sprintf(costString, "%dpts", cost);
    DrawText(costString, UPGRADE_X, y_pos + 30, SUB_HEADER_SIZE, cost_color);
}

Color getCostColor(World *world, int cost){
    Color cost_color = RED;
    if (world->points >= cost){
        cost_color = GREEN;
    }
    return cost_color;
}