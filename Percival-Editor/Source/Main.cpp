#include "Core/api/VP_Engine.hpp"

#include <iostream>
#include <cstdlib>

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
