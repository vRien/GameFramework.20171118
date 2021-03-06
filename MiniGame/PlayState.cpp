#include "PlayState.h"
#include "Game.h"
#include "PauseState.h"
#include "SDLGameObject.h"
#include "GameOverState.h"
#include "GameClearState.h"
#include "Score.h"
#include "Obstacle.h"
#include "Obstacle1.h"
#include "Obstacle2.h"
#include "Obstacle3.h"
#include "Back.h"

const std::string PlayState::s_playID = "PLAY";

bool PlayState::checkCollision(SDLGameObject* p1, SDLGameObject* p2)
{
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA = p1->getPosition().getX();
	rightA = p1->getPosition().getX() + p1->getWidth();
	topA = p1->getPosition().getY();
	bottomA = p1->getPosition().getY() + p1->getHeight();

	//Calculate the sides of rect B
	leftB = p2->getPosition().getX();
	rightB = p2->getPosition().getX() + p2->getWidth();
	topB = p2->getPosition().getY();
	bottomB = p2->getPosition().getY() + p2->getHeight();

	//If any of the sides from A are outside of B
	if (bottomA <= topB) { return false; }
	if (topA >= bottomB) { return false; }
	if (rightA <= leftB) { return false; }
	if (leftA >= rightB) { return false; }
	return true;
}

void PlayState::update()
{
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_ESCAPE))
	{
		TheGame::Instance()->getStateMachine()->changeState(new PauseState());
		return;
	}
	for (int i = 0; i < m_gameObjects.size(); i++) {
		m_gameObjects[i]->update();
	}
	if (checkCollision(
		dynamic_cast<SDLGameObject*>(m_gameObjects[1]),
		dynamic_cast<SDLGameObject*>(m_gameObjects[2]))||checkCollision(
			dynamic_cast<SDLGameObject*>(m_gameObjects[1]),
			dynamic_cast<SDLGameObject*>(m_gameObjects[4]))|| checkCollision(
				dynamic_cast<SDLGameObject*>(m_gameObjects[1]),
				dynamic_cast<SDLGameObject*>(m_gameObjects[5])) || checkCollision(
					dynamic_cast<SDLGameObject*>(m_gameObjects[1]),
					dynamic_cast<SDLGameObject*>(m_gameObjects[6]))|| checkCollision(
						dynamic_cast<SDLGameObject*>(m_gameObjects[1]),
						dynamic_cast<SDLGameObject*>(m_gameObjects[7])))
	{
		TheGame::Instance()->getStateMachine()->changeState(new GameOverState());
		return;
	}	
	if (checkCollision(
		dynamic_cast<SDLGameObject*>(m_gameObjects[1]),
		dynamic_cast<SDLGameObject*>(m_gameObjects[3])))
	{
		TheGame::Instance()->getStateMachine()->changeState(new GameClearState());
		return;
	}
}

void PlayState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool PlayState::onEnter()
{
	if (!TheTextureManager::Instance()->load("assets/helicopter.png",
		"helicopter", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/helicopter2.png",
		"helicopter2", TheGame::Instance()->getRenderer())) {
		return false;
	}	
	if (!TheTextureManager::Instance()->load("assets/score.png",
		"score", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/Obstacle.png",
		"obstacle", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/background.png",
		"background", TheGame::Instance()->getRenderer())) {
		return false;
	}
	GameObject* player = new Player(
		new LoaderParams(500, 100, 128, 55, "helicopter"));
	GameObject* enemy = new Enemy(
		new LoaderParams(100, 100, 128, 55, "helicopter2"));
	GameObject* score = new Score(
		new LoaderParams(200, 200, 35, 35, "score"));
	GameObject* obstacle = new Obstacle(
		new LoaderParams(100, 100, 70, 70, "obstacle"));
	GameObject* obstacle1 = new Obstacle1(
		new LoaderParams(300, 300, 70, 70, "obstacle"));
	GameObject* obstacle2 = new Obstacle2(
		new LoaderParams(200, 200, 70, 70, "obstacle"));
	GameObject* obstacle3 = new Obstacle3(
		new LoaderParams(400, 400, 70, 70, "obstacle"));
	GameObject* background = new Back(
		new LoaderParams(0, 0, 640, 480, "background"));
	m_gameObjects.push_back(background);
	m_gameObjects.push_back(player);
	m_gameObjects.push_back(enemy);
	m_gameObjects.push_back(score);
	m_gameObjects.push_back(obstacle);
	m_gameObjects.push_back(obstacle1);
	m_gameObjects.push_back(obstacle2);
	m_gameObjects.push_back(obstacle3);
	std::cout << "entering PlayState\n";
	return true;
}

bool PlayState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();

	TheTextureManager::Instance()->clearFromTextureMap("helicopter");
	std::cout << "exiting PlayState\n";
	return true;
}

void SDLGameObject::draw()
{
	if (m_velocity.getX() > 0)
	{
		TextureManager::Instance()->drawFrame(m_textureID,
			(Uint32)m_position.getX(), (Uint32)m_position.getY(),
			m_width, m_height, m_currentRow, m_currentFrame,
			TheGame::Instance()->getRenderer(),
			SDL_FLIP_HORIZONTAL);
	}
	else {
		TextureManager::Instance()->drawFrame(m_textureID,
			(Uint32)m_position.getX(), (Uint32)m_position.getY(),
			m_width, m_height, m_currentRow, m_currentFrame,
			TheGame::Instance()->getRenderer());
	}
}