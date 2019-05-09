/**
* @file zoom.c
* @brief roto zoom
* @author myriam
* @version 1.0
* @date Apr 01,2019

*/
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_rotozoom.h>
#include "zoom.h"

void roto(SDL_Surface *screen,SDL_Surface *image, SDL_Surface *rotation ,SDL_Rect rect){
	int tempsActuel = 0; int tempsPrecedent = 0; int done;
	Uint32 oldTime = SDL_GetTicks();
	done = 1; int angle = 0;
	while(done){
		angle += 2;
		SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
 
		rotation = rotozoomSurface(image, angle, 1.5, 1);
		SDL_BlitSurface(rotation , NULL, screen, NULL); 
		
		SDL_Flip(screen);        
		SDL_FreeSurface(rotation);
		if(SDL_GetTicks() - oldTime > 600){
			done = 0;
		}

    }
}

