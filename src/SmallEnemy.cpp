#include "SmallEnemy.h"
#include "Game.h"
#include "ScoreBoardManager.h"

SmallEnemy::SmallEnemy(int theYPosition)
	:Enemy(
		"../Assets/Ship_01/SmallEnemy.png",
		"smallEnemy",
		ENEMY, glm::vec2(Config::SCREEN_WIDTH, theYPosition))
{
	m_alpha = 255;
	m_health = 5;

	for (int i = 0; i < MAX_BULLETS; i++)
	{
		pEnemyBullets[i] = new EnemyBullet();
	}
}
//{
//	m_alpha = 255;
//	TheTextureManager::Instance()->load("../Assets/Ship_01/SmallEnemy.png",
//		"SmallEnemy", TheGame::Instance()->getRenderer());
//	glm::vec2 size = TheTextureManager::Instance()->getTextureSize("SmallEnemy");
//	setWidth(size.x);
//	setHeight(size.y);
//	setPosition(glm::vec2(0.0f, 0.0f));
//	setVelocity(glm::vec2(0.0f, 0.0f));
//	setAcceleration(glm::vec2(0.0f, 0.0f));
//	setIsColliding(false);
//	setActive(true);
//	setType(GameObjectType::ENEMY);
//	m_health = 5;	
//	reset();
//}

SmallEnemy::~SmallEnemy()
{
}
//void SmallEnemy::draw()
//{
//	int xComponent = getPosition().x;
//	int yComponent = getPosition().y;
//	//xComponent = 700;
//	//yComponent = 300;
//
//	TheTextureManager::Instance()->draw("SmallEnemy", xComponent, yComponent,
//		TheGame::Instance()->getRenderer(), m_alpha, true);
//}

//void SmallEnemy::update()
//{
//	glm::vec2 currentPosition = getPosition();
//	move();
//	if (getPosition().x <= 0 - getWidth())
//	{
//		reset();
//	}
//	if (m_health <= 0)
//	{
//		reset();
//		m_health = 2;
//	}	
//}
void SmallEnemy::update()
{
	if (getPosition().x >= Config::SCREEN_WIDTH * 0.8) {
		setPosition(glm::vec2((getPosition().x - 2), getPosition().y));
	}
	if (m_health <= 0)
	{
		setAlpha(0);
		setIsColliding(false);
		setPosition(glm::vec2(0.0f, -getHeight()));
	}
	for (int i = 0; i < MAX_BULLETS; i++)
	{
		pEnemyBullets[i]->update();
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

void SmallEnemy::decreaseHealth()
{
	m_health -= 1;
	if (m_health <= 0) {
		//increas the score when enemy dies
		ScoreBoardManager::Instance()->setScore(ScoreBoardManager::Instance()->getScore() + 300);

		ScoreBoardManager::Instance()->setEnemies("Decrease");
		if (ScoreBoardManager::Instance()->enemiesLeft() <= 0) {
			Game::Instance()->changeSceneState(NEXT_LEVEL_SCENE);
		}
	}
}

int SmallEnemy::getHealth()
{
	return m_health;
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

void SmallEnemy::handleFiring()
{
	
	for (int i = 0; i < MAX_BULLETS; i++)
	{
		if (!pEnemyBullets[i]->isActive())
		{
			pEnemyBullets[i]->fire(this->getPosition());
			break;
		}
	}
}

void SmallEnemy::drawBullets() {

	for (int i = 0; i < MAX_BULLETS; i++)
	{
		pEnemyBullets[i]->draw();
	}
}
