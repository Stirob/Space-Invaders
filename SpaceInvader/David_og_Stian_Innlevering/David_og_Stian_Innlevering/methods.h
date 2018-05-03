//methods_H

#ifndef methods_H
#define methods_H

#include <iostream>
#include <SDL.h>

using namespace std;

//Våre metoder
SDL_Window* createWindow(int, int);
void close(SDL_Window*, SDL_Surface*);
SDL_Surface* loadMedia(const char*);
void updatePicture(const char*, SDL_Window*);


#endif // methods_H
