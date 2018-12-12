#pragma once
#include "SDLGameObject.h"

class Back : public SDLGameObject
{
private:

public:
	Back(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
};