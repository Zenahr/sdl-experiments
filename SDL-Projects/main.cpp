#include <iostream>
#include "MainGame.h"

int main(int argc, char *argv[])
{
	MainGame mainGame;
	mainGame.run();
	std::cout << "Enter any key to quit...";
	std::cin.get();
	return 0;
}