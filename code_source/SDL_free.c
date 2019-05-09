/**
* @file [SDL_free.c]
* @brief free allocation libs
* @author voidprod
* @version 1.0
* @date Apr 01,2019

*/
#include "SDL_free.h"


void freeMenu(menu m, int frames){
	for(int i = 0;i < 2;i++){
		SDL_FreeSurface(m.b1.image[i]);
		SDL_FreeSurface(m.b2.image[i]);
		SDL_FreeSurface(m.b3.image[i]);
	}

	free(m.b1.image);
	free(m.b2.image);
	free(m.b3.image);

	SDL_FreeSurface(m.font.image[0]);
	free(m.font.image);
	for(int i = 0;i < frames;i++){
		SDL_FreeSurface(m.background[i]);
	}
	free(m.background);
	
}

void freeSettingsMenu(menu m){
	for(int i = 0;i < 2;i++){
		SDL_FreeSurface(m.b1.image[i]);
	}

	free(m.b1.image);

	SDL_FreeSurface(m.background[0]);
	free(m.background);
}

void freeProjectile(projectile p){
	SDL_FreeSurface(p.image);
}