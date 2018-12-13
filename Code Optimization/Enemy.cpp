#include "Enemy.h"
#include "InputHandler.h"
#include "Vector2D.h"


Enemy::Enemy(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	m_velocity.setY(2);
	m_velocity.setX(1);
}

void Enemy::draw()
{
	SDLGameObject::draw();
}

void Enemy::update()
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % 5));
	if (m_position.getY() < 0) {
		m_velocity.setX(-2);
		m_velocity.setY(2);
	}
	else if (m_position.getX() < 0)
	{
		m_velocity.setX(2);
		m_velocity.setY(2);
	}
	else if (m_position.getY() > 400) {
		m_velocity.setX(2);
		m_velocity.setY(-2);
	}
	else if (m_position.getX() > 500) {
		m_velocity.setX(-2);
		m_velocity.setY(-2);
	}
	SDLGameObject::update();
}
