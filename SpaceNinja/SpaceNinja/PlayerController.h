#pragma once

#include "Controller.h"

class PlayerController : public Controller {
public:
	PlayerController();
	~PlayerController();

	virtual Command getCommand(SDL_Event &e);
};

