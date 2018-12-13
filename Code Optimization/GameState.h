#pragma once
#include "SDLGameObject.h"
#include<string>
#include<vector>

class GameState
{
protected:
	std::vector<SDLGameObject*> m_SDLGameObjects;
public:
	virtual void update() = 0;
	virtual void render() = 0;
	virtual bool onEnter() = 0;
	virtual bool onExit() = 0;
	virtual std::string getStateID() const = 0;
};	