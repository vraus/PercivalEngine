#pragma once

#include "VP_Window.hpp"
#include "VP_Device.hpp"
#include "../Renderer/VP_Renderer.hpp"
#include "VP_Pipeline.hpp"

#include <iostream>
#include <stdexcept>
#include <memory>
#include <vector>

#define VERT_SPV_PATH "C:/Users/hadri/Documents/GitHub/PercivalEngine/Percival-Core/Source/Core/Shaders/simple_shader.vert.spv"
#define FRAG_SPV_PATH "C:/Users/hadri/Documents/GitHub/PercivalEngine/Percival-Core/Source/Core/Shaders/simple_shader.frag.spv"

namespace vraus_percival {
	
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
		// Device device{ window };
		// Renderer renderer{ window, device };
		
		Pipeline pipeline{ VERT_SPV_PATH,FRAG_SPV_PATH};
	};
}