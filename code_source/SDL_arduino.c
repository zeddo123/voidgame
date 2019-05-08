#include "SDL_arduino.h"

int eventHandlerArduino(hero *player, SDL_Surface *calque_game){
	int event = readFromArd();
	//player->orientation = 0;
	switch(event){
		case 1:
			//UP
			if (collision_Parfaite(calque_game,player->position,STEP,0) != 1){
				move(player,0,-1);
				player->moveWithMouse = 0;
				player->orientation = 0;
				return 1;
			}
			break;
		case 2:
			//Down
			if(collision_Parfaite(calque_game,player->position,STEP,1) != 1){
				move(player,0,1);
				player->moveWithMouse = 0;
				player->orientation = 0;
				return 1;
			}
			break;
		case 3:
			//Left
			if(collision_Parfaite(calque_game,player->position,STEP,3) != 1){
				move(player,1,-1);
				player->orientation = -1;
				player->moveWithMouse = 0;
				return 1;
			}
			break;
		case 4:
			//Rigth
			if(collision_Parfaite(calque_game,player->position,STEP,2) != 1){
				move(player,1,1);
				player->orientation = 1;
				player->moveWithMouse = 0;
				return 1;
			}
			break;

	}
	return 0;

}

void turnOnOff(int e1, int e2){
	if(e1 == 1 && e2 != 1){
		writeToArd(1);
	}
	if(e1 =! 1 && e2 == 1){
		writeToArd(2);
	}
	if(e1 == 1 && e2 == 1){
		writeToArd(3);
	}
	if(e1 != 1 && e2 != 1){
		writeToArd(0);
	}
}

char readFromArd(){
	char path[] = "/dev/ttyACM0";
	FILE* f;
	char c;

	f = fopen(path,"r");
	if(f == NULL){
		return -1;
	}
	fscanf(f,"%c\n",&c);
	fclose(f);
	return c;

}

int writeToArd(int x){
	char path[] = "/dev/ttyACM0";
	char c = x + 48;
	FILE* f;
	f = fopen(path,"w");
	if(f == NULL){
		return -1;
	}

	fprintf(f,"%c",c);
	fclose(f);
	return 0;
}
