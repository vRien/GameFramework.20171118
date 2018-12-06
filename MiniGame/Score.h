#pragma once
#include "SDLGameObject.h"

class Score : public SDLGameObject
{
private:
	void handleInput();

public:
	Score(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
};