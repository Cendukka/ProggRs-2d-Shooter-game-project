#pragma once
#ifndef __Game__
#define __Game__

// Core Libraries
#include <iostream>
#include <vector>
#include <string>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

// IMGUI Includes
#include "IMGUI/imgui.h"
#include "IMGUI_SDL/imgui_sdl.h"

// Game Managers
#include "Config.h"
#include "TextureManager.h"
#include "CollisionManager.h"
#include "Util.h"

// Scenes
#include "StartScene.h"
#include "Level1Scene.h"
#include "NextLevelScene.h"
#include "LevelTwo.h"
#include "ToFinalLevelScene.h"
#include "FinalLevel.h"
#include "EndScene.h"

class Game
{
public:
	

	static Game* Instance()
	{
		if (s_pInstance == nullptr)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}

		return s_pInstance;
	}

	// simply set the running variable to true
	void init() { m_bRunning = true; }
	void setScore(int value);
	int getScore();

	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	// public functions
	void render();
	void update();
	void handleEvents();
	void clean();

	// a function to access the private running variable
	bool running() { return m_bRunning; }

	// getters
	SDL_Renderer* getRenderer();
	glm::vec2 getMousePosition();

	void setFrames(Uint32 frames);
	Uint32 getFrames();
	int getCurrentScene();

	void changeSceneState(SceneState newState);
	void quit();

private:
	Game();
	~Game();

	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	int m_currentFrame;

	bool m_bRunning;

	int m_score;

	static Game* s_pInstance;
	
	void start();

	glm::vec2 m_mousePosition;

	Uint32 m_frames;

	Scene* m_currentScene;
	SceneState m_currentSceneState;
};

typedef Game TheGame;

#endif /* defined (__Game__) */

