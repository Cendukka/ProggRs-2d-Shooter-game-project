#include "Background.h"
#include "Game.h"
#include "Level1Scene.h"

Background::Background()
{

	TheTextureManager::Instance()->load("../Assets/BG2.png","level1Scene1", TheGame::Instance()->getRenderer());
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("level1Scene1");
	setWidth(size.x);
	setHeight(size.y);
	setPosition(glm::vec2(Config::SCREEN_WIDTH * 0.5, Config::SCREEN_HEIGHT * 0.5));
	setType(GameObjectType::BACK_GROUND);

	setFlowingSpeed(5.0);
	setStartingPosition(glm::vec2(getPosition().x, getPosition().y));
	
	
}

Background::~Background()
{
}

void Background::draw()
{
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("level1Scene1");
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;
	
	TheTextureManager::Instance()->draw("level1Scene1", xComponent, yComponent, TheGame::Instance()->getRenderer(), 0, 255,true);
	


}

void Background::update()
{
	//update the position of the background
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("level1Scene1");
	glm::vec2 currentPositionTemp = getPosition();
	currentPositionTemp.x -= getFlowingSpeed();
	//std::cout << size.x << std::endl;
	setPosition(currentPositionTemp);
	//reset the background position if the current x position is -texture size
	if(getPosition().x ==  -(size.x*0.5))
	{
		setPosition(glm::vec2(getStartingPosition().x + getWidth() , getStartingPosition().y));
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
