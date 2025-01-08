#pragma once

namespace vraus_percival {

	class Model
	{
	public:
		Model() {}
		~Model() {}

		Model(const Model& model) = delete;
		Model& operator=(const Model& model) = delete;
	};

}
