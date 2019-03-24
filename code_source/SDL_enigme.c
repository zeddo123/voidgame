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
	
	enigme e;
	FILE* fq = fopen(file_q,"r");
	FILE* fa = fopen(file_a,"r");
	int num_q = rand() % 10;
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

void riddle(enigme e, hero player, SDL_Surface *screen){
	int job = 1;

	if(collisionBox(player.position,e.positionRiddle) == 1){
		SDL_BlitSurface(e.Background,NULL,screen,&e.positionBackground);
		
		SDL_BlitSurface(e.Button,NULL,screen,&e.positionButton1);
		SDL_BlitSurface(e.Button,NULL,screen,&e.positionButton2);
		SDL_BlitSurface(e.Button,NULL,screen,&e.positionButton3);
		SDL_BlitSurface(e.Button,NULL,screen,&e.positionButton4);

		SDL_BlitSurface(e.Question,NULL,screen,&e.positionQuestion);
		SDL_BlitSurface(e.Answer1,NULL,screen,&e.positionAnswer1);
		SDL_BlitSurface(e.Answer2,NULL,screen,&e.positionAnswer2);
		SDL_BlitSurface(e.Answer3,NULL,screen,&e.positionAnswer3);
		SDL_BlitSurface(e.Answer4,NULL,screen,&e.positionAnswer4);
		//SDL_Flip(screen);	
	}else{
		return;
	}

int answer_selection ( enigme e , SDL_Rect positionButton1 , SDL_Rect positionButton2 , SDL_Rect positionButton3 , SDL_Rect positionButton4 )
true_answer=
{
	int answer_selected =1;
	int dx_cursor, dy_cursor;
	SDL_Event event;
	
	while(job){
		SDL_WaitEvent(&event);
		
		switch(event.type){ 
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym){
					case SDLK_ESCAPE:
						job=0;

						break;
					case SDLK_DOWN:
						if ((answer_selected == 3)||(answer_selected == 4))
							answer_selected=answer_selected;
						else
							answer_selected=answer_selected+2;
						
						break;
					case SDLK_UP:
						if ((answer_selected == 1)||(answer_selected == 2))
							answer_selected=answer_selected;
						else
							answer_selected=answer_selected-2;
						
						break;
					case SDLK_RIGHT:
						if ((answer_selected == 2)||(answer_selected == 4))
							answer_selected = answer_selected;
						else
							answer_selected = answer_selected+1;
						
						break;
					case SDLK_LEFT:
						if ((answer_selected == 1)||(answer_selected == 3))
							answer_selected=answer_selected;
						else
							answer_selected=answer_selected-1;
						break;
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
				switch(event.button.button){
					case SDL_BUTTON_LEFT:
						SDL_GetMousweState(&dx_cursor,&dy_cursor);

						// les buttons eli lfou9
						if (dy_cursor >= e.positionButton1.y)&&(dy_cursor<=((e.positionButton1.y)+(e.positionButton1.h))))
							{ if (dx_cursor >= e.positionButton1.x)&&(dx_cursor<=((e.positionButton1.x)+(e.positionButton1.w))))
								answer_selected=1;
							else if (dx_cursor >= e.positionButton2.x)&&(dx_cursor<=((e.positionButton2.x)+(e.positionButton2.w))))
								{
								 answer_selected=2;
								}}

						// les buttons eli louta
						if (dy_cursor >= e.positionButton3.y)&&(dy_cursor<=((e.positionButton3.y)+(e.positionButton3.h))))
							{ if (dx_cursor >= e.positionButton3.x)&&(dx_cursor<=((e.positionButton3.x)+(e.positionButton3.w))))
								answer_selected=3;
							else if (dx_cursor >= e.positionButton4.x)&&(dx_cursor<=((e.positionButton4.x)+(e.positionButton4.w))))
								{
								 answer_selected=4;
								}}

}

int verify_answer ( enigme e )
{
int test;
int user_answer;
int true_answer;
int longeur_question;
test=0; // initialement l reponse 8alta
user_answer=answer_selection ( e , positionButton1 ,positionButton2 ,positionButton3 ,positionButton4 );
longeur_question=strlen(e.question);
true_answer=atoi(question[longeur_question]);
if ( user_answer=true_answer)
	{ test=1;} // la reponse choisie s7i7a
return test;
}