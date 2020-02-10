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
	setPosition(getPosition());
	setVelocity(glm::vec2(0.0f, 0.0f));
	setAcceleration(glm::vec2(0.0f, 0.0f));
	setIsColliding(false);
	setType(GameObjectType::COMET);
}

Comet::~Comet()
{
}

void Comet::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;
	xComponent = 700;
	yComponent = 300;

	TheTextureManager::Instance()->draw("comet", xComponent, yComponent,
		TheGame::Instance()->getRenderer(), m_currentDirection, m_alpha, true);
}

void Comet::update()
{
	glm::vec2 currentPosition = getPosition();
	//currentPosition.x -= 2;
	//setPosition(currentPosition);
	move();
	if(getPosition().x <= 0)
	{
		currentPosition.x = 800;
		setPosition(currentPosition);
	}
	
}

void Comet::clean()
{
	setIsColliding(false);
}

void Comet::move()
{
	setPosition(glm::vec2((getPosition().x - 10), getPosition().y));
}
