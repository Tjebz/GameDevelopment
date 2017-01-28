#include <iostream>
#include "ObjectManager.h"
#include "Entity.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int, char**) {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		return 1;
	}

	SDL_Window *window = SDL_CreateWindow("Test", 100, 100, SCREEN_WIDTH,
		SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == nullptr) {
		SDL_Quit();
		return 1;
	}
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr) {
		utility::cleanup(window);
		SDL_Quit();
		return 1;
	}

	RepresentationManager reprManager;
	ObjectManager objManager(&reprManager);
	SDL_Rect rect = { 0, 0, 1, 1 };
	ObjectPtr entity(new Entity(rect, "../Resources/Test/image.bmp", renderer));

	objManager.addObject(entity);
	objManager.updateAll();
	reprManager.drawAll(renderer);
	SDL_Delay(1000);
	utility::cleanup(renderer, window);
	SDL_Quit();
	return 0;
}