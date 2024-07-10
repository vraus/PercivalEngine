#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

namespace VrausPercival {

	class Window
	{
	public:
		Window() {}
		~Window() {}

		Window(const Window& window) = delete;
		Window& operator=(const Window& window) = delete;

	};

}
