#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "SDL_char.h"
#include "SDL_acceleration.h"

void acceleration(hero *player){
    if(player->step < 20)
        player->step += 5;
}

void decceleration(hero *player){
    if(player->step > 0)
    player->step -= 5; 
}