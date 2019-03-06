//Header file of the riddles

#include <string.h>
#include <SDL/SDL.h>
#include "SDL_char.h"
#include "SDL_collision.h"

struct Enigme{
	char question[256];
	char answer1[256];
	char answer2[256];
	char answer3[256];
	char answer4[256];
	int solution;
	SDL_Surface *Button;
	SDL_Surface *Background;
	
	SDL_Surface *Question;
	SDL_Surface *Answer1;
	SDL_Surface *Answer2;
	SDL_Surface *Answer3;
	SDL_Surface *Answer4;
	SDL_Rect positionBackground;
	SDL_Rect positionQuestion;
	SDL_Rect positionAnswer1;
	SDL_Rect positionAnswer2;
	SDL_Rect positionAnswer3;
	SDL_Rect positionAnswer4;

	SDL_Rect positionRiddle;
	SDL_Rect positionButton1;
	SDL_Rect positionButton2;
	SDL_Rect positionButton3;
	SDL_Rect positionButton4;

};
typedef struct Enigme enigme;

int findIndex(char string[], char x);

void erase(char string[], int pos);

void riddle(enigme e, hero player, SDL_Surface *screen);

enigme fetchQuestion(char file_q[], char file_a[]);
