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

void MainGame::gameLoop()
{
	while (_gameState != GameState::EXIT)
	{
		processInput();
	}
}

void MainGame::processInput()
{

}