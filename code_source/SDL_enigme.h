typedef struct{
	char question[256];
	char answer1[256];
	char answer2[256];
	char answer3[256];
	char answer4[256];
	SDL_Surface *background = NULL;
	SDL_Surface *question = NULL;
	SDL_Surface *answer1 = NULL;
	SDL_Surface *answer2 = NULL;
	SDL_Surface *answer3 = NULL;
	SDL_Surface *answer4 = NULL;
	SDL_Rect positionBackground;
	SDL_Rect positionQuestion;
	SDL_Rect positionAnswer1;
	SDL_Rect positionAnswer2;
	SDL_Rect positionAnswer3;
	SDL_Rect positionAnswer4;
}enigme;

SDL_Surface Riddle(enigme e);
int findIndex(char string[], char x);
void erase(char string[], int pos);
enigme fetchQuestion(char file_name[], char file_nom[]);