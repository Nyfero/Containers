#include "../class/utils.hpp"

int main() {
	std::cout << std::endl;
	std::cout << "\e[96m*** STACK ***\e[39m" << std::endl;
	launch_stack();
	
	std::cout << std::endl;
	std::cout << "\e[96m*** VECTOR ***\e[39m" << std::endl;
	launch_vector();
	
	std::cout << std::endl;
	std::cout << "\e[96m*** MAP ***\e[39m" << std::endl;
	// launch_map();
	
	return (0);
}
