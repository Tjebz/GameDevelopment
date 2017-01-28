#pragma once
#include "Object.h"
class Entity : public Object {
public:
	Entity();
	Entity(SDL_Rect rect, std::string filename, SDL_Renderer *ren);
	~Entity();

	virtual std::vector<Object *> update();
};
