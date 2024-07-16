#include "VP_Window.hpp"

VrausPercival::Window::Window(int width, int height, const char* windowName)
{
	window = glfwCreateWindow(width, height, windowName, nullptr, nullptr);
}

void VrausPercival::Window::createWindowSurface(VkInstance instance, VkSurfaceKHR* surface)
{
	if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS) {
		throw std::runtime_error("Failed to create window surface");
	}
}
