#include "SDL_Game.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

void loadFrames(SDL_Surface *set[], int maxframes, char file_name[]){
	FILE *ptr_file = fopen(file_name,"r");

	char *string = NULL;
	string = malloc(sizeof(char)*100);

	if(string == NULL){
		printf("allocation prob\n");
		exit(0);
	}

	for(int i = 0;i < maxframes;i++){
		fscanf(ptr_file,"%s\n",string);
		set[i] = IMG_Load(string);
	}

	free(string);
}

void displayFormatFrame(SDL_Surface *set[], int maxframes){
	if(checkImageLoad(set,0,maxframes) != 1){
		printf("error on loading %s",IMG_GetError());
		exit(0);
	}

	for(int i = 0;i < maxframes;i++){
		set[i] = SDL_DisplayFormat(set[i]);
	}
	if(checkImageLoad(set,0,maxframes) != 1){
		printf("error on loading %s",IMG_GetError());
		exit(0);
	}
}

void moveToMouse(hero *player, int dx, int dy){
	player->dx = dx;
	player->dy = dy;
}

void nextFrame(int *frame, int maxframes){
	if(*frame + 1 < maxframes){
		(*frame)++;
	}else{
		(*frame) = 0;
	}
}

int checkImageLoad(SDL_Surface *set[], int index, int maxIndex){
	if(index >= maxIndex){
		return 1;
	}else{
		if(set[index] != NULL){
			return checkImageLoad(set,index+1,maxIndex);
		}else{
			printf("unable to load image %s\n", SDL_GetError());
			return 0;
		}
	}
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

int moveInMenuByKeyboard(int pointeur, int operation, int a, int b, Uint32 *oldTime){
	Uint32 currentTime = SDL_GetTicks();
	if(currentTime - (*oldTime) > 100){
		if(pointeur == a){
			pointeur = b;
		}else{
			pointeur += operation; 
		}
		*oldTime = currentTime;
	}
	return pointeur;
}