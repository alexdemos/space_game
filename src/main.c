#include "spaceship.h"
#include "bullet.h"
#include "enemy.h"
#include "enemyWave.h"
#include "world.h"
#include "collisions.h"
#include "ui.h"
#include "raylib.h"
#include <stdlib.h>
/*
Future Plans:
- more waves
- waves start after time limit, don't wait for previous waves
- power ups
- abilities (dash, force field)
- graphics
- sound
- stars in background
- read from file so status can be saved

TODOs:
Finish making the 10 waves
Balance the game
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
    int max_bullets =  100;

    World world = initWorld(max_bullets);

    InitWindow(screenWidth, screenHeight, "Space Game");

    Bullet **bullets = initBullets(world.maxBullets);
    Spaceship spaceship = initSpaceship();
    EnemyWave enemyWave = createNewWave(4);

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        if (world.start == 0){
            drawStartMenu(&world);
        } else if (spaceship.health > 0) {
        // Update
            updateSpaceship(&spaceship);
            updateBullets(bullets, world.maxBullets);
            updateEnemyWave(&enemyWave, &world);
            fireBullets(bullets, &spaceship, world.maxBullets);
            checkCollisions(&enemyWave, &spaceship, bullets, &world);

                // Draw
                //----------------------------------------------------------------------------------
                BeginDrawing();

                    ClearBackground(BLACK);
                    drawBullets(bullets, world.maxBullets);
                    drawSpaceship(&spaceship);
                    drawEnemyWave(&enemyWave);
                    drawUI(&spaceship, &enemyWave, &world);

                EndDrawing();
        //player has 0 health
        } else {
            drawUpgradeMenu(&spaceship, &world, &enemyWave);
            if (IsKeyDown(KEY_G)){
                resetWaves(&enemyWave);
                resetAfterDeath(&spaceship);
            }
        }
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