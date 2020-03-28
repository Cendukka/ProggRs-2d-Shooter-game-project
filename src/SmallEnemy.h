#pragma once

#ifndef __SMALL_ENEMY__
#define __SMALL_ENEMY__
#include "Enemy.h"
#include "Scene.h"
#include "EnemyBullet.h"
#include <vector>
#include "DisplayObject.h"
#include "TextureManager.h"

class SmallEnemy : public Enemy
{
public:
	SmallEnemy(int theYPosition);
	~SmallEnemy();

	/*void draw() override;*/
	void decreaseHealth() override;
	void update() override;
	void clean() override;
	void move();
	void reset();


	static const int MAX_BULLETS = 20;
	EnemyBullet* pEnemyBullets[MAX_BULLETS];
	void handleFiring();
	void drawBullets();
	//Getters
	void getDamage();
	int getHealth();
	bool isActive();

	//setters
	void setActive(bool active);
	

private:

	int m_health; 
	float m_maxSpeed;
	double m_currentDirection;
	Uint8 m_alpha;
	bool m_isActive;

};


#endif
