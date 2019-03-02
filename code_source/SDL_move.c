#include "SDL_move.h"

void moveToMouse(hero *player, int dx, int dy){
	player->dx = dx;
	player->dy = dy;
}

void move(hero *player, int xy, int i){
	if(xy == 1){
		player->dx += i*STEP;
		if((player->dx < 0) || (player->dx + player->width) > SCREEN_WIDTH){
			player->dx -= i*STEP;
		}
	}else{
		player->dy += i*STEP;
		if((player->dy < 0) || (player->dy + player->height) > SCREEN_HEIGHT){
			player->dy -= i*STEP;
		}
	}
}

void moveBetweenTwo(hero *entit, int axe, int a, int b, Uint32 *oldTime){
	Uint32 currentTime = SDL_GetTicks();
	if(currentTime - (*oldTime) > 10){
		entit->dx += entit->orientation * STEP;
		if(entit->dx >= b){
			entit->orientation *= -1;
			entit->dx += entit->orientation * STEP;
		}else if(entit->dx <= a){
			entit->orientation *= -1;
			entit->dx += entit->orientation * STEP;
		}
		*oldTime = currentTime;
	}
}