#include "VP_Pipeline.hpp"

void VrausPercival::Pipeline::createGraphicsPipeline()
{
	auto vertShaderCode = readFile("../Shaders/simple_shader.vert.spv");
	auto fragShaderCode = readFile("../Shaders/simple_shader.frag.spv");
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
	return VkShaderModule();
}
