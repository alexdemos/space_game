#include "spaceship.h"
#include "bullet.h"
#include "enemy.h"
#include "enemyWave.h"
#include "raylib.h"
#include <stdlib.h>
/*
Enemies
-health
-patterns
-health bar
Point System
RogueLite upgrades
Menu
Heart Containers
*/

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1300;
    const int screenHeight = 800;
    int maxBullets = 100;
    int currentBullet = 0;
    Bullet **bullets = malloc(sizeof(*bullets) * maxBullets);
    initBullets(bullets, maxBullets);

    InitWindow(screenWidth, screenHeight, "Space Game");

    Spaceship spaceship = initSpaceship();
    EnemyWave enemyWave = initEnemyWave(1);

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
       updateSpaceship(&spaceship);
       updateBullets(bullets, maxBullets);
       updateEnemyWave(&enemyWave);
       fireBullets(bullets, &spaceship, &currentBullet, maxBullets);

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(BLACK);
            drawBullets(bullets, maxBullets);
            drawSpaceship(&spaceship);
            drawEnemyWave(&enemyWave);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();  
    free(bullets); 
    freeEnemyWave(&enemyWave);     // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}