#include "Coord.h"



Coord::Coord() : _x(0), _y(0), _init(false)
{
}

Coord::Coord(int x, int y) : _x(x), _y(y), _init(true)
{
}

Coord::~Coord()
{
}

void Coord::init(int x, int y)
{
	_x = x;
	_y = y;
	_init = true;
}

void Coord::setX(int x)
{
	_x = x;
}

void Coord::setY(int y)
{
	_y = y;
}

int Coord::getX()
{
	return _x;
}

int Coord::getY()
{
	return _y;
}

bool Coord::isInitialized()
{
	return _init;
}
