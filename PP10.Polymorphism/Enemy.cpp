#include "Game.h"

void Enemy::update()
{

	if (x == true)
	{
		if (m_x == 0 || m_x < 500)
		{
			m_x += 1;
			if (m_x == 500) 
			{
				x = false;
			}
	}
	}
	if (x == false)
	{
		if (m_x == 500 || m_x >= 0)
		{
			m_x -= 1;
			if (m_x == 0)
			{
				x = true;
			}
		}
	}
	m_currentFrame = int(((SDL_GetTicks() / 100) % 4));
}