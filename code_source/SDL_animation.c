#include <stdlib.h>
#include <stdio.h>
#include "SDL_Game.h"
#include "SDL_animation.h"

void set_clips(hero *player){
    //On coupe la feuille de sprite à droite 
    player->clipsRight[0].x = 0;
    player->clipsRight[0].y = 0;
    player->clipsRight[0].w = 209 / 2;
    player->clipsRight[0].h = 326 / 2;

    player->clipsRight[1].x = 209 / 2;
    player->clipsRight[1].y = 0;
    player->clipsRight[1].w = 209 / 2;
    player->clipsRight[1].h = 326 / 2;

    player->clipsRight[2].x = 418 / 2;
    player->clipsRight[2].y = 0;
    player->clipsRight[2].w = 209 / 2;
    player->clipsRight[2].h = 326 / 2;

    player->clipsRight[3].x = 627 / 2;
    player->clipsRight[3].y = 0 / 2;
    player->clipsRight[3].w = 209 / 2;
    player->clipsRight[3].h = 326 / 2;

    player->clipsRight[4].x = 836 / 2;
    player->clipsRight[4].y = 0 / 2;
    player->clipsRight[4].w = 209 / 2;
    player->clipsRight[4].h = 326 / 2;

    player->clipsRight[5].x = 1045 / 2;
    player->clipsRight[5].y = 0 / 2;
    player->clipsRight[5].w = 209 / 2;
    player->clipsRight[5].h = 326 / 2;

    player->clipsRight[6].x = 1254 / 2;
    player->clipsRight[6].y = 0 / 2;
    player->clipsRight[6].w = 209 / 2;
    player->clipsRight[6].h = 326 / 2;

    player->clipsRight[7].x = 1463 / 2;
    player->clipsRight[7].y = 0 / 2;
    player->clipsRight[7].w = 209 / 2;
    player->clipsRight[7].h = 326 / 2;

    player->clipsRight[8].x = 1672 / 2;
    player->clipsRight[8].y = 0 / 2;
    player->clipsRight[8].w = 209 / 2;
    player->clipsRight[8].h = 326 / 2;

    player->clipsRight[9].x = 1881 / 2;
    player->clipsRight[9].y = 0 / 2;
    player->clipsRight[9].w = 209 / 2;
    player->clipsRight[9].h = 326 / 2;

    player->clipsRight[10].x = 2090 / 2;
    player->clipsRight[10].y = 0 / 2;
    player->clipsRight[10].w = 209 / 2;
    player->clipsRight[10].h = 326 / 2;

    player->clipsRight[11].x = 2299 / 2;
    player->clipsRight[11].y = 0 / 2;
    player->clipsRight[11].w = 209 / 2;
    player->clipsRight[11].h = 326 / 2;

    player->clipsRight[12].x = 2508 / 2;
    player->clipsRight[12].y = 0 / 2;
    player->clipsRight[12].w = 209 / 2;
    player->clipsRight[12].h = 326 / 2;

    player->clipsRight[13].x = 2717 / 2;
    player->clipsRight[13].y = 0 / 2;
    player->clipsRight[13].w = 209 / 2;
    player->clipsRight[13].h = 326 / 2;

    player->clipsRight[14].x = 2926 / 2;
    player->clipsRight[14].y = 0 / 2;
    player->clipsRight[14].w = 209 / 2;
    player->clipsRight[14].h = 326 / 2;

    player->clipsRight[15].x = 3135 / 2;
    player->clipsRight[15].y = 0 / 2;
    player->clipsRight[15].w = 209 / 2;
    player->clipsRight[15].h = 326 / 2;

    player->clipsRight[16].x = 3344 / 2;
    player->clipsRight[16].y = 0 / 2;
    player->clipsRight[16].w = 209 / 2;
    player->clipsRight[16].h = 326 / 2;

    player->clipsRight[17].x = 3553 / 2;
    player->clipsRight[17].y = 0 / 2;
    player->clipsRight[17].w = 209 / 2;
    player->clipsRight[17].h = 326 / 2;

    player->clipsRight[18].x = 3762 / 2;
    player->clipsRight[18].y = 0 / 2;
    player->clipsRight[18].w = 209 / 2;
    player->clipsRight[18].h = 326 / 2;

    player->clipsRight[19].x = 3971 / 2;
    player->clipsRight[19].y = 0 / 2;
    player->clipsRight[19].w = 209 / 2;
    player->clipsRight[19].h = 326 / 2;


    //On coupe la feuille de sprite à gauche 
    player->clipsLeft[0].x = 0 / 2;
    player->clipsLeft[0].y = 326 / 2;
    player->clipsLeft[0].w = 209 / 2;
    player->clipsLeft[0].h = 326 / 2;

    player->clipsLeft[1].x = 209 / 2;
    player->clipsLeft[1].y = 326 / 2;
    player->clipsLeft[1].w = 209 / 2;
    player->clipsLeft[1].h = 326 / 2;

    player->clipsLeft[2].x = 418 / 2;
    player->clipsLeft[2].y = 326 / 2;
    player->clipsLeft[2].w = 209 / 2;
    player->clipsLeft[2].h = 326 / 2;

    player->clipsLeft[3].x = 627 / 2;
    player->clipsLeft[3].y = 326 / 2;
    player->clipsLeft[3].w = 209 / 2;
    player->clipsLeft[3].h = 326 / 2;

    player->clipsLeft[4].x = 836 / 2;
    player->clipsLeft[4].y = 326 / 2;
    player->clipsLeft[4].w = 209 / 2;
    player->clipsLeft[4].h = 326 / 2;

    player->clipsLeft[5].x = 1045 / 2;
    player->clipsLeft[5].y = 326 / 2;
    player->clipsLeft[5].w = 209 / 2;
    player->clipsLeft[5].h = 326 / 2;

    player->clipsLeft[6].x = 1254 / 2;
    player->clipsLeft[6].y = 326 / 2;
    player->clipsLeft[6].w = 209 / 2;
    player->clipsLeft[6].h = 326 / 2;

    player->clipsLeft[7].x = 1463 / 2;
    player->clipsLeft[7].y = 326 / 2;
    player->clipsLeft[7].w = 209 / 2;
    player->clipsLeft[7].h = 326 / 2;

    player->clipsLeft[8].x = 1672 / 2;
    player->clipsLeft[8].y = 326 / 2;
    player->clipsLeft[8].w = 209 / 2;
    player->clipsLeft[8].h = 326 / 2;

    player->clipsLeft[9].x = 1881 / 2;
    player->clipsLeft[9].y = 326 / 2;
    player->clipsLeft[9].w = 209 / 2;
    player->clipsLeft[9].h = 326 / 2;

    player->clipsLeft[10].x = 2090 / 2;
    player->clipsLeft[10].y = 326 / 2;
    player->clipsLeft[10].w = 209 / 2;
    player->clipsLeft[10].h = 326 / 2;

    player->clipsLeft[11].x = 2299 / 2;
    player->clipsLeft[11].y = 326 / 2;
    player->clipsLeft[11].w = 209 / 2;
    player->clipsLeft[11].h = 326 / 2;

    player->clipsLeft[12].x = 2508 / 2;
    player->clipsLeft[12].y = 326 / 2;
    player->clipsLeft[12].w = 209 / 2;
    player->clipsLeft[12].h = 326 / 2;

    player->clipsLeft[13].x = 2717 / 2;
    player->clipsLeft[13].y = 326 / 2;
    player->clipsLeft[13].w = 209 / 2;
    player->clipsLeft[13].h = 326 / 2;

    player->clipsLeft[14].x = 2926 / 2;
    player->clipsLeft[14].y = 326 / 2;
    player->clipsLeft[14].w = 209 / 2;
    player->clipsLeft[14].h = 326 / 2;

    player->clipsLeft[15].x = 3135 / 2;
    player->clipsLeft[15].y = 326 / 2;
    player->clipsLeft[15].w = 209 / 2;
    player->clipsLeft[15].h = 326 / 2;

    player->clipsLeft[16].x = 3344 / 2;
    player->clipsLeft[16].y = 326 / 2;
    player->clipsLeft[16].w = 209 / 2;
    player->clipsLeft[16].h = 326 / 2;

    player->clipsLeft[17].x = 3553 / 2;
    player->clipsLeft[17].y = 326 / 2;
    player->clipsLeft[17].w = 209 / 2;
    player->clipsLeft[17].h = 326 / 2;

    player->clipsLeft[18].x = 3762 / 2;
    player->clipsLeft[18].y = 326 / 2;
    player->clipsLeft[18].w = 209 / 2;
    player->clipsLeft[18].h = 326 / 2;

    player->clipsLeft[19].x = 3971 / 2;
    player->clipsLeft[19].y = 326 / 2;
    player->clipsLeft[19].w = 209 / 2;
    player->clipsLeft[19].h = 326 / 2;
}

void set_clipsEnemie(ennemi *e){
    //On coupe la feuille de sprite à droite 
    e->clipsRight[0].x = 0;
    e->clipsRight[0].y = 0;
    e->clipsRight[0].w = 209 / 2;
    e->clipsRight[0].h = 326 / 2;

    e->clipsRight[1].x = 209 / 2;
    e->clipsRight[1].y = 0;
    e->clipsRight[1].w = 209 / 2;
    e->clipsRight[1].h = 326 / 2;

    e->clipsRight[2].x = 418 / 2;
    e->clipsRight[2].y = 0;
    e->clipsRight[2].w = 209 / 2;
    e->clipsRight[2].h = 326 / 2;

    e->clipsRight[3].x = 627 / 2;
    e->clipsRight[3].y = 0 / 2;
    e->clipsRight[3].w = 209 / 2;
    e->clipsRight[3].h = 326 / 2;

    e->clipsRight[4].x = 836 / 2;
    e->clipsRight[4].y = 0 / 2;
    e->clipsRight[4].w = 209 / 2;
    e->clipsRight[4].h = 326 / 2;

    e->clipsRight[5].x = 1045 / 2;
    e->clipsRight[5].y = 0 / 2;
    e->clipsRight[5].w = 209 / 2;
    e->clipsRight[5].h = 326 / 2;

    e->clipsRight[6].x = 1254 / 2;
    e->clipsRight[6].y = 0 / 2;
    e->clipsRight[6].w = 209 / 2;
    e->clipsRight[6].h = 326 / 2;

    e->clipsRight[7].x = 1463 / 2;
    e->clipsRight[7].y = 0 / 2;
    e->clipsRight[7].w = 209 / 2;
    e->clipsRight[7].h = 326 / 2;

    e->clipsRight[8].x = 1672 / 2;
    e->clipsRight[8].y = 0 / 2;
    e->clipsRight[8].w = 209 / 2;
    e->clipsRight[8].h = 326 / 2;

    e->clipsRight[9].x = 1881 / 2;
    e->clipsRight[9].y = 0 / 2;
    e->clipsRight[9].w = 209 / 2;
    e->clipsRight[9].h = 326 / 2;

    e->clipsRight[10].x = 2090 / 2;
    e->clipsRight[10].y = 0 / 2;
    e->clipsRight[10].w = 209 / 2;
    e->clipsRight[10].h = 326 / 2;

    e->clipsRight[11].x = 2299 / 2;
    e->clipsRight[11].y = 0 / 2;
    e->clipsRight[11].w = 209 / 2;
    e->clipsRight[11].h = 326 / 2;

    e->clipsRight[12].x = 2508 / 2;
    e->clipsRight[12].y = 0 / 2;
    e->clipsRight[12].w = 209 / 2;
    e->clipsRight[12].h = 326 / 2;

    e->clipsRight[13].x = 2717 / 2;
    e->clipsRight[13].y = 0 / 2;
    e->clipsRight[13].w = 209 / 2;
    e->clipsRight[13].h = 326 / 2;

    e->clipsRight[14].x = 2926 / 2;
    e->clipsRight[14].y = 0 / 2;
    e->clipsRight[14].w = 209 / 2;
    e->clipsRight[14].h = 326 / 2;

    e->clipsRight[15].x = 3135 / 2;
    e->clipsRight[15].y = 0 / 2;
    e->clipsRight[15].w = 209 / 2;
    e->clipsRight[15].h = 326 / 2;

    e->clipsRight[16].x = 3344 / 2;
    e->clipsRight[16].y = 0 / 2;
    e->clipsRight[16].w = 209 / 2;
    e->clipsRight[16].h = 326 / 2;

    e->clipsRight[17].x = 3553 / 2;
    e->clipsRight[17].y = 0 / 2;
    e->clipsRight[17].w = 209 / 2;
    e->clipsRight[17].h = 326 / 2;

    e->clipsRight[18].x = 3762 / 2;
    e->clipsRight[18].y = 0 / 2;
    e->clipsRight[18].w = 209 / 2;
    e->clipsRight[18].h = 326 / 2;

    e->clipsRight[19].x = 3971 / 2;
    e->clipsRight[19].y = 0 / 2;
    e->clipsRight[19].w = 209 / 2;
    e->clipsRight[19].h = 326 / 2;


    //On coupe la feuille de sprite à gauche 
    e->clipsLeft[0].x = 0 / 2;
    e->clipsLeft[0].y = 326 / 2;
    e->clipsLeft[0].w = 209 / 2;
    e->clipsLeft[0].h = 326 / 2;

    e->clipsLeft[1].x = 209 / 2;
    e->clipsLeft[1].y = 326 / 2;
    e->clipsLeft[1].w = 209 / 2;
    e->clipsLeft[1].h = 326 / 2;

    e->clipsLeft[2].x = 418 / 2;
    e->clipsLeft[2].y = 326 / 2;
    e->clipsLeft[2].w = 209 / 2;
    e->clipsLeft[2].h = 326 / 2;

    e->clipsLeft[3].x = 627 / 2;
    e->clipsLeft[3].y = 326 / 2;
    e->clipsLeft[3].w = 209 / 2;
    e->clipsLeft[3].h = 326 / 2;

    e->clipsLeft[4].x = 836 / 2;
    e->clipsLeft[4].y = 326 / 2;
    e->clipsLeft[4].w = 209 / 2;
    e->clipsLeft[4].h = 326 / 2;

    e->clipsLeft[5].x = 1045 / 2;
    e->clipsLeft[5].y = 326 / 2;
    e->clipsLeft[5].w = 209 / 2;
    e->clipsLeft[5].h = 326 / 2;

    e->clipsLeft[6].x = 1254 / 2;
    e->clipsLeft[6].y = 326 / 2;
    e->clipsLeft[6].w = 209 / 2;
    e->clipsLeft[6].h = 326 / 2;

    e->clipsLeft[7].x = 1463 / 2;
    e->clipsLeft[7].y = 326 / 2;
    e->clipsLeft[7].w = 209 / 2;
    e->clipsLeft[7].h = 326 / 2;

    e->clipsLeft[8].x = 1672 / 2;
    e->clipsLeft[8].y = 326 / 2;
    e->clipsLeft[8].w = 209 / 2;
    e->clipsLeft[8].h = 326 / 2;

    e->clipsLeft[9].x = 1881 / 2;
    e->clipsLeft[9].y = 326 / 2;
    e->clipsLeft[9].w = 209 / 2;
    e->clipsLeft[9].h = 326 / 2;

    e->clipsLeft[10].x = 2090 / 2;
    e->clipsLeft[10].y = 326 / 2;
    e->clipsLeft[10].w = 209 / 2;
    e->clipsLeft[10].h = 326 / 2;

    e->clipsLeft[11].x = 2299 / 2;
    e->clipsLeft[11].y = 326 / 2;
    e->clipsLeft[11].w = 209 / 2;
    e->clipsLeft[11].h = 326 / 2;

    e->clipsLeft[12].x = 2508 / 2;
    e->clipsLeft[12].y = 326 / 2;
    e->clipsLeft[12].w = 209 / 2;
    e->clipsLeft[12].h = 326 / 2;

    e->clipsLeft[13].x = 2717 / 2;
    e->clipsLeft[13].y = 326 / 2;
    e->clipsLeft[13].w = 209 / 2;
    e->clipsLeft[13].h = 326 / 2;

    e->clipsLeft[14].x = 2926 / 2;
    e->clipsLeft[14].y = 326 / 2;
    e->clipsLeft[14].w = 209 / 2;
    e->clipsLeft[14].h = 326 / 2;

    e->clipsLeft[15].x = 3135 / 2;
    e->clipsLeft[15].y = 326 / 2;
    e->clipsLeft[15].w = 209 / 2;
    e->clipsLeft[15].h = 326 / 2;

    e->clipsLeft[16].x = 3344 / 2;
    e->clipsLeft[16].y = 326 / 2;
    e->clipsLeft[16].w = 209 / 2;
    e->clipsLeft[16].h = 326 / 2;

    e->clipsLeft[17].x = 3553 / 2;
    e->clipsLeft[17].y = 326 / 2;
    e->clipsLeft[17].w = 209 / 2;
    e->clipsLeft[17].h = 326 / 2;

    e->clipsLeft[18].x = 3762 / 2;
    e->clipsLeft[18].y = 326 / 2;
    e->clipsLeft[18].w = 209 / 2;
    e->clipsLeft[18].h = 326 / 2;

    e->clipsLeft[19].x = 3971 / 2;
    e->clipsLeft[19].y = 326 / 2;
    e->clipsLeft[19].w = 209 / 2;
    e->clipsLeft[19].h = 326 / 2;
}

void apply_surface(int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* frame){
    //Make a temporary rectangle to hold the offsets
    SDL_Rect offset;
    
    //Give the offsets to the rectangle
    offset.x = x;
    offset.y = y;
    //Blit the surface
    SDL_BlitSurface(source, frame, destination, &offset);
}

void show(hero *player, SDL_Surface *screen){
    //If player is moving left
    if(player->orientation < 0)
    {
        //Set the animation to Left
        player->status = 0;
        //Move to the next frame in the animation
        player->frame++;
    }
    //If player is moving Left
    else if(player->orientation > 0)
    {
        //Set the animation to right
        player->status = 1;
        
        //Move to the next frame in the animation
        player->frame++;
    }
    //If player standing
    else
    {
        //Restart the animation
        player->frame = 0;    
    }

    //Loop the animation
    if(player->frame >= 19)
    {
        player->frame = 0;
    }

    //Show the stick figure
    if(player->status == 1)
    {
        apply_surface(player->positionRelative.x, player->positionRelative.y, player->image, screen, &player->clipsRight[player->frame]);
    }
    else if(player->status == 0)
    {
        apply_surface(player->positionRelative.x, player->positionRelative.y, player->image, screen, &player->clipsLeft[player->frame]);
    }
}


/*
void move_animation(hero *player){
    //Move
    player->pos += player->speed;
    
    //Keep the stick figure in bounds
    if((player->pos < 0) || (player->position.x +player->position.w > 8000))
    {
        player->pos -= player->speed;    
    }
}
*/
void start(int *started, int *paused, int *startTicks){   
    //Start the timer
    *started = 1;
    
    //Unpause the timer
    *paused = 0;
    
    //Get the current clock time
    *startTicks = SDL_GetTicks();    
}


int get_ticks(int *started , int *paused , int *startTicks ,int *pausedTicks){
    //If the timer is running
    if(*started == 1)
    {
        //If the timer is paused
        if(*paused == 1)
        {
            //Return the number of ticks when the timer was paused
            return *pausedTicks;
        }
        else
        {
            //Return the current time minus the start time
            return SDL_GetTicks() - *startTicks;
        }
    }
    
    //If the timer isn't running
    return 0;    
}