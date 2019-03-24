#include "SDL_scrolling.h"

SDL_Rect moveCamera(SDL_Rect camera, hero player, SDL_Surface *game){
	camera.x = (player.position.x + player.position.w / 2) - SCREEN_WIDTH / 2;
	camera.y = (player.position.y + player.position.h / 2) - SCREEN_HEIGHT / 2;
	
	if(camera.x < 0){
		camera.x = 0; 
	}
	
	if(camera.y < 0){
		camera.y = 0; 
	}

	if(player.position.x > game->w - camera.w){
		camera.x = game->w - camera.w;
	}
	
	if(player.position.y > game->h - camera.h){
		camera.y = game->h - camera.h;
	}
	
	return camera;
}

SDL_Rect makeItRelative(SDL_Rect positionEntit, SDL_Rect camera){
	SDL_Rect positionRelative;
	positionRelative.x = positionEntit.x - camera.x;
	positionRelative.y = positionEntit.y - camera.y;

	return positionRelative;
}