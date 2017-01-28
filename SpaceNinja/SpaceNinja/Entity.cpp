#include "Entity.h"



Entity::Entity() {
}

Entity::Entity(SDL_Rect rect, std::string filename, SDL_Renderer *ren) : Object(rect, filename, ren) {
}


Entity::~Entity() {
}

std::vector<Object*> Entity::update() {
	return std::vector<Object*>();
}
