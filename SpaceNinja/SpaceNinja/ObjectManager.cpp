#include "ObjectManager.h"

ObjectManager::ObjectManager() {
}

ObjectManager::ObjectManager(RepresentationManager *reprManager) {
	_reprManager = reprManager;
}

ObjectManager::~ObjectManager() {
}

void ObjectManager::addObject(ObjectPtr object) {
	_objectList.push_back(object);
	_reprManager->addRepr(object->getRepresentation());
}

void ObjectManager::updateAll() {
	for (std::vector<ObjectPtr>::iterator it = _objectList.begin(); it != _objectList.end(); it++) {
		(*it)->update();
	}
}
