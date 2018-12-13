#include "MenuState.h"
#include "MenuButton.h"
#include "TextureManager.h"
#include "Game.h"
#include "PlayState.h"

const std::string MenuState::s_menuID = "MENU";
MenuState* MenuState::s_pInstance = 0;

void MenuState::update()
{
	for (int i = 0; i < m_SDLGameObjects.size(); i++)
	{
		m_SDLGameObjects[i]->update();
	}
}

void MenuState::render()
{
	for (int i = 0; i < m_SDLGameObjects.size(); i++)
	{
		m_SDLGameObjects[i]->draw();
	}
}

bool MenuState::onEnter()
{
	if (!TheTextureManager::Instance()->load("assets/button.png",
		"playbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/exit.png",
		"exitbutton", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	SDLGameObject* button1 = new MenuButton(
		new LoaderParams(100, 100, 400, 100, "playbutton"),
		s_menuToPlay);

	SDLGameObject* button2 = new MenuButton(
		new LoaderParams(100, 300, 400, 100, "exitbutton"),
		s_exitFromMenu);

	m_SDLGameObjects.push_back(button1);
	m_SDLGameObjects.push_back(button2);
	std::cout << "entering MenuState\n";
	return true;
}

bool MenuState::onExit()
{
	for (int i = 0; i < m_SDLGameObjects.size(); i++)
	{
		m_SDLGameObjects[i]->clean();
	}
	m_SDLGameObjects.clear();
	TheTextureManager::Instance()
		->clearFromTextureMap("playbutton");
	TheTextureManager::Instance()
		->clearFromTextureMap("exitbutton");
	std::cout << "exiting MenuState\n";
	return true;
}

void MenuState::s_menuToPlay()
{
	TheGame::Instance()->getStateMachine()->changeState(new PlayState());
}

void MenuState::s_exitFromMenu()
{
	TheGame::Instance()->quit();
}