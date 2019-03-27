#include "SDL_gestion.h"

health gestionVie(hero player, hero villain, health vie, Uint32 *oldTime){

	Uint32 currentTime = SDL_GetTicks();
    if(currentTime - (*oldTime) > 130){
		int testCollistion = collisionBox(player.position, villain.position);
		if (testCollistion){
			vie.vie -= 20;
		}
		*oldTime = currentTime;
	}
	return vie;
}

keys gestionKey(keys key, int x){
	int key1 = 0;
	if (x == 1){
		key1 = 1;
	}
	key.keys = key1;
	return key ;
}
