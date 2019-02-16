#include "SDL_Game.h"
#include <SDL/SDL.h>

void move(hero *player,int dx, int dy, char mouse){
	if(mouse){
		player->dx = dx;
		player->dy = dy;
	}else{
		player->dx += dx;
		player->dy += dy;
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
					move(player,0,-4,0);
					positionPlayer->y = player->dy;
					break;
				case SDLK_DOWN:
					move(player,0,4,0);
					positionPlayer->y = player->dy;
					break;
				case SDLK_LEFT:
					move(player,-4,0,0);
					positionPlayer->x = player->dx;
					break;
				case SDLK_RIGHT:
					move(player,4,0,0);
					positionPlayer->x = player->dx;
					break; 
			}
			break;
			
		case SDL_MOUSEBUTTONDOWN:
			switch(event.button.button){
				case SDL_BUTTON_LEFT:
					SDL_GetMouseState(&dx_cursor_in_game,&dy_cursor_in_game);

					move(player,dx_cursor_in_game-413,dy_cursor_in_game-628,1);
													
					positionPlayer->x = player->dx;
					positionPlayer->y = player->dy;
												
					break;
			}
			break;
	}

}