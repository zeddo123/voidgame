#ifndef INIT_H_INCLUDED
#define INIT_H_INCLUDED

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

int checkImageLoad(SDL_Surface *set[], int index, int maxIndex);

void displayFormatFrame(SDL_Surface *set[], int maxframes);

void nextFrame(int *frame, int maxframes);

void loadFrames(SDL_Surface *set[], int maxframes, char file_name[]);

SDL_Rect initPosition(SDL_Rect position, int x, int y, int w, int h);

#endif