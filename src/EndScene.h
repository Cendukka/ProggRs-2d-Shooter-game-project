#pragma once
#ifndef __END_SCENE__
#define __END_SCENE__

#include "Scene.h"
#include "Label.h"
#include "Background.h"
#include "Background1.h"

class EndScene : public Scene
{
public:
	EndScene();
	~EndScene();

	// Inherited via Scene
	virtual void draw() override;
	virtual void update() override;
	virtual void clean() override;
	virtual void handleEvents() override;
	virtual void start() override;


private:
	Label* m_LabelGameOver;
	Label* m_LabelNewGame;
	Background* m_pBackground;
	Background1* m_pBackground1;
};

#endif /* defined (__END_SCENE__) */