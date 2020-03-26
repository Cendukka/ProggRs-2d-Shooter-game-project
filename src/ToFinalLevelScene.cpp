#include "ToFinalLevelScene.h"
#include "Game.h"
#include <ctime>
#include "GLM/gtx/string_cast.hpp"
#include <algorithm>
#include "TileComparators.h"
#include <iomanip>

ToFinalLevelScene::ToFinalLevelScene()
{
	ToFinalLevelScene::start();
}

ToFinalLevelScene::~ToFinalLevelScene()
{
}

void ToFinalLevelScene::draw()
{
	m_pBackground->draw();
	m_pBackground1->draw();
	m_pFinalLevelLabel->draw();
	m_pFinalLevelButton->draw();

}

void ToFinalLevelScene::update()
{

	m_pBackground->update();
	m_pBackground1->update();
	m_pFinalLevelButton->setMousePosition(m_mousePosition);
	m_pFinalLevelButton->ButtonClick();
}

void ToFinalLevelScene::clean()
{
	delete m_pFinalLevelLabel;

	removeAllChildren();
}

void ToFinalLevelScene::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->quit();
			break;
		case SDL_MOUSEMOTION:
			m_mousePosition.x = event.motion.x;
			m_mousePosition.y = event.motion.y;

			/*std::cout << "Mouse X: " << m_mousePosition.x << std::endl;
			std::cout << "Mouse Y: " << m_mousePosition.y << std::endl;
			std::cout << "---------------------------------------------" << std::endl;*/
			break;
		case SDL_MOUSEBUTTONDOWN:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pFinalLevelButton->setMouseButtonClicked(true);
				break;
			}

			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pFinalLevelButton->setMouseButtonClicked(false);
				break;
			}
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				TheGame::Instance()->quit();
				break;
			case SDLK_1:
				TheGame::Instance()->changeSceneState(SceneState::LEVEL1_SCENE);
				break;
			case SDLK_2:
				TheGame::Instance()->changeSceneState(SceneState::END_SCENE);
				break;
			case SDLK_3:
				TheGame::Instance()->changeSceneState(SceneState::NEXT_LEVEL_SCENE);
				break;
			}
			break;

		default:
			break;
		}
	}
}

// this function is used for initialization
void ToFinalLevelScene::start()
{
	SDL_Color colorr = { 255,255,255, 255 };
	m_pFinalLevelLabel = new Label("Move To Final Level", "Consolas", 60, colorr, glm::vec2(400.0f, 40.0f));
	m_pFinalLevelLabel->setParent(this);
	addChild(m_pFinalLevelLabel);
	m_pFinalLevelButton = new FinalLevelButton();
	m_pFinalLevelButton->setMouseButtonClicked(false);


	m_pBackground = new Background();
	m_pBackground1 = new Background1();

	addChild(m_pBackground);
	addChild(m_pBackground1);


}

glm::vec2 ToFinalLevelScene::getMousePosition()
{
	return m_mousePosition;
}
