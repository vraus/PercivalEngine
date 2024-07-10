#pragma once

namespace VrausPercival {

	class Model
	{
	public:
		Model() {}
		~Model() {}

		Model(const Model& model) = delete;
		Model& operator=(const Model& model) = delete;
	};

}
