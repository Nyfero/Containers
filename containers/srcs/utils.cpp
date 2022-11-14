#include "../class/utils.hpp"

void	annonce(std::string msg) {
	std::cout << msg << std::endl;
}

void	Test_failure() {
	std::cout << "\e[31m[KO]\e[39m" << std::endl;
}

void	Test_success() {
	std::cout << "\e[92m[OK]\e[39m" << std::endl;
}
