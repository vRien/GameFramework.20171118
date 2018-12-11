#include "Enemy1.h"
#include "InputHandler.h"
#include "Vector2D.h"


Enemy1::Enemy1(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	//m_velocity.setY(2);
	m_velocity.setX(-4);
}

void Enemy1::draw()
{
	SDLGameObject::draw();
}

void Enemy1::update()
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
	/*if (m_position.getY() < 0) {
		m_velocity.setX(-2);
		m_velocity.setY(2);
	}*/
	if (m_position.getX() < 0)
	{
		m_velocity.setX(4);
	}
	/*else if (m_position.getY() > 400) {
		m_velocity.setX(2);
		m_velocity.setY(-2);
	}*/
	else if (m_position.getX() > 500) {
		m_velocity.setX(-4);
	}
	SDLGameObject::update();
}

//void Enemy1::handleInput()
//{
//	if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
//	{
//		m_velocity.setX(1);
//	}
//
//	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
//	m_velocity = (*vec - m_position) / 100.0f;
//}
void Enemy1::clean()
{
}