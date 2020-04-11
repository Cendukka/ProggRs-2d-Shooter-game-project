#include "TutorialButton.h"

#include "Game.h"

TutorialButton::TutorialButton()
	:Button(
		"../Assets/textures/TutorialButton.png",
		"tutorialButton",
		TUTORIAL_BUTTON, glm::vec2(400.0f, 400.0f)), m_isClicked(false)
{}

TutorialButton::~TutorialButton()
{
}

bool TutorialButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{
			std::cout << "Mouse Button Clicked!" << std::endl;
			m_isClicked = true;
			TheGame::Instance()->changeSceneState(SceneState::TUTORIAL_SCENE);
		}
		return true;
	}
	else
	{
		m_isClicked = false;
	}

	return false;
}
