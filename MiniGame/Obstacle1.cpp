#include "Obstacle1.h"
#include "InputHandler.h"
#include "Vector2D.h"


Obstacle1::Obstacle1(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	m_velocity.setX(-4);
}

void Obstacle1::draw()
{
	SDLGameObject::draw();
}

void Obstacle1::update()
{
	if (m_position.getX() < 0)
	{
		m_velocity.setX(4);
	}
	else if (m_position.getX() > 500) {
		m_velocity.setX(-4);
	}
	SDLGameObject::update();
}

void Obstacle1::clean()
{
}