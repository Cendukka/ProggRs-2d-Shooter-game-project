#include "ship.h"
#include "Game.h"
#include "NextLevelButton.h"

NextLevelButton::NextLevelButton()
// call super constructor
	:Button(
		"../Assets/textures/Next.png",
		"startButton",
		NEXT_LEVEL_BUTTON, glm::vec2(400.0f, 300.0f)), m_isClicked(false)
{

}

NextLevelButton::~NextLevelButton()
{
}

bool NextLevelButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{
			std::cout << "Mouse Button Clicked!" << std::endl;
			m_isClicked = true;
			TheGame::Instance()->changeSceneState(SceneState::LEVEL_TWO);
			std::cout << "You Have Entered Level 2" << std::endl;
		}
		return true;
	}
	else
	{
		m_isClicked = false;
	}

	return false;
}


