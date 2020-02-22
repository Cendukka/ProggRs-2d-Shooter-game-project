#include "Background1.h"
#include "Game.h"
#include "Level1Scene.h"

Background1::Background1()
{

	


	TheTextureManager::Instance()->load("../Assets/BG1.png", "level1Scene2", TheGame::Instance()->getRenderer());
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("level1Scene2");
	setWidth(size.x);
	setHeight(size.y);
	setPosition(glm::vec2((Config::SCREEN_WIDTH*0.5)+getWidth(), Config::SCREEN_HEIGHT * 0.5));
	setType(GameObjectType::BACK_GROUND);

	setFlowingSpeed(5.0);
	setStartingPosition(getPosition());


}

Background1::~Background1()
{
}

void Background1::draw()
{
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("level1Scene2");
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("level1Scene2", xComponent, yComponent, TheGame::Instance()->getRenderer(), 0, 255, true);



}

void Background1::update()
{
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("level1Scene2");
	//update the current position of the background
	glm::vec2 currentPositionTemp = getPosition();
	currentPositionTemp.x -= getFlowingSpeed();
	std::cout << currentPositionTemp.x << std::endl;
	setPosition(currentPositionTemp);
	//reset the background position if the current x position is -texture size
	if (getPosition().x == -(size.x * 0.5))
	{
		setPosition(getStartingPosition());
	}
}

void Background1::clean()
{
}

float Background1::getFlowingSpeed()
{
	return m_flowingSpeed;
}

glm::vec2 Background1::getStartingPosition()
{
	return m_startingPosition;
}

void Background1::setStartingPosition(glm::vec2 startingPosition)
{
	m_startingPosition = startingPosition;
}

void Background1::setFlowingSpeed(float speed)
{
	m_flowingSpeed = speed;
}
