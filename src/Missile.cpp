
#include "Game.h"
#include "Level1Scene.h"
#include "CollisionManager.h"
#include "Missile.h"


Missile::Missile()
{
	TheTextureManager::Instance()->load("../Assets/Sprites/Missile/Missile_1_Flying_000_Right.png",
		"Missile", TheGame::Instance()->getRenderer());

	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("Missile");
	setWidth(20);
	setHeight(20);
	//setPosition(glm::vec2(400.0f, 300.0f));
	setIsColliding(false);
	setType(MISSILE);
	setSpeed(10.0f);
	setActive(false);
	m_alpha = 0;
	m_missilePosition = MIDDLE;

}

Missile::~Missile() = default;

void Missile::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;


	TheTextureManager::Instance()->draw("Missile", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), 0, m_alpha, true);
}

void Missile::update()
{
	if (getPosition().x >= Config::SCREEN_WIDTH + getWidth())
	{
		reset();
	}
	if (isActive())
	{
		if (m_missilePosition == TOP)
		{
			setPosition(glm::vec2((getPosition().x + getSpeed()), getPosition().y + getSpeed() / 2));
		}
		else if (m_missilePosition == BOTTOM)
		{
			setPosition(glm::vec2((getPosition().x + getSpeed()), getPosition().y - getSpeed() / 2));
		}
		else if (m_missilePosition == MIDDLE)
		{
			setPosition(glm::vec2((getPosition().x + getSpeed()), getPosition().y));
		}
	}
	if (m_pComet != nullptr)
	{
		//Collision::squaredRadiusCheck(this, m_pComet);
	}
}

void Missile::setComet(Comet * pcomet)
{
	m_pComet = pcomet;
}

void Missile::reset()
{
	setIsColliding(false);
	setPosition(glm::vec2(-getWidth(), -getHeight()));
	setActive(false);
	m_alpha = 0;
}


void Missile::clean()
{
	//reset();
}

void Missile::setActive(bool active)
{
	m_isActive = active;
}

bool Missile::isActive()
{
	return m_isActive;
}

void Missile::fire(glm::vec2 position)
{
	setIsColliding(false);
	m_alpha = 255;
	setPosition(position);
	draw();
	setActive(true);
}

void Missile::fire(glm::vec2 position, MissilePosition missilePosition)
{
	m_missilePosition = missilePosition;
	setIsColliding(false);
	m_alpha = 255;
	setPosition(position);
	draw();
	setActive(true);
}

void Missile::setSpeed(float newSpeed)

{
	m_speed = newSpeed;
}

float Missile::getSpeed()
{
	return m_speed;
}

void Missile::checkBounds()
{
	if (getPosition().x > Config::SCREEN_WIDTH)
	{
		setPosition(glm::vec2(0.0f, getPosition().y));
	}
}
