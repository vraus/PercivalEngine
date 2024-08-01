#pragma once

#include "VP_Device.hpp"
#include "VP_Window.hpp"

#include <vector>

namespace VrausPercival {

	class SwapChain
	{
	public:
		SwapChain(Device& deviceRef, VkExtent2D windowExtent);
		~SwapChain() {}

		SwapChain(const SwapChain& swapChain) = delete;
		SwapChain& operator=(const SwapChain& swapChain) = delete;

	private:
		void init();
		void createSwapChain();
		void createImageViews();
		void cleanup();

		// Choosers
		VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
		VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
		VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR capabilities); // Extent = Resolution of the swap chain image

		Device& device;
		VkExtent2D windowExtent;

		VkSwapchainKHR swapChain;
		VkFormat swapChainImageFormat;
		VkExtent2D swapChainExtent;

		std::vector<VkImage> swapChainImages;
		std::vector<VkImageView> swapChainImageViews;
	};

}
