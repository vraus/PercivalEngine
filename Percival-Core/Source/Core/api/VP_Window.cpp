#include "VP_Window.hpp"

VrausPercival::Window::Window(int w, int h, std::string name) : width { w }, height { h }, windowName { name }
{
	initwindow();
}

void VrausPercival::Window::createWindowSurface(VkInstance instance, VkSurfaceKHR* surface)
{
	if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS) {
		throw std::runtime_error("Failed to create window surface");
	}
}

void VrausPercival::Window::initwindow()
{
	glfwInit();
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
	glfwSetWindowUserPointer(window, this);
	// glfwSetFramebufferSizeCallback(window, nullptr);
}
