game:SDL_Game.o SDL_Game_Funcs.o SDL_Init.o SDL_move.o SDL_enigme.o SDL_collision.o
	gcc SDL_enigme.o SDL_collision.o SDL_Game.o SDL_Game_Funcs.o SDL_Init.o SDL_move.o -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g -o game

SDL_Game.o:SDL_Game.c SDL_Game.h
	gcc -c SDL_Game.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g

SDL_Game_Funcs.o:SDL_Game_Funcs.c
	gcc -c SDL_Game_Funcs.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g

SDL_Init.o:SDL_Init.h SDL_Init.c
	gcc -c SDL_Init.c -lSDL -lSDL_image -g

SDL_move.o:SDL_move.h SDL_move.c
	gcc -c SDL_move.c -lSDL -g

SDL_enigme.o:SDL_enigme.h SDL_enigme.c
	gcc -c SDL_enigme.c -lSDL -g

SDL_collision.o:SDL_collision.h SDL_collision.c
	gcc -c SDL_collision.c -lSDL -g

love:
	rm *.o
