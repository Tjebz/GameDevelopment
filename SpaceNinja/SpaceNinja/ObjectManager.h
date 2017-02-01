#pragma once

#include "RepresentationManager.h"
#include "Object.h"

using ObjectPtr = std::shared_ptr<Object>;

class ObjectManager {
public:
	ObjectManager();
	ObjectManager(RepresentationManager *reprManager);
	~ObjectManager();

	void addObject(ObjectPtr Object);

	void resolveInput(SDL_Event &e);
	void updateAll();

private:
	RepresentationManager *_reprManager;
	std::vector<ObjectPtr> _objectList;
};

