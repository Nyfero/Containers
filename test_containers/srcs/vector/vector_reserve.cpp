#include "../../class/List.h"

int	vector_reserve() {
	std::vector<int> tab{3};
	tab.reserve(5);
	std::cout << "Reserve: " << tab.capacity() << std::endl;
	return (0);
}
