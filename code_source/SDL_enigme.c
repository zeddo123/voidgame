#include "SDL_enigme.h"

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
}