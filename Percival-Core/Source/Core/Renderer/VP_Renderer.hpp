#pragma once

#include "../api/VP_Window.hpp"
#include "../api/VP_Device.hpp"
#include "../api/VP_SwapChain.hpp"

namespace VrausPercival {

	class Renderer
	{
	public:
		Renderer(Window& window, Device& device);
		~Renderer() {}

		Renderer(const Renderer&) = delete;
		Renderer& operator=(const Renderer&) = delete;

	private:
		Window& window;
		Device& device;
		std::unique_ptr<SwapChain> swapChain;
	};

}
