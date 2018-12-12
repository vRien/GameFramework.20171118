#include "Obstacle3.h"
#include "InputHandler.h"
#include "Vector2D.h"


Obstacle3::Obstacle3(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	m_velocity.setY(-4);
}

void Obstacle3::draw()
{
	SDLGameObject::draw();
}

void Obstacle3::update()
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

void Obstacle3::clean()
{
}