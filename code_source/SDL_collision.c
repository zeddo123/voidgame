#include "SDL_collision.h"

int collisionBox(SDL_Rect a, SDL_Rect b){
	int leftSideA = a.x;
	int rightSideA = a.x + a.w;
	int topA = a.y;
	int bottomA = a.y + a.h;

	int leftSideB = b.x;
	int rightSideB = b.x + b.w;
	int topB = b.y;
	int bottomB = b.y + b.h;

	if(bottomA <= topB){
		return 0;
	}

	if(topA >= bottomB){
		return 0;
	}

	if(rightSideA <= leftSideB){
		return 0;
	}

	if(leftSideA >= rightSideB){
		return 0;
	}

	return 1;
}