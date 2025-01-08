#include "VP_Engine.hpp"

void vraus_percival::Engine::run()
{
	while (!window_.shouldClose())
		glfwPollEvents();
}
