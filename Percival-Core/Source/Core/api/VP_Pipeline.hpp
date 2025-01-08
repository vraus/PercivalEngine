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
		Pipeline(Device& device,
			const std::string& vert_file_path,
			const std::string& frag_file_path,
			const PipelineConfigInfo& config_info);

		~Pipeline();

		Pipeline(const Pipeline&) = delete;
		Pipeline& operator=(const Pipeline&) = delete;
		
		static PipelineConfigInfo defaultPipelineConfigInfo(uint32_t width, uint32_t height);
	private:
		// void createPipelineLayout();
		void createGraphicsPipeline(const std::string& vert_file_path, const std::string& frag_file_path, const PipelineConfigInfo& config_info);
		void createShaderModule(const std::vector<char>& code, VkShaderModule* shader_module);
		// void cleanup();

		Device& device_; // Could be memory unsafe
		VkPipeline graphics_pipeline_;
		VkPipelineLayout pipeline_layout_; // Put later in the render system

		// Shaders
		VkShaderModule vert_shader_module_;
		VkShaderModule frag_shader_module_;

		// helper
		static std::vector<char> readFile(const std::string& filename);
	};

}
