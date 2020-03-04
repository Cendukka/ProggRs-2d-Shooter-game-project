#pragma once
#ifndef __START_SCENE__
#define __START_SCENE__

#include "Scene.h"
#include "StartButton.h"
#include "Label.h"
#include "Background.h"
#include "Background1.h"

class StartScene : public Scene
{
public:
	// constructor
	StartScene();
	// destructor
	~StartScene();

	// Inherited via Scene
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;
	
	// getters
	glm::vec2 getMousePosition();
private:
	Label* m_pStartLabel;
	// game objects

	glm::vec2 m_mousePosition;
	Background* m_pBackground;
	Background1* m_pBackground1;
	StartButton* m_pStartButton;
};

#endif /* defined (__START_SCENE__) */