/**
* @file SDL_condition.c
* @brief roto zoom
* @author tarek(rayen)
* @version 1.0
* @date May 8,2019

*/
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include "SDL_gestion.h"
#include "SDL_char.h"
#include "SDL_CONDITION.h"
#include "zoom.h"

void condition_fin(char *game, hero player, health h, keys key, SDL_Surface* screen){
	SDL_Surface* end_of_the_game;

	if (h.vie <= 0){ 
		end_of_the_game = IMG_Load("../src/design/condition_fin/killed.png");
	    *game =0;
	    SDL_BlitSurface(end_of_the_game,NULL,screen,NULL);
		SDL_Flip(screen);
		SDL_Delay(3000);
		roto(screen,end_of_the_game,end_of_the_game,player.positionRelative);
	}else if (key.keys == 2){ // ken l nombre mta3 l keys eli lezmna 2
		IMG_Load ("../src/design/condition_fin/you_won.png");
		*game=0;
		SDL_BlitSurface(end_of_the_game,NULL,screen,NULL);
		SDL_Flip(screen);
		SDL_Delay(3000);
		roto(screen,end_of_the_game,end_of_the_game,player.positionRelative);
	}

	
}