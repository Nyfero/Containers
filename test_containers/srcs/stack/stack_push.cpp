#include "../../class/List.hpp"

int	stack_push() {
	
	// Stack<int>
	try {
		FT::stack<int> a;
		
		a.push(0);
		a.push(1);
		a.push(2);
		a.push(3);
		a.push(4);
		a.push(5);
		a.push(6);
		a.push(7);
		a.push(8);
		a.push(9);
	}
	catch (const std::exception& e) {
		std::cerr << "\e[91mStack <int> failed\e[39m" << std::endl;
		return (1);
	}
	
	// Stack<char>
	try {
		FT::stack<char> a;
		
		a.push('a');
		a.push('b');
		a.push('c');
		a.push('d');
		a.push('e');
		a.push('f');
		a.push('g');
		a.push('h');
		a.push('i');
		a.push('j');
	}
	catch (const std::exception& e) {
		std::cerr << "\e[91mStack <char> failed\e[39m" << std::endl;
		return (1);
	}
	
	// Stack Push succeeded
	return (0);
}
