#pragma once
#include "SDLGameObject.h"

class Enemy1 : public SDLGameObject
{
private:
	void handleInput();

public:
	Enemy1(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
};