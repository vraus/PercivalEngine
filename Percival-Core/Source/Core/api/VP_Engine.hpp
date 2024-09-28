#pragma once

#include "VP_Window.hpp"
#include "VP_Device.hpp"
#include "../Renderer/VP_Renderer.hpp"
#include "VP_Pipeline.hpp"

#include <iostream>
#include <stdexcept>
#include <memory>
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

		void run();

	private:

		Window window{ WIDTH, HEIGHT, "Percival Engine" };
		Device device{ window };
		// Renderer renderer{ window, device };
		
		Pipeline pipeline{ device, "../Shaders/simple_shader.vert.spv","../Shaders/simple_shader.frag.spv", Pipeline::defaultPipelineConfigInfo(WIDTH, HEIGHT)};
	};
}