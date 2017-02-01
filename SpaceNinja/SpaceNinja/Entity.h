#pragma once

#include "Object.h"

class Entity : public Object {
public:
	Entity();
	Entity(SDL_Rect rect, std::string filename, SDL_Renderer *ren);
	~Entity();

	void setAcceleration(int acceleration);

	int getAcceleration();

	void accelerate(int xAcc, int yAcc);
	void decellerate(bool horizontal, bool vertical);
	void move();

	virtual void resolveInput(SDL_Event &e);
	virtual std::vector<Object *> update();

private:
	int _acceleration;
	int _maxVel;
	SDL_Point _velocity;
};
