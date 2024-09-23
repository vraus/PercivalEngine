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

	// Size 2 array for Shader Stage Create Info
	// Index 0 is for Vertex Shader Stages
	// Index 1 is for Fragment Shader Stages
	VkPipelineShaderStageCreateInfo shaderStagesInfo[2];
	// Vertex shader stages info
	shaderStagesInfo[0].sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
	shaderStagesInfo[0].stage = VK_SHADER_STAGE_VERTEX_BIT; // Which pipeline stage the vertex will be used
	shaderStagesInfo[0].module = vertShaderModule;
	shaderStagesInfo[0].pName = "main"; // Function name, entrypoint, to the shader
	// Fragment shader stages info
	shaderStagesInfo[1].sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
	shaderStagesInfo[1].stage = VK_SHADER_STAGE_FRAGMENT_BIT;
	shaderStagesInfo[1].module = fragShaderModule;
	shaderStagesInfo[1].pName = "main";

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
