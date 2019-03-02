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