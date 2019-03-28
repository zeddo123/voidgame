#include "SDL_enigme.h"
#include <string.h>

int findIndex(char string[], char x){
	for(int i = 0;i < strlen(string);i++){
		if(string[i] == x){
			return i;
		}
	}
	return -1;
}

void erase(char string[], int pos){
	char tmp[256];
	int c = 0;
	for(int i = pos+1;i < strlen(string);i++){
		tmp[c] = string[i];
		c++;
	}
	tmp[c+1] = '\0';
	strcpy(string,tmp);
	string[strlen(tmp)] = '\0';
}

enigme fetchQuestion(char file_q[], char file_a[]){
	srand(time(NULL));
	
	enigme e;
	FILE* fq = fopen(file_q,"r");
	FILE* fa = fopen(file_a,"r");
	int num_q = rand() % 6;
	char question[256];
	char answer[256];
	int i = 1, j = 1;


	while(i != num_q && !feof(fq)){
		fgets(question,255,fq);	
		i++;
	}
	fgets(question,255,fq);
	
	while(j != num_q && !feof(fa)){
		fgets(answer,255,fa);	
		j++;
	}

	fgets(answer,255,fa);	
	e.solution = (int) question[strlen(question)-2] - 48;
	question[strlen(question)-2] = '\0';

	strcpy(e.question,question);
	
	
	strncpy(e.answer1,answer,findIndex(answer,'-'));
	e.answer1[findIndex(answer,'-')] = '\0';
	erase(answer,findIndex(answer,'-'));

	
	strncpy(e.answer2,answer,findIndex(answer,'-'));
	e.answer2[findIndex(answer,'-')] = '\0';	
	erase(answer,findIndex(answer,'-'));
	
	
	strncpy(e.answer3,answer,findIndex(answer,'-'));
	e.answer3[findIndex(answer,'-')] = '\0';
	erase(answer,findIndex(answer,'-'));
	
	strncpy(e.answer4,answer,findIndex(answer,'-'));
	e.answer4[findIndex(answer,'-')] = '\0';
	
	fclose(fq);
	fclose(fa);
	return e;
}

enigme createQustion(){
	srand(time(NULL));

	enigme e;
	int valueTrue = rand() % (13 - 1) + 1;
	int colorTrue = rand() % 4; // CHEST : clubs hearts spades Diamants 
	int value2, value3, value4, color2, color3, color4;
	e.solution = rand() % 4;
	
	generateFake(valueTrue,colorTrue,&value2,&color2,&value3,&color3,&value4,&color4);

	sprintf(e.question,"La Machine tire une Carte au hazard :\n Quelle est cette carte?");

	if(e.solution == 1){
		sprintf(e.answer1,"%s",formatCarte(valueTrue,colorTrue));
		sprintf(e.answer2,"%s",formatCarte(value2,color2));
		sprintf(e.answer3,"%s",formatCarte(value3,color3));
		sprintf(e.answer4,"%s",formatCarte(value4,color4));
	}else if(e.solution == 2){
		sprintf(e.answer2,"%s",formatCarte(valueTrue,colorTrue));
		sprintf(e.answer1,"%s",formatCarte(value2,color2));
		sprintf(e.answer3,"%s",formatCarte(value3,color3));
		sprintf(e.answer4,"%s",formatCarte(value4,color4));
	}else if(e.solution == 3){
		sprintf(e.answer3,"%s",formatCarte(valueTrue,colorTrue));
		sprintf(e.answer1,"%s",formatCarte(value2,color2));
		sprintf(e.answer2,"%s",formatCarte(value3,color3));
		sprintf(e.answer4,"%s",formatCarte(value4,color4));
	}else if(e.solution == 4){
		sprintf(e.answer4,"%s",formatCarte(valueTrue,colorTrue));
		sprintf(e.answer1,"%s",formatCarte(value2,color2));
		sprintf(e.answer2,"%s",formatCarte(value3,color3));
		sprintf(e.answer3,"%s",formatCarte(value4,color4));
	}

	return e;
}

void generateFake(int value, int color, int *value2, int *color2, int *value3, int *color3, int *value4, int *color4){
	srand(time(NULL));
	do{
		*value2 = rand() % (13 - 1) + 1;
		*color2 = rand() % 4;	
	}while(*value2 == value && *color2 == color);

	do{
		*value3 = rand() % (13 - 1) + 1;
		*color3 = rand() % 4;	
	}while(*value3 == value && *color3 == color || *value2 == *value3 && *color2 == *color3);

	do{
		*value4 = rand() % (13 - 1) + 1;
		*color4 = rand() % 4;	
	}while(*value4 == value && *color4 == color || *value2 == *value4 && *color2 == *color4 || *value3 == *value4 && *color3 == *color4);
}

char *formatCarte(int value, int color){
	char carte[3];
	char carte_value[3];
	char carte_color[3];

	if(value > 10){
		if(value == 11)
			strcpy(carte_value,"J");
		
		if(value == 12)
			strcpy(carte_value,"Q");

		if(value == 13)
			strcpy(carte_value,"K");	
	
	}else{
		sprintf(carte_value,"%d",value);
	}

	if(color == 1)
		strcpy(carte_color,"C");

	if(color == 2)
		strcpy(carte_color,"H");

	if(color == 3)
		strcpy(carte_color,"S");

	if(color == 4)
		strcpy(carte_color,"D");

	sprintf(carte, "%s:%s",carte_value,carte_color);
	char *ptr_carte = carte;
	
	return ptr_carte;
}

int riddle(enigme e, hero player, SDL_Surface *screen){
	/*
		return 1 if the answer is True
		return 0 if the answer is False
		return -1 if the player did not play
	*/
	int job = 1;
	int answer_selected = 1;
	int locked = 0;
	int test;
	int over1, over2, over3, over4;

	if(collisionBox(player.position,e.positionRiddle) == 1){
		while(job){
			locked = getSelection(e,&answer_selected);

			if(locked == -1){
				job = 0;
			}else if(locked == 0){
				if(verifyAnswer(e,answer_selected)){
					return 1;
				}else{
					return 0;
				}
			}

			if(answer_selected == 1){
				over1 = 1;
				over2 = 0;
				over3 = 0;
				over4 = 0;
			}else if(answer_selected == 2){
				over1 = 0;
				over2 = 1;
				over3 = 0;
				over4 = 0;
			}else if(answer_selected == 3){
				over1 = 0;
				over2 = 0;
				over3 = 1;
				over4 = 0;
			}else if(answer_selected == 4){
				over1 = 0;
				over2 = 0;
				over3 = 0;
				over4 = 1;
			}
			SDL_BlitSurface(e.Background,NULL,screen,&e.positionBackground);
		
			SDL_BlitSurface(e.Button[over1],NULL,screen,&e.positionButton1);
			SDL_BlitSurface(e.Button[over2],NULL,screen,&e.positionButton2);
			SDL_BlitSurface(e.Button[over3],NULL,screen,&e.positionButton3);
			SDL_BlitSurface(e.Button[over4],NULL,screen,&e.positionButton4);

			SDL_BlitSurface(e.Question,NULL,screen,&e.positionQuestion);
			SDL_BlitSurface(e.Answer1,NULL,screen,&e.positionAnswer1);
			SDL_BlitSurface(e.Answer2,NULL,screen,&e.positionAnswer2);
			SDL_BlitSurface(e.Answer3,NULL,screen,&e.positionAnswer3);
			SDL_BlitSurface(e.Answer4,NULL,screen,&e.positionAnswer4);
			
			SDL_Flip(screen);
		}	
	}else{
		return -1;
	}
}

int getSelection(enigme e, int *answer_selected){
	/*
		return -1 if the player wants to quit
		return 0 if the player lock this answer
		return 1 if the player did not choise yet
	*/
	int dx_cursor, dy_cursor;
	SDL_Event event;
	
	SDL_WaitEvent(&event);
		
	switch(event.type){ 
		case SDL_KEYDOWN:
			switch(event.key.keysym.sym){
				case SDLK_RETURN:
					return 0;
				
				case SDLK_ESCAPE:
					return -1;
					break;

				case SDLK_DOWN:
					if ((*answer_selected == 3) || (*answer_selected == 4))
						*answer_selected = *answer_selected;
					else
						*answer_selected = *answer_selected + 2;
						break;
					return 1;
				case SDLK_UP:
					if ((*answer_selected == 1) || (*answer_selected == 2))
						*answer_selected = *answer_selected;
					else
						*answer_selected = *answer_selected-2;
					return 1;
					break;
				case SDLK_RIGHT:
					if ((*answer_selected == 2) || (*answer_selected == 4))
						*answer_selected = *answer_selected;
					else
						*answer_selected = *answer_selected+1;
					return 1;
					break;
				case SDLK_LEFT:
					if ((*answer_selected == 1) || (*answer_selected == 3))
						*answer_selected = *answer_selected;
					else
						*answer_selected = *answer_selected - 1;
					return 1;
					break;
				}
		case SDL_MOUSEBUTTONDOWN:
			switch(event.button.button){
				case SDL_BUTTON_LEFT:
				
					SDL_GetMouseState(&dx_cursor,&dy_cursor);
				
					if ((dy_cursor >= e.positionButton1.y)&&(dy_cursor<=((e.positionButton1.y)+(e.positionButton1.h)))){
						if ((dx_cursor >= e.positionButton1.x) && (dx_cursor<=((e.positionButton1.x)+(e.positionButton1.w)))){
							*answer_selected = 1;
							return 0;
						}else if((dx_cursor >= e.positionButton2.x)&&(dx_cursor<=((e.positionButton2.x)+(e.positionButton2.w)))){
							*answer_selected = 2;
							return 0;
						}
					}

					if ((dy_cursor >= e.positionButton3.y)&&(dy_cursor<=((e.positionButton3.y)+(e.positionButton3.h)))){
						if ((dx_cursor >= e.positionButton3.x)&&(dx_cursor<=((e.positionButton3.x)+(e.positionButton3.w)))){
							*answer_selected = 3;
							return 0;
						}else if ((dx_cursor >= e.positionButton4.x)&&(dx_cursor<=((e.positionButton4.x)+(e.positionButton4.w)))){
							*answer_selected = 4;
							return 0;
						}
					}

			}
			break;
	}
}

int verifyAnswer(enigme e, int answer_selected){
	return e.solution == answer_selected;
}