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
	m_wave1CanBeShot = true;
	m_wave2CanBeShot = false;

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
		handleFiring();
		for (int i = 0; i < MAX_BULLETS; i++)
		{
			pEnemyBullets[i]->update();
			if(pEnemyBullets[0]->getPosition().x == 718 && pEnemyBullets[1]->getPosition().x == 718 &&
				pEnemyBullets[2]->getPosition().x == 718 && pEnemyBullets[3]->getPosition().x == 718
				&& pEnemyBullets[4]->getPosition().x == 718)
			{
				m_wave1CanBeShot = true;
				m_wave2CanBeShot = false;
			}else if(pEnemyBullets[0]->getPosition().x <= 500 && pEnemyBullets[1]->getPosition().x <= 500 &&
				pEnemyBullets[2]->getPosition().x <= 500 && pEnemyBullets[3]->getPosition().x <= 500
				&& pEnemyBullets[4]->getPosition().x <= 500)
			{
				m_wave1CanBeShot = false;
				m_wave2CanBeShot = true;
			}
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
		//std::cout << "Final " << getPosition().x << std::endl;
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
			if((i == 0 && m_wave1CanBeShot) || (i == 5 && m_wave2CanBeShot))
			{
				//std::cout << "Enemy bullet is active" << std::endl;
				pEnemyBullets[i]->fire(glm::vec2(this->getPosition().x, this->getPosition().y));
				break;
			}else if((i == 1 && m_wave1CanBeShot) || (i == 6 && m_wave2CanBeShot))
			{
				pEnemyBullets[i]->fire(glm::vec2(this->getPosition().x, this->getPosition().y + getHeight() / 2),
					2.0f);
				break;
			}
			else if ((i == 2 && m_wave1CanBeShot) || (i == 7 && m_wave2CanBeShot))
			{
				pEnemyBullets[i]->fire(glm::vec2(this->getPosition().x, this->getPosition().y + getHeight() / 3)
				,2.0f);
				break;
			}
			else if ((i == 3 && m_wave1CanBeShot) || (i == 8 && m_wave2CanBeShot))
			{
				pEnemyBullets[i]->fire(glm::vec2(this->getPosition().x, this->getPosition().y - getHeight() / 2),
					-2.0f);
				break;
			}
			else if ((i == 4 && m_wave1CanBeShot) || (i == 9 && m_wave2CanBeShot))
			{
				pEnemyBullets[i]->fire(glm::vec2(this->getPosition().x, this->getPosition().y - getHeight() / 3)
				-2.0f);
				break;
			}
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
