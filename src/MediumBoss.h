#pragma once

#ifndef __MEDIUM_BOSS__
#define __MEDIUM_BOSS__

#include "Enemy.h"
#include "EnemyBullet.h"


class MediumBoss : public Enemy
{
public:
	MediumBoss();
	~MediumBoss();

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
