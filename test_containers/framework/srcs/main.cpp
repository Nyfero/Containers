#include "../class/Tester.hpp"

int	disp_coucou() {
	std::cout << "coucou" << std::endl;
	return (0);
}

int	main() {
	std::vector<Tester>	list;
	
	try {
		Tester t("p", "coucou_0", &disp_coucou);
		list.push_back(t);
		std::cout << list.at(0) << std::endl;
		Tester a("p", "coucou_1", &disp_coucou);
		list.push_back(a);
		std::cout << list.at(1) << std::endl;
		list.at(0).RunTest(list);
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
