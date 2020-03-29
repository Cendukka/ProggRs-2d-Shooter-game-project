#include "ScoreBoardManager.h"
#include "Game.h"

ScoreBoardManager* ScoreBoardManager::m_pInstance = nullptr;

void ScoreBoardManager::Start()
{
	const SDL_Color yellow = { 255, 255, 0, 255 };
	m_pHealthLabel = new Label("Health: 100", "lazy", 24, yellow,
		glm::vec2(10.0f, 10.0f), TTF_STYLE_NORMAL, false);


	setPowerUp(0);
	
	m_pScoreLabel = new Label("Score: 0", "lazy", 24, yellow,
		glm::vec2(650.0f, 10.0f), TTF_STYLE_NORMAL, false);
}

void ScoreBoardManager::Draw() const
{
	m_pHealthLabel->draw();

	m_pScoreLabel->draw();

}

int ScoreBoardManager::getScore() const
{
	return m_score;
}

void ScoreBoardManager::setScore(const int new_score)
{
	m_score = new_score;
	std::cout << m_score << std::endl;
	m_pScoreLabel->setText("Score: " + std::to_string(m_score));
}

int ScoreBoardManager::getHealth() const
{
	return m_health;
}

void ScoreBoardManager::setHealth(const int new_lives)
{
	m_health = new_lives;
	if (m_health < 1)
	{
		Game::Instance()->changeSceneState(END_SCENE);
	}
	m_pHealthLabel->setText("Lives: " + std::to_string(m_health));
}

int ScoreBoardManager::getPowerUp() const
{
	return m_powerUp;
}

void ScoreBoardManager::setPowerUp(int new_powerUp)
{
	if(new_powerUp <= 2)
	{
		m_powerUp = new_powerUp;
	}
}

void ScoreBoardManager::setEnemies(std::string setType)
{
	if (setType == "Increase") {
		m_enemiesLeft += 1;
	}
	else if (setType == "Decrease") {
		m_enemiesLeft -= 1;
	}
}

int ScoreBoardManager::enemiesLeft()
{
	return m_enemiesLeft;
}

ScoreBoardManager::ScoreBoardManager()
{
	Start();
	setScore(Config::SCORE);
	setHealth(Config::HEALTH);
}

ScoreBoardManager::~ScoreBoardManager()
= default;
