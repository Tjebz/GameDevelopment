#include "PlayerController.h"



PlayerController::PlayerController() {
}


PlayerController::~PlayerController() {
}

Command PlayerController::getCommand(SDL_Event &e) {
	SDL_PollEvent(&e);
	if (e.type == SDL_KEYDOWN) {
		switch (e.key.keysym.sym) {
		case (SDLK_UP):
			return AccUp;
		case (SDLK_DOWN):
			return AccDown;
		case(SDLK_LEFT):
			return AccLeft;
		case (SDLK_RIGHT):
			return AccRight;
		}
	}
	else if (e.type = SDL_KEYUP) {
		switch (e.key.keysym.sym) {
		case (SDLK_UP):
			return DeccUp;
		case (SDLK_DOWN):
			return DeccDown;
		case(SDLK_LEFT):
			return DeccLeft;
		case (SDLK_RIGHT):
			return DeccRight;
		}
	}
	return None;
}
