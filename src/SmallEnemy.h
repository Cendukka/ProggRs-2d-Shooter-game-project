#pragma once

#ifndef __SMALL_ENEMY__
#define __SMALL_ENEMY__
#include "Enemy.h"


class SmallEnemy : public Enemy
{
public:
	SmallEnemy();
	~SmallEnemy();

	void update() override;
	void decreaseHealth();
	void clean() override;
	int getHealth();

private:

	int m_health;
};


#endif
