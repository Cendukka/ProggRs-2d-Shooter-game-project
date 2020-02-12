#include "Level1Scene.h"
#include "Game.h"
#include <iostream>
#include "Background.h"
#include "CollisionManager.h"

Level1Scene::Level1Scene()
{
	start();
}

Level1Scene::~Level1Scene()
{
}

void Level1Scene::draw()
{
	//draws game objects
	
	m_pBackground->draw();
	m_pShip->draw();
	m_pComet->draw();
	//m_pBullet->draw();


}

void Level1Scene::update()
{
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
	m_pComet->update();
	m_pBackground->update();
	for(int i = 0; i < m_pShip->MAX_BULLETS; i++)
	{
		Collision::squaredRadiusCheck(m_pComet, m_pShip->mBullets[i]);
	}
	Collision::squaredRadiusCheck(m_pShip, m_pComet);

	//std::cout << m_pBullet->getSpeed() << std::endl;
	//updates bullet movement on x-axis
	//m_pBullet->setPosition(glm::vec2((m_pBullet->getPosition().x + m_pBullet->getSpeed()), m_pBullet->getPosition().y));


	//Bullet place is on the tip of the ship
	//m_pBullet->setPosition(glm::vec2(m_pShip->getPosition().x+35.0f, m_pShip->getPosition().y));
	//m_pBullet->setPosition(m_mousePosition);
}



void Level1Scene::clean()
{
	
}

void Level1Scene::handleEvents()
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
				m_pShip->handleFiring();
				break;
			}

			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				//m_pStartButton->setMouseButtonClicked(false);
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
				break;
			case SDLK_2:
				TheGame::Instance()->changeSceneState(SceneState::END_SCENE);
				break;

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

void Level1Scene::start()
{
	// allocates memory on the heap for this game object


	m_pShip = new Ship();
	m_pBullet = new Bullet();
	m_pBackground = new Background();
	m_pComet = new Comet();
	for(int i = 0; i < m_pShip->MAX_BULLETS; i++)
	{
		m_pShip->mBullets[i]->setComet(m_pComet);
	}
}

glm::vec2 Level1Scene::getMousePosition()
{
	return m_mousePosition;
}

/*
bool Level1Scene::m_MouseOver()
{
	float topLeftX = m_pStartButton->getPosition().x - m_pStartButton->getWidth() * 0.5;
	float topLeftY = m_pStartButton->getPosition().y - m_pStartButton->getHeight() * 0.5;
	float width = m_pStartButton->getWidth();
	float height = m_pStartButton->getHeight();


	if(m_mousePosition.x > topLeftX &&
		m_mousePosition.x < topLeftX + width &&
		m_mousePosition.y > topLeftY &&
		m_mousePosition.y < topLeftY + height)
	{
		//std::cout << "Mouse Over!!" << std::endl;

		m_pStartButton->setAlpha(178);
		return true;
	}
	else
	{
		m_pStartButton->setAlpha(255);
		return false;
	}
}

void Level1Scene::m_MouseClick()
{
	if(m_MouseOver() && m_mouseClicked)
	{
		std::cout << "Mouse Button Clicked!" << std::endl;
	}
}

*/
