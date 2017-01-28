#include "RepresentationManager.h"

RepresentationManager::RepresentationManager() {
}


RepresentationManager::~RepresentationManager() {
}

void RepresentationManager::addRepr(ReprPtr repr) {
	_reprList.push_back(repr);
}

void RepresentationManager::updateList() {
	for (std::vector<ReprPtr>::iterator it = _reprList.begin(); it != _reprList.end();) {
		if (it->unique()) {
			it = _reprList.erase(it);
		}
		else {
			it++;
		}
	}
}

void RepresentationManager::drawAll(SDL_Renderer *ren) {
	for (std::vector<ReprPtr>::iterator it = _reprList.begin(); it != _reprList.end(); it++) {
		(*it)->drawSelf(ren);
	}
	SDL_RenderPresent(ren);
}
