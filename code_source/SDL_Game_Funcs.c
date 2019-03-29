#include <string.h>
#include "SDL_Game.h"
#include "SDL_scrolling.h"
#include "SDL_gestion.h"
#include "SDL_animation.h"
#include "SDL_collision.h"

/*_______________________________MAIN MENU EVENT HANDLER_________________________________*/

void menuEventHandler(SDL_Surface *menu, char *ptr_job, int *ptr_menuFrame, int *ptr_menuKey, char *ptr_in_menu, Mix_Chunk *effect, Uint32 *oldTimeKey,SDL_Rect positionScreen, SDL_Surface *screen, SDL_Rect positionText, SDL_Surface *font, SDL_Rect logoCrop, SDL_Rect positionLogo, SDL_Surface *logo, SDL_Surface *play[], SDL_Surface *set[], SDL_Surface *quit[], SDL_Rect positionNewGame, SDL_Surface *newGame[], SDL_Rect positionLoadGame, SDL_Surface *loadGame[], SDL_Rect positionBack, SDL_Surface *back[] ,SDL_Surface *background[], SDL_Surface *menu_frame[], SDL_Surface *menu_setting){
	SDL_Event event;
	int dx_cursor, dy_cursor;
	SDL_PollEvent(&event);

	switch(event.type){
		case SDL_QUIT:
			printf("..Quiting the menu..\n");
			*ptr_job = 0;
			break;
		case SDL_KEYDOWN:
			switch(event.key.keysym.sym){
				case SDLK_ESCAPE:
					*ptr_menuFrame = 0;
					menu = menu_frame[*ptr_menuFrame];
					nextFrame(ptr_menuFrame,19);
					*ptr_in_menu = 1;
					break;
				case SDLK_DOWN:
					*ptr_menuKey = moveInMenuByKeyboard(*ptr_menuKey,1,2,0,oldTimeKey);
					Mix_PlayChannel(-1,effect,0);
					break;
				case SDLK_UP:
					*ptr_menuKey = moveInMenuByKeyboard(*ptr_menuKey,-1,0,2,oldTimeKey);
					Mix_PlayChannel(-1,effect,0);
					break;
			}
			break;
		case SDL_MOUSEBUTTONDOWN:
			switch(event.button.button){
				case SDL_BUTTON_LEFT:

					SDL_GetMouseState(&dx_cursor,&dy_cursor);
					if(dx_cursor >= FROM && dx_cursor <= play[0]->w + FROM && *ptr_in_menu != 0){

						// PLAY MENU
						if(dy_cursor >= PLAY_FROM && dy_cursor <= play[0]->h + PLAY_FROM){
							playMenu(ptr_job,effect,
									positionScreen,screen,
									positionText,font,
									logoCrop,positionLogo,logo,
									positionNewGame,newGame,
									positionLoadGame,loadGame,
									positionBack,back,background);

							*ptr_menuFrame = 0;
							menu = menu_frame[*ptr_menuFrame];
							nextFrame(ptr_menuFrame,19);
							*ptr_in_menu = 1;
						}
						//open the settings
						if (dy_cursor >= SET_FROM && dy_cursor <= set[0]->h + SET_FROM){
							*ptr_menuFrame = 0;
							//load the setting to the user
							SDL_BlitSurface(menu_setting,NULL,screen,NULL);
							SDL_BlitSurface(logo,NULL,screen,&positionLogo);
							SDL_Flip(screen);
							*ptr_in_menu = 0;
						}
						//quit the game
						if (dy_cursor >= QUIT_FROM && dy_cursor <= quit[0]->h + QUIT_FROM){
							*ptr_job = 0;
							*ptr_in_menu = 1;
						}

					}
					break;

			}
			break;
	}
}

/*_______________________________PLAY MENU_________________________________*/

void playMenu(char *ptr_job, Mix_Chunk *effect, SDL_Rect positionScreen, SDL_Surface *screen, SDL_Rect positionText, SDL_Surface *font, SDL_Rect logoCrop, SDL_Rect positionLogo, SDL_Surface *logo, SDL_Rect positionNewGame, SDL_Surface *newGame[], SDL_Rect positionLoadGame, SDL_Surface *loadGame[], SDL_Rect positionBack, SDL_Surface *back[], SDL_Surface *background[]){
	char job = 1;
	char in_menu = 1;
	int next = 0;
	int playmenu_key = -1;
	int dx_cursor, dy_cursor;
	int over_new = 1, over_load = 1, over_back = 1, licence = 1;
	SDL_Surface *playMenu;
	Uint32 oldTimeKey , oldTimeBackground, currentTime;
	SDL_Event event;


	while(job){

		SDL_PollEvent(&event);
		switch(event.type){
			case SDL_QUIT:
				printf("..Quiting..\n");
				job = 0;
				*ptr_job = 0;
				break;
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym){
					case SDLK_ESCAPE:
						next = 0;
						playMenu = background[next];
						nextFrame(&next,19);
						in_menu = 1;
						job = 0;
						break;
					case SDLK_DOWN:
						playmenu_key = moveInMenuByKeyboard(playmenu_key,1,2,0,&oldTimeKey);
						Mix_PlayChannel(-1,effect,0);
						break;
					case SDLK_UP:
						playmenu_key = moveInMenuByKeyboard(playmenu_key,-1,0,2,&oldTimeKey);
						Mix_PlayChannel(-1,effect,0);
						break;
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
				switch(event.button.button){
					case SDL_BUTTON_LEFT:

						SDL_GetMouseState(&dx_cursor,&dy_cursor);
						if(dx_cursor >= FROM && dx_cursor <= newGame[0]->w + FROM && in_menu != 0){

							//play
							if(dy_cursor >= PLAY_FROM && dy_cursor <= newGame[0]->h + PLAY_FROM){
								play(&in_menu,&job,positionScreen,screen);
								in_menu = 1;
							}
							//Load game
							if (dy_cursor >= SET_FROM && dy_cursor <= loadGame[0]->h + SET_FROM){
								next = 0;
								//CODE TO LOAD GAME HERE!!!!
								in_menu = 0;
							}
							//return 
							if (dy_cursor >= QUIT_FROM && dy_cursor <= back[0]->h + QUIT_FROM){
								job = 0;
								in_menu = 0;
							}

						}
						break;

				}
				break;
		}
		
		
		if(in_menu){
			overWhat(effect,&playmenu_key,FROM,FROM + newGame[0]->w,
					PLAY_FROM,PLAY_FROM + newGame[0]->h,
					SET_FROM,SET_FROM + loadGame[0]->h,
					QUIT_FROM,QUIT_FROM + back[0]->h,
					0,100,
					0,100,
					&over_new,&over_load,&over_back,&licence);

			currentTime = SDL_GetTicks();
			if(currentTime - oldTimeBackground > 200){
				playMenu = background[next];
				nextFrame(&next,7);
				oldTimeBackground = currentTime;
			}
			menuBlitter(positionScreen,screen,playMenu,positionText,font,logoCrop,positionLogo,logo,positionNewGame,newGame,positionLoadGame,loadGame,positionBack,back,over_new,over_load,over_back,licence,playmenu_key);

		}
	}
}

/*_______________________________MAIN LOOP OF THE GAME_________________________________*/

void play(char *ptr_in_menu, char *ptr_job, SDL_Rect positionScreen, SDL_Surface *screen){
	// Load map and Calque Map(black and white)
	SDL_Surface *game_surface = SDL_DisplayFormat(IMG_Load("../src/design/map/map.png"));
	SDL_Surface *calque_surface = SDL_DisplayFormat(IMG_Load("../src/design/map/map_back_white.png"));

	SDL_Rect positionMouse;
	Uint32 oldTimeEntite = 0, oldTimeDamage = 0;
	
	hero villain, player;
	
	object key, circle,key2;
	Circle c;
	
	enigme firstEnigme, secondEnigme;
	
	SDL_Rect camera = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
	
	TTF_Font *font = NULL;
	SDL_Color fontColor = {63, 13, 58};
	
	char bufferVie[5],bufferKey[10];
	char game = 1;
	
	health vie;
	
	int xKEY = -1, xKEY2 = -1;
	keys number_key;
	
	int randpoint = -1;
	
	int quit, FRAMES_PER_SECOND = 120, paused, started, startTicks , pausedTicks;
	
	SDL_Event animEvent;


	//init TTF Font
	font = TTF_OpenFont("../src/font/Baron Neue.otf",50);

	//Init health
	vie.vie = 1000;
	sprintf(bufferVie, "%d", vie.vie);
	vie.font_vie = TTF_RenderText_Blended(font,bufferVie,fontColor);
	vie.position = initPosition(vie.position,50,20,vie.font_vie->w,vie.font_vie->h);
	
	//Init number keys
	number_key.keys = 0;
	sprintf(bufferKey, "Key : %d", number_key.keys);
	number_key.font_key = TTF_RenderText_Blended(font,bufferKey,fontColor);
	number_key.position = initPosition(number_key.position,SCREEN_WIDTH - 199,20,number_key.font_key->w,number_key.font_key->h);

	
	//init position and images

	villain = initHero(villain,"../src/characters/hero2t.png",5320,7427);

	player = initHero(player,"../src/characters/hero1t.PNG",1,SCREEN_HEIGHT / 2);

	key = initObject(key,"../src/design/bazar/key.png",5321,7427);

	key2 = initObject(key2,"../src/design/bazar/key.png",5000,7430);

	circle = initObject(circle,"../src/design/bazar/circle.png",200,200);
	c.x = circle.position.x;
	c.y = circle.position.y;
	c.r = circle.position.w / 2;

	//Init riddle 1

	firstEnigme = fetchQuestion("enigme.q","enigme.s");
	firstEnigme.positionRiddle = initPosition(firstEnigme.positionRiddle,key.position.x,key.position.y,key.position.w,key.position.h);
	firstEnigme = loadTextForRiddle(firstEnigme);
	
	firstEnigme.Background = loadImage("../src/design/enigmes/question_box.png");
	firstEnigme.Button[0] = loadImage("../src/design/enigmes/answer_box_0.png"); //non selected
	firstEnigme.Button[1] = loadImage("../src/design/enigmes/answer_box_1.png"); //selected	
	
	firstEnigme = initPrintRiddle(firstEnigme);
	
	//Init riddle 1

	secondEnigme = createQustion();
	secondEnigme.positionRiddle = initPosition(secondEnigme.positionRiddle,key2.position.x,key2.position.y,key2.position.w,key2.position.h);
	secondEnigme = loadTextForRiddle(secondEnigme);
	
	secondEnigme.Background = loadImage("../src/design/enigmes/question_box.png");
	secondEnigme.Button[0] = firstEnigme.Button[0]; //non selected
	secondEnigme.Button[1] = firstEnigme.Button[1]; //selected	
	
	secondEnigme = initPrintRiddle(secondEnigme);
	

	moveToMouse(&player,2657,7429);
	SDL_EnableKeyRepeat(10,15);
	
	while(game){
        //Mise en route du timer
        start(&started,&paused,&startTicks);
		
		eventHandler(&player,&game,ptr_in_menu,ptr_job,calque_surface,camera,&positionMouse);

		moveToMouseDynamic(&player,positionMouse.x,positionMouse.y);

		moveBetweenTwoRandom(&villain,1,5120,5320,&oldTimeEntite,&randpoint);
		
		//show(&player);


		camera = moveCamera(camera,player,game_surface); // gestion de la camera (scrolling)

		vie = gestionVie(player, villain, vie, &oldTimeDamage); // gestion de points de vie

		player.positionRelative = makeItRelative(player.position,camera);
		villain.positionRelative = makeItRelative(villain.position,camera);
		key.positionRelative = makeItRelative(key.position,camera);
		key2.positionRelative = makeItRelative(key2.position,camera);
		circle.positionRelative = makeItRelative(circle.position,camera);
		
		SDL_BlitSurface(game_surface,&camera,screen,NULL); //show background
		
		SDL_BlitSurface(villain.image,&positionScreen,screen,&villain.positionRelative);
		
		if(key.state){
			SDL_BlitSurface(key.image,&positionScreen,screen,&key.positionRelative);
		}

		if(key2.state){
			SDL_BlitSurface(key2.image,&positionScreen,screen,&key2.positionRelative);	
		}

		SDL_BlitSurface(circle.image,&positionScreen,screen,&circle.positionRelative);

		SDL_BlitSurface(player.image,NULL,screen,&player.positionRelative);

		if(collisionBxC(c,player.position) == 1){
			vie.vie -= 1;
		}
		
		if(xKEY == -1){
			xKEY = riddle(firstEnigme,player,screen);
			if(xKEY != -1){
				key.state = 0;
			}
		}
		
		if(xKEY2 == -1){
			xKEY2 = riddle(secondEnigme,player,screen);
			if(xKEY2 != -1){
				key2.state = 0;
			}
		}

		number_key = gestionKey(number_key,xKEY,xKEY2);
		

		sprintf(bufferVie, " %d", vie.vie);
		vie.font_vie = TTF_RenderText_Blended(font,bufferVie,fontColor);
		SDL_BlitSurface(vie.font_vie,NULL,screen,&vie.position);
		
		sprintf(bufferKey, "Key : %d", number_key.keys);
		number_key.font_key = TTF_RenderText_Blended(font,bufferKey,fontColor);
		SDL_BlitSurface(number_key.font_key,NULL,screen,&number_key.position);

		SDL_Flip(screen);

        while( get_ticks(started,paused,startTicks,pausedTicks) < 1000 / FRAMES_PER_SECOND){
			SDL_Delay( ( 1000 / FRAMES_PER_SECOND) - get_ticks(started, paused, startTicks, pausedTicks));
        }

	}
	TTF_CloseFont(font);

	SDL_FreeSurface(game_surface);
	SDL_FreeSurface(calque_surface);
	
	SDL_FreeSurface(firstEnigme.Button[0]);
	SDL_FreeSurface(firstEnigme.Button[1]);
	SDL_FreeSurface(firstEnigme.Background);
	SDL_FreeSurface(firstEnigme.Question);
	SDL_FreeSurface(firstEnigme.Answer1);
	SDL_FreeSurface(firstEnigme.Answer2);
	SDL_FreeSurface(firstEnigme.Answer3);
	SDL_FreeSurface(firstEnigme.Answer4);

	SDL_FreeSurface(secondEnigme.Background);
	SDL_FreeSurface(secondEnigme.Question);
	SDL_FreeSurface(secondEnigme.Answer1);
	SDL_FreeSurface(secondEnigme.Answer2);
	SDL_FreeSurface(secondEnigme.Answer3);
	SDL_FreeSurface(secondEnigme.Answer4);
	
	SDL_FreeSurface(vie.font_vie);

	SDL_FreeSurface(villain.image);
	SDL_FreeSurface(player.image);

	SDL_FreeSurface(key.image);

}

/*_______________________________GAME EVENT HANDLER_________________________________*/

void eventHandler(hero *player, char *ptr_game, char *ptr_in_menu, char *ptr_job, SDL_Surface *calque_game, SDL_Rect camera, SDL_Rect *positionMouse){
	
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
					if(collision_Parfaite(calque_game,player->image,player->position,STEP,0) != 1){
						move(player,0,-1);
						player->moveWithMouse = 0;
					}
					break;
				
				case SDLK_DOWN:
					if(collision_Parfaite(calque_game,player->image,player->position,STEP,1) != 1){
						move(player,0,1);
						player->moveWithMouse = 0;
					}
					break;
				
				case SDLK_LEFT:
					if(collision_Parfaite(calque_game,player->image,player->position,STEP,3) != 1){
						move(player,1,-1);
						player->moveWithMouse = 0;
					}
					break;
				case SDLK_RIGHT:
					if(collision_Parfaite(calque_game,player->image,player->position,STEP,2) != 1){
						move(player,1,1);
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


/*_______________________________MOUSEOVER && KEYBOARDOVER HANDLER_________________________________*/


void overWhat(Mix_Chunk *effect, int *menu_key, int x1a, int x1b, int y1a, int y1b, int y2a, int y2b, int y3a, int y3b, int x2a, int x2b, int y4a, int y4b, int *button1, int *button2, int *button3, int *button4){
	/*	XXa : coordonnees de debut
		XXb : coordonnees de fin
	*/
	int dx_cursor, dy_cursor;
	
	SDL_GetMouseState(&dx_cursor,&dy_cursor);
	if(dx_cursor >= x1a && dx_cursor <= x1b){
				
		if(dy_cursor >= y1a && dy_cursor <= y1b){
		
			if(*button1 != 0){
				twist(button1,button2,button3,button4);
				Mix_PlayChannel(-1,effect,0);
				*menu_key = -1;
			}
		
		}else if (dy_cursor >= y2a && dy_cursor <= y2b){
		
			if(*button2 != 0){
				twist(button2,button1,button3,button4);
				Mix_PlayChannel(-1,effect,0);
				*menu_key = -1;
			}
		
		}else if (dy_cursor >= y3a && dy_cursor <= y3b){
		
			if(*button3 != 0){
				twist(button3,button2,button1,button4);
				Mix_PlayChannel(-1,effect,0);
				*menu_key = -1;
			}
		
		}else if(dy_cursor >= y4a && dy_cursor <= y4b){
		
			if(*button4 != 0){
				twist(button4,button2,button3,button1);
			} 
		
		}else{
			twist(button3,button2,button1,button4);
			*button3 = 1;
		
		}
	}else{
		twist(button3,button2,button1,button4);
		*button3 = 1;
	}
}


/*_______________________________MENU BLITTER_________________________________*/


void menuBlitter(SDL_Rect positionScreen,SDL_Surface *screen,SDL_Surface *background, SDL_Rect positionText,SDL_Surface *font, SDL_Rect logoCrop, SDL_Rect positionLogo, SDL_Surface *logo, SDL_Rect positionB1, SDL_Surface *button1[], SDL_Rect positionB2, SDL_Surface *button2[], SDL_Rect positionB3, SDL_Surface *button3[], int over_b1, int over_b2, int over_b3, int over_b4, int menu_key){
	
	SDL_BlitSurface(background,&positionScreen,screen,NULL);
		
	SDL_BlitSurface(logo,&logoCrop,screen,&positionLogo);
		
	if(menu_key == -1){
		SDL_BlitSurface(button1[over_b1],NULL,screen,&positionB1);
		SDL_BlitSurface(button2[over_b2],NULL,screen,&positionB2);
		SDL_BlitSurface(button3[over_b3],NULL,screen,&positionB3);
	}else if(menu_key == 0){
		SDL_BlitSurface(button1[0],NULL,screen,&positionB1);
		SDL_BlitSurface(button2[1],NULL,screen,&positionB2);
		SDL_BlitSurface(button3[1],NULL,screen,&positionB3);
	}else if(menu_key == 1){
		SDL_BlitSurface(button1[1],NULL,screen,&positionB1);
		SDL_BlitSurface(button2[0],NULL,screen,&positionB2);
		SDL_BlitSurface(button3[1],NULL,screen,&positionB3);
	}else if (menu_key == 2){
		SDL_BlitSurface(button1[1],NULL,screen,&positionB1);
		SDL_BlitSurface(button2[1],NULL,screen,&positionB2);
		SDL_BlitSurface(button3[0],NULL,screen,&positionB3);
	}
	if(over_b4 == 0){
		SDL_BlitSurface(font,NULL,screen,&positionText);
	}
	SDL_Flip(screen);
}

/*_______________________________NAVIGATE IN THE MENU WITH KEYBOARD_________________________________*/

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

/*_______________________________MOUSEOVER OPTIMIZATION_________________________________*/

void twist(int *a, int *b, int *c, int *d){
	*a = 0;
	*b = 1;
	*c = 1;
	*d = 1;
}
