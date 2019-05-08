libs = -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf

printObject = minimap.o AI.o SDL_multiplayer.o SDL_animation.o SDL_enigme.o zoom.o SDL_Game_Funcs.o

moveObject = SDL_jump.o SDL_atack.o SDL_scrolling.o SDL_arduino.o SDL_move.o SDL_acceleration.o

initObject = SDL_gestion.o SDL_collision.o SDL_Game.o  SDL_Init.o SDL_free.o  SDL_savegame.o SDL_condition.o

allObjects = $(printObject) $(moveObject) $(initObject)

game: $(allObjects)
	gcc $(allObjects) -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -lSDL_gfx -lm -ldl -g -o game

SDL_Game.o:SDL_Game.c SDL_Game.h
	gcc -c SDL_Game.c $(libs) -g

SDL_Game_Funcs.o:SDL_Game_Funcs.c
	gcc -c SDL_Game_Funcs.c $(libs) -g

SDL_Init.o:SDL_Init.h SDL_Init.c
	gcc -c SDL_Init.c -lSDL -lSDL_image -lSDL_ttf -g

SDL_move.o:SDL_move.h SDL_move.c
	gcc -c SDL_move.c -lSDL -g

SDL_enigme.o:SDL_enigme.h SDL_enigme.c
	gcc -c SDL_enigme.c -lSDL -g

SDL_collision.o:SDL_collision.h SDL_collision.c
	gcc -c SDL_collision.c -lSDL -g

SDL_scrolling.o:SDL_scrolling.h SDL_scrolling.c
	gcc -c SDL_scrolling.c -lSDL -g

SDL_free.o:SDL_free.h SDL_free.c
	gcc -c SDL_free.c -LSDL -g

SDL_gestion.o:SDL_gestion.h SDL_gestion.c
	gcc -c SDL_gestion.c -lSDL -g

SDL_animation.o:SDL_animation.h SDL_animation.c
	gcc -c SDL_animation.c -lSDL -g

SDL_arduino.o:SDL_arduino.h SDL_arduino.c
	gcc -c SDL_arduino.c -lSDL -g

AI.o:AI.h AI.c
	gcc -c AI.c -lSDL -lm -ldl -g 

minimap.o:minimap.h minimap.c
	gcc -c minimap.c -lSDL -g -lSDL_gfx		

SDL_multiplayer.o:SDL_multiplayer.h SDL_multiplayer.c
	gcc -c SDL_multiplayer.c -lSDL -g

zoom.o :zoom.c zoom.h
	gcc -c zoom.c -g $(libs) -lSDL_gfx

SDL_atack.o:SDL_atack.c SDL_atack.h
	gcc -c SDL_atack.c -lSDL -g

SDL_jump.o:SDL_jump.c SDL_jump.h
	gcc -c SDL_jump.c -lSDL -g

SDL_acceleration.o:SDL_acceleration.h SDL_acceleration.c
	gcc -c SDL_acceleration.c -lSDL -g

SDL_savegame.o:SDL_savegame.h SDL_savegame.c
	gcc -c SDL_savegame.c -lSDL -g

SDL_condition.o:SDL_CONDITION.h SDL_condition.c
	gcc -c SDL_condition.c -lSDL -g

clean:
	rm *.o
