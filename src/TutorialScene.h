#pragma once
#ifndef __TUTORIAL_SCENE__
#define __TUTORIAL_SCENE__
#include "Scene.h"
#include "ship.h"
#include "Background.h"
#include "Background1.h"


class TutorialScene : public Scene {
public:
	TutorialScene();
	~TutorialScene();
	void draw() override;
	void update() override;
	void clean() override;
	void handleEvents() override;
	void start() override;
	void moveToTheNextStage();
	
private:
	glm::vec2 m_mousePosition;
	bool m_canShoot;
	int m_enemyCounter;
	int m_tutorialStage;
	int m_mouseRegister;

	Ship* m_pShip;
	Comet* m_pComet;
	Label* m_pLabel;
	Background* m_pBackground;
	Background1* m_pBackground1;
};

#endif
