#include "spaceship.h"
#include "bullet.h"
#include "raylib.h"
#include <stdlib.h>
/*
Enemies
Set up GitHub
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
    int fireRate = 0;
    Bullet **bullets = malloc(sizeof(*bullets) * maxBullets);
    initBullets(bullets, maxBullets);

    InitWindow(screenWidth, screenHeight, "Space Game");

    Spaceship spaceship = initSpaceship();

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
       fireRate -= 1;
       updateSpaceshipPos(&spaceship);
       fireBullets(bullets, &spaceship, &currentBullet, maxBullets, &fireRate);

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(BLACK);
            updateBullets(bullets, maxBullets);
            drawSpaceship(&spaceship);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}