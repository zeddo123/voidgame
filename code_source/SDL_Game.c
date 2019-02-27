//the main code of the game
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "SDL_Game.h"

int main(void)
{
	SDL_Surface *screen = NULL;
	SDL_Surface *game_surface = NULL;
	SDL_Surface *image_player = NULL;
	SDL_Surface *menu = NULL;
	SDL_Surface *menu_setting = NULL;
	SDL_Surface *menu_frame[7];
	SDL_Surface *font_surface = NULL;
	SDL_Surface *play[2];
	SDL_Surface *set[2];
	SDL_Surface *quit[2];
	SDL_Surface *logo = NULL;


	SDL_Rect positionScreen;
	SDL_Rect positionDestination = {0, 0, 0, 0};
	SDL_Rect positionPlayer;
	SDL_Rect positionText;
	SDL_Rect positionPlay;
	SDL_Rect positionQuit;
	SDL_Rect positionSet;
	SDL_Rect positionLogo;

	SDL_Event event;
	SDL_Event event_in_game;

	SDL_Color fontColor = {255, 255, 255};

	Uint32 oldTime = 0, currentTime = 0;

	Mix_Music *music = NULL; //pointer of the music

	Mix_Chunk *effect = NULL; //pointer of the sound effect

	TTF_Font *font = NULL;

	hero player = {0,0,68,25};

	int dx_cursor = 0,dy_cursor = 0;
	int next = 0;
	int dx_cursor_in_game = 0,dy_cursor_in_game = 0;
	char job = 1;
	char game = 1;
	char in_menu = 1;
	char over_play = 1, over_set = 1, over_quit = 1, licence = 1;

	if(SDL_Init(SDL_INIT_VIDEO) != 0){
		printf("unable to init SDL %s\n", SDL_GetError());
		return 1;
	}

	if(TTF_Init() == -1){
		return 1;
	}

	if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024) != 0){
		return 1;
	}

	font = TTF_OpenFont("../src/font/Monaco.ttf",30);
	font_surface = TTF_RenderText_Blended(font,"game under the GPL 2.0 licence",fontColor);
	if(font_surface == NULL || font == NULL){
		printf("unable to TTF_RenderText_Solid\n");
		return 1;
	}

	SDL_WM_SetCaption("void prod game",NULL); //set the caption

	screen = SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,0,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
	if(screen == NULL){
		printf("unable to set video mode %s\n", SDL_GetError());
		return 1;
	}

	// load the background
	menu_frame[0] = IMG_Load(MENU_FILE_FRAME_1);
	menu_frame[1] = IMG_Load(MENU_FILE_FRAME_2);
	menu_frame[2] = IMG_Load(MENU_FILE_FRAME_3);
	menu_frame[3] = IMG_Load(MENU_FILE_FRAME_4);
	menu_frame[4] = IMG_Load(MENU_FILE_FRAME_5);
	menu_frame[5] = IMG_Load(MENU_FILE_FRAME_6);
	menu_frame[6] = IMG_Load(MENU_FILE_FRAME_7);

	//load the play botton
	play[1] = IMG_Load(PLAY_B_STATIC);
	play[0] = IMG_Load(PLAY_B_OVER);

	//load the setting botton
	set[1] = IMG_Load(SET_B_STATIC);
	set[0] = IMG_Load(SET_B_OVER);

	//load the quit botton
	quit[1] = IMG_Load(QUIT_B_STATIC);
	quit[0] = IMG_Load(QUIT_B_OVER);

	//load logo
	logo = IMG_Load(LOGO);

	displayFormatFrame(menu_frame,7);
	displayFormatFrame(play,3);
	displayFormatFrame(set,3);
	displayFormatFrame(quit,3);


	music = Mix_LoadMUS("../src/sound/music.wav"); // load the music
	if(music == NULL){
		printf("->cant load the music \n");
		return 1;
	}

	effect = Mix_LoadWAV("../src/sound/effect1.wav");//load the sound effects
	if(effect == NULL){
		printf("->cant load the sound effect %s\n",Mix_GetError());
		return 1;
	}


	//iniatilizing the positions
	positionScreen.x = 0;
	positionScreen.y = 0;
	positionScreen.w = SCREEN_WIDTH;
	positionScreen.h = SCREEN_HEIGHT;

	positionPlay.x = FROM;
	positionPlay.y = PLAY_FROM;
	positionPlay.w = play[0]->w;
	positionPlay.h = play[0]->h;

	positionQuit.x = FROM;
	positionQuit.y = QUIT_FROM;
	positionQuit.w = quit[0]->w;
	positionQuit.h = quit[0]->h;

	positionSet.x = FROM;
	positionSet.y = SET_FROM;
	positionSet.w = set[0]->w;
	positionSet.h = set[0]->h;
	
	positionPlayer.x = 500;
	positionPlayer.y = 500;

	positionText.x = 0;
	positionText.y = SCREEN_HEIGHT - 2.55*font_surface->h;
	positionText.w = font_surface->w;
	positionText.h = font_surface->h;

	positionLogo.x = SCREEN_WIDTH - logo->w-20;
	positionLogo.y = 20;
	positionLogo.w = logo->w;
	positionLogo.h = logo->h;

	//starting everything
	SDL_BlitSurface(menu_frame[next],&positionScreen,screen,&positionDestination);
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
						next = 0;
						menu = menu_frame[next];
						nextFrame(&next,7);
						in_menu = 1;
						break;
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
				switch(event.button.button){
					case SDL_BUTTON_LEFT:

						SDL_GetMouseState(&dx_cursor,&dy_cursor);
						if(dx_cursor >= FROM && dx_cursor <= play[0]->w + FROM && in_menu != 0){

							// player wants to play
							if(dy_cursor >= PLAY_FROM && dy_cursor <= play[0]->h + PLAY_FROM){
								in_menu = 0;
								next = 0;
								game = 1;
								game_surface = SDL_DisplayFormat(IMG_Load("../src/play.jpg")); //load the game to the player
								image_player = IMG_Load("../src/characters/hero1t.PNG");

								SDL_BlitSurface(game_surface,&positionScreen,screen,&positionDestination);
								SDL_BlitSurface(image_player,&positionScreen,screen,&positionPlayer);
								SDL_Flip(screen);
								moveToMouse(&player,500,500);
								SDL_EnableKeyRepeat(10,10);
								while(game){
									
									eventHandler(&player,&positionPlayer,&game,&in_menu,&job);
									
									SDL_BlitSurface(game_surface,&positionScreen,screen,&positionDestination);
									SDL_BlitSurface(image_player,&positionScreen,screen,&positionPlayer);
									SDL_Flip(screen);
								}

								SDL_FreeSurface(image_player);
								SDL_FreeSurface(game_surface);
							}
							//open the settings
							if (dy_cursor >= SET_FROM && dy_cursor <= set[0]->h + SET_FROM){
								next = 0;
								menu_setting = SDL_DisplayFormat(IMG_Load("../src/design/bazar/wallhaven-553699.png")); //load the setting to the user
								SDL_BlitSurface(menu_setting,&positionScreen,screen,&positionDestination);
								SDL_BlitSurface(logo,NULL,screen,&positionLogo);
								SDL_Flip(screen);
								in_menu = 0;
							}
							//quit the game
							if (dy_cursor >= QUIT_FROM && dy_cursor <= quit[0]->h + QUIT_FROM){
								job = 0;
								in_menu = 0;
							}

						}
						break;

				}
				break;
		}
		
		if(in_menu){
			
			SDL_GetMouseState(&dx_cursor,&dy_cursor);
			if(dx_cursor >= FROM && dx_cursor <= play[0]->w + FROM){
				
				if(dy_cursor >= PLAY_FROM && dy_cursor <= play[0]->h + PLAY_FROM){
					if(over_play != 0){
						twist(over_play,over_quit,over_set,licence);
						Mix_PlayChannel(-1,effect,0);
					}
				}else if (dy_cursor >= SET_FROM && dy_cursor <= set[0]->h + SET_FROM){
					if(over_set != 0){
						twist(over_set,over_play,over_quit,licence);
						Mix_PlayChannel(-1,effect,0);
					}
				}else if (dy_cursor >= QUIT_FROM && dy_cursor <= quit[0]->h + QUIT_FROM){
					if(over_quit != 0){
						twist(over_quit,over_play,over_set,licence);
						Mix_PlayChannel(-1,effect,0);
					}
				}else{
					twist(over_quit,over_play,over_set,licence);
					over_quit = 1;
				}
			}else if (dx_cursor >= 0 && dx_cursor <= 100){
				if(dy_cursor >= SCREEN_HEIGHT - 100 && dy_cursor <= SCREEN_HEIGHT){
					if(licence != 0){
						twist(licence,over_set,over_play,over_quit);
					}
				} 
			}else{
				twist(over_quit,over_play,over_set,licence);
				over_quit = 1;
			}
		
		currentTime = SDL_GetTicks();
		if(currentTime - oldTime > 500){
			menu = menu_frame[next];
			nextFrame(&next,7);
			oldTime = currentTime;
		}

		SDL_BlitSurface(menu,&positionScreen,screen,&positionDestination);
		if(licence == 0){
			SDL_BlitSurface(font_surface,NULL,screen,&positionText);
		}
		SDL_BlitSurface(logo,NULL,screen,&positionLogo);

		SDL_BlitSurface(play[over_play],NULL,screen,&positionPlay);
		SDL_BlitSurface(quit[over_quit],NULL,screen,&positionQuit);
		SDL_BlitSurface(set[over_set],NULL,screen,&positionSet);

		SDL_Flip(screen);
		
		}

	}

	SDL_FreeSurface(menu);
	SDL_FreeSurface(font_surface);
	SDL_FreeSurface(image_player);
	SDL_FreeSurface(game_surface);
	SDL_FreeSurface(logo);

	for(int i = 0;i < 8;i++){
		SDL_FreeSurface(menu_frame[i]);
	}

	for(int i = 0;i < 3;i++){
		SDL_FreeSurface(play[i]);
		SDL_FreeSurface(set[i]);
		SDL_FreeSurface(quit[i]);
	}
	Mix_FreeMusic(music);
	Mix_CloseAudio();
	TTF_CloseFont(font);
	TTF_Quit();
	SDL_Quit();

	return 0;
}
