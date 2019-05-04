#include <SDL/SDL.h>
#include "SDL_char.h"
#include "SDL_Game.h"

SDL_Rect moveCamera(SDL_Rect camera, hero player, SDL_Surface* game);

SDL_Rect moveCameraPlayer1(SDL_Rect camera, hero player, SDL_Surface* game);

SDL_Rect moveCameraPlayer2(SDL_Rect camera, hero player, SDL_Surface* game);

SDL_Rect makeItRelative(SDL_Rect positionEntit, SDL_Rect camera);

SDL_Rect makeItRelativePlayer2(SDL_Rect positionEntit, SDL_Rect camera);