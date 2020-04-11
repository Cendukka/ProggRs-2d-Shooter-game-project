#pragma once
#ifndef __TUTORIAL_BUTTON__
#define __TUTORIAL_BUTTON__
#include "Button.h"

class TutorialButton : public Button
{
public:
	TutorialButton();
	~TutorialButton();
	
	bool ButtonClick() override;
private:
	bool m_isClicked;
};

#endif

