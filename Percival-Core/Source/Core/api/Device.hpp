#pragma once

#include "window.hpp"

namespace VrausPercival {

	class Device
	{
	public:
		Device() {}
		~Device() {}

		Device(const Device& device) = delete;
		Device& operator=(const Device& device) = delete;
	};

}
