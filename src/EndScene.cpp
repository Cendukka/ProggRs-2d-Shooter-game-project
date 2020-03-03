#include "EndScene.h"
#include "Game.h"
#include <ctime>
#include "GLM/gtx/string_cast.hpp"
#include <algorithm>
#include "TileComparators.h"
#include <iomanip>

EndScene::EndScene()
{
	EndScene::start();
}

EndScene::~EndScene()
{
}

void EndScene::draw()
{
	m_LabelGameOver->draw();
	m_LabelNewGame->draw();
}

void EndScene::update()
{
}

void EndScene::clean()
{
	delete m_LabelGameOver;
	delete m_LabelNewGame;
	removeAllChildren();
}

void EndScene::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->quit();
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				TheGame::Instance()->quit();
				break;
			
			case SDLK_1:
				TheGame::Instance()->changeSceneState(SceneState::START_SCENE);
				break;
			}
			break;
		default:
			break;
		}
	}
}

void EndScene::start()
{
	SDL_Color blue = { 0, 0, 255, 255 };
	SDL_Color red = { 255, 0, 0, 255 };
	m_LabelGameOver = new Label("GAME OVER", "Dock51", 80, blue, glm::vec2(400.0f, 40.0f));
	m_LabelNewGame = new Label("Press \"1\" to Start again!", "Dock51", 30, red, glm::vec2(400.0f, 160.0f));
	m_LabelGameOver->setParent(this);
	m_LabelNewGame->setParent(this);
	addChild(m_LabelGameOver);
	addChild(m_LabelNewGame);
}