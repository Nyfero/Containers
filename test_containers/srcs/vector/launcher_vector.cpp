#include "../../class/List.h"

using namespace MyContainerTester;

int	vector_launch() {
	std::vector<Tester>	list;
	
	try {
		Tester a("Vector capacity", "capacity()", &vector_capacity);
		Tester b("Vector capacity", "reserve()", &vector_reserve);
		Tester c("Vector modifiers", "resize()", &vector_resize);
		list.push_back(a);
		list.push_back(b);
		list.push_back(c);
		list.at(0).RunTest(list);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
		return (1);
	}
	return (0);
}
