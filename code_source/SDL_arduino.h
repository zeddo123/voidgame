#include <SDL/SDL.h>
#include "SDL_char.h"
#include "SDL_Game.h"
#include <stdlib.h>
#include <stdio.h>

int eventHandlerArduino(hero *player, SDL_Surface *calque_game);

void turnOnOff(int e1, int e2);

int readFromArd();

int writeToArd(int x);
