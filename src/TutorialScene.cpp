#include "TutorialScene.h"
#include "Game.h"
#include "ScoreBoardManager.h"
#include <ctime>
#include "GLM/gtx/string_cast.hpp"
#include <algorithm>
#include "TileComparators.h"
#include <iomanip>

TutorialScene::TutorialScene()
{
	start();
}

TutorialScene::~TutorialScene()
{
}

void TutorialScene::draw()
{
	m_pBackground->draw();
	m_pBackground1->draw();
	m_pShip->draw();
	m_pComet->draw();
	m_pLabel->draw();
	ScoreBoardManager::Instance()->Draw();
}

void TutorialScene::update()
{
	if((m_pShip->getPosition().y >= 300.0f + m_pShip->getHeight() 
		|| m_pShip->getPosition().y <= 300.0f - m_pShip->getHeight()) && m_tutorialStage == 0)
	{
		moveToTheNextStage();
	}
	if (m_mousePosition.x > (Config::SCREEN_WIDTH * 0.5f))
	{
		m_pShip->setPosition(glm::vec2((Config::SCREEN_WIDTH * 0.5), m_mousePosition.y));
	}
	else
	{
		m_pShip->setPosition(m_mousePosition);
	}
	m_pShip->update();
	if(m_tutorialStage > 0)
	{
		m_pComet->update();
	}
	for(int i = 0; i < m_pShip->MAX_BULLETS; i++)
	{
		if(CollisionManager::squaredRadiusCheck(m_pComet ,m_pShip->mBullets[i]))
		{
			m_pComet->getDamage();
			m_pShip->mBullets[i]->reset();
		}
	}
	if(CollisionManager::squaredRadiusCheck(m_pShip, m_pComet->getPowerUp()))
	{
		m_pComet->getPowerUp()->reset();
	}
	m_pBackground->update();
	m_pBackground1->update();
	if(ScoreBoardManager::Instance()->getPowerUp() > 0)
	{
		moveToTheNextStage();
	}
}

void TutorialScene::clean()
{
	removeAllChildren();
}

void TutorialScene::handleEvents()
{
	int wheel = 0;

	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->quit();
			break;
		case SDL_MOUSEMOTION:
			m_mousePosition.x = event.motion.x;
			m_mousePosition.y = event.motion.y;

		case SDL_MOUSEBUTTONDOWN:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				//m_pBullet->fire(m_pShip->getPosition());

				if (m_mouseRegister < 1 && m_canShoot) {
					m_pShip->handleFiring();
					m_mouseRegister = 1;
				}
				break;
			}

			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				//m_pStartButton->setMouseButtonClicked(false);
				m_mouseRegister = 0;
				break;
			}
			break;
		case SDL_MOUSEWHEEL:
			wheel = event.wheel.y;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				TheGame::Instance()->quit();
				break;
			case SDLK_1:
				ScoreBoardManager::Instance()->setPowerUp(0);
				ScoreBoardManager::Instance()->setScore(0);
				TheGame::Instance()->changeSceneState(SceneState::START_SCENE);
				break;
				//case SDLK_2:
				//	TheGame::Instance()->changeSceneState(SceneState::START_SCENE);
				//	break;
				/*case SDLK_3:
					TheGame::Instance()->changeSceneState(SceneState::NEXT_LEVEL_SCENE);
					break;*/
					/*case SDLK_4:
						TheGame::Instance()->changeSceneState(SceneState::FINAL_LEVEL);
						ScoreBoardManager::Instance()->setHealth(100);
						ScoreBoardManager::Instance()->setScore(0);
						break;*/

						/************************************************************************/
			case SDLK_w:

				break;
			case SDLK_s:

				break;
			case SDLK_a:

				break;
			case SDLK_d:

				break;
			}

			break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
			case SDLK_w:

				break;

			case SDLK_s:

				break;

			case SDLK_a:

				break;
			case SDLK_d:

				break;
			}

			break;
		default:
			break;
		}
	}
}

void TutorialScene::start()
{
	m_tutorialStage = 0;
	
	m_pShip = new Ship();
	addChild(m_pShip);

	m_pComet = new Comet();
	addChild(m_pComet);

	SDL_Color white = { 255, 255, 255, 255 };
	m_pLabel = new Label("Use your mouse to move", "Consolas", 24, white,
		glm::vec2(400.0f, 50.0f));
	addChild(m_pLabel);

	m_pBackground = new Background();
	addChild(m_pBackground);

	m_pBackground1 = new Background1();
	addChild(m_pBackground1);

	ScoreBoardManager::Instance()->Start();
}

void TutorialScene::moveToTheNextStage()
{
	if(m_tutorialStage == 0)
	{
		m_tutorialStage = 1;
		m_canShoot = 1;
		m_pLabel->setText("To shoot enemies press left mouse button");
	}else if(m_tutorialStage == 1)
	{
		m_tutorialStage = 2;
		m_pLabel->setText("To finish tutorial press \"1\"");
	}
}
