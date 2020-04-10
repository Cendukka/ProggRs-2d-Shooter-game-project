
#pragma once
#ifndef __FINAL_LEVEL_
#define __FINAL_LEVEL_

#include "Scene.h"

#include "ship.h"
#include "Bullet.h"
#include "Background.h"
#include "Background1.h"
#include "Comet.h"
#include "SmallEnemy.h"
#include "MediumBoss.h"
#include "FinalBoss.h"

class FinalLevel : public Scene
{
public:
	FinalLevel();
	~FinalLevel();

	void draw() override;
	void update() override;
	void clean() override;
	void handleEvents() override;
	void start() override;
	static const int MAX_COMETS = 5;
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
	FinalBoss* m_pFinalBoss;
	Label* m_pLabel;
};

#endif /* defined (__FINAL_LEVEL_) */
