#include "VP_Pipeline.hpp"

VrausPercival::Pipeline::Pipeline(Device& device, const std::string& vertFilePath, const std::string& fragFilePath, const PipelineConfigInfo& configInfo) : device{device}
{
	createGraphicsPipeline(vertFilePath, fragFilePath);
}

void VrausPercival::Pipeline::createGraphicsPipeline(const std::string& vertFilePath, const std::string& fragFilePath)
{
	auto vertShaderCode = readFile(vertFilePath);
	auto fragShaderCode = readFile(fragFilePath);

	VkShaderModule vertShaderModule = createShaderModule(vertShaderCode);
	VkShaderModule fragShaderModule = createShaderModule(fragShaderCode);

	vkDestroyShaderModule(device.device(), fragShaderModule, nullptr);
	vkDestroyShaderModule(device.device(), vertShaderModule, nullptr);
}

std::vector<char> VrausPercival::Pipeline::readFile(const std::string& filename)
{
	std::ifstream file(filename, std::ios::ate | std::ios::binary);

	if (!file.is_open()) {
		throw std::runtime_error("Failed to open file!");
	}

	size_t fileSize = (size_t)file.tellg();
	std::vector<char> buffer(fileSize);

	file.seekg(0);
	file.read(buffer.data(), fileSize);
	file.close();

	return buffer;
}

VkShaderModule VrausPercival::Pipeline::createShaderModule(const std::vector<char>& code)
{
	VkShaderModuleCreateInfo createInfo{};
	createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
	createInfo.codeSize = code.size();
	createInfo.pCode = reinterpret_cast<const uint32_t*>(code.data());

	VkShaderModule shaderModule;
	if (vkCreateShaderModule(device.device(), &createInfo, nullptr, &shaderModule) != VK_SUCCESS)
		throw std::runtime_error("Failed to create shader module!");

	return shaderModule;
}
