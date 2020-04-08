#include "Commons.h"
#include "MainGame.h"
#include <string>
#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>


void fatalError(std::string error)
{
	std::cout << error << std::endl;
	std::cout << "Enter any key to quit...";
	std::cin.get();
	SDL_Quit();
}


// Constructor
MainGame::MainGame()
{
	_window = nullptr;
	_screenWidth = 1024;
	_screenHeight = 768;
	_gameState = GameState::PLAY;
}

// Desctructor
MainGame::~MainGame()
{

}


void MainGame::run()
{
	initSystems();
	gameLoop();
}

void MainGame::initSystems()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	_window = SDL_CreateWindow("Zenahr Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_MAXIMIZED);

	if (_window == nullptr)
	{
		fatalError("SDL Window could not be created!");
	}

	SDL_GLContext glContext = SDL_GL_CreateContext(_window);
	if (glContext == nullptr)
	{
		fatalError("SDL_GL context could not be created!");
	}

	
	// Stops flickering
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	// 0 - 225 <=> 0.0f - 1.0f (RGBA)
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

// Main Game Loop
void MainGame::gameLoop()
{
	while (_gameState != GameState::EXIT)
	{
		processInput();
		drawGame();
	}
}

void MainGame::processInput()
{
	SDL_Event evnt;
	
	// Pass event by reference
	while (SDL_PollEvent(&evnt))
	{
		switch (evnt.type)
		{
		case SDL_QUIT:
			_gameState = GameState::EXIT;
			break;
		case SDL_MOUSEMOTION:
			std::cout << "X: " << evnt.motion.x << " Y: " << evnt.motion.y << std::endl;
			break;
		}
	}
}

// Rendering process
void MainGame::drawGame()
{
	// glClearDepth(1.0);
	// glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



	SDL_GL_SwapWindow(_window);

}
