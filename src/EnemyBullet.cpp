#include "EnemyBullet.h"
#include "Game.h"
#include "Level1Scene.h"
#include "CollisionManager.h"


EnemyBullet::EnemyBullet()
{
	TheTextureManager::Instance()->load("../Assets/Sprites/Missile/EnemyMissile_1_Flying_000_Left.png",
		"EnemyBullet", TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("EnemyBullet");
	setWidth(20);
	setHeight(20);
	//setPosition(glm::vec2(400.0f, 300.0f));
	setIsColliding(false);
	setType(BULLET);
	setSpeed(10.0f);
	setActive(false);
	m_alpha = 0;
}

EnemyBullet::~EnemyBullet() = default;

void EnemyBullet::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;


	TheTextureManager::Instance()->draw("EnemyBullet", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, m_alpha, true);
}

void EnemyBullet::update()
{
	if (getPosition().x <= 0 - getWidth())
	{
		reset();
	}
	if (isActive())
	{
		setPosition(glm::vec2((getPosition().x - getSpeed()), getPosition().y));
	}
}



void EnemyBullet::reset()
{
	setIsColliding(false);
	setPosition(glm::vec2(-getWidth(), -getHeight()));
	setActive(false);
	m_alpha = 0;
}


void EnemyBullet::clean()
{
	//reset();
}

void EnemyBullet::setActive(bool active)
{
	m_isActive = active;
}

bool EnemyBullet::isActive()
{
	return m_isActive;
}

void EnemyBullet::fire(glm::vec2 position)
{
	setIsColliding(false);
	m_alpha = 255;
	setPosition(position);
	draw();
	setActive(true);
}

void EnemyBullet::setSpeed(float newSpeed)

{
	m_speed = newSpeed;
}

float EnemyBullet::getSpeed()
{
	return m_speed;
}

void EnemyBullet::checkBounds()
{
	if (getPosition().x > Config::SCREEN_WIDTH)
	{
		setPosition(glm::vec2(0.0f, getPosition().y));
	}
}
