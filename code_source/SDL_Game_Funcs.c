#include "SDL_Game.h"
#include <SDL/SDL.h>

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

void eventHandler(hero *player, SDL_Rect *positionPlayer, char *ptr_game, char *ptr_in_menu, char *ptr_job){
	
	SDL_Event event;
	int dx_cursor_in_game,dy_cursor_in_game;
	SDL_WaitEvent(&event);
	switch(event.type){
		case SDL_QUIT:
			printf("..Quiting the game..\n");
			*ptr_job = 0;
			*ptr_game = 0;
			break;
		case SDL_KEYDOWN:
		
			switch(event.key.keysym.sym){
				case SDLK_ESCAPE:
					*ptr_game = 0;
					*ptr_in_menu = 1;
					break;
				case SDLK_UP:
					move(player,0,-1);
					break;
				case SDLK_DOWN:
					move(player,0,1);
					break;
				case SDLK_LEFT:
					move(player,1,-1);
					break;
				case SDLK_RIGHT:
					move(player,1,1);;
					break; 
			}
			break;

		case SDL_MOUSEBUTTONDOWN:
			switch(event.button.button){
				case SDL_BUTTON_LEFT:
					SDL_GetMouseState(&dx_cursor_in_game,&dy_cursor_in_game);
					moveToMouse(player,dx_cursor_in_game-player->width,dy_cursor_in_game-player->height);
					break;
			}
			break;
	}
	positionPlayer->x = player->dx;
	positionPlayer->y = player->dy;

}