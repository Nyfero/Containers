#include "../../class/List.hpp"

int	stack_empty() {
	FT::stack<int> a;
	
	// Empty stack
	if (a.empty()) {
		std::cout << "\e[91mEmpty stack failed\e[39m" << std::endl;
		return (1);
	}

	// Stack not empty
	a.push(1);
	if (a.empty()) {
		std::cout << "\e[91mStack not empty failed\e[39m" << std::endl;
		return (1);
	}

	//Stack empty succeeded
	return (0);
}
