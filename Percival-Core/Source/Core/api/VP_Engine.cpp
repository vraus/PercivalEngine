#include "VP_Engine.hpp"

void VrausPercival::Engine::run()
{
	while (!window.shouldClose())
		glfwPollEvents();
}
