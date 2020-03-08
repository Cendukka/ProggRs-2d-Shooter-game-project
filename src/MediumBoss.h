#pragma once

#ifndef __MEDIUM_BOSS__
#define __MEDIUM_BOSS__

#include "Enemy.h"


class MediumBoss : public Enemy
{
public:
	MediumBoss();
	~MediumBoss();

	void update() override;
	void decreaseHealth() override;
	void clean() override;
	int getHealth();

private:

	int m_health;
};


#endif
