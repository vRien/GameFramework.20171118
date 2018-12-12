#include "Obstacle.h"
#include "InputHandler.h"
#include "Vector2D.h"


Obstacle::Obstacle(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	m_velocity.setX(-4);
}

void Obstacle::draw()
{
	SDLGameObject::draw();
}

void Obstacle::update()
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

void Obstacle::clean()
{
}