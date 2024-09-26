#pragma once

#include "VP_Device.hpp"
#include "VP_SwapChain.hpp"

#include <vector>
#include <iostream>
#include <fstream>

namespace VrausPercival {

	struct PipelineConfigInfo {
		PipelineConfigInfo(const PipelineConfigInfo&) = delete;
		PipelineConfigInfo& operator=(const PipelineConfigInfo&) = delete;

		VkPipelineViewportStateCreateInfo viewportInfo;
		VkPipelineInputAssemblyStateCreateInfo inputAssemblyInfo;
		VkPipelineRasterizationStateCreateInfo rasterizationInfo;
		VkPipelineMultisampleStateCreateInfo multisampleInfo;
		VkPipelineColorBlendAttachmentState colorBlendAttachment;
		VkPipelineColorBlendStateCreateInfo colorBlendInfo;
		VkPipelineDepthStencilStateCreateInfo depthStencilInfo;
		std::vector<VkDynamicState> dynamicStateEnables;
		VkPipelineDynamicStateCreateInfo dynamicStateInfo;
		VkPipelineLayout pipelineLayout = nullptr;
		VkRenderPass renderPass = nullptr;
		uint32_t subpass = 0;
	};

	class Pipeline
	{
	public:
		Pipeline(Device& device,
			const std::string& vertFilePath,
			const std::string& fragFilePath,
			const PipelineConfigInfo& configInfo);
		~Pipeline() {}

		Pipeline(const Pipeline& pipeline) = delete;
		Pipeline& operator=(const Pipeline& pipeline) = delete;
		
		static void defaultPipelineCongifInfo(PipelineConfigInfo& configInfo);

	private:
		void createGraphicsPipeline(const std::string& vertFilePath, const std::string& fragFilePath);
		void cleanup();

		Device& device;
		VkPipelineLayout pipelineLayout; // Put later in the reder system
		std::unique_ptr<SwapChain> swapChain;
		VkPipeline graphicsPipeline;


		// helper
		static std::vector<char> readFile(const std::string& filename);
		VkShaderModule createShaderModule(const std::vector<char>& code);
	};

}
