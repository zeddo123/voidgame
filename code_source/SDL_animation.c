#include <stdlib.h>
#include <stdio.h>
#include "SDL_Game.h"
#include "SDL_animation.h"

void set_clips(hero *player){
    //On coupe la feuille de sprite à droite 
    player->clipsRight[0].x = 0;
    player->clipsRight[0].y = 0;
    player->clipsRight[0].w = 130;
    player->clipsRight[0].h = 716;

    player->clipsRight[1].x = 192;
    player->clipsRight[1].y = 0;
    player->clipsRight[1].w = 474 - 192;
    player->clipsRight[1].h = 716;

    player->clipsRight[2].x = 498;
    player->clipsRight[2].y = 0;
    player->clipsRight[2].w = 858 - 498;
    player->clipsRight[2].h = 716;

    player->clipsRight[3].x = 872;
    player->clipsRight[3].y = 0;
    player->clipsRight[3].w = 1106 - 872;
    player->clipsRight[3].h = 716;

    player->clipsRight[4].x = 1130;
    player->clipsRight[4].y = 0;
    player->clipsRight[4].w = 1514 - 1130;
    player->clipsRight[4].h = 712;

    //On coupe la feuille de sprite à gauche 
    /*
    clipsLeft[0].x = 0;
    clipsLeft[0].y = player->postion.h;
    clipsLeft[0].w = player->postion.w;
    clipsLeft[0].h = player->postion.h;

    clipsLeft[1].x = player->postion.w;
    clipsLeft[1].y = player->postion.h;
    clipsLeft[1].w = player->postion.w;
    clipsLeft[1].h = player->postion.h;

    clipsLeft[2].x = player->postion.w * 2;
    clipsLeft[2].y = player->postion.h;
    clipsLeft[2].w = player->postion.w;
    clipsLeft[2].h = player->postion.h;

    clipsLeft[3].x = player->postion.w * 3;
    clipsLeft[3].y = player->postion.h;
    clipsLeft[3].w = player->postion.w;
    clipsLeft[3].h = player->postion.h;

    clipsLeft[4].x = player->postion.w * 4;
    clipsLeft[4].y = player->postion.h;
    clipsLeft[4].w = player->postion.w;
    clipsLeft[4].h = player->postion.h;
    */
}

//initialiser les parametres de mouvement / animation
void build(hero *player){
    player->pos=0;
    player->speed=0;
    player->frame=0;
    player->status=1;
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
        //Set the animation to left
        player->status = 0;
        //Move to the next frame in the animation
        player->frame++;
    }
    //If player is moving right
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
    if(player->frame >= 4)
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



void move_animation(hero *player){
    //Move
    player->pos += player->speed;
    
    //Keep the stick figure in bounds
    if((player->pos < 0) || (player->position.x +player->position.w > 8000))
    {
        player->pos -= player->speed;    
    }
}

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