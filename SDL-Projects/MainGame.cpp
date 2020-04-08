#include "MainGame.h"

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
	_window = SDL_CreateWindow("Zenahr Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_OPENGL);
}

// Main Game Loop
void MainGame::gameLoop()
{
	while (_gameState != GameState::EXIT)
	{
		processInput();
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
		}
	}
}