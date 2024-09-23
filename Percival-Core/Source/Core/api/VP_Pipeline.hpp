#pragma once

#include "VP_Device.hpp"

#include <vector>
#include <iostream>
#include <fstream>

namespace VrausPercival {
	struct PipelineConfigInfo {};

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

	private:
		void createGraphicsPipeline(const std::string& vertFilePath, const std::string& fragFilePath);

		Device& device;

		// helper
		static std::vector<char> readFile(const std::string& filename);
		VkShaderModule createShaderModule(const std::vector<char>& code);
	};

}
