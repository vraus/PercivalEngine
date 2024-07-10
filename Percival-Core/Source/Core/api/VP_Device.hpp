#pragma once

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
