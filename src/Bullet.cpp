#include "Bullet.h"
#include "Game.h"
#include "Level1Scene.h"


Bullet::Bullet()
{
	TheTextureManager::Instance()->load("../Assets/textures/Mine.png",
		"mineBullet", TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("mineBullet");
	setWidth(size.x);
	setHeight(size.y);
	setPosition(glm::vec2(400.0f, 300.0f));
	setType(BULLET);
	setSpeed(10.0f);
}

Bullet::~Bullet()
{
}

void Bullet::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("mineBullet", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, 255, true);
}

void Bullet::update()
{
	
	
}

void Bullet::clean()
{
}

void Bullet::setSpeed(float newSpeed)

{
	m_speed = newSpeed;
}

float Bullet::getSpeed()
{
	return m_speed;
}

void Bullet::checkBounds()
{
	if (getPosition().x > Config::SCREEN_WIDTH)
	{
		setPosition(glm::vec2(0.0f, getPosition().y));
	}
}
