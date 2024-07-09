#include "Engine.hpp"

void VrausPercival::Engine::run()
{
	init();
	mainLoop();
	cleanup();
}