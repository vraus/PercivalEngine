#pragma once

#include "VP_Device.hpp"

#include <vector>
#include <iostream>
#include <fstream>

namespace VrausPercival {

	class Pipeline
	{
	public:
		Pipeline() {}
		~Pipeline() {}

		Pipeline(const Pipeline& pipeline) = delete;
		Pipeline& operator=(const Pipeline& pipeline) = delete;

	private:
		void createGraphicsPipeline();

		// helper
		static std::vector<char> readFile(const std::string& filename);
		VkShaderModule createShaderModule(const std::vector<char>& code);
	};

}
