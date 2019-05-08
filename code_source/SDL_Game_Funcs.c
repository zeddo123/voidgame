#include <string.h>
#include "SDL_Game.h"
#include "SDL_scrolling.h"
#include "SDL_gestion.h"
#include "SDL_animation.h"
#include "SDL_collision.h"
#include "SDL_arduino.h"
#include "AI.h"
#include "ennemie.h"
#include "SDL_multiplayer.h"
#include "SDL_atack.h"
#include "minimap.h"
#include "SDL_jump.h"
#include "SDL_acceleration.h"
#include "SDL_savegame.h"
#include "SDL_CONDITION.h"


/*_______________________________MAIN MENU EVENT HANDLER_________________________________*/

void menuEventHandler(menu *mainMenu, menu playMenu, menu settingMenu, char *ptr_job, int *ptr_menuFrame, int *ptr_menuKey, char *ptr_in_menu, Mix_Chunk *effect, Uint32 *oldTimeKey, SDL_Surface *screen, int *oldVolume){
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
				case SDLK_RETURN:
					if(*ptr_menuKey == 0){
						
						openPlayMenu(ptr_job,effect,playMenu,screen);
						*ptr_menuFrame = 0;
						*ptr_in_menu = 1;

					}else if(*ptr_menuKey == 1){
						
						openSettingMenu(oldVolume,screen,settingMenu);
						*ptr_menuFrame = 0;
						*ptr_in_menu = 1;
					
					}else if(*ptr_menuKey == 2){
						*ptr_job = 0;
						*ptr_in_menu = 1;
					}
					break;
				case SDLK_ESCAPE:
					*ptr_menuFrame = 0;
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
					if(dx_cursor >= mainMenu->b1.position.x && dx_cursor <= mainMenu->b1.position.w + mainMenu->b1.position.x && *ptr_in_menu != 0){

						// PLAY MENU
						if(dy_cursor >= mainMenu->b1.position.y && dy_cursor <= mainMenu->b1.position.h + mainMenu->b1.position.y){
							openPlayMenu(ptr_job,effect,playMenu,screen);
							*ptr_menuFrame = 0;
							*ptr_in_menu = 1;

						}
						//open the settings
						if (dy_cursor >= mainMenu->b2.position.y && dy_cursor <= mainMenu->b2.position.h + mainMenu->b2.position.y){
							openSettingMenu(oldVolume,screen,settingMenu);
							*ptr_menuFrame = 0;
							*ptr_in_menu = 1;
						}
						//quit the game
						if (dy_cursor >= mainMenu->b3.position.y && dy_cursor <= mainMenu->b3.position.h + mainMenu->b3.position.y){
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

void openPlayMenu(char *ptr_job, Mix_Chunk *effect, menu playMenu, SDL_Surface *screen){
	char job = 1;
	char in_menu = 1;
	
	int next = 0;
	int playmenu_key = -1;
	
	int dx_cursor, dy_cursor;

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
					case SDLK_RETURN:
						if(playmenu_key == 0){
							playMultiplayer(&in_menu,&job,screen);
							in_menu = 1;
						}else if(playmenu_key == 1){
							next = 0;
							LoadGame(&in_menu,&job,screen);
							in_menu = 0;
						}else if(playmenu_key == 2){
							job = 0;
							in_menu = 0;
						}
						break;
					case SDLK_ESCAPE:
						next = 0;
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
						if(dx_cursor >= playMenu.b1.position.x && dx_cursor <= playMenu.b1.position.w + playMenu.b1.position.x && in_menu != 0){

							//play
							if(dy_cursor >= playMenu.b1.position.y && dy_cursor <= playMenu.b1.position.h + playMenu.b1.position.y){
								play(&in_menu,&job,screen);
								in_menu = 1;
							}
							//Load game
							if (dy_cursor >= playMenu.b2.position.y && dy_cursor <= playMenu.b2.position.h + playMenu.b2.position.y){
								next = 0;

								LoadGame(&in_menu,&job,screen);
								in_menu = 1;
							}
							//return 
							if (dy_cursor >= playMenu.b3.position.y && dy_cursor <= playMenu.b3.position.h + playMenu.b3.position.y){
								next = 0;
								nextFrame(&next,19);
								in_menu = 1;
								job = 0;
							}

						}
						break;

				}
				break;
		}
		
		
		if(in_menu){
			playMenu = overWhat(effect,&playmenu_key,playMenu);

			currentTime = SDL_GetTicks();
			if(currentTime - oldTimeBackground > 100){
				nextFrame(&next,7);
				oldTimeBackground = currentTime;
			}
			menuBlitter(screen,playMenu,playmenu_key,next);

		}
	}
}

/*_______________________________MAIN LOOP OF THE GAME (SOLO)_________________________________*/

void play(char *ptr_in_menu, char *ptr_job, SDL_Surface *screen){
	// Load map and Calque Map(black and white)
	SDL_Surface *game_surface = SDL_DisplayFormat(IMG_Load("../src/design/map/map.png"));
	SDL_Surface *calque_surface = SDL_DisplayFormat(IMG_Load("../src/design/map/map_back_white.png"));

	SDL_Rect positionMouse;
	
	Uint32 oldTimeEntite = 0, oldTimeDamageVillain = 0, oldTimeDamageProjectile = 0, animationTime = 0;
	
	hero player;

	projectile villainProjectile;
	
	object key, key2;
	SDL_Event event;
	enigme firstEnigme, secondEnigme;
	
	SDL_Rect camera = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
	
	TTF_Font *font = NULL;
	SDL_Color fontColor = {255, 255, 255};
	
	char bufferVie[5],bufferKey[10];
	char game = 1;
	
	ennemi villain;
	health vie;
	
	int xKEY = -1, xKEY2 = -1,follow=0,wait=1,attack=0;
	keys number_key;
	int animation2=0;
	int randpoint = -1;
	
	int quit, FRAMES_PER_SECOND = 60, paused, started, startTicks , pausedTicks;
	
	if(TTF_Init() == -1){
		exit(0);
	}

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
	villain = initEnnemie(villain,"../Sprites/entité secondaire/entité_sprite_demon_breath.png",5320,7427);

	villainProjectile.image = SDL_DisplayFormat(loadImage("../src/design/bazar/fire.png"));
	villainProjectile = launchProjectile(villainProjectile,villain.position,3);

	player = initHero(player,"../Sprites/Sprites Rayen/sprite_aio_half.png",2260,7645);

	key = initObject(key,"../src/design/bazar/key.png",5321,7427);

	key2 = initObject(key2,"../src/design/bazar/key.png",5000,7430);

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
	
	moveToMouse(&player,2260,7427);
	SDL_EnableKeyRepeat(10,15);
	while(game){
        //Mise en route du timer
        start(&started,&paused,&startTicks);
		if(eventHandlerArduino(&player,calque_surface) == 0)
			eventHandler(&player,&game,ptr_in_menu,ptr_job,calque_surface,camera,&positionMouse,&animationTime);

		moveToMouseDynamic(&player,positionMouse.x,positionMouse.y,calque_surface);

		//jump(&player,camera);
		
		camera = moveCamera(camera,player,game_surface); // gestion de la camera (scrolling)

		vie = gestionVie(player.position, villain.position, vie, &oldTimeDamageVillain); // gestion de points de vie
		vie = gestionVie(player.position,villainProjectile.position,vie,&oldTimeDamageProjectile);
		
		player.positionRelative = makeItRelative(player.position,camera);
		villain.positionRelative = makeItRelative(villain.position,camera);
		key.positionRelative = makeItRelative(key.position,camera);
		key2.positionRelative = makeItRelative(key2.position,camera);
		
		SDL_BlitSurface(game_surface,&camera,screen,NULL); //show background
		
		//SDL_BlitSurface(villain.image,&positionScreen,screen,&villain.positionRelative);
		
		if(key.state){
			SDL_BlitSurface(key.image,NULL,screen,&key.positionRelative);
		}

		if(key2.state){
			SDL_BlitSurface(key2.image,NULL,screen,&key2.positionRelative);	
		}
		
		/*---------------------------Launch the projectile------------------------------------------------*/
		
		if(!villainProjectile.active)
			villainProjectile = launchProjectile(villainProjectile,villain.position,3);
		
		moveProjectile(&villainProjectile);
				
		
		villainProjectile.positionRelative = makeItRelative(villainProjectile.position,camera);		

		if(villainProjectile.active)
			SDL_BlitSurface(villainProjectile.image,NULL,screen,&villainProjectile.positionRelative);

		/*---------------------------END-----------------------------------------------------------------*/

		Afficher_Minimap(screen,player.position,villain.position);

		/*---------------------------Show moving characters------------------------------------------------*/

		transitionn(&villain,player,camera,&vie,screen,&animation2,&follow,&wait,&attack);//Show the villain
		show(&player,screen);

		/*---------------------------END-----------------------------------------------------------------*/

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
		turnOnOff(xKEY,xKEY2);
		number_key = gestionKey(number_key,xKEY,xKEY2);
		

		sprintf(bufferVie, " %d", vie.vie);
		vie.font_vie = TTF_RenderText_Blended(font,bufferVie,fontColor);
		SDL_BlitSurface(vie.font_vie,NULL,screen,&vie.position);
		sprintf(bufferKey, "Key : %d", number_key.keys);
		number_key.font_key = TTF_RenderText_Blended(font,bufferKey,fontColor);
		SDL_BlitSurface(number_key.font_key,NULL,screen,&number_key.position);

		SDL_Flip(screen);
		
		/*---------------------------Move to next level--------------------------------------------------*/
		if(player.position.x > 5311 && player.position.x < 5511 && player.position.y > 7002 && player.position.y < 7323){
			if(number_key.keys >= 1){
				SDL_Delay(100);
				moveToMouse(&player,2089,3826);
			}
		}
        /*---------------------------END-----------------------------------------------------------------*/


        while( get_ticks(&started,&paused,&startTicks,&pausedTicks) < (1000 / FRAMES_PER_SECOND)){
			SDL_Delay( ( 1000 / FRAMES_PER_SECOND) - get_ticks(&started, &paused, &startTicks, &pausedTicks));
        }

        condition_fin(&game,player,vie,number_key,screen);

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
	SDL_FreeSurface(villainProjectile.image);

	SDL_FreeSurface(player.image);

	SDL_FreeSurface(key.image);

}
/*-----------------------Load the game-----------------------*/
/*_______________________________GAME EVENT HANDLER_________________________________*/

void eventHandler(hero *player, char *ptr_game, char *ptr_in_menu, char *ptr_job, SDL_Surface *calque_game, SDL_Rect camera, SDL_Rect *positionMouse, Uint32 *animationTime){
	SDL_Event event;
	int dx_cursor_in_game,dy_cursor_in_game;
	
	Uint32 currentTime = SDL_GetTicks();
    if(currentTime - (*animationTime) > 300){
		player->orientation = 0;
		player->step = 0;
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

				case SDLK_LSHIFT:
					acceleration(player);
					break;

				case SDLK_s:
					SaveGame(*player,1000,1,"savegame.txt");

				default:
					decceleration(player);
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


menu overWhat(Mix_Chunk *effect, int *menu_key, menu m){
	int dx_cursor, dy_cursor;
	
	SDL_GetMouseState(&dx_cursor,&dy_cursor);
	if(dx_cursor >= m.b1.position.x && dx_cursor <= m.b1.position.x + m.b1.position.w){
				
		if(dy_cursor >= m.b1.position.y && dy_cursor <= m.b1.position.y + m.b1.position.h){
		
			if(m.over_b1 != 0){
				twist(&m.over_b1,&m.over_b2,&m.over_b3,&m.over_b4);
				Mix_PlayChannel(-1,effect,0);
				*menu_key = -1;
			}
		
		}else if (dy_cursor >= m.b2.position.y && dy_cursor <= m.b2.position.y + m.b2.position.h){
		
			if(m.over_b2 != 0){
				twist(&m.over_b2,&m.over_b1,&m.over_b3,&m.over_b4);
				Mix_PlayChannel(-1,effect,0);
				*menu_key = -1;
			}
		
		}else if (dy_cursor >= m.b3.position.y && dy_cursor <= m.b3.position.y + m.b3.position.h){
		
			if(m.over_b3 != 0){
				twist(&m.over_b3,&m.over_b2,&m.over_b1,&m.over_b4);
				Mix_PlayChannel(-1,effect,0);
				*menu_key = -1;
			}
		
		}else if(dy_cursor >= m.b4.position.y && dy_cursor <= m.b4.position.y + m.b4.position.h){
		
			if(m.over_b4 != 0){
				twist(&m.over_b4,&m.over_b3,&m.over_b2,&m.over_b1);
			} 
		
		}else{
			twist(&m.over_b3,&m.over_b2,&m.over_b1,&m.over_b4);
			m.over_b3 = 1;
		
		}
	}else{
		twist(&m.over_b3,&m.over_b2,&m.over_b1,&m.over_b4);
		m.over_b3 = 1;
	}

	return m;
}


/*_______________________________MENU BLITTER_________________________________*/


void menuBlitter(SDL_Surface *screen, menu m, int menu_key, int next){
	
	SDL_BlitSurface(m.background[next],NULL,screen,NULL);
		
	SDL_BlitSurface(m.menuLogo,&m.menuLogoCrop,screen,&m.menuLogoPosition);
		
	if(menu_key == -1){
		SDL_BlitSurface(m.b1.image[m.over_b1],NULL,screen,&m.b1.position);
		SDL_BlitSurface(m.b2.image[m.over_b2],NULL,screen,&m.b2.position);
		SDL_BlitSurface(m.b3.image[m.over_b3],NULL,screen,&m.b3.position);
	}else if(menu_key == 0){
		SDL_BlitSurface(m.b1.image[0],NULL,screen,&m.b1.position);
		SDL_BlitSurface(m.b2.image[1],NULL,screen,&m.b2.position);
		SDL_BlitSurface(m.b3.image[1],NULL,screen,&m.b3.position);
	}else if(menu_key == 1){
		SDL_BlitSurface(m.b1.image[1],NULL,screen,&m.b1.position);
		SDL_BlitSurface(m.b2.image[0],NULL,screen,&m.b2.position);
		SDL_BlitSurface(m.b3.image[1],NULL,screen,&m.b3.position);
	}else if (menu_key == 2){
		SDL_BlitSurface(m.b1.image[1],NULL,screen,&m.b1.position);
		SDL_BlitSurface(m.b2.image[1],NULL,screen,&m.b2.position);
		SDL_BlitSurface(m.b3.image[0],NULL,screen,&m.b3.position);	}
	if(m.over_b4 == 0){
		SDL_BlitSurface(m.font.image[0],NULL,screen,&m.font.position);
	}
	SDL_Flip(screen);
}

/*_______________________________NAVIGATE IN THE MENU WITH KEYBOARD_________________________________*/

int moveInMenuByKeyboard(int pointeur, int operation, int a, int b, Uint32 *oldTime){
	Uint32 currentTime = SDL_GetTicks();
	if(currentTime - (*oldTime) > 50){
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

/*_______________________________Volume mixer_________________________________*/

void setVolume(int volumeValue){
	Mix_VolumeMusic(volumeValue);
}

/*_______________________________Settings menu_________________________________*/

void openSettingMenu(int* oldVolume, SDL_Surface* screen, menu settings){
	int job = 1;
	
	SDL_Rect fullBar = {210,PLAY_FROM+50,384,30}; // the Rect of the full volume bar
	SDL_Rect currBar = {210,PLAY_FROM+50,*oldVolume * 3,30}; // the Rect of the current volume level
	
	SDL_Rect volumePosition = {350,PLAY_FROM,0,0};// the Rect of the position of the Text "Volume"
	
	Uint32 colorCurr = SDL_MapRGB(screen->format, 130, 71, 152);
	Uint32 colorFull = SDL_MapRGB(screen->format, 39, 50, 56);
	SDL_Color white = {255, 255, 255};
	
	SDL_Surface *volumeText = NULL;
	TTF_Font *font = NULL;

	if(TTF_Init() == -1){
		exit(0);
	}
	font = TTF_OpenFont("../src/font/blue highway rg.ttf",40);
	
	if(font == NULL){
		fprintf(stderr, "Enable to load font from the file\n");
		return;
	}

	volumeText = TTF_RenderText_Blended(font,"Volume",white);
	if(volumeText == NULL){
		fprintf(stderr, "Enable to load TTF font\n");
		return;
	}


	while(job){
		settingsEventHandler(&job,oldVolume,fullBar,settings);
		currBar.w = *oldVolume * 3;
		
		//draw the background
		SDL_BlitSurface(settings.background[0],NULL,screen,NULL);
		
		//draw the menu
		SDL_BlitSurface(settings.menuLogo,&settings.menuLogoCrop,screen,&settings.menuLogoPosition);
		
		//draw the volume level
		SDL_FillRect(screen, &fullBar, colorFull);
		SDL_FillRect(screen, &currBar, colorCurr);
		
		//draw the text "Volume" above the volume level selector
		SDL_BlitSurface(volumeText,NULL,screen,&volumePosition);

		SDL_BlitSurface(settings.b1.image[0],NULL,screen,&settings.b1.position);
		
		SDL_Flip(screen);
	}
	
	SDL_FreeSurface(volumeText);
	TTF_CloseFont(font);

}

void settingsEventHandler(int *job, int *oldVolume, SDL_Rect fullBar, menu settings){
	int dx_cursor, dy_cursor;
	SDL_Event event;

	SDL_PollEvent(&event);
	switch(event.type){
		case SDL_QUIT:
				printf("..Quiting..\n");
				*job = 0;
				break;
		case SDL_MOUSEBUTTONDOWN:
			switch(event.button.button){
				case SDL_BUTTON_LEFT:
					SDL_GetMouseState(&dx_cursor,&dy_cursor);
					// Over the volume splider
					if(dy_cursor >= fullBar.y && dy_cursor <= (fullBar.h + fullBar.y)){
						if(dx_cursor >= fullBar.x && dx_cursor <= (fullBar.w + fullBar.x)){
							*oldVolume = (dx_cursor - 210) / 3;
							setVolume(*oldVolume);
						}
					}

					if(dx_cursor >= settings.b1.position.x && dx_cursor <= settings.b1.position.w + settings.b1.position.x){
							//return 
							if (dy_cursor >= settings.b1.position.y && dy_cursor <= settings.b1.position.h + settings.b1.position.y){
								*job = 0;
							}

					}

			}
			break;
	}
}

hero selectCharacter(SDL_Surface* screen){
	menu selectMenu = initSelectMenu();
	int job = 1;
	int menu_key = -1;
	int selected = -1;
	Uint32 oldTimeKey;

	while(job && selected == -1){
		selected = eventSelect(selectMenu,&job,&menu_key,&oldTimeKey);
		menuBlitter(screen,selectMenu,menu_key,0);
	}
	if(selected == 0){
		
	}else if(selected == 1){

	}else{

	}
}

int eventSelect(menu m, int *job, int *ptr_menuKey, Uint32 *oldTimeKey){
	SDL_Event event;
	int dx_cursor,dy_cursor;
	SDL_PollEvent(&event);

	switch(event.type){
		case SDL_QUIT:
			*job = 0;
			break;
		case SDL_KEYDOWN:
			switch(event.key.keysym.sym){
				case SDLK_RETURN:
					return *ptr_menuKey;
					break;
				case SDLK_ESCAPE:
					*job = 1;
					break;
				case SDLK_DOWN:
					*ptr_menuKey = moveInMenuByKeyboard(*ptr_menuKey,1,2,0,oldTimeKey);
					break;
				case SDLK_UP:
					*ptr_menuKey = moveInMenuByKeyboard(*ptr_menuKey,-1,0,2,oldTimeKey);
					break;
			}
			break;
		case SDL_MOUSEBUTTONDOWN:
			switch(event.button.button){
				case SDL_BUTTON_LEFT:

					SDL_GetMouseState(&dx_cursor,&dy_cursor);
					if(dx_cursor >= m.b1.position.x && dx_cursor <= m.b1.position.w + m.b1.position.x){

						// PLAY MENU
						if(dy_cursor >= m.b1.position.y && dy_cursor <= m.b1.position.h + m.b1.position.y){
							return 0;

						}
						//open the settings
						if (dy_cursor >= m.b2.position.y && dy_cursor <= m.b2.position.h + m.b2.position.y){
							return 1;
						}
						//quit the game
						if (dy_cursor >= m.b3.position.y && dy_cursor <= m.b3.position.h + m.b3.position.y){
							return 2;
						}

					}
					break;

			}
			break;
	}
	return -1;
}