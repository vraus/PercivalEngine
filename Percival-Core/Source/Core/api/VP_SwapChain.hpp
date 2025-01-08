#pragma once

#include "VP_Device.hpp"
#include "VP_Window.hpp"
#include "VP_Pipeline.hpp"

#include <vector>

namespace vraus_percival {

	class SwapChain
	{
	public:
		SwapChain(Device& deviceRef, VkExtent2D windowExtent);
		~SwapChain() {}

		SwapChain(const SwapChain& swapChain) = delete;
		SwapChain& operator=(const SwapChain& swapChain) = delete;

		VkExtent2D getSwapChainExtent() const { return swapChainExtent; }
		uint32_t width() const { return swapChainExtent.width; }
		uint32_t height() const { return swapChainExtent.height; }
		VkFormat getSwapChainImageFormat() const { return swapChainImageFormat; }
		VkFormat findDepthFormat();
		VkRenderPass getRenderPass() const { return renderPass; }

	private:
		void init();
		void createSwapChain();
		void createImageViews();
		void createRenderPass();
		void createFramebuffers();
		void cleanup();

		// Choosers
		VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
		VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
		VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR capabilities); // Extent = Resolution of the swap chain image

		VkPipelineLayout pipelineLayout;

		Device& device;
		VkExtent2D windowExtent;

		std::vector<VkFramebuffer> swapChainFramebuffers;
		VkRenderPass renderPass;

		VkSwapchainKHR swapChain;
		VkFormat swapChainImageFormat;
		VkExtent2D swapChainExtent;

		std::vector<VkImage> swapChainImages;
		std::vector<VkImageView> swapChainImageViews;
	};

}
