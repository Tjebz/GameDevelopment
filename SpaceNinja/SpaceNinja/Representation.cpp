#include "Representation.h"



Representation::Representation()
{
}

Representation::Representation(std::string filename, SDL_Renderer *ren, SDL_Point pos){
	loadSprite(filename, ren);
	_rect.x = pos.x;
	_rect.y = pos.y;
}


Representation::~Representation()
{
}

void Representation::loadSprite(std::string filename, SDL_Renderer *ren) {
	SDL_Surface *surface = SDL_LoadBMP(filename.c_str());
	if (surface) {
		_texture = SDL_CreateTextureFromSurface(ren, surface);
		SDL_FreeSurface(surface);
		if (!_texture) {
			utility::logSDLError(std::cout, "CreateTextureFromSurface");
		}
		int width, heigth;
		SDL_QueryTexture(_texture, NULL, NULL, &width, &heigth);
		_rect.w = width;
		_rect.h = heigth;
	}
	else {
		utility::logSDLError(std::cout, "LoadBMP");
	}
}

void Representation::updatePos(SDL_Point pos) {
	_rect.x = pos.x;
	_rect.y = pos.y;
}

void Representation::drawSelf(SDL_Renderer * ren) {
	//std::cout << _rect.x << " " << _rect.y << std::endl;
	SDL_RenderCopy(ren, _texture, NULL, &_rect);
}
