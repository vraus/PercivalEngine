#pragma once

namespace VrausPercival {

	class SwapChain
	{
	public:
		SwapChain();
		~SwapChain();

		SwapChain(const SwapChain& swapChain) = delete;
		SwapChain& operator=(const SwapChain& swapChain) = delete;

	};

}
