#include "VP_Renderer.hpp"

VrausPercival::Renderer::Renderer(Window& window, Device& device) : window {window}, device {device}
{
	std::cout << "here in renderer\n";

	auto extent = window.getExtent();
	if (swapChain == nullptr) {
		swapChain = std::make_unique<SwapChain>(device, extent);
	}
}
