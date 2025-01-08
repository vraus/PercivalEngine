#pragma once

#include "VP_Device.hpp"
#include "VP_SwapChain.hpp"

namespace vraus_percival {

	struct PipelineConfigInfo {
		VkViewport viewport;
		VkRect2D scissor;
		VkPipelineViewportStateCreateInfo viewportInfo;
		VkPipelineInputAssemblyStateCreateInfo inputAssemblyInfo;
		VkPipelineRasterizationStateCreateInfo rasterizationInfo;
		VkPipelineMultisampleStateCreateInfo multisampleInfo;
		VkPipelineColorBlendAttachmentState colorBlendAttachment;
		VkPipelineColorBlendStateCreateInfo colorBlendInfo;
		VkPipelineDepthStencilStateCreateInfo depthStencilInfo;
		VkPipelineLayout pipelineLayout = nullptr;
		VkRenderPass renderPass = nullptr;
		uint32_t subpass = 0;
	};

	class Pipeline
	{
	public:
		/*
		Pipeline(Device& device,
			const std::string& vertFilePath,
			const std::string& fragFilePath,
			const PipelineConfigInfo& configInfo);
			*/
		Pipeline(const std::string& vertFilePath,
			const std::string& fragFilePath);

		~Pipeline();

		Pipeline(const Pipeline&) = delete;
		Pipeline& operator=(const Pipeline&) = delete;
		
		// static PipelineConfigInfo defaultPipelineConfigInfo(uint32_t width, uint32_t height);
	private:
		// void createPipelineLayout();
		void createGraphicsPipeline(const std::string& vertFilePath, const std::string& fragFilePath);
		// void cleanup();

		// Device& device; // Could be memory unsafe
		VkPipeline graphicsPipeline;
		VkPipelineLayout pipelineLayout; // Put later in the render system

		VkShaderModule vertShaderModule;
		VkShaderModule fragShaderModule;

		// helper
		static std::vector<char> readFile(const std::string& filename);
		// void createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule);
	};

}
