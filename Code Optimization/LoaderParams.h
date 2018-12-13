#pragma once
#include "SDL.h"
#include <iostream>

class LoaderParams
{
public:
	LoaderParams(float x, float y, int width, int height,
		std::string textureID) : m_x(x), m_y(y), m_width(width),
		m_height(height), m_textureID(textureID) {}
	float getX() const { return m_x; }
	float getY() const { return m_y; }
	int getWidth() const { return m_width; }
	int getHeight() const { return m_height; }
	std::string getTextureID() const { return m_textureID; }
private:
	int m_x;
	int m_y;
	int m_width;
	int m_height;
	std::string m_textureID;
};