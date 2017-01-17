#pragma once
#include "Coord.h"
#include "Size.h"

class Entity
{
public:
	Entity();
	Entity(Coord coord, Size size);
	~Entity();
	bool collision(Entity e);
private:
	Coord _coord;
	Size _size;
};

