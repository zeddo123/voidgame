#include "SDL_move.h"

void moveToMouse(hero *player, int dx, int dy){
	player->position.x = dx;
	player->position.y = dy;
}

void move(hero *player, int xy, int i){
	if(xy == 1){
		player->position.x += i*STEP;
		if((player->position.x < 0) || (player->position.x + player->position.w) > SCREEN_WIDTH){
			player->position.x -= i*STEP;
		}
	}else{
		player->position.y += i*STEP;
		if((player->position.y < 0) || (player->position.y + player->position.h) > SCREEN_HEIGHT){
			player->position.y -= i*STEP;
		}
	}
}

void moveBetweenTwo(hero *entit, int axe, int a, int b, Uint32 *oldTime){
	Uint32 currentTime = SDL_GetTicks();
	if(currentTime - (*oldTime) > 10){
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