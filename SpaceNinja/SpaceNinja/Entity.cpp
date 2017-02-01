#include "Entity.h"



Entity::Entity() : _acceleration(0) {
}

Entity::Entity(SDL_Rect rect, std::string filename, SDL_Renderer *ren) : Object(rect, filename, ren), _acceleration(0),
	_maxVel(5){
}


Entity::~Entity() {
}

void Entity::setAcceleration(int acceleration) {
	_acceleration = acceleration;
}

int Entity::getAcceleration() {
	return _acceleration;
}

void Entity::accelerate(int xAcc, int yAcc) {
	if (xAcc > 0) {
		if (_velocity.x + xAcc < _maxVel) {
			_velocity.x += xAcc;
		}
		else {
			_velocity.x = _maxVel;
		}
	}
	else if(xAcc < 0){
		if (_velocity.x + xAcc > -_maxVel) {
			_velocity.x += xAcc;
		}
		else {
			_velocity.x = -_maxVel;
		}
	}
	
	if (yAcc > 0) {
		if (_velocity.y + yAcc < _maxVel) {
			_velocity.y += yAcc;
		}
		else {
			_velocity.y = _maxVel;
		}
	}
	else if (yAcc < 0) {
		if (_velocity.y + yAcc > -_maxVel) {
			_velocity.y += yAcc;
		}
		else {
			_velocity.y = -_maxVel;
		}
	}
}

void Entity::decellerate(bool horizontal, bool vertical) {
	if (horizontal) {
		_velocity.x = 0;
	}
	if (vertical) {
		_velocity.y = 0;
	}
}

void Entity::move() {
	SDL_Point pos = getPos();
	setPos(pos.x + _velocity.x, pos.y + _velocity.y);
}

void Entity::resolveInput(SDL_Event &e) {
	Command com = getController()->getCommand(e);
	switch (com) {
	case AccUp:
		accelerate(0, -_acceleration);
		break;
	case AccDown:
		accelerate(0, _acceleration);
		break;
	case AccLeft:
		accelerate(-_acceleration, 0);
		break;
	case AccRight:
		accelerate(_acceleration, 0);
		break;
	case DeccUp:
		decellerate(false, true);
		break;
	case DeccDown:
		decellerate(false, true);
		break;
	case DeccLeft:
		decellerate(true, false);
		break;
	case DeccRight:
		decellerate(true, false);
		break;
	}
}

std::vector<Object*> Entity::update() {
	move();
	return std::vector<Object*>();
}
