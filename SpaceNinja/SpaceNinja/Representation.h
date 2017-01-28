#pragma once

#include <string>
#include <iostream>
#include <SDL.h>
#include "utility.h"

class Representation
{
public:
	Representation();
	Representation(std::string filename, SDL_Renderer *ren, SDL_Point pos);
	~Representation();

	void loadSprite(std::string filename, SDL_Renderer *ren);
	void updatePos(SDL_Point pos);

	void drawSelf(SDL_Renderer *ren);

private:
	SDL_Texture *_texture;
	SDL_Rect _rect;

};