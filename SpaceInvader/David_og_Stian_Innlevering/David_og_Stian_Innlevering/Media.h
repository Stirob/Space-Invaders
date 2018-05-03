#include <SDL.h>

#ifndef MEDIA_H
#define MEDIA_H

class Media {
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Surface* Scoreboard;
	SDL_Surface* Aliens;
	SDL_Texture* drawable;
	SDL_Texture* drawable2;
	SDL_Texture* drawable3;
	SDL_Rect ScoreboardXY;
	SDL_Rect AlienXY;
	SDL_Event event;
public: 
	Media();
	~Media();

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

};
#endif MEDIA_H