#pragma once

#include <SDL.h>
#include "Command.h"

class Controller {
public:
	Controller();
	~Controller();

	virtual Command getCommand(SDL_Event &e) = 0;
};

