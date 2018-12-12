#pragma once
#include "SDLGameObject.h"

class Obstacle3 : public SDLGameObject
{
public:
	Obstacle3(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
};