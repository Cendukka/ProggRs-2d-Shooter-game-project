#include "PowerUp.h"
#include "Game.h"

PowerUp::PowerUp()
{
	TheTextureManager::Instance()->load("../Assets/Bonus_Items/Bonus.png",
		"powerUp", TheGame::Instance()->getRenderer());
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("powerUp");
	setWidth(size.x);
	setHeight(size.y);
	setPosition(glm::vec2(-1000.0f, -1000.0f));
	setVelocity(glm::vec2(0.0f, 0.0f));
	setAcceleration(glm::vec2(0.0f, 0.0f));
	setIsColliding(false);
	setType(GameObjectType::POWER_UP);
	isActive = false;
	m_alpha = 0;
}

PowerUp::~PowerUp()
{
}

void PowerUp::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("powerUp", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, m_alpha, true);
}

void PowerUp::update()
{
	if(isActive == true)
	{
		m_alpha = 255;
		setPosition(glm::vec2(getPosition().x - 5.0, getPosition().y));
	}
	else
	{
		m_alpha = 0;
	}
	if(getPosition().x < 0 - getWidth())
	{
		reset();
	}

}

void PowerUp::clean()
{
}

void PowerUp::start(glm::vec2 position)
{
	isActive = true;
	setPosition(position);
}

void PowerUp::reset()
{
	isActive = false;
	glm::vec2 currentPosition = getPosition();
	currentPosition.x = -1000;
	setPosition(currentPosition);
}
