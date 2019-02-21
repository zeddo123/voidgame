game:SDL_Game.o SDL_Game_Funcs.o
	gcc SDL_Game.o SDL_Game_Funcs.o -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf  -o game
SDL_Game.o:SDL_Game.c SDL_Game.h
	gcc -c SDL_Game.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
SDL_Game_Funcs.o:SDL_Game_Funcs.c
	gcc -c SDL_Game_Funcs.c -lSDL -lSDL_image -lSDL_mixer
love:
	rm *.o
