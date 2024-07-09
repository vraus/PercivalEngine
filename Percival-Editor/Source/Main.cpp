#include "Core/api/Engine.hpp"

#include <iostream>
#include <cstdlib>

int main() {
	VrausPercival::Engine engine;

	try {
		engine.run(); // The editor runs the Core Engine
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
