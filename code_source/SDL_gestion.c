#include "SDL_gestion.h"

health gestionVie(hero player, hero villain, health vie){
	int testCollistion = collisionBox(player.position, villain.position);
	if (testCollistion){
		vie.vie -= 20;
	}
	return vie;
}