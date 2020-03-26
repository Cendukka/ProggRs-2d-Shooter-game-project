#pragma once
#ifndef  __TO_FINAL_LEVEL__
#define __TO_FINAL_LEVEL__

#include "Scene.h"
#include "FinalLevelButton.h"
#include "Label.h"
#include "Background.h"
#include "Background1.h"

class ToFinalLevelScene : public Scene
{
public:
	// constructor
	ToFinalLevelScene();
	// destructor
	~ToFinalLevelScene();

	// Inherited via Scene
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;

	// getters
	glm::vec2 getMousePosition();
private:
	Label* m_pFinalLevelLabel;
	// game objects

	glm::vec2 m_mousePosition;

	Background* m_pBackground;
	Background1* m_pBackground1;
	FinalLevelButton* m_pFinalLevelButton;
};

#endif // ! __TO_FINAL_LEVEL__
