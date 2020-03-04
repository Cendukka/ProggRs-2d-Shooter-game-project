#include "Comet.h"
#include "Game.h"

Comet::Comet()
{
	m_alpha = 255;
	TheTextureManager::Instance()->load("../Assets/Sprites/Asteroid.png",
		"comet", TheGame::Instance()->getRenderer());
	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("comet");
	setWidth(size.x);
	setHeight(size.y);
	setPosition(glm::vec2(0.0f, 0.0f));
	setVelocity(glm::vec2(0.0f, 0.0f));
	setAcceleration(glm::vec2(0.0f, 0.0f));
	setIsColliding(false);
	setActive(true);
	setType(GameObjectType::COMET);
	m_health = 2;
	m_angle = 0;
}

Comet::~Comet()
{
}

void Comet::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;
	//xComponent = 700;
	//yComponent = 300;

	TheTextureManager::Instance()->draw("comet", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), m_angle, m_alpha, true);
}

void Comet::update()
{
	
	glm::vec2 currentPosition = getPosition();
	move();
	if(getPosition().x <= 0 - getWidth())
	{
		reset();
	}
	if(m_health <= 0)
	{
		reset();
		m_health = 2;
	}
	m_angle += 1;
	
}

void Comet::clean()
{

}

void Comet::move()
{
	setPosition(glm::vec2((getPosition().x - 10), getPosition().y));
}

void Comet::reset()
{
	m_angle = (rand() % 179) + 1;
	glm::vec2 currentPosition = getPosition();
	m_alpha = 255;
	currentPosition.x = rand() % 500 + Config::SCREEN_WIDTH;
	currentPosition.y = rand() % (600 - getHeight()) + getHeight() * 0.5 + 1;
	if(m_health <= 0)
	{
		currentPosition.x += 250.0f;
	}
	setPosition(currentPosition);
}

void Comet::getDamage()
{
	m_health--;
	reset();
}

void Comet::setActive(bool active)
{
	m_isActive = active;
}

bool Comet::isActive()
{
	return m_isActive;
}
