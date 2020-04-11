#pragma once

#ifndef __FINAL_BOSS__
#define __FINAL_BOSS__

#include "Enemy.h"
#include "EnemyBullet.h"
#include "Missile.h"


class FinalBoss : public Enemy
{
public:
	FinalBoss();
	~FinalBoss();

	void update() override;
	void decreaseHealth() override;
	void clean() override;
	int getHealth();

	static const int MAX_BULLETS = 20;
	EnemyBullet* pEnemyBullets[MAX_BULLETS];
	void handleFiring();
	void handleFiring(glm::vec2 destination);
	void drawBullets();
	void setIsActive(bool isActive);
	bool getIsActive();
	void setDestination(glm::vec2 destination);
	static const int MAX_MISSILES = 2;
	Missile* m_missiles[MAX_MISSILES];
private:

	int m_health;
	bool m_isActive;
	glm::vec2 m_destination;
};


#endif
