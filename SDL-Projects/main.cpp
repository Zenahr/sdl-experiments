#include "Commons.h"
#include "MainGame.h"
#include <string>

void fatalError(std::string error)
{
	std::cout << error << std::endl;
	std::cout << "Enter any key to quit...";
	std::cin.get();
	SDL_Quit();

}

int main(int argc, char *argv[])
{
	MainGame mainGame;
	mainGame.run();
	return 0;
}