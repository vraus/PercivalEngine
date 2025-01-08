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
		VkCommandPool getCommandPool() { return commandPool; }
		VkDevice device() { return _device; }
		VkSurfaceKHR surface() { return _surface; }
		VkQueue graphicsQueue() { return _graphicsQueue; }
		VkQueue presentQueue() { return _presentQueue;
		}
		VkFormat findSupportedFormat(
			const std::vector<VkFormat>& candidates, VkImageTiling tiling, VkFormatFeatureFlags features);
		SwapChainSupportDetails getSwapChainSupport() { return querySwapChainSupport(physicalDevice); }
		QueueFamilyIndices findPhysicalQueueFamilies() { return findQueueFamilies(physicalDevice); }

		// This function is temporary
		VkExtent2D getWindowExtent() { return window.getExtent(); }

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

		VkInstance instance; // Instance of Vulkan library
		VkDebugUtilsMessengerEXT debugMessenger;

		Window& window;
		VkSurfaceKHR _surface;
		VkCommandPool commandPool;

		VkSwapchainKHR swapChain;
		std::vector<VkImage> swapchainImages;
		VkFormat swapChainImageFormat;
		VkExtent2D swapChainExtent;

		VkPhysicalDevice physicalDevice = VK_NULL_HANDLE; // The GPU of the computer 
		VkDevice _device; // Logical device to describe features and queue families

		VkQueue _graphicsQueue;
		VkQueue _presentQueue;

		const std::vector<const char*> validationLayers = { "VK_LAYER_KHRONOS_validation" };
		const std::vector<const char*> deviceExtensions = { VK_KHR_SWAPCHAIN_EXTENSION_NAME };
	};

}
