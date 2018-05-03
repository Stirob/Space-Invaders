//David og Stian Innlevering CPP fil.

#include "DrawMedia.h"
#include "methods.h"

int main(int argc, char* argv[])
{
	SDL_Window* window = createWindow(450, 400);
	if (window == nullptr)
	{
		cout << "Failed to create window: " << SDL_GetError() << endl;
		SDL_Quit();
		return EXIT_FAILURE;
	}

	SDL_Renderer* renderer; // Pointer to window's renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (renderer == nullptr)
	{
		cout << "Failed to create renderer: " << SDL_GetError() << endl;
		SDL_DestroyWindow(window); SDL_Quit(); return EXIT_FAILURE;
	}

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	SDL_Surface* Scoreboard = loadMedia("Scoreboard.bmp");

	if (Scoreboard == nullptr)
	{
		cout << "Failed to load Scoreboard: " << SDL_GetError() << endl;
		SDL_DestroyRenderer(renderer); SDL_DestroyWindow(window); SDL_Quit(); return EXIT_FAILURE;
	}

	SDL_Surface* Aliens = loadMedia("Aliens.bmp");

	if (Aliens == nullptr)
	{
		cout << "Failed to load Aliens: " << SDL_GetError() << endl;
		SDL_DestroyRenderer(renderer); SDL_DestroyWindow(window); SDL_Quit(); return EXIT_FAILURE;
	}
	//Load in graphicscard
	SDL_Texture* drawable = SDL_CreateTextureFromSurface(renderer, Scoreboard);
	SDL_Texture* drawable2 = SDL_CreateTextureFromSurface(renderer, Aliens);

	SDL_Rect ScoreboardXY;
	ScoreboardXY.h = 46;
	ScoreboardXY.w = 450;
	ScoreboardXY.x = 0;
	ScoreboardXY.y = 0;

	SDL_Rect AlienXY;
	AlienXY.h = Aliens->h; // Samme bredde og høyde som surface
	AlienXY.w = Aliens->w;
	AlienXY.x = 0; // Endre disse for å "flytte" bildet i vinduet/renderer
	AlienXY.y = 66;

	SDL_FreeSurface(Aliens); 
	SDL_FreeSurface(Scoreboard);

	SDL_Event event;
	bool runningGame = true;

	//GameLoop
	while (runningGame) {
		SDL_RenderCopy(renderer, drawable, nullptr, &ScoreboardXY);
		SDL_RenderCopy(renderer, drawable2, nullptr, &AlienXY);
		SDL_RenderPresent(renderer);
		SDL_RenderClear(renderer);

		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {
				case SDLK_SPACE:
					//Shoot Projectile
					cout << "You shoot!" << endl;
					break;
				case SDLK_LEFT:
					cout << "You hit the left key" << endl;
					break;
				case SDLK_RIGHT:
					cout << "You hit the right key" << endl;
					break;
				case SDLK_ESCAPE:
					//Quit
					runningGame = false;
					break;
				case SDL_QUIT:
					//Quit
					runningGame = false;
					break;
				default:
					break;
				}
			}
		}
	}

	close(window, Aliens);
	return 0;
}

