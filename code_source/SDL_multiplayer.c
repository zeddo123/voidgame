#include "SDL_multiplayer.h"

void playMultiplayer(char *ptr_in_menu, char *ptr_job, SDL_Surface *screen){
	// Load map and Calque Map(black and white)
	SDL_Surface *game_surface = SDL_DisplayFormat(IMG_Load("../src/design/map/map.png"));
	SDL_Surface *calque_surface = SDL_DisplayFormat(IMG_Load("../src/design/map/map_back_white.png"));

	SDL_Rect positionMouse1;
	SDL_Rect positionMouse2;

	Uint32 oldTimeEntite = 0, oldTimeDamage = 0;
	
	hero villain, player1, player2;
	
	object key_player1, key2_player1;
	object key_player2, key2_player2;
	
	enigme firstEnigme_player1, secondEnigme_player1;
	enigme firstEnigme_player2, secondEnigme_player2;

	SDL_Rect camera1 = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT / 2};
	SDL_Rect split1 = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT / 2};
	
	SDL_Rect camera2 = {0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2};
	SDL_Rect split2 = {0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2};
	
	TTF_Font *font = NULL;
	SDL_Color fontColor = {63, 13, 58};
	
	char bufferVie[5],bufferKey[10];
	char game = 1;
	
	health vie_player1, vie_player2;
	
	int xKEY_player1 = -1, xKEY2_player1 = -1;
	int xKEY_player2 = -1, xKEY2_player2 = -1;
	
	keys number_key_player1, number_key_player2;
	
	int randpoint = -1;
	
	int quit, FRAMES_PER_SECOND = 120, paused, started, startTicks , pausedTicks;
	
	SDL_Event animEvent;

	if(TTF_Init() == -1){
		exit(0);
	}

	//init TTF Font
	font = TTF_OpenFont("../src/font/Baron Neue.otf",50);

	//Init player 1 health
	vie_player1.vie = 1000;
	sprintf(bufferVie, "%d", vie_player1.vie);
	vie_player1.font_vie = TTF_RenderText_Blended(font,bufferVie,fontColor);
	vie_player1.position = initPosition(vie_player1.position,50,20,vie_player1.font_vie->w,vie_player1.font_vie->h);
	
	//Init player 2 health
	vie_player2.vie = 1000;
	sprintf(bufferVie, "%d", vie_player2.vie);
	vie_player2.font_vie = TTF_RenderText_Blended(font,bufferVie,fontColor);
	vie_player2.position = initPosition(vie_player2.position,SCREEN_WIDTH / 2 + 50,20,vie_player2.font_vie->w,vie_player2.font_vie->h);
	
	//Init number keys player1
	number_key_player1.keys = 0;
	sprintf(bufferKey, "Key : %d", number_key_player1.keys);
	number_key_player1.font_key = TTF_RenderText_Blended(font,bufferKey,fontColor);
	number_key_player1.position = initPosition(number_key_player1.position,SCREEN_WIDTH / 2 - 199,20,number_key_player1.font_key->w,number_key_player1.font_key->h);
	
	//Init number keys player2
	number_key_player2.keys = 0;
	sprintf(bufferKey, "Key : %d", number_key_player2.keys);
	number_key_player2.font_key = TTF_RenderText_Blended(font,bufferKey,fontColor);
	number_key_player2.position = initPosition(number_key_player2.position,SCREEN_WIDTH - 199,20,number_key_player2.font_key->w,number_key_player2.font_key->h);
	
	//init position and images
	set_clips(&villain);
	villain = initHero(villain,"../src/characters/Rayen_left_right.png",5320,7427);

	set_clips(&player1);
	player1 = initHero(player1,"../src/characters/Rayen_left_right.png",2260,7645);

	set_clips(&player2);
	player2 = initHero(player2,"../src/characters/Rayen_left_right.png",2260,7645);

	key_player1 = initObject(key_player1,"../src/design/bazar/key.png",5321,7427);

	key2_player2 = initObject(key2_player2,"../src/design/bazar/key.png",5000,7430);

	//Init riddle 1 of player 1

	firstEnigme_player1 = fetchQuestion("enigme.q","enigme.s");
	firstEnigme_player1.positionRiddle = initPosition(firstEnigme_player1.positionRiddle,key_player1.position.x,key_player1.position.y,key_player1.position.w,key_player1.position.h);
	firstEnigme_player1 = loadTextForRiddle(firstEnigme_player1);
	
	firstEnigme_player1.Background = loadImage("../src/design/enigmes/question_box.png");
	firstEnigme_player1.Button[0] = loadImage("../src/design/enigmes/answer_box_0.png"); //non selected
	firstEnigme_player1.Button[1] = loadImage("../src/design/enigmes/answer_box_1.png"); //selected	
	
	firstEnigme_player1 = initPrintRiddle(firstEnigme_player1);
	
	//Init riddle 1 of player 2

	firstEnigme_player2 = fetchQuestion("enigme.q","enigme.s");
	firstEnigme_player2.positionRiddle = initPosition(firstEnigme_player2.positionRiddle,key_player2.position.x,key_player2.position.y,key_player2.position.w,key_player2.position.h);
	firstEnigme_player2 = loadTextForRiddle(firstEnigme_player2);
	
	firstEnigme_player2.Background = firstEnigme_player1.Background;
	firstEnigme_player2.Button[0] = firstEnigme_player1.Button[0]; //non selected
	firstEnigme_player2.Button[1] = firstEnigme_player1.Button[1]; //selected	
	
	firstEnigme_player2 = initPrintRiddle(firstEnigme_player2);
	
	//Init riddle player 1

	secondEnigme_player1 = createQustion();
	secondEnigme_player1.positionRiddle = initPosition(secondEnigme_player1.positionRiddle,key2_player1.position.x,key2_player1.position.y,key2_player1.position.w,key2_player1.position.h);
	secondEnigme_player1 = loadTextForRiddle(secondEnigme_player1);
	
	secondEnigme_player1.Background = loadImage("../src/design/enigmes/question_box.png");
	secondEnigme_player1.Button[0] = firstEnigme_player1.Button[0]; //non selected
	secondEnigme_player1.Button[1] = firstEnigme_player1.Button[1]; //selected	
	
	secondEnigme_player1 = initPrintRiddle(secondEnigme_player1);
	
	//Init riddle player 2

	secondEnigme_player2 = createQustion();
	secondEnigme_player2.positionRiddle = initPosition(secondEnigme_player2.positionRiddle,key2_player2.position.x,key2_player2.position.y,key2_player2.position.w,key2_player2.position.h);
	secondEnigme_player2 = loadTextForRiddle(secondEnigme_player2);
	
	secondEnigme_player2.Background = loadImage("../src/design/enigmes/question_box.png");
	secondEnigme_player2.Button[0] = firstEnigme_player2.Button[0]; //non selected
	secondEnigme_player2.Button[1] = firstEnigme_player2.Button[1]; //selected	
	
	secondEnigme_player2 = initPrintRiddle(secondEnigme_player2);
	
	moveToMouse(&player1,2260,7427);
	moveToMouse(&player2,2260,7427);
	SDL_EnableKeyRepeat(10,15);
	
	while(game){
        //Mise en route du timer
        start(&started,&paused,&startTicks);

		if(eventHandlerArduino(&player2,calque_surface) == 0)
			eventHandlerMultiplayer(&player1,&player2,&game,ptr_in_menu,ptr_job,calque_surface,camera1,camera2,&positionMouse1,&positionMouse2);

		moveToMouseDynamic(&player1,positionMouse1.x,positionMouse1.y,calque_surface);
		moveToMouseDynamic(&player2,positionMouse2.x,positionMouse2.y,calque_surface);

		moveBetweenTwoRandom(&villain,1,5120,5320,&oldTimeEntite,&randpoint);
		


		camera1 = moveCameraPlayer1(camera1,player1,game_surface); // gestion de la camera (scrolling)
		camera2 = moveCameraPlayer2(camera2,player2,game_surface); // gestion de la camera (scrolling)

		vie_player1 = gestionVie(player1, villain, vie_player1, &oldTimeDamage); // gestion de points de vie
		vie_player2 = gestionVie(player2, villain, vie_player2, &oldTimeDamage); // gestion de points de vie

		player1.positionRelative = makeItRelative(player1.position,camera1);
		villain.positionRelative = makeItRelative(villain.position,camera1);
		key_player1.positionRelative = makeItRelative(key_player1.position,camera1);
		key2_player1.positionRelative = makeItRelative(key2_player1.position,camera1);		

		player2.positionRelative = makeItRelative(player2.position,camera2);
		villain.positionRelative = makeItRelative(villain.position,camera2);
		key_player2.positionRelative = makeItRelative(key_player2.position,camera2);
		key2_player2.positionRelative = makeItRelative(key2_player2.position,camera2);		

		SDL_BlitSurface(game_surface,&camera1,screen,&split1); //show background
		SDL_BlitSurface(game_surface,&camera2,screen,&split2); //show background
		
		//SDL_BlitSurface(villain.image,&positionScreen,screen,&villain.positionRelative);
		
		if(key_player1.state){
			SDL_BlitSurface(key_player1.image,NULL,screen,&key_player1.positionRelative);
		}
		if(key_player2.state){
			SDL_BlitSurface(key_player2.image,NULL,screen,&key_player2.positionRelative);
		}

		if(key2_player1.state){
			SDL_BlitSurface(key2_player1.image,NULL,screen,&key2_player1.positionRelative);	
		}
		if(key2_player2.state){
			SDL_BlitSurface(key2_player2.image,NULL,screen,&key2_player2.positionRelative);	
		}
		show(&villain,screen);
		show(&player1,screen);
		show(&player2,screen);
		
		if(xKEY_player1 == -1){
			xKEY_player1 = riddle(firstEnigme_player1,player1,screen);
			if(xKEY_player1 != -1){
				key_player1.state = 0;
			}
		}
		
		if(xKEY2_player1 == -1){
			xKEY2_player1 = riddle(secondEnigme_player1,player1,screen);
			if(xKEY2_player1 != -1){
				key2_player1.state = 0;
			}
		}

		if(xKEY_player2 == -1){
			xKEY_player2 = riddle(firstEnigme_player2,player2,screen);
			if(xKEY_player2 != -1){
				key_player2.state = 0;
			}
		}
		
		if(xKEY2_player2 == -1){
			xKEY2_player2 = riddle(secondEnigme_player2,player2,screen);
			if(xKEY2_player2 != -1){
				key2_player2.state = 0;
			}
		}
		
		turnOnOff(xKEY_player1,xKEY2_player1);
		number_key_player1 = gestionKey(number_key_player1,xKEY_player1,xKEY2_player1);
		number_key_player2 = gestionKey(number_key_player2,xKEY_player2,xKEY2_player2);


		sprintf(bufferVie, " %d", vie_player1.vie);
		vie_player1.font_vie = TTF_RenderText_Blended(font,bufferVie,fontColor);
		SDL_BlitSurface(vie_player1.font_vie,NULL,screen,&vie_player1.position);
		
		sprintf(bufferKey, "Key : %d", number_key_player1.keys);
		number_key_player1.font_key = TTF_RenderText_Blended(font,bufferKey,fontColor);
		SDL_BlitSurface(number_key_player1.font_key,NULL,screen,&number_key_player1.position);

		sprintf(bufferVie, " %d", vie_player2.vie);
		vie_player2.font_vie = TTF_RenderText_Blended(font,bufferVie,fontColor);
		SDL_BlitSurface(vie_player2.font_vie,NULL,screen,&vie_player2.position);
		
		sprintf(bufferKey, "Key : %d", number_key_player2.keys);
		number_key_player2.font_key = TTF_RenderText_Blended(font,bufferKey,fontColor);
		SDL_BlitSurface(number_key_player2.font_key,NULL,screen,&number_key_player2.position);

		SDL_Flip(screen);
		
        while( get_ticks(&started,&paused,&startTicks,&pausedTicks) < (1000 / FRAMES_PER_SECOND)){
			SDL_Delay( ( 1000 / FRAMES_PER_SECOND) - get_ticks(&started, &paused, &startTicks, &pausedTicks));
        }

	}
	TTF_CloseFont(font);

	SDL_FreeSurface(game_surface);
	SDL_FreeSurface(calque_surface);
	
	SDL_FreeSurface(firstEnigme_player1.Button[0]);
	SDL_FreeSurface(firstEnigme_player1.Button[1]);
	SDL_FreeSurface(firstEnigme_player1.Background);
	SDL_FreeSurface(firstEnigme_player1.Question);
	SDL_FreeSurface(firstEnigme_player1.Answer1);
	SDL_FreeSurface(firstEnigme_player1.Answer2);
	SDL_FreeSurface(firstEnigme_player1.Answer3);
	SDL_FreeSurface(firstEnigme_player1.Answer4);

	SDL_FreeSurface(firstEnigme_player2.Question);
	SDL_FreeSurface(firstEnigme_player2.Answer1);
	SDL_FreeSurface(firstEnigme_player2.Answer2);
	SDL_FreeSurface(firstEnigme_player2.Answer3);
	SDL_FreeSurface(firstEnigme_player2.Answer4);

	SDL_FreeSurface(secondEnigme_player1.Answer1);
	SDL_FreeSurface(secondEnigme_player1.Answer2);
	SDL_FreeSurface(secondEnigme_player1.Answer3);
	SDL_FreeSurface(secondEnigme_player1.Answer4);

	SDL_FreeSurface(secondEnigme_player2.Answer1);
	SDL_FreeSurface(secondEnigme_player2.Answer2);
	SDL_FreeSurface(secondEnigme_player2.Answer3);
	SDL_FreeSurface(secondEnigme_player2.Answer4);
	
	SDL_FreeSurface(vie_player1.font_vie);
	SDL_FreeSurface(vie_player2.font_vie);

	SDL_FreeSurface(villain.image);
	
	SDL_FreeSurface(player1.image);
	SDL_FreeSurface(player2.image);

	SDL_FreeSurface(key_player1.image);
	SDL_FreeSurface(key_player2.image);

	SDL_FreeSurface(key2_player1.image);
	SDL_FreeSurface(key2_player2.image);

}

void eventHandlerMultiplayer(hero *player1, hero *player2, char *ptr_game, char *ptr_in_menu, char *ptr_job, SDL_Surface *calque_game, SDL_Rect camera1, SDL_Rect camera2, SDL_Rect *positionMouse1, SDL_Rect *positionMouse2){
	SDL_Event event;
	int dx_cursor_in_game,dy_cursor_in_game;
	
	player1->orientation = 0;
	player2->orientation = 0;
	
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
					if(collision_Parfaite(calque_game,player1->position,STEP,0) != 1){
						move(player1,0,-1);
						player1->moveWithMouse = 0;
						player1->orientation = 0;
					}
					break;
				
				case SDLK_DOWN:
					if(collision_Parfaite(calque_game,player1->position,STEP,1) != 1){
						move(player1,0,1);
						player1->moveWithMouse = 0;
						player1->orientation = 0;
					}
					break;
				
				case SDLK_LEFT:
					if(collision_Parfaite(calque_game,player1->position,STEP,3) != 1){
						move(player1,1,-1);
						player1->orientation = -1;
						player1->moveWithMouse = 0;
					}
					break;
				case SDLK_RIGHT:
					if(collision_Parfaite(calque_game,player1->position,STEP,2) != 1){
						move(player1,1,1);
						player1->orientation = 1;
						player1->moveWithMouse = 0;
					}
					break;
				
				case SDLK_z:
					if(collision_Parfaite(calque_game,player2->position,STEP,0) != 1){
						move(player2,0,-1);
						player2->moveWithMouse = 0;
						player2->orientation = 0;
					}
					break;
				
				case SDLK_s:
					if(collision_Parfaite(calque_game,player2->position,STEP,1) != 1){
						move(player2,0,1);
						player2->moveWithMouse = 0;
						player2->orientation = 0;
					}
					break;
				
				case SDLK_q:
					if(collision_Parfaite(calque_game,player2->position,STEP,3) != 1){
						move(player2,1,-1);
						player2->orientation = -1;
						player2->moveWithMouse = 0;
					}
					break;
				case SDLK_d:
					if(collision_Parfaite(calque_game,player2->position,STEP,2) != 1){
						move(player2,1,1);
						player2->orientation = 1;
						player2->moveWithMouse = 0;
					}
					break;
			}
			break;

		case SDL_MOUSEBUTTONDOWN:
			switch(event.button.button){
				case SDL_BUTTON_LEFT:
					SDL_GetMouseState(&dx_cursor_in_game,&dy_cursor_in_game);
					if(dx_cursor_in_game < SCREEN_WIDTH){
						player1->moveWithMouse = 1;
						positionMouse1->x = dx_cursor_in_game - player1->position.w + camera1.x;
						positionMouse1->y = dy_cursor_in_game - player1->position.h + camera1.y;					
					}else{
						player2->moveWithMouse = 1;
						positionMouse2->x = dx_cursor_in_game - player2->position.w + camera2.x;
						positionMouse2->y = dy_cursor_in_game - player2->position.h + camera2.y;
					}
					break;
			}
			break;
	}
}