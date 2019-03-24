#include "SDL_Init.h"

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

void nextFrame(int *frame, int maxframes){
	if(*frame + 1 < maxframes){
		(*frame)++;
	}else{
		(*frame) = 0;
	}
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

SDL_Rect initPosition(SDL_Rect position, int x, int y, int w, int h){
	if(x != -1){
		position.x = x;
	}

	if(y != -1){
		position.y = y;
	}

	if(w != -1){
		position.w = w;
	}

	if(h != -1){
		position.h = h;
	}

	return position;
}

hero initHero(hero h, char image_name[], int x, int y){
	h.image = NULL;
	h.image = IMG_Load(image_name);
	if(h.image == NULL){
		fprintf(stderr, "%s\n",SDL_GetError());
	}

	h.position = initPosition(h.position,x,y,h.image->w,h.image->h);
	h.orientation = 1;

	return h;
}

object initObject(object o, char image_name[], int x, int y){
	o.image = NULL;
	o.image = IMG_Load(image_name);
	if(o.image == NULL){
		fprintf(stderr, "%s\n",SDL_GetError());
	}

	o.position = initPosition(o.position,x,y,o.image->w,o.image->h);

	return o;
}

enigme loadTextForRiddle(enigme e){
	TTF_Font *font = NULL;
	SDL_Color fontColor = {63, 13, 58};

	font = TTF_OpenFont("../src/font/Baron Neue.otf",50);

	e.Question = TTF_RenderText_Blended(font,e.question,fontColor);
	if(e.Question == NULL || font == NULL){
		printf("unable to TTF_RenderText_Solid\n");
	}


	e.Answer1 = TTF_RenderText_Blended(font,e.answer1,fontColor);
	if(e.Answer1 == NULL || font == NULL){
		printf("unable to TTF_RenderText_Solid\n");
	}

	e.Answer2 = TTF_RenderText_Blended(font,e.answer2,fontColor);
	if(e.Answer2 == NULL || font == NULL){
		printf("unable to TTF_RenderText_Solid\n");
	}

	e.Answer3 = TTF_RenderText_Blended(font,e.answer3,fontColor);
	if(e.Answer3 == NULL || font == NULL){
		printf("unable to TTF_RenderText_Solid\n");
	}

	e.Answer4 = TTF_RenderText_Blended(font,e.answer4,fontColor);
	if(e.Answer4 == NULL || font == NULL){
		printf("unable to TTF_RenderText_Solid\n");
	}

	TTF_CloseFont(font);
	
	return e;
}


SDL_Surface* loadImage(char file_name[]){
	SDL_Surface *s = NULL;
	s = IMG_Load(file_name);
	if(s == NULL){
		fprintf(stderr, "%s\n",SDL_GetError());
	}
	return s;
}

enigme initPrintRiddle(enigme e){
	int xBackground, yBackground;
	int xA1, yA1;
	int xA2, yA2;
	int xA3, yA3;
	int xA4, yA4;
	int xAnswer1, yAnswer1;
	int xAnswer2, yAnswer2;
	int xAnswer3, yAnswer3;
	int xAnswer4, yAnswer4;
	int xQuestion, yQuestion;

	xBackground = (SCREEN_WIDTH / 2) - (e.Background->w/2);
	yBackground = (SCREEN_HEIGHT / 2) - (e.Background->h/2);
	
	yA1 = (yBackground + e.Background->h) / 2;
	xA1 = xBackground + 25;
	xA2 = e.Button[0]->w + xA1 + 50;
	yA3 = yA1 + e.Button[0]->h + 25;
	xA3 = xBackground + 25;
	xA4 = e.Button[0]->w + xA3 + 50;

	xAnswer1 = xA1;
	yAnswer1 = yA1;

	xAnswer2 = xA2;
	yAnswer2 = yA1;

	xAnswer3 = xA3;
	yAnswer3 = yA3;

	xAnswer4 = xA4;
	yAnswer4 = yA3;

	xQuestion = (xBackground + e.Background->w / 2) - (e.Question->w / 2);
	yQuestion = yBackground + 20;

	e.positionButton1 = initPosition(e.positionButton1,xA1,yA1,e.Button[0]->w,e.Button[0]->h);
	e.positionButton2 = initPosition(e.positionButton2,xA2,yA1,e.Button[0]->w,e.Button[0]->h);
	e.positionButton3 = initPosition(e.positionButton3,xA3,yA3,e.Button[0]->w,e.Button[0]->h);
	e.positionButton4 = initPosition(e.positionButton2,xA4,yA3,e.Button[0]->w,e.Button[0]->h);

	e.positionBackground = initPosition(e.positionBackground,xBackground,yBackground,e.Background->w,e.Background->h);
	e.positionQuestion = initPosition(e.positionQuestion,xQuestion,yQuestion,e.Question->w,e.Question->h);
	e.positionAnswer1 = initPosition(e.positionAnswer1,xAnswer1,yAnswer1,e.Answer1->w,e.Answer1->h);
	e.positionAnswer2 = initPosition(e.positionAnswer2,xAnswer2,yAnswer2,e.Answer2->w,e.Answer2->h);
	e.positionAnswer3 = initPosition(e.positionAnswer3,xAnswer3,yAnswer3,e.Answer3->w,e.Answer3->h);
	e.positionAnswer4 = initPosition(e.positionAnswer4,xAnswer4,yAnswer4,e.Answer4->w,e.Answer4->h);

	return e;
}