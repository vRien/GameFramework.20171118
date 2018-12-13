#include "PauseState.h"
#include "Game.h"
#include "MenuState.h"
#include "MenuButton.h"

const std::string PauseState::s_pauseID = "PAUSE";

void PauseState::s_pauseToMain()
{
	TheGame::Instance()->getStateMachine()->changeState(MenuState::Instance());
}

void PauseState::s_resumePlay()
{
	TheGame::Instance()->getStateMachine()->popState();
}

void PauseState::update()
{
	for (int i = 0; i < m_SDLGameObjects.size(); i++)
	{
		m_SDLGameObjects[i]->update();
	}
}

void PauseState::render()
{
	for (int i = 0; i < m_SDLGameObjects.size(); i++)
	{
		m_SDLGameObjects[i]->draw();
	}
}

bool PauseState::onEnter()
{
	if (!TheTextureManager::Instance()->load("assets/resume.png",
		"resumebutton", TheGame::Instance()->getRenderer())) {
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/main.png",
		"mainbutton", TheGame::Instance()->getRenderer())) {
		return false;
	}
	SDLGameObject* button1 = new MenuButton(new
		LoaderParams(200, 100, 200, 80, "mainbutton"), s_pauseToMain);
	SDLGameObject* button2 = new MenuButton(new
		LoaderParams(200, 300, 200, 80, "resumebutton"), s_resumePlay);
	m_SDLGameObjects.push_back(button1);
	m_SDLGameObjects.push_back(button2);
	std::cout << "entering PauseState\n";
	return true;
}

bool PauseState::onExit()
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