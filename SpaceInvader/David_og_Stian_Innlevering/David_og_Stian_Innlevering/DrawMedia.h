#include "methods.h"

SDL_Surface* loadMedia(const char* theFile)
{
	return SDL_LoadBMP(theFile);
}

SDL_Window* createWindow(int w, int h)
{
	SDL_Init(SDL_INIT_VIDEO); // Init. SDL2

	return SDL_CreateWindow("Space Invaders",
		SDL_WINDOWPOS_UNDEFINED, //x-posisjon
		SDL_WINDOWPOS_UNDEFINED, //y-posisjon
		w, 	//Bredde
		h, 	//Høyde
		SDL_WINDOW_SHOWN); //Flagg
}

void close(SDL_Window* w, SDL_Surface* m)
{
	SDL_FreeSurface(m);
	m = nullptr;
	SDL_DestroyWindow(w);
	w = nullptr;
	SDL_Quit();
}
