#include "SDL_jump.h"
// Les variables lkol 7atithom random khatr naarach lmap mte3na kifeni
int player_vely = 0;
int ground_level = 250; //Niveau eli supposé ykoun feha sa9in lperso
int h = 50 //Toul etangiza

void jump(hero *player)
{
	SDL_PollEvent(&event);

	// Check to see if player is in the air	
	if ( player->position.y + h < ground_level ) 
	{
		player_vely += 1; // Add gravity if he is
	}
	else
	{
		// Keep player from falling through the ground
		player_vely = 0; // put player_vely = -player_vely / 3;  to make the player bounce off the ground :)
		player->position.y = ground_level - h;
	}
	
	player->position.y += player_vely;  // Add velocity to position
	
	if(event.type == SDL_KEYDOWN)
	{
		switch(event.key.keysym.sym)
		{
		case SDLK_UP:
			if ( player->position.y + h == ground_level )
				player_vely = -8;
			break;
			
	    }
	}
}
