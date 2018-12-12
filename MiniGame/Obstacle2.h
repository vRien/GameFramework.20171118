#pragma once
#include "SDLGameObject.h"

class Obstacle2 : public SDLGameObject
{
public:
	Obstacle2(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
};