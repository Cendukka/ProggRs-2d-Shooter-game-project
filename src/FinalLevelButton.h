#pragma once
#ifndef __FINAL_LEVEL_BUTTON__
#define __FINAL_LEVEL_BUTTON__

#include "Button.h"

class FinalLevelButton : public Button
{
public:
	FinalLevelButton();
	~FinalLevelButton();


	bool ButtonClick() override;
private:
	bool m_isClicked;
};

#endif /* defined (__FINAL_LEVEL_BUTTON__) */