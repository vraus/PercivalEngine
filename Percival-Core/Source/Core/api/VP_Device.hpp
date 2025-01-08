#pragma once

// Vulkan
#define VK_USE_PLATFORM_WIN32_KHR
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#define GLFW_EXPOE_NATIVE_WIN32
#include <GLFW/glfw3native.h>

// VP
#include "VP_Window.hpp"

// std
#include <stdexcept>
#include <vector>
#include <iostream>
#include <cstring>
#include <map>
#include <optional>
#include <set>
#include <limits>
#include <cstdint>
#include <algorithm>

namespace vraus_percival {

	static VkResult CreateDebugUtilsMessengerEXT(
		VkInstance instance,
		const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
		const VkAllocationCallbacks* pAllocator,
		VkDebugUtilsMessengerEXT* pDebugMessenger
	) {
		auto func = (PFN_vkCreateDebugUtilsMessengerEXT)vkGetInstanceProcAddr(instance, "vkCreateDebugUtilsMessengerEXT");
		if (func != nullptr) {
			return func(instance, pCreateInfo, pAllocator, pDebugMessenger);
		}
		else {
			return VK_ERROR_EXTENSION_NOT_PRESENT;
		}
	}

	static void DestroyDebugUtilsMessengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator) {
		auto func = (PFN_vkDestroyDebugUtilsMessengerEXT)vkGetInstanceProcAddr(instance, "vkDestroyDebugUtilsMessengerEXT");
		if (func != nullptr) {
			func(instance, debugMessenger, pAllocator);
		}
	}

	struct QueueFamilyIndices {
		std::optional<uint32_t> graphicsFamily;
		std::optional<uint32_t> presentFamily;

		bool isComplete() {
			 return graphicsFamily.has_value() && presentFamily.has_value();
		}
	};

	struct SwapChainSupportDetails {
		VkSurfaceCapabilitiesKHR capabilities;
		std::vector<VkSurfaceFormatKHR> formats;
		std::vector<VkPresentModeKHR> presentModes;
	};

	class Device
	{
	public:
#ifdef NDEBUG
		const bool enableValidationLayers = false;
#else 
		const bool enableValidationLayers = true;
#endif

		Device(Window& window);
		~Device();

		Device(const Device& device) = delete;
		Device& operator=(const Device&) = delete;
		Device(Device&&) = delete;
		Device& operator=(Device&&) = delete;

		// Accessors
		VkCommandPool getCommandPool() { return command_pool_; }
		VkDevice device() { return device_; }
		VkSurfaceKHR surface() { return surface_; }
		VkQueue graphicsQueue() { return graphics_queue_; }
		VkQueue presentQueue() { return present_queue_;
		}
		VkFormat findSupportedFormat(
			const std::vector<VkFormat>& candidates, VkImageTiling tiling, VkFormatFeatureFlags features);
		SwapChainSupportDetails getSwapChainSupport() { return querySwapChainSupport(physical_device_); }
		QueueFamilyIndices findPhysicalQueueFamilies() { return findQueueFamilies(physical_device_); }

		// This function is temporary
		VkExtent2D getWindowExtent() { return window_.getExtent(); }

	private:
		void createInstance();
		void createSurface();
		void pickPhysicalDevice();
		void createLogicalDevice();
		void createCommandPool();

		void mainLoop();
		void cleanup() const;

		// Debugs
		void setupDebugMessenger();
		void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);

		// Helpers
		bool checkValidationLayerSupport();
		std::vector<const char*> getRequiredExtensions() const;
		bool checkDeviceExtensionSupport(VkPhysicalDevice device);
		QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device) const;
		SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);
		
		// Choosers
		int rateDeviceSuitability(VkPhysicalDevice device);

		// Callbak for the validation layer
		static VKAPI_ATTR VkBool32 VKAPI_CALL debugcallback(
			VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
			VkDebugUtilsMessageTypeFlagsEXT messageType,
			const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
			void* pUserData
		);

		VkInstance instance_; // Instance of Vulkan library
		VkDebugUtilsMessengerEXT debug_messenger_;
		VkPhysicalDevice physical_device_ = VK_NULL_HANDLE; // The GPU of the computer 

		Window& window_;
		VkDevice device_; // Logical device to describe features and queue families
		VkSurfaceKHR surface_;
		VkCommandPool command_pool_;

		VkSwapchainKHR swap_chain_;
		std::vector<VkImage> swapchain_images_;
		VkFormat swap_chain_image_format_;
		VkExtent2D swap_chain_extent_;


		VkQueue graphics_queue_;
		VkQueue present_queue_;

		const std::vector<const char*> validation_layers_ = { "VK_LAYER_KHRONOS_validation" };
		const std::vector<const char*> device_extensions_ = { VK_KHR_SWAPCHAIN_EXTENSION_NAME };
	};

}
