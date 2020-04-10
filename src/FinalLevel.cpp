#include "FinalLevel.h"
#include "Game.h"
#include <iostream>
#include "Background.h"
#include "Background1.h"
#include "CollisionManager.h"
#include "ScoreBoardManager.h"


FinalLevel::FinalLevel()
{
	start();
}

FinalLevel::~FinalLevel()
{
}

void FinalLevel::draw()
{
	//draws game objects
	m_pBackground->draw();
	m_pBackground1->draw();
	//m_pLabel->draw();
	m_pShip->draw();
	for (int i = 0; i < MAX_COMETS; i++)
	{
		m_pComets[i]->draw();
	}
	//m_pComet->draw();

	//Draws small enemies
	/*for(int i = 0; i < MAX_SMALL_ENEMIES; i++)
	{
		m_pSmallEnemies[i]->draw(i);
	}*/
	m_pMediumBoss->draw();
	ScoreBoardManager::Instance()->Draw();
}

void FinalLevel::update()
{

	/*if (ScoreBoardManager::Instance()->getScore() >= 10000)
	{
		std::cout << ScoreBoardManager::Instance()->getScore() << std::endl;
		TheGame::Instance()->changeSceneState(SceneState::END_SCENE);
	}*/
	//ship follows the mouse
	//also checks that ship won't go over half of the screen
	if (m_mousePosition.x > (Config::SCREEN_WIDTH * 0.5f))
	{
		m_pShip->setPosition(glm::vec2((Config::SCREEN_WIDTH * 0.5), m_mousePosition.y));
	}
	else
	{
		m_pShip->setPosition(m_mousePosition);
	}
	m_pShip->update();

	for (int i = 0; i < MAX_COMETS; i++)
	{
		m_pComets[i]->update();
	}
	for (int i = 0; i < MAX_SMALL_ENEMIES; i++) {
		m_pSmallEnemies[i]->update();
	}
	for (int i = 0; i < m_pShip->MAX_BULLETS; i++)
	{
		for (int j = 0; j < MAX_COMETS; j++)
		{
			if (Collision::squaredRadiusCheck(m_pComets[j], m_pShip->mBullets[i]))
			{
				m_pShip->mBullets[i]->reset();
				m_pComets[j]->getDamage();
			}
			if (Collision::squaredRadiusCheck(m_pShip, m_pComets[j]))
			{
				m_pShip->decreaseLife();
				m_pComets[j]->reset();

			}
		}
		//Update enemies and check collision
		for (int k = 0; k < MAX_SMALL_ENEMIES; k++) {
			if (Collision::squaredRadiusCheck(m_pShip->mBullets[i], m_pSmallEnemies[k]))
			{
				m_pSmallEnemies[k]->decreaseHealth();
				m_pShip->mBullets[i]->reset();

			}

			//	if (Collision::squaredRadiusCheck(m_pShip->mBullets[i], m_pMediumBoss))
			//	{
			//		m_pMediumBoss->decreaseHealth();
			//		m_pShip->mBullets[i]->reset();
			//	}
			}
	}
	m_pBackground->update();
	m_pBackground1->update();
	m_pMediumBoss->update();
	//m_pLabel->setText("SCORE: " + std::to_string(TheGame::Instance()->getScore()));

}



void FinalLevel::clean()
{

}

void FinalLevel::handleEvents()
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

				if (m_mouseRegister < 1) {
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
				TheGame::Instance()->changeSceneState(SceneState::START_SCENE);
				ScoreBoardManager::Instance()->setHealth(100);
				ScoreBoardManager::Instance()->setScore(0);
				break;
				/*case SDLK_2:
					TheGame::Instance()->changeSceneState(SceneState::END_SCENE);
					break;
				case SDLK_3:
					TheGame::Instance()->changeSceneState(SceneState::NEXT_LEVEL_SCENE);
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

void FinalLevel::start()
{
	// allocates memory on the heap for this game object


	m_pShip = new Ship();
	m_pBackground = new Background();
	m_pBackground1 = new Background1();
	m_pMediumBoss = new MediumBoss();
	//SDL_Color color = { 255, 0, 0, 255 };
	//m_pLabel = new Label("", "Consolas", 20, color, glm::vec2(75.0f, 25.0f));
	ScoreBoardManager::Instance()->Start();
	//Creates 3 small enemies
	for (int i = 0; i < MAX_SMALL_ENEMIES; i++)
	{
		int position = 150*(i+1);
		m_pSmallEnemies[i] = new SmallEnemy(position);
		std::cout << m_pSmallEnemies[i]->getPosition().x << " " << m_pSmallEnemies[i]->getPosition().y << std::endl;
	}

	for (int i = 0; i < MAX_COMETS; i++)
	{
		m_pComets[i] = new Comet();
	}
	ScoreBoardManager::Instance()->Start();
}

glm::vec2 FinalLevel::getMousePosition()
{
	return m_mousePosition;
}

