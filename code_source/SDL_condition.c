#include <stdlib.h>
#include <stdio.h>
#include <SDL_image.h>
#include "SDL_gestion.h"
#include "SDL_Game.h"


int condition_fin ( ){
		if (gestionVie(hero player, hero villain, health vie, Uint32 *oldTime)<=0){ 
			IMG_Load ("../src/design/condition_fin/killed.png")
		    SDL_Delay(3000);
		    job=0;}
		else if (gestionKey(keys key, int x, int x2)==4){ // ken l nombre mta3 l keys eli lezmna 4
			IMG_Load ("../src/design/condition_fin/you_won.png")
		    SDL_Delay(3000);
		    job=0;}   
	return job;
}