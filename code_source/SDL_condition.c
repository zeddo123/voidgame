#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include "SDL_gestion.h"
#include "SDL_char.h"
#include "SDL_CONDITION.h"

void condition_fin(char *game, hero player, health h, keys key){
		if (h.vie<=0){ 
			IMG_Load ("../src/design/condition_fin/killed.png");
		    SDL_Delay(3000);
		    *game =0;}
		else if (key.keys==2){ // ken l nombre mta3 l keys eli lezmna 2
			IMG_Load ("../src/design/condition_fin/you_won.png");
		    SDL_Delay(3000);
		    *game=0;}   

}