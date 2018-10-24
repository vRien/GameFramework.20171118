#pragma once
#include "SDL.h"
#include <iostream>

class GameObject
{
public:
	void load(int x, int y, int width, int height,
		std::string textureID);
	void draw(SDL_Renderer* pRenderer);
	virtual void update();
	void clean();
	virtual int speed();
protected:
	std::string m_textureID;
	int m_currentFrame;
	int m_currentRow;
	int m_x;
	int m_y;
	int m_width;
	int m_height;
	int sp;
	bool x = true;
};