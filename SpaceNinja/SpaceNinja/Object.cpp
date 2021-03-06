#include "Object.h"

Object::Object() {
	_representation = std::make_shared<Representation>(Representation());
}

Object::Object(SDL_Rect rect, std::string filename, SDL_Renderer *ren) {
	_rect = rect;
	_representation = std::make_shared<Representation>(Representation(filename, ren, getPos()));
}

Object::~Object() {
}

SDL_Point Object::getPos() {
	SDL_Point pt = {_rect.x, _rect.y};
	return pt;
}

SDL_Rect Object::getRect() {
	return _rect;
}

void Object::setPos(int x, int y) {
	_rect.x = x;
	_rect.y = y;
	_representation->updatePos(SDL_Point{ x, y });
}

void Object::setRect(SDL_Rect rect) {
	_rect = rect;
}

void Object::setController(CtrlPtr controller) {
	_controller = controller;
}

ReprPtr Object::getRepresentation() {
	return _representation;
}

CtrlPtr Object::getController() {
	return _controller;
}
