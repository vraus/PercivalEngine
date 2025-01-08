#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

// std
#include <stdexcept>
#include <cstdint>
#include <algorithm>
#include <limits>

namespace vraus_percival {

	class Window
	{
	public:
		Window(int width, int height, std::string windowName);
		~Window();

		Window(const Window& window) = delete;
		Window& operator=(const Window& window) = delete;

		bool shouldClose() { return glfwWindowShouldClose(window_); }
		VkExtent2D getExtent() { return { static_cast<uint32_t>(width_),static_cast<uint32_t>(height_) }; }
		void createWindowSurface(VkInstance instance, VkSurfaceKHR* surface);
		VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR capabilities);

	private:
		void initwindow();

		int width_;
		int height_;
		std::string window_name_;

		GLFWwindow* window_;
	};

}
