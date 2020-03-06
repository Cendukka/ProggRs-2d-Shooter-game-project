#include "MediumBoss.h"
#include "Game.h"

MediumBoss::MediumBoss()
	:Enemy(
		"../Assets/Ship_01/MediumBoss.png",
		"mediumEnemy",
		ENEMY, glm::vec2(Config::SCREEN_WIDTH*1.2, Config::SCREEN_HEIGHT*0.5))
{
	m_health = 20;
}
MediumBoss::~MediumBoss()
= default;

void MediumBoss::update()
{
	if (getPosition().x >= Config::SCREEN_WIDTH * 0.9) {
		setPosition(glm::vec2((getPosition().x - 2), getPosition().y));
	}
	if (m_health <= 0)
	{
		setAlpha(0);
		setIsColliding(false);
		setPosition(glm::vec2(0.0f, -getHeight()));
	}
}

void MediumBoss::decreaseHealth()
{
	m_health -= 1;
}

void MediumBoss::clean()
{
}

int MediumBoss::getHealth()
{
	return m_health;
}
