#pragma once

#ifndef __SMALL_ENEMY__
#define __SMALL_ENEMY__
#include "Enemy.h"


class SmallEnemy : public Enemy
{
public:
	SmallEnemy(int theYPosition);
	~SmallEnemy();

	void update() override;
	void decreaseHealth() override;
	void clean() override;
	int getHealth();

private:

	int m_health;
};


#endif
