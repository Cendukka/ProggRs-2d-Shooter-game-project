#include "MediumBoss.h"
#include "Game.h"
#include "ScoreBoardManager.h"

MediumBoss::MediumBoss()
	:Enemy(
		"../Assets/Ship_01/MediumBoss.png",
		"mediumEnemy",
		ENEMY, glm::vec2(Config::SCREEN_WIDTH*1.2, Config::SCREEN_HEIGHT*0.5))
{
	m_health = 50;

	for (int i = 0; i < MAX_BULLETS; i++)
	{
		pEnemyBullets[i] = new EnemyBullet();
	}
}
MediumBoss::~MediumBoss()
= default;

void MediumBoss::update()
{
	if (getPosition().x >= Config::SCREEN_WIDTH * 0.9) {
		setPosition(glm::vec2((getPosition().x - 2), getPosition().y));
	}
	//move enemies up
	if (getMovingUp()) {
		setPosition(glm::vec2(getPosition().x, (getPosition().y - 2)));
		if (getPosition().y <= (300 - 200)) {
			setMovingUp(false);
		}
	}
	//move enemies down
	if (!getMovingUp()) {
		setPosition(glm::vec2(getPosition().x, (getPosition().y + 2)));
		if (getPosition().y >= (300 + 200)) {
			setMovingUp(true);
		}
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

void MediumBoss::decreaseHealth()
{
	m_health -= 1;
	if (m_health <= 0) {
		//increas the score when enemy dies
		ScoreBoardManager::Instance()->setScore(ScoreBoardManager::Instance()->getScore() + 500);

		ScoreBoardManager::Instance()->setEnemies("Decrease");
		if (ScoreBoardManager::Instance()->enemiesLeft() <= 0) {
			clean();
			if (Game::Instance()->getCurrentScene() == LEVEL_TWO) {

				Game::Instance()->changeSceneState(TO_FINAL_LEVEL_SCENE);
			}
		}
	}
}

void MediumBoss::clean()
{
}

int MediumBoss::getHealth()
{
	return m_health;
}

void MediumBoss::handleFiring()
{
	for (int i = 0; i < MAX_BULLETS; i++)
	{
		if (!pEnemyBullets[i]->isActive())
		{
			std::cout << "Enemy bullet ei aktiivinen" << std::endl;
			pEnemyBullets[i]->fire(this->getPosition());
			break;
		}
	}
}

void MediumBoss::drawBullets()
{
	for (int i = 0; i < MAX_BULLETS; i++)
	{
		pEnemyBullets[i]->draw();
	}
}
