/**
* @file SDL_jump.c
* @brief save game
* @author Kaisouneltahfoun
* @version 0.5
* @date May 9,2019

*/
//#include "SDL_jump.h"

void jump(hero *player, SDL_Rect camera){
	// Les variables lkol 7atithom random khatr naarach lmap mte3na kifeni
	SDL_Event event;

	SDL_PollEvent(&event);

	// Check to see if player is in the air	
	if ( player->position.y + H < camera.y + ground_level ) 
	{
		player->vel += 1; // Add gravity if he is
	}
	else
	{
		// Keep player from falling through the ground
		player->vel = 0; // put player_vely = -player_vely / 3;  to make the player bounce off the ground :)
		player->position.y -= ground_level - H;
	}
	
	player->position.y += player->vel;  // Add velocity to position
	
	if(event.type == SDL_KEYDOWN)
	{
		switch(event.key.keysym.sym)
		{
		case SDLK_SPACE:
			if ( player->position.y + H == ground_level )
				player->vel = -8;
			break;
			
	    }
	}
}
