//the main code of the game
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "SDL_Game.h"

int main(void)
{
	SDL_Surface *screen = NULL;
	SDL_Surface *menu = NULL;
	SDL_Surface *game_surface = NULL;
	SDL_Surface *image_player = NULL;

	SDL_Rect positionScreen;
	SDL_Rect positionDestination = {0, 0, 0, 0};
	SDL_Rect positionPlayer;

	SDL_Event event;
	SDL_Event event_in_game;

	Mix_Music *music = NULL; //pointer of the music

	Mix_Chunk *effect = NULL; //pointer of the sound effect

	hero player;

	int dx_cursor = 0,dy_cursor = 0;
	int dx_cursor_in_game = 0,dy_cursor_in_game = 0;
	char job = 1;
	char game = 1;
	char in_menu = 1;
	char over_play = 1, over_set = 1, over_quit = 1;

	if(SDL_Init(SDL_INIT_VIDEO) != 0){
		printf("unable to init SDL %s\n", SDL_GetError());
		return 1;
	}

	if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024) != 0){
		return 1;
	}
	
	SDL_WM_SetCaption("Menu of the game",NULL); //set the caption

	screen = SDL_SetVideoMode(0,0,0,SDL_HWSURFACE | SDL_DOUBLEBUF);
	if(screen == NULL){
		printf("unable to set video mode %s\n", SDL_GetError());
		return 1;
	}

	SDL_Surface *tmp = IMG_Load("../src/menu1.png"); // load the background
	if (tmp == NULL){
		printf("unable to load image %s\n", SDL_GetError());
		return 1;
	}

	menu = SDL_DisplayFormat(tmp);
	SDL_FreeSurface(tmp);
	if(menu == NULL){
		printf("unable to load menu %s\n", SDL_GetError());
		return 1;
	}

	music = Mix_LoadMUS("../src/music.wav"); // load the music
	if(music == NULL){
		printf("->cant load the music \n");
		return 1;
	}

	effect = Mix_LoadWAV("../src/effect1.wav");//load the sound effects
	if(effect == NULL){
		printf("->cant load the sound effect %s\n",Mix_GetError());
		return 1;
	}



	//iniatilizing the positions
	positionScreen.x = 0;
	positionScreen.y = 0;
	positionScreen.w = menu->w;
	positionScreen.h = menu->h;
	positionPlayer.x = 500;
	positionPlayer.y = 500;

	//starting everything
	SDL_BlitSurface(menu,&positionScreen,screen,&positionDestination);
	SDL_Flip(screen);
	
	if(Mix_PlayMusic(music,-1) == 1){ //play music
		printf("cant play music ->%s\n",Mix_GetError());
		return 1;
	}
	
	while(job){
		SDL_PollEvent(&event);

		switch(event.type){
			case SDL_QUIT:
				printf("..Quiting the menu..\n");
				job = 0;
				break;
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym){
					case SDLK_ESCAPE:
						menu = SDL_DisplayFormat(IMG_Load("../src/menu1.png"));
						in_menu = 1;
						break;
				}
			case SDL_MOUSEBUTTONDOWN:
				switch(event.button.button){
					case SDL_BUTTON_LEFT:

						SDL_GetMouseState(&dx_cursor,&dy_cursor);
						if(dx_cursor >= 434 && dx_cursor <= 1486 && in_menu != 0){
							
							// player wants to play
							if(dy_cursor >= 371 && dy_cursor <= 529){

								in_menu = 0;
								game_surface = SDL_DisplayFormat(IMG_Load("../src/play.jpg")); //load the game to the player
								image_player = IMG_Load("../src/hero1.PNG");

								SDL_BlitSurface(game_surface,&positionScreen,screen,&positionDestination);
								SDL_BlitSurface(image_player,&positionScreen,screen,&positionPlayer);
								SDL_Flip(screen);
								
								move(&player,500,500,1);

								while(game){
									
									eventHandler(&player,&positionPlayer,&game,&in_menu,&job);
									
									SDL_BlitSurface(game_surface,&positionScreen,screen,&positionDestination);
									SDL_BlitSurface(image_player,&positionScreen,screen,&positionPlayer);
									SDL_Flip(screen);
								}

								SDL_FreeSurface(image_player);
								SDL_FreeSurface(game_surface);
							}else if (dy_cursor >= 596 && dy_cursor <= 754){
								menu = SDL_DisplayFormat(IMG_Load("../src/settings.jpg")); //load the setting to the user
								in_menu = 0;
							}else if (dy_cursor >= 821 && dy_cursor <= 979){
								job = 0;
							}

							break;
						}
				}
				break;
		}
		
		if(in_menu){
			
			SDL_GetMouseState(&dx_cursor,&dy_cursor);
			if(dx_cursor >= 434 && dx_cursor <= 1486){
							
				if(dy_cursor >= 371 && dy_cursor <= 529){
					if(over_play != 0){
						twist(over_play,over_quit,over_set);
						menu = SDL_DisplayFormat(IMG_Load("../src/menu1_play_mouseover.png")); //load the mouseover play
						Mix_PlayChannel(-1,effect,0);
					}
				}else if (dy_cursor >= 596 && dy_cursor <= 754){
					if(over_set != 0){
						twist(over_set,over_play,over_quit);
						menu = SDL_DisplayFormat(IMG_Load("../src/menu1_set_mouseover.png")); //load the mouseover settings
						Mix_PlayChannel(-1,effect,0);
					}
				}else if (dy_cursor >= 821 && dy_cursor <= 979){
					if(over_quit != 0){
						twist(over_quit,over_play,over_set);
						menu = SDL_DisplayFormat(IMG_Load("../src/menu1_quit_mouseover.png")); //load the mouseover quit
						Mix_PlayChannel(-1,effect,0);
					}
				}else{
					twist(over_quit,over_play,over_set);
					over_quit = 1;
					menu = SDL_DisplayFormat(IMG_Load("../src/menu1.png"));
				}
			}else{
				twist(over_quit,over_play,over_set);
				over_quit = 1;
				menu = SDL_DisplayFormat(IMG_Load("../src/menu1.png"));
			}
		}
		SDL_BlitSurface(menu,&positionScreen,screen,&positionDestination);
		SDL_Flip(screen);

	}

	SDL_FreeSurface(menu);
	Mix_FreeMusic(music);
	Mix_CloseAudio();
	SDL_Quit();

	return 0;
}
