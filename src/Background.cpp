#include "Background.h"
#include "Game.h"
#include "Level1Scene.h"

Background::Background()
{

	TheTextureManager::Instance()->load("../Assets/BG1.png","level1Scene1", TheGame::Instance()->getRenderer());
	

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("level1Scene1");
	setWidth(size.x);
	setHeight(size.y);
	setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5, Config::SCREEN_HEIGHT * 0.5));
	setType(GameObjectType::BACK_GROUND);

	TheTextureManager::Instance()->load("../Assets/BG1.png", "level1Scene2", TheGame::Instance()->getRenderer());
	size = TheTextureManager::Instance()->getTextureSize("level1Scene2");
	setWidth(size.x);
	setHeight(size.y);
	setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5, Config::SCREEN_HEIGHT * 0.5));

	setType(GameObjectType::BACK_GROUND);

	setFlowingSpeed(1.0);
	setStartingPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5, Config::SCREEN_HEIGHT * 0.5));
	
	
}

Background::~Background()
{
}

void Background::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;
	
	TheTextureManager::Instance()->draw("level1Scene1", xComponent, yComponent, TheGame::Instance()->getRenderer(), 0, 255,true);
	TheTextureManager::Instance()->draw("level1Scene2", xComponent+Config::SCREEN_WIDTH, yComponent, TheGame::Instance()->getRenderer(), 0, 255, true);
	
	/*glm::vec2 size = TheTextureManager::Instance()->getTextureSize("level1Scene");
	for (int i = 0; i < 2; i++)
	{
		switch (i)
		{
		case 0:


			TheTextureManager::Instance()->draw("level1Scene1", Config::SCREEN_WIDTH * 0.5, Config::SCREEN_HEIGHT * 0.5, TheGame::Instance()->getRenderer(), 0, 255, true);
			break;
		case 1:

			TheTextureManager::Instance()->draw("level1Scene2", size.x * 1.5, Config::SCREEN_HEIGHT * 0.5, TheGame::Instance()->getRenderer(), 0, 255, true);
			break;
		default:
			break;
		}
	}
	*/


}

void Background::update()
{
	glm::vec2 currentPositionTemp = getPosition();
	currentPositionTemp.x -= getFlowingSpeed();
	std::cout << currentPositionTemp.x << std::endl;
	setPosition(currentPositionTemp);

	if(getPosition().x == -260)
	{
		setPosition(getStartingPosition());
	}
}

void Background::clean()
{
}

float Background::getFlowingSpeed()
{
	return m_flowingSpeed;
}

glm::vec2 Background::getStartingPosition()
{
	return m_startingPosition;
}

void Background::setStartingPosition(glm::vec2 startingPosition)
{
	m_startingPosition = startingPosition;
}

void Background::setFlowingSpeed(float speed)
{
	m_flowingSpeed = speed;
}
