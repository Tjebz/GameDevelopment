#pragma once

#include <vector>
#include <memory>
#include "Representation.h"

using ReprPtr = std::shared_ptr<Representation>;

class Object
{
public:
	Object();
	Object(SDL_Rect rect, std::string filename, SDL_Renderer *ren);
	~Object();

	SDL_Rect getRect();
	SDL_Point getPos();

	void setPos(int x, int y);
	void setRect(SDL_Rect);

	ReprPtr getRepresentation();

	virtual std::vector<Object *> update()=0;
	
private:
	SDL_Rect _rect;
	ReprPtr _representation;
};

