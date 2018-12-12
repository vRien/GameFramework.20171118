#include "Obstacle2.h"
#include "InputHandler.h"
#include "Vector2D.h"


Obstacle2::Obstacle2(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	m_velocity.setY(-4);
}

void Obstacle2::draw()
{
	SDLGameObject::draw();
}

void Obstacle2::update()
{
	if (m_position.getY() < 0)
	{
		m_velocity.setY(4);
	}
	else if (m_position.getY() > 400)
	{
		m_velocity.setY(-4);
	}
	SDLGameObject::update();
}

void Obstacle2::clean()
{
}