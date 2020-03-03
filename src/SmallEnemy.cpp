#include  "SmallEnemy.h"
#include "Game.h"

SmallEnemy::SmallEnemy()
	:Enemy(
	"../Assets/Ship_01/Enemy.png",
	"smallEnemy",
	ENEMY, glm::vec2(Config::SCREEN_WIDTH, 300.0f))
{
	m_health = 200;
}

SmallEnemy::~SmallEnemy()
{
}

void SmallEnemy::decreaseHealth()
{
	m_health -= 1;
}
int SmallEnemy::getHealth()
{
	return m_health;
}
