#pragma once

#include "VP_Window.hpp"
#include "VP_Device.hpp"

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

		void run() {}

	private:
		void initEngine() {}
		void cleanup() {}

		Window window{};
		Device device{};
	};
}