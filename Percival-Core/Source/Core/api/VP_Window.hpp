#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

// std
#include <stdexcept>
#include <cstdint>
#include <algorithm>
#include <limits>

namespace VrausPercival {

	class Window
	{
	public:
		Window(int width, int height, std::string windowName);
		~Window() {}

		Window(const Window& window) = delete;
		Window& operator=(const Window& window) = delete;

		bool shouldClose() { return glfwWindowShouldClose(window); }

		void createWindowSurface(VkInstance instance, VkSurfaceKHR* surface);
		VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR capabilities);

	private:
		void initwindow();

		int width;
		int height;
		std::string windowName;

		GLFWwindow* window;
	};

}
