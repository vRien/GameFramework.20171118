#include "GameOverState.h"
#include "Game.h"
#include "MenuState.h"
#include "PlayState.h"
#include "MenuButton.h"
#include "AnimatedGraphic.h"

const std::string GameOverState::s_gameOverID = "GAMEOVER";

void GameOverState::update()
{
	for (int i = 0; i < m_SDLGameObjects.size(); i++)
	{
		m_SDLGameObjects[i]->update();
	}
}

void GameOverState::render() 
{
	for (int i = 0; i < m_SDLGameObjects.size(); i++)
	{
		m_SDLGameObjects[i]->draw();
	}
}

bool GameOverState::onExit()
{
	for (int i = 0; i < m_SDLGameObjects.size(); i++)
	{
		m_SDLGameObjects[i]->clean();
	}
	m_SDLGameObjects.clear();
	TheTextureManager::Instance()
		->clearFromTextureMap("resumebutton");
	TheTextureManager::Instance()
		->clearFromTextureMap("mainbutton");
	// reset the mouse button states to false
	TheInputHandler::Instance()->reset();
	std::cout << "exiting PauseState\n";
	return true;
}

void GameOverState::s_gameOverToMain()
{
	TheGame::Instance()->getStateMachine()->changeState(
		MenuState::Instance());
}
void GameOverState::s_restartPlay()
{
	TheGame::Instance()->getStateMachine()->changeState(
		new PlayState());
}

bool GameOverState::onEnter()
{
	if (!TheTextureManager::Instance()->load("assets/gameover.png",
		"gameovertext", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/main.png",
		"mainbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/restart.png",
		"restartbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	SDLGameObject* gameOverText = new AnimatedGraphic(
		new  LoaderParams(200, 100, 190, 30, "gameovertext"), 2);

	SDLGameObject* button1 = new MenuButton(
		new LoaderParams(200, 200, 200, 80, "mainbutton"),
		s_gameOverToMain);

	SDLGameObject* button2 = new MenuButton(
		new LoaderParams(200, 300, 200, 80, "restartbutton"),
		s_restartPlay);

	m_SDLGameObjects.push_back(gameOverText);
	m_SDLGameObjects.push_back(button1);
	m_SDLGameObjects.push_back(button2);
	std::cout << "entering PauseState\n";
	return true;
}