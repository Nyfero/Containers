#include "../class/Tester.hpp"

int	disp_coucou() {
	std::cout << "coucou" << std::endl;
	return (0);
}

int	main() {
	Tester t("coucou", "coucou_0", &disp_coucou);
	std::vector<Tester>	list;
	
	list.push_back(t);
	Tester a("poil", "coucou_1", &disp_coucou);
	list.push_back(a);
	std::cout << list.at(0) << std::endl;
	std::cout << list.at(1) << std::endl;
	list.at(0).RunTest(list);
	
	return (0);
}
