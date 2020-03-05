#pragma once
#ifndef __NEXT_LEVEL_BUTTON__
#define __NEXT_LEVEL_BUTTON__

#include "Button.h"

class NextLevelButton : public Button
{
public:
	NextLevelButton();
	~NextLevelButton();


	bool ButtonClick() override;
private:
	bool m_isClicked;
};

#endif /* defined (__Next_LEVEL_BUTTON__) */