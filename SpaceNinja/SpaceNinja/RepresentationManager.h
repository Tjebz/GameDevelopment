#pragma once

#include <vector>
#include <memory>
#include "Representation.h"

using ReprPtr = std::shared_ptr<Representation>;

class RepresentationManager
{
public:
	RepresentationManager();
	~RepresentationManager();

	void addRepr(ReprPtr repr);
	void updateList();

	void drawAll(SDL_Renderer *ren);

private:
	std::vector<ReprPtr> _reprList;
};

