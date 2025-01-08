#include "VP_Window.hpp"

#include <iostream>

vraus_percival::Window::Window(int w, int h, std::string name) : width_ { w }, height_ { h }, window_name_ { name }
{
	initwindow();
}

vraus_percival::Window::~Window() {
	glfwDestroyWindow(window_);
	glfwTerminate();
}

void vraus_percival::Window::createWindowSurface(VkInstance instance, VkSurfaceKHR* surface)
{
	if (glfwCreateWindowSurface(instance, window_, nullptr, surface) != VK_SUCCESS) {
		throw std::runtime_error("Failed to create window surface");
	}
}

VkExtent2D vraus_percival::Window::chooseSwapExtent(const VkSurfaceCapabilitiesKHR capabilities)
{
	if (capabilities.currentExtent.width != int(std::numeric_limits<uint32_t>::max)) {
		return capabilities.currentExtent;
	}
	else {
		int width, height;
		glfwGetFramebufferSize(window_, &width, &height);

		VkExtent2D actualExtent = {
			static_cast<uint32_t>(width),
			static_cast<uint32_t>(height)
		};

		actualExtent.width = std::clamp(actualExtent.width, capabilities.minImageExtent.width, capabilities.maxImageExtent.width);
		actualExtent.height = std::clamp(actualExtent.height, capabilities.minImageExtent.height, capabilities.maxImageExtent.height);

		return actualExtent;
	}
}

void vraus_percival::Window::initwindow()
{
	glfwInit();
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	window_ = glfwCreateWindow(width_, height_, window_name_.c_str(), nullptr, nullptr);
	glfwSetWindowUserPointer(window_, this);
	// glfwSetFramebufferSizeCallback(window, nullptr);
}
