#include <iostream>
#include "ObjectManager.h"
#include "Entity.h"
#include "PlayerController.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int, char**) {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		return 1;
	}

	SDL_Window *window = SDL_CreateWindow("Test", 100, 100, SCREEN_WIDTH,
		SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == nullptr) {
		utility::logSDLError(std::cerr, "SDL_CreateWindow");
		SDL_Quit();
		return 1;
	}
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr) {
		utility::logSDLError(std::cerr, "SDL_CreateRenderer");
		utility::cleanup(window);
		SDL_Quit();
		return 1;
	}

	RepresentationManager reprManager;
	ObjectManager objManager(&reprManager);
	SDL_Rect rect = { 0, 0, 1, 1 };
	Entity *entity = new Entity(rect, "../Resources/Test/image.bmp", renderer);
	entity->setAcceleration(1);
	ObjectPtr object(entity);
	CtrlPtr controller(new PlayerController());
	object->setController(controller);
	objManager.addObject(object);

	bool quit = false;
	SDL_Event e;
	while (!quit) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				quit = true;
				break;
			}
			objManager.resolveInput(e);
		}
		objManager.updateAll();
		SDL_RenderClear(renderer);
		reprManager.drawAll(renderer);
	}

	utility::cleanup(renderer, window);
	SDL_Quit();
	return 0;
}