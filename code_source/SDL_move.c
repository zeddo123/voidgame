#include "SDL_move.h"

void moveToMouse(hero *player, int dx, int dy){
	player->position.x = dx;
	player->position.y = dy;
}

void moveToMouseDynamic(hero *player, int dx, int dy, SDL_Surface *calque_game){
	if(player->moveWithMouse == 1){
		if(player->position.x < dx && (dx - player->position.x) > STEP && collision_Parfaite(calque_game,player->position,STEP,3) != 1){
			player->orientation = 1;
			player->position.x += STEP;
		
		}else if(player->position.x > dx && (player->position.x - dx) > STEP && collision_Parfaite(calque_game,player->position,STEP,2) != 1){
			player->orientation = -1;
			player->position.x -= STEP;
		}

		if(player->position.y < dy && (dy - player->position.y) > STEP && collision_Parfaite(calque_game,player->position,STEP,0) != 0){
			player->orientation = 0;
			player->position.y += STEP;

		}else if(player->position.y > dy && (player->position.y - dy) > STEP && collision_Parfaite(calque_game,player->position,STEP,1) != 1){
			player->orientation = 0;
			player->position.y -= STEP;
		}
	}
}

void move(hero *player, int xy, int i){
	if(xy == 1){
		player->position.x += i*STEP;
		if((player->position.x < 0) || (player->position.x + player->position.w) > 8000){
			player->position.x -= i*STEP;
		}
	}else{
		player->position.y += i*STEP;
		if((player->position.y < 0) || (player->position.y + player->position.h) > 8000){
			player->position.y -= i*STEP;
		}
	}
}

void moveBetweenTwo(hero *entit, int axe, int a, int b, Uint32 *oldTime){
	Uint32 currentTime = SDL_GetTicks();
	if(currentTime - (*oldTime) > 50){
		entit->position.x += entit->orientation * STEP;
		if(entit->position.x >= b){
			entit->orientation *= -1;
			entit->position.x += entit->orientation * STEP;
		}else if(entit->position.x <= a){
			entit->orientation *= -1;
			entit->position.x += entit->orientation * STEP;
		}
		*oldTime = currentTime;
	}
}

void moveBetweenTwoRandom(hero *entit, int axe, int a, int b, Uint32 *oldTime, int *randpoint){
	Uint32 currentTime = SDL_GetTicks();

	// random between A and B
	if(*randpoint == -1){
		srand(time(NULL));
		*randpoint = rand()%(b-a) + a;

	}	

	if(currentTime - (*oldTime) > 200){
		
		if(entit->position.x >= *randpoint){
        	
        	if(entit->orientation == -1){
        		if(entit->position.x - a == 0){
					*randpoint = -1;	
				}else{
					*randpoint = rand()%(entit->position.x - a) + a;
				}
			}else {
				if(b - entit->position.x == 0){
					*randpoint = -1;	
				}else{
					*randpoint = rand()%(b - entit->position.x) + (b-a);
				}
				
			}
		
		}


		if (entit->position.x < *randpoint){
			entit->orientation = 1;
		}else if (entit->position.x > *randpoint){
			entit->orientation = -1;
		}
		
		entit->position.x += entit->orientation * STEP;

		*oldTime = currentTime;
	}


}