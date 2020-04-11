#include "FinalBoss.h"
#include "Game.h"
#include "ScoreBoardManager.h"

FinalBoss::FinalBoss()
	:Enemy(
		"../Assets/Ship_01/MediumBoss.png",
		"finalEnemy",
		ENEMY, glm::vec2(Config::SCREEN_WIDTH * 1.2, Config::SCREEN_HEIGHT * 0.5))
{
	m_health = 50;

	for (int i = 0; i < MAX_BULLETS; i++)
	{
		pEnemyBullets[i] = new EnemyBullet();
	}
}
FinalBoss::~FinalBoss()
= default;

void FinalBoss::update()
{
	if(m_isActive)
	{
		//std::cout << "Final " << getPosition().x << std::endl;
		if (getPosition().x >= Config::SCREEN_WIDTH * 0.9) {
			setPosition(glm::vec2((getPosition().x - 2), getPosition().y));
		}
		//move enemies up
		if (getMovingUp()) {
			setPosition(glm::vec2(getPosition().x, (getPosition().y - 2)));
			if (getPosition().y <= (100)) {
				setMovingUp(false);
			}
		}
		//move enemies down
		if (!getMovingUp()) {
			setPosition(glm::vec2(getPosition().x, (getPosition().y + 2)));
			if (getPosition().y >= (500)) {
				setMovingUp(true);
			}
		}

		if (m_health <= 0)
		{
			setAlpha(0);
			setIsColliding(false);
			setPosition(glm::vec2(800 + getWidth(), -getHeight()));
		}

		for (int i = 0; i < MAX_BULLETS; i++)
		{
			pEnemyBullets[i]->update();
		}
	}

}

void FinalBoss::decreaseHealth()
{
	m_health -= 1;
	if (m_health <= 0) {
		//increas the score when enemy dies
		ScoreBoardManager::Instance()->setScore(ScoreBoardManager::Instance()->getScore() + 500);

		ScoreBoardManager::Instance()->setEnemies("Decrease");
		if (ScoreBoardManager::Instance()->enemiesLeft() <= 0) {
			Game::Instance()->changeSceneState(END_SCENE);
		}
	}
}

void FinalBoss::clean()
{
}

int FinalBoss::getHealth()
{
	return m_health;
}

void FinalBoss::handleFiring()
{
	for (int i = 0; i < MAX_BULLETS; i++)
	{
		if (!pEnemyBullets[i]->isActive() && m_isActive)
		{
			std::cout << "Enemy bullet is active" << std::endl;
			pEnemyBullets[i]->fire(this->getPosition());
			break;
		}
	}
}

void FinalBoss::drawBullets()
{
	for (int i = 0; i < MAX_BULLETS; i++)
	{
		pEnemyBullets[i]->draw();
	}
}

void FinalBoss::setIsActive(bool isActive)
{
	m_isActive = isActive;
}

bool FinalBoss::getIsActive()
{
	return m_isActive;
}
