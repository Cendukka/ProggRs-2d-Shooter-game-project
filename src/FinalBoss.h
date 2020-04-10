#pragma once

#ifndef __FINAL_BOSS__
#define __FINAL_BOSS__

#include "Enemy.h"
#include "EnemyBullet.h"


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
	void drawBullets();

private:

	int m_health;
};


#endif
