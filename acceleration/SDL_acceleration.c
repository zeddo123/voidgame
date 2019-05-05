#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "SDL_char.h"
#include "SDL_acceleration.h"



void Acceleration(hero *h)
{ 
    if( h->sp.s <= 5 && !h->sp.runing )
    {
        if(SDL_GetTicks() - h->sp.s_tick > 250 )
        {
            h->sp.s += 1 ;
            h->sp.s_tick = SDL_GetTicks();
        }
        if(h->sp.s==5)
        h->sp.runing=0;

    }
}

void Decceleration(hero *h)
{ 
    if( h->sp.s > 2 && h->sp.runing )
    {
        if(SDL_GetTicks() - h->sp.s_tick > 250 )
        {
            h->sp.s -= 1 ;
            h->sp.s_tick = SDL_GetTicks();
        }
        if(h->sp.s<2)
        h->sp.runing=0;

    }
}

