SDL_Surface Riddle(enigme e){

	font = TTF_OpenFont("../src/font/Baron Neue.otf",30);

	font_surface = TTF_RenderText_Blended(font," Question? ",fontColor);
	if(font_surface == NULL || font == NULL){
		printf("unable to TTF_RenderText_Solid\n");
		return 1;
	}


	font_surface = TTF_RenderText_Blended(font," Answer1 ",fontColor);
	if(font_surface == NULL || font == NULL){
		printf("unable to TTF_RenderText_Solid\n");
		return 1;
	}

	font_surface = TTF_RenderText_Blended(font," Answer2 ",fontColor);
	if(font_surface == NULL || font == NULL){
		printf("unable to TTF_RenderText_Solid\n");
		return 1;
	}

	font_surface = TTF_RenderText_Blended(font," Answer3 ",fontColor);
	if(font_surface == NULL || font == NULL){
		printf("unable to TTF_RenderText_Solid\n");
		return 1;
	}

	font_surface = TTF_RenderText_Blended(font," Answer4 ",fontColor);
	if(font_surface == NULL || font == NULL){
		printf("unable to TTF_RenderText_Solid\n");
		return 1;
	}
}


int findIndex(char string[], char x){
	for(int i;i < len(string);i++){
		if(ch[i] == x){
			return i;
		}
	}
	return -1;
}

void erase(char string[], int pos){
	char tmp[256];
	for(int i = pos+1,int c = 0;i < len(string);i++,c++){
		tmp[c] = string[i];
	}
	tmp[c+1]='\0';
}

enigme fetchQuestion(char file_name[], char file_nom[]){
	
	enigme e;
	FILE* fq = fopen(file_name,"r");
	FILE* fa = fopen(file_nom,"r");
	int num_q = rand() % 10;
	char question[256];
	char answer[256];
	int i=1;


	while(i != num_q){
		fgets(question,256,fp);	
		i++;
	}
	fgets(question,256,fp);
	
	while(j != num_q){
		fgets(question,256,fa);	
		j++;
	}
	fgets(answer,256,fa);	

	strcpy(e.question,question);
	strncpy(e.answer1,answer,findIndex(answer,'-'));
	erase(answer,findIndex(answer,'-'));
	strncpy(e.answer2,answer,findIndex(answer,'-'));
	erase(answer,findIndex(answer,'-'));
	strncpy(e.answer3,answer,findIndex(answer,'-'));
	erase(answer,findIndex(answer,'-'));
	strncpy(e.answer4,answer,findIndex(answer,'-'));

	return e;
}