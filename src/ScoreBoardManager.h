#pragma once
#ifndef __SCORE_BOARD_MANAGER__
#define __SCORE_BOARD_MANAGER__

#include "Config.h"
#include "Label.h"

class ScoreBoardManager
{
public:
	// singleton
	static ScoreBoardManager* Instance()
	{
		if (m_pInstance == nullptr)
		{
			m_pInstance = new ScoreBoardManager();
			return m_pInstance;
		}
		return m_pInstance;
	}

	void Start();
	void Draw() const;

	// getters and setters
	int getScore() const;
	void setScore(int new_score);

	int getHealth() const;
	void setHealth(int new_health);

	int getPowerUp() const;
	void setPowerUp(int new_powerUp);


	void setEnemies(std::string setType);
	int enemiesLeft();



private:
	ScoreBoardManager();
	~ScoreBoardManager();

	int m_score{};
	int m_health{};
	int m_powerUp{};

	Label* m_pHealthLabel{};
	Label* m_pScoreLabel{};

	static ScoreBoardManager* m_pInstance;

	int m_enemiesLeft;
};
#endif /* defined (__SCORE_BOARD_MANAGER__) */