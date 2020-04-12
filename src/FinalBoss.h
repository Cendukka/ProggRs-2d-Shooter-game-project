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

	static const int MAX_BULLETS = 10;
	EnemyBullet* pEnemyBullets[MAX_BULLETS];
	void handleFiring();
	void drawBullets();
	void setIsActive(bool isActive);
	bool getIsActive();
private:

	int m_health;
	bool m_isActive;
	bool m_wave1CanBeShot;
	bool m_wave2CanBeShot;
};


#endif
