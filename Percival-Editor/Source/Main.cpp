#include "Core/api/VP_Engine.hpp"

// std
#include <iostream>
#include <cstdlib>
#include <stdexcept>

int main() {
	
	VrausPercival::Engine engine{};

	try {
		engine.run(); // The editor runs the Core Engine
		std::cin.get();
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
