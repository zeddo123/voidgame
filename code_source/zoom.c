#include<stdio.h>
#include"/usr/include/SDL/SDL.h"
#include"/usr/include/SDL/SDL_image.h"
#include"/usr/include/SDL/SDL_rotozoom.h"
#include"h.h"
void roto(SDL_Surface *screen,SDL_Surface *image, SDL_Surface *rotation ,SDL_Rect rect , SDL_Event event)
{
	int tempsActuel = 0; int tempsPrecedent = 0; int done;
	done = 1; int angle = 0;
	while(done)
    	{
        	angle += 2;
 
 
       SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
 
        rotation = rotozoomSurface(image, angle, 1.5, 1);
        SDL_BlitSurface(rotation , NULL, screen, &rect); 
	SDL_Flip(screen);        
	SDL_FreeSurface(rotation); 
    }
}

