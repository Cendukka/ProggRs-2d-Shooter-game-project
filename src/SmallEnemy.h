#pragma once

#ifndef __SMALL_ENEMY__
#define __SMALL_ENEMY__
#include "Enemy.h"

#include <vector>
#include "DisplayObject.h"
#include "TextureManager.h"

class SmallEnemy : public DisplayObject
{
public:
	SmallEnemy();
	~SmallEnemy();

	void draw() override;
	void update() override;
	void clean() override;
	void move();
	void reset();
	void getDamage();
	void setActive(bool active);
	bool isActive();

private:

	int m_health; 
	float m_maxSpeed;
	double m_currentDirection;
	Uint8 m_alpha;
	bool m_isActive;

};


#endif
