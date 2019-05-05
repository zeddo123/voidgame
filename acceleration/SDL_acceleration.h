#ifndef ACCELERATION_H_INCLUDED
#define ACCELERATION_H_INCLUDED

#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "SDL_char.h"


void Acceleration(hero *h);
void Decceleration(hero *h);

void eventHandler(hero *player, char *ptr_game, char *ptr_in_menu, char *ptr_job, SDL_Surface *calque_game, SDL_Rect camera, SDL_Rect *positionMouse, Uint32 *animationTime){
	SDL_Event event;
	int dx_cursor_in_game,dy_cursor_in_game;
	
	Uint32 currentTime = SDL_GetTicks();
    if(currentTime - (*animationTime) > 300){
		player->orientation = 0;
		*animationTime = currentTime;
	}

	SDL_PollEvent(&event);
	switch(event.type){
		case SDL_QUIT:
			printf("..Quiting the game..\n");
			*ptr_job = 0;
			*ptr_game = 0;
			break;
		case SDL_KEYDOWN:
		
			switch(event.key.keysym.sym){
				
				case SDLK_ESCAPE:
					break;

				case SDLK_LSHIFT:
                	Acceleration(&hero);
                	break;  
				
				case SDLK_UP:
					if(collision_Parfaite(calque_game,player->position,STEP,0) != 1){
						move(player,0,-1);
						player->moveWithMouse = 0;
						player->orientation = 0;
					}
					break;
				
				case SDLK_DOWN:
					if(collision_Parfaite(calque_game,player->position,STEP,1) != 1){
						move(player,0,1);
						player->moveWithMouse = 0;
						player->orientation = 0;
					}
					break;
				
				case SDLK_LEFT:
					if(collision_Parfaite(calque_game,player->position,STEP,3) != 1){
						move(player,1,-1);
						player->orientation = -1;
						player->moveWithMouse = 0;
					}
					break;
				case SDLK_RIGHT:
					if(collision_Parfaite(calque_game,player->position,STEP,2) != 1){
						move(player,1,1);
						player->orientation = 1;
						player->moveWithMouse = 0;
					}
					break; 
			}
			break;
		case SDL_KEYDUP :

			switch(event.key.keysym.sym){
				
					case SDLK_ESCAPE:
						break;

					case SDLK_LSHIFT:
                		Decceleration(&hero);
                		break;  
				
					case SDLK_UP:
						if(collision_Parfaite(calque_game,player->position,STEP,0) != 1){
							move(player,0,-1);
							player->moveWithMouse = 0;
							player->orientation = 0;
						}
						break;
				
					case SDLK_DOWN:
						if(collision_Parfaite(calque_game,player->position,STEP,1) != 1){
							move(player,0,1);
							player->moveWithMouse = 0;
							player->orientation = 0;
						}
						break;
				
					case SDLK_LEFT:
						if(collision_Parfaite(calque_game,player->position,STEP,3) != 1){
							move(player,1,-1);
							player->orientation = -1;
							player->moveWithMouse = 0;
						}
						break;
					case SDLK_RIGHT:
						if(collision_Parfaite(calque_game,player->position,STEP,2) != 1){
							move(player,1,1);
							player->orientation = 1;
							player->moveWithMouse = 0;
						}
						break; 
				}
				break;

		case SDL_MOUSEBUTTONDOWN:
			switch(event.button.button){
				case SDL_BUTTON_LEFT:
					SDL_GetMouseState(&dx_cursor_in_game,&dy_cursor_in_game);
					player->moveWithMouse = 1;
					positionMouse->x = dx_cursor_in_game - player->position.w + camera.x;
					positionMouse->y = dy_cursor_in_game-player->position.h + camera.y;					
					break;
			}
			break;
	}
}

#endif