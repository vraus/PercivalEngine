#pragma once

#include "VP_Window.hpp"

#include <stdexcept>
#include <vector>
#include <iostream>
#include <cstring>

namespace VrausPercival {

	class Device
	{
	public:
#ifdef NDEBUG
		const bool enableValidationLayers = false;
#else 
		const bool enableValidationLayers = true;
#endif

		Device(Window& window);
		~Device() {}

		Device(const Device& device) = delete;
		Device& operator=(const Device&) = delete;
		Device(Device&&) = delete;
		Device& operator=(Device&&) = delete;

	private:
		void createInstance();

		// Helpers
		bool checkValidationLayerSupport();

		VkInstance instance;
		Window& window;

		const std::vector<const char*> validationLayers = { "VK_LAYER_KHRONOS_validation" };
	};

}
