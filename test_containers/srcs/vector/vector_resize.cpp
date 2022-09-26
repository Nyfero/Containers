#include "../../class/List.h"

int	vector_resize() {
	std::vector<int> tab{3};
	tab.resize(2);
	std::cout << "Resizes: " << tab.capacity() << std::endl;
	return (0);
}
