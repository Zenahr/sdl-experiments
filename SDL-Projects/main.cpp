#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Commons.h"
#include "MainGame.h"

int main(int argc, char *argv[])
{
	MainGame mainGame;
	mainGame.run();
	return 0;
}