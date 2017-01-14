#include "Size.h"



Size::Size()
{
}

Size::Size(int width, int heigth) : _width(width), _heigth(heigth)
{
}


Size::~Size()
{
}

void Size::setWidth(int width)
{
	_width = width;
}

void Size::setHeigth(int heigth)
{
	_heigth = heigth;
}

int Size::getWidth()
{
	return _width;
}

int Size::getHeigth()
{
	return _heigth;
}
