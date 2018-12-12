#pragma once
#include "SDLGameObject.h"

class Obstacle1 : public SDLGameObject
{
public:
	Obstacle1(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
};