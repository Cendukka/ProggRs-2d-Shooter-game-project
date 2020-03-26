#pragma once
#ifndef __NEXT_LEVEL_SCENE__
#define __NEXT_LEVEL_SCENE__


#include "Scene.h"
#include "NextLevelButton.h"
#include "Label.h"
#include "Background.h"
#include "Background1.h"

class NextLevelScene : public Scene
{
public:
	// constructor
	NextLevelScene();
	// destructor
	~NextLevelScene();

	// Inherited via Scene
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;

	// getters
	glm::vec2 getMousePosition();
private:
	Label* m_pNextLevelLabel;
	// game objects

	glm::vec2 m_mousePosition;

	Background* m_pBackground;
	Background1* m_pBackground1;
	NextLevelButton* m_pNextLevelButton;
};

#endif /* defined (__NEXT_LEVEL_SCENE__) */