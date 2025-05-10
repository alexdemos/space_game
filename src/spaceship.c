#include "spaceship.h"
#include "bullet.h"
#include "raylib.h"

Spaceship initSpaceship(){
    Spaceship spaceship;
    spaceship.color = GRAY;
    spaceship.rectangle.x = 200;
    spaceship.rectangle.y = GetScreenHeight() / 2;
    spaceship.rectangle.width = 50;
    spaceship.rectangle.height = 25;
    spaceship.speed = BASE_SPEED;
    spaceship.damage = BASE_DAMAGE;
    spaceship.fire_rate = BASE_FIRE_RATE;
    spaceship.cooldown = spaceship.fire_rate;
    spaceship.bullet_count = 0;
    spaceship.bullet_speed = BASE_BULLET_SPEED;
    spaceship.isInvincible = 0;
    spaceship.health = BASE_HEALTH;

    return spaceship;
}

void updateSpaceship(Spaceship *spaceship){
    updateSpaceshipPos(spaceship);
    spaceship->cooldown -= 1;
}

void updateSpaceshipPos(Spaceship *spaceship){
    if(IsKeyDown(KEY_RIGHT) && spaceship->rectangle.x < GetScreenWidth() - spaceship->rectangle.width) {
        spaceship->rectangle.x += spaceship->speed;
    }
    if(IsKeyDown(KEY_LEFT) && spaceship->rectangle.x > 0) { 
        spaceship->rectangle.x -= spaceship->speed;
    }
    if(IsKeyDown(KEY_UP) && spaceship->rectangle.y > 0 ) {
        spaceship->rectangle.y -= spaceship->speed;
    }
    if(IsKeyDown(KEY_DOWN) && spaceship->rectangle.y < GetScreenHeight() - spaceship->rectangle.height) {
        spaceship->rectangle.y += spaceship->speed;
    }
}

void drawSpaceship(Spaceship *spaceship){
    DrawRectangleRec(spaceship->rectangle, spaceship->color);
}

int calculateNumberOfUpgrades(Spaceship *spaceship, int property_index){
    int current;
    int base;
    int inc;
    switch(property_index){
        case DAMAGE_POS:
            current = spaceship->damage;
            base = BASE_DAMAGE;
            inc = DAMAGE_INC;
            break;
        case SPEED_POS:
            current = spaceship->speed;
            base = BASE_SPEED;
            inc = SPEED_INC;
            break;
        case FIRE_RATE_POS:
            current = spaceship->fire_rate;
            base = BASE_FIRE_RATE;
            inc = FIRE_RATE_INC;
            break;
        case BULLET_SPEED_POS:
            current = spaceship->bullet_speed;
            base = BASE_BULLET_SPEED;
            inc = BULLET_SPEED_INC;
            break;
        default:
            return 0;
    }
    return (current - base)/inc;
}