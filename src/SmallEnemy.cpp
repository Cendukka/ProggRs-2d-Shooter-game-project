#include  "SmallEnemy.h"
#include "Game.h"

SmallEnemy::SmallEnemy()
	:Enemy(
	"../Assets/Ship_01/Enemy.png",
	"smallEnemy",
	ENEMY, glm::vec2(Config::SCREEN_WIDTH, 300.0f))
{
	m_health = 5;
}

SmallEnemy::~SmallEnemy()
{
}

void SmallEnemy::update()
{
	if (getPosition().x >= Config::SCREEN_WIDTH * 0.8) {
		setPosition(glm::vec2((getPosition().x - 2), getPosition().y));
	}
	if(m_health <= 0)
	{
		setAlpha(0);
		setIsColliding(false);
		setPosition(glm::vec2(0.0f, -getHeight()));
	}
}

void SmallEnemy::decreaseHealth()
{
	m_health -= 1;
}

void SmallEnemy::clean()
{
	
}

int SmallEnemy::getHealth()
{
	return m_health;
}
