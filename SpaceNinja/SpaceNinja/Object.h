#pragma once

#include <vector>
#include <memory>
#include "Representation.h"
#include "Controller.h"

using ReprPtr = std::shared_ptr<Representation>;
using CtrlPtr = std::shared_ptr<Controller>;

class Object
{
public:
	Object();
	Object(SDL_Rect rect, std::string filename, SDL_Renderer *ren);
	~Object();

	SDL_Rect getRect();
	SDL_Point getPos();
	ReprPtr getRepresentation();
	CtrlPtr getController();

	void setPos(int x, int y);
	void setRect(SDL_Rect);
	void setController(CtrlPtr controller);

	virtual void resolveInput(SDL_Event &e)=0;
	virtual std::vector<Object *> update()=0;
	
private:
	SDL_Rect _rect;
	ReprPtr _representation;
	CtrlPtr _controller;
};

