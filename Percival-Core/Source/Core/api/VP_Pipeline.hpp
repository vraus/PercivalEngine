#pragma once

namespace VrausPercival {

	class Pipeline
	{
	public:
		Pipeline() {}
		~Pipeline() {}

		Pipeline(const Pipeline& pipeline) = delete;
		Pipeline& operator=(const Pipeline& pipeline) = delete;
	};

}
