#include  "SmallEnemy.h"
#include "Game.h"
#include "ScoreBoardManager.h"

SmallEnemy::SmallEnemy()
{
	m_alpha = 255;
	TheTextureManager::Instance()->load("../Assets/Ship_01/SmallEnemy.png",
		"SmallEnemy", TheGame::Instance()->getRenderer());
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("SmallEnemy");
	setWidth(size.x);
	setHeight(size.y);
	setPosition(glm::vec2(0.0f, 0.0f));
	setVelocity(glm::vec2(0.0f, 0.0f));
	setAcceleration(glm::vec2(0.0f, 0.0f));
	setIsColliding(false);
	setActive(true);
	setType(GameObjectType::ENEMY);
	m_health = 5;	
	reset();
}

SmallEnemy::~SmallEnemy()
{
}
void SmallEnemy::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;
	//xComponent = 700;
	//yComponent = 300;

	TheTextureManager::Instance()->draw("SmallEnemy", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), m_alpha, true);
}

void SmallEnemy::update()
{
	glm::vec2 currentPosition = getPosition();
	move();
	if (getPosition().x <= 0 - getWidth())
	{
		reset();
	}
	if (m_health <= 0)
	{
		reset();
		m_health = 2;
	}	
}

void SmallEnemy::move()
{
	setPosition(glm::vec2((getPosition().x - 10), getPosition().y));
}
void SmallEnemy::reset()
{	
	glm::vec2 currentPosition = getPosition();
	m_alpha = 255;
	currentPosition.x = rand() % 500 + Config::SCREEN_WIDTH;
	currentPosition.y = rand() % (600 - getHeight()) + getHeight() * 0.5 + 1;
	if (m_health <= 0)
	{
		currentPosition.x += 250.0f;
	}
	setPosition(currentPosition);
}

void SmallEnemy::clean()
{
	
}

void SmallEnemy::getDamage()
{
	 m_health--;
}

void SmallEnemy::setActive(bool active)
{
	m_isActive = active;
}

bool SmallEnemy::isActive()
{
	return m_isActive;
}
