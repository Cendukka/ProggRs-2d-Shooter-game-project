#include "Enemy.h"
#include "TextureManager.h"
#include "Game.h"

Enemy::Enemy(std::string imagePath, std::string enemyName, GameObjectType type, glm::vec2 position, bool isCentered) : m_name(enemyName), m_isCentered(isCentered), m_alpha(255)
{
	TheTextureManager::Instance()->load(imagePath,
		m_name, TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize(m_name);
	setWidth(size.x);
	setHeight(size.y);
	setPosition(position);
	setType(type);

}

Enemy::~Enemy()
{
}

void Enemy::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;




	TheTextureManager::Instance()->draw(m_name, xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, m_alpha, true);
}

void Enemy::update()
{
	//Move the enemies forward
	if (getPosition().x >= Config::SCREEN_WIDTH * 0.8) {
		setPosition(glm::vec2((getPosition().x - 2), getPosition().y));
	}
}

void Enemy::clean()
{
	setIsColliding(false);
	setActive(false);
	m_alpha = 0;
}
void Enemy::setActive(bool active)
{
	m_isActive = active;
}

void Enemy::setAlpha(Uint8 value)
{
	m_alpha = value;
}

bool Enemy::isActive()
{
	return m_isActive;
}

void Enemy::setMovingUp(bool goingUp)
{
	m_movingUp = goingUp;
}



bool Enemy::getMovingUp()
{
	return m_movingUp;
}

//Drawing more small enemies
void Enemy::draw(int yEnemyPosition)
{
	
	int yComponent = 0;
	switch(yEnemyPosition)
	{
	case 0:
		yComponent = Config::SCREEN_HEIGHT*0.2;
		break;
	case 1:
		yComponent = Config::SCREEN_HEIGHT * 0.5;
		break;
	case 2:
		yComponent = Config::SCREEN_HEIGHT * 0.8;
		break;
	}
	int xComponent = getPosition().x;
	
	TheTextureManager::Instance()->draw(m_name, xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, m_alpha, true);
}
