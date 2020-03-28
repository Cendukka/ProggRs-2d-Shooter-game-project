#pragma once
#ifndef __LEVEL_TWO__
#define __LEVEL_TWO__

#include "Scene.h"
#include "ship.h"
#include "Bullet.h"
#include "Background.h"
#include "Background1.h"
#include "Comet.h"
#include "SmallEnemy.h"
#include "MediumBoss.h"


class LevelTwo : public Scene
{
public:
	LevelTwo();
	~LevelTwo();

	void draw() override;
	void update() override;
	void clean() override;
	void handleEvents() override;
	void start() override;
	static const int MAX_COMETS = 4;
	static const int MAX_SMALL_ENEMIES = 3;



	// getters
	glm::vec2 getMousePosition();


private:
	// game objects

	glm::vec2 m_mousePosition;

	int m_mouseRegister;
	Ship* m_pShip;
	Bullet* m_pBullet;
	Background* m_pBackground;
	Background1* m_pBackground1;
	//Comet* m_pComet;
	Comet* m_pComets[MAX_COMETS];
	SmallEnemy* m_pSmallEnemies[MAX_SMALL_ENEMIES];
	MediumBoss* m_pMediumBoss;
	Label* m_pLabel;
};

#endif /* defined (__LEVEL_TWO__) */
