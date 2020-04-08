#pragma once
#include "SDL.h"
#include "SDL_opengl.h"

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

	SDL_Window* _window;
	int _screenWidth;
	int _screenHeight;
};

