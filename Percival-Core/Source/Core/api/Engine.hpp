#pragma once

#include "Window.hpp"

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

#include <iostream>
#include <stdexcept>
#include <vector>

namespace VrausPercival {
	
	class Engine {
	public:
		static constexpr int WIDTH = 800;
		static constexpr int HEIGHT = 600;

		Engine() {}
		~Engine() {}

		Engine(const Engine&) = delete;
		Engine& operator=(const Engine&) = delete;

		void run(); // This initialize everything (for now)

	private:
		void initEngine();
		void createInstance();
		void cleanup();

		VkInstance instance{};

		GLFWwindow* window;
	};
}