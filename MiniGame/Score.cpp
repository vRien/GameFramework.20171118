#include "Score.h"
#include "InputHandler.h"
#include "Vector2D.h"


Score::Score(const LoaderParams* pParams) : SDLGameObject(pParams)
{
	m_velocity.setY(4);
	m_velocity.setX(-4);
}

void Score::draw()
{
	SDLGameObject::draw();
}

void Score::update()
{
	m_currentFrame = int(((SDL_GetTicks() / 100) % 1));
	if (m_position.getY() < 0) {
		m_velocity.setX(-4);
		m_velocity.setY(4);
	}
	else if (m_position.getX() < 0)
	{
		m_velocity.setX(4);
		m_velocity.setY(4);
	}
	else if (m_position.getY() > 400) {
		m_velocity.setX(4);
		m_velocity.setY(-4);
	}
	else if (m_position.getX() > 500) {
		m_velocity.setX(-4);
		m_velocity.setY(-4);
	}
	SDLGameObject::update();
}

void Score::handleInput()
{
	if (TheInputHandler::Instance()->getMouseButtonState(LEFT))
	{
		m_velocity.setX(1);
	}

	Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
	m_velocity = (*vec - m_position) / 100.0f;
}
void Score::clean()
{
}