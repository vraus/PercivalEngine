#include "VP_Device.hpp"

VrausPercival::Device::Device(Window& window) : window{&window}
{
	createInstance();
	setupDebugMessenger();
	pickPhysicalDevice();
	createLogicalDevice();
	cleanup();
}

void VrausPercival::Device::createInstance()
{
	if (enableValidationLayers && !checkValidationLayerSupport()) {
		throw std::runtime_error("validation layers requested, but not available!");
	}
	// VkApplicationInfo provides informations to the driver. This will help for later optimisation.
	VkApplicationInfo appInfo{};
	appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
	appInfo.pApplicationName = "Percival Editor";
	appInfo.applicationVersion = VK_MAKE_API_VERSION(0, 1, 0, 0);
	appInfo.pEngineName = "Percival Engine";
	appInfo.engineVersion = VK_MAKE_API_VERSION(0, 1, 0, 0);
	appInfo.apiVersion = VK_API_VERSION_1_0;

	// Counting extentions for the next struct
	auto extensions = getRequiredExtensions();

	// VkInstanceCreateInfo tells the Vulkan driver which global extensions and validation
	// layers we want to use.
	VkInstanceCreateInfo createInfo{};
	createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
	createInfo.pApplicationInfo = &appInfo;
	createInfo.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
	createInfo.ppEnabledExtensionNames = extensions.data();
	createInfo.enabledLayerCount = 0;
	if (enableValidationLayers) {
		createInfo.enabledLayerCount = static_cast<uint32_t>(validationLayers.size());
		createInfo.ppEnabledLayerNames = validationLayers.data();
	}
	else {
		createInfo.enabledLayerCount = 0;
	}

	VkDebugUtilsMessengerCreateInfoEXT debugCreateInfo{};
	if (enableValidationLayers) {
		createInfo.enabledLayerCount = static_cast<uint32_t>(validationLayers.size());
		createInfo.ppEnabledLayerNames = validationLayers.data();

		populateDebugMessengerCreateInfo(debugCreateInfo);
		createInfo.pNext = (VkDebugUtilsMessengerCreateInfoEXT*) &debugCreateInfo;
	}
	else {
		createInfo.enabledLayerCount = 0;
		createInfo.pNext = nullptr;
	}

	if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS)
		throw std::runtime_error("Failed to create instance!");
}

void VrausPercival::Device::pickPhysicalDevice()
{
	uint32_t deviceCount = 0;
	vkEnumeratePhysicalDevices(instance, &deviceCount, nullptr);

	if (deviceCount == 0)
		throw std::runtime_error("Failed to find GPUs with Vulkan support!");

	std::vector<VkPhysicalDevice> devices(deviceCount);
	vkEnumeratePhysicalDevices(instance, &deviceCount, devices.data());

	// Store GPU suitability score
	std::multimap<int, VkPhysicalDevice> candidates;

	for(const auto & device : devices) {
		int score = rateDeviceSuitability(device);
		candidates.insert(std::make_pair(score, device)); // Rate candidates
	}

	// Check if the best candidate is suitable at all
	if (candidates.rbegin()->first > 0) { // If score is > 0
		physicalDevice = candidates.rbegin()->second; // Collect candidate
	}
	else {
		throw std::runtime_error("Failed to find a suitable GPU!");
	}

	if (physicalDevice == VK_NULL_HANDLE)
		throw std::runtime_error("Failed to find a suitable GPU!");
}

void VrausPercival::Device::createLogicalDevice()
{
	// Specifying Queue Families
	QueueFamilyIndices indices = findQueueFamilies(physicalDevice);

	VkDeviceQueueCreateInfo queueCreateInfo{};
	queueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
	queueCreateInfo.queueFamilyIndex = indices.graphicsFamily.value();
	queueCreateInfo.queueCount = 1;
	float queuePriority = 1.f;
	queueCreateInfo.pQueuePriorities = &queuePriority;

	// Specifiying Device Features
	VkPhysicalDeviceFeatures deviceFeatures{}; // Empty for now ...
	
	// Creating the logical device
	VkDeviceCreateInfo createInfo{};
	createInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
	createInfo.pQueueCreateInfos = &queueCreateInfo;
	createInfo.queueCreateInfoCount = 1;
	createInfo.pEnabledFeatures = &deviceFeatures;
	createInfo.enabledExtensionCount = 0;
	if (enableValidationLayers) {
		createInfo.enabledLayerCount = static_cast<uint32_t>(validationLayers.size());
		createInfo.ppEnabledLayerNames = validationLayers.data();
	}
	else {
		createInfo.enabledLayerCount = 0;
	}

	// Create and check the device creation
	if (vkCreateDevice(physicalDevice, &createInfo, nullptr, &device) != VK_SUCCESS)
		throw std::runtime_error("Failed to create logical device!");

	vkGetDeviceQueue(device, indices.graphicsFamily.value(), 0, &graphicsQueue);
}

void VrausPercival::Device::cleanup() const
{
	if (enableValidationLayers) {
		DestroyDebugUtilsMessengerEXT(instance, debugMessenger, nullptr);
	}

	vkDestroyDevice(device, nullptr);
	vkDestroyInstance(instance, nullptr);

	// glfwDestroyWindow(window);

	glfwTerminate();
}

void VrausPercival::Device::setupDebugMessenger()
{
	if (!enableValidationLayers) return;

	VkDebugUtilsMessengerCreateInfoEXT createInfo{};
	populateDebugMessengerCreateInfo(createInfo);

	if (CreateDebugUtilsMessengerEXT(instance, &createInfo, nullptr, &debugMessenger) != VK_SUCCESS) {
		throw std::runtime_error("Failed to setup deubg messenger!");
	}
}

void VrausPercival::Device::populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo)
{
	createInfo = {};
	createInfo.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
	createInfo.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT
		| VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
	createInfo.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT
		| VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
	createInfo.pfnUserCallback = debugcallback;
}

bool VrausPercival::Device::checkValidationLayerSupport()
{
	uint32_t layerCount = 0;
	vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

	std::vector<VkLayerProperties> availableLayers(layerCount);
	vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

	for (const char* layerName : validationLayers) {
		bool layerFound = false;

		for (const auto& layerProperties : availableLayers) {
			if (strcmp(layerName, layerProperties.layerName) == 0) {
				layerFound = true;
				break;
			}
		}

		if (!layerFound)
			return false;
	}

	return true;
}

std::vector<const char*> VrausPercival::Device::getRequiredExtensions() const
{
	uint32_t glfwExtensionCount = 0;
	const char** glfwExtensions;
	glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

	std::vector<const char*> extensions(glfwExtensions, glfwExtensions + glfwExtensionCount);

	if (enableValidationLayers) {
		extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
	}

	return extensions;
}

int VrausPercival::Device::rateDeviceSuitability(VkPhysicalDevice device)
{
	VkPhysicalDeviceProperties deviceProperties;
	VkPhysicalDeviceFeatures deviceFeatures;

	vkGetPhysicalDeviceProperties(device, &deviceProperties);
	vkGetPhysicalDeviceFeatures(device, &deviceFeatures);

	int score = 0;

	// Discrete GPUs have a significant performance advantage
	if (deviceProperties.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU) {
		score += 100;
	}

	// Maximum possible size of textures affects graphics quality
	score += deviceProperties.limits.maxImageDimension2D;

	QueueFamilyIndices indices = findQueueFamilies(device);
	if (!indices.isComplete())
		score = 0;
	else
		score += indices.graphicsFamily.value();

	// Application can't function without geometry shaders
	if (!deviceFeatures.geometryShader)
		score = 0;

	return score;
}

VrausPercival::QueueFamilyIndices VrausPercival::Device::findQueueFamilies(VkPhysicalDevice device)
{
	QueueFamilyIndices indices;

	uint32_t queueFamilyCount = 0;
	vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, nullptr);

	std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
	vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, queueFamilies.data());

	int i = 0;
	for (const auto& queueFamily : queueFamilies) {
		if (indices.isComplete())
			break;

		if (queueFamily.queueFlags & VK_QUEUE_GRAPHICS_BIT) {
			indices.graphicsFamily = i;
		}

		i++;
	}

	return indices;
}

VKAPI_ATTR VkBool32 VKAPI_CALL VrausPercival::Device::debugcallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, void* pUserData)
{
	std::cerr << "Validation  layer: " << pCallbackData->pMessage << std::endl;
	return VK_FALSE;
}
