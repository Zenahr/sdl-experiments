#pragma once
#include "SDL.h"
#include "SDL_opengl.h"
#include <string>
#include <windows.h>
#include <GL\GL.h>
#include <GL\GLU.h>
#include <GLM\glm.hpp>

enum class GameState {PLAY, EXIT};

class MainGame
{
public:
	MainGame();
	~MainGame();

	void run();
	

private:
	void initSystems();
	void gameLoop();
	void processInput();
	void drawGame();

	SDL_Window* _window;
	int _screenWidth;
	int _screenHeight;
	GameState _gameState;
};

