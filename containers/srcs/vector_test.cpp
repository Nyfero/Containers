#include "../class/utils.hpp"

void	vector_test_constructors() {
	annonce("Constructors");
	
	ft::vector<int>		mine;

	mine.push_back(44);
	mine.push_back(-34);
	mine.push_back(112);

	ft::vector<int>	mine2(mine.begin(), mine.end());
	if (!ft::equal(mine.begin(), mine.end(), mine2.begin())) {
		return Test_failure();
	}
	
	ft::vector<int> mine3(mine);
	if (!ft::equal(mine.begin(), mine.end(), mine3.begin())) {
		return Test_failure();
	}
	
	ft::vector<int> mine4 = mine;
	if (!ft::equal(mine.begin(), mine.end(), mine4.begin())) {
		return Test_failure();
	}
	
	Test_success();
}

void vector_test_assign() {
	annonce("Assign");
	srand(time(NULL));
	
	std::vector<int>	real;
	ft::vector<int>		mine;

	int i = rand() % 2147483647;
	int j = rand() % 1000;
	real.assign(j,i);
	mine.assign(j,i);

	if (!ft::equal(real.begin(), real.end(), mine.begin())) {
		std::cout << "Real vector: " << real.size() << std::endl;
		std::cout << "Mine vector: " << mine.size() << std::endl;
		return Test_failure();
	}
	
	std::vector<int>	real2;
	ft::vector<int>		mine2;
	
	real2.assign(real.begin(), real.end());
	mine2.assign(mine.begin(), mine.end());
	
	if (!ft::equal(real2.begin(), real2.end(), mine2.begin())) {
		std::cout << "Real vector: " << real2.size() << std::endl;
		std::cout << "Mine vector: " << mine2.size() << std::endl;
		return Test_failure();
	}

	Test_success();
}

void	vector_test_at() {
	annonce("At");
	srand(time(NULL));
	
	std::vector<int>	real;
	ft::vector<int>		mine;
	
	for (int i = 0; i < 10; i++) {
		real.push_back(i);
		mine.push_back(i);
	}
	if (!ft::equal(real.begin(), real.end(), mine.begin())) {
		std::cout << "Real vector: " << real.size() << std::endl;
		std::cout << "Mine vector: " << mine.size() << std::endl;
		return Test_failure();
	}
	
	try {
		for (int k = 0; k < 3; k++) {
			int i = rand() % 10;
			if (real.at(i) != mine.at(i)) {
				std::cout << "Real vector: " << real.at(i) << std::endl;
				std::cout << "Mine vector: " << mine.at(i) << std::endl;
				return Test_failure();
			}
		}
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return Test_failure();
	}
	
	try {
		int must_fail = mine.at(-1);
		std::cout << "At(-1) ? " << must_fail << std::endl;
		return Test_failure();
	}
	catch (const std::exception& e) {
		;
	}
	
	try {
		int must_fail = mine.at(10);
		std::cout << "At(10) ? " << must_fail << std::endl;
		return Test_failure();
	}
	catch (const std::exception& e) {
		;
	}
	
	Test_success();
}

void	vector_test_brackets() {
	annonce("Brackets []");
	srand(time(NULL));
	
	std::vector<int>	real;
	ft::vector<int>		mine;
	
	for (int i = 0; i < 10; i++) {
		real.push_back(i);
		mine.push_back(i);
	}
	if (!ft::equal(real.begin(), real.end(), mine.begin())) {
		std::cout << "Real vector: " << real.size() << std::endl;
		std::cout << "Mine vector: " << mine.size() << std::endl;
		return Test_failure();
	}
	
	for (int k = 0; k < 3; k++) {
		int i = rand() % 10;
		if (real[i] != mine[i]) {
			std::cout << "Real vector: " << real[i] << std::endl;
			std::cout << "Mine vector: " << mine[i] << std::endl;
			return Test_failure();
		}
	}
	
	if (real[-1] != mine[-1]) {
		std::cout << "Real vector: " << real[-1] << std::endl;
		std::cout << "Mine vector: " << mine[-1] << std::endl;
		return Test_failure();
	}
	
	if (real[10] != mine[10]) {
		std::cout << "Real vector: " << real[10] << std::endl;
		std::cout << "Mine vector: " << mine[10] << std::endl;
		return Test_failure();
	}
	
	Test_success();
}

void	vector_test_front() {
	annonce("Front");
	srand(time(NULL));
	
	std::vector<int>	real;
	ft::vector<int>		mine;
	int n = rand() % 2147483647;
	
	real.push_back(n);
	mine.push_back(n);
	
	if (real.front() != mine.front()) {
		std::cout << "Real vector: " << real.front() << std::endl;
		std::cout << "Mine vector: " << mine.front() << std::endl;
		return Test_failure();
	}
	
	for (int i = 0; i < 10; i++) {
		n = rand() % 2147483647;
		real.push_back(n);
		mine.push_back(n);
	}
	
	if (real.front() != mine.front()) {
		std::cout << "Real vector: " << real.front() << std::endl;
		std::cout << "Mine vector: " << mine.front() << std::endl;
		return Test_failure();
	}
	
	Test_success();
}

void launch_vector() {
	vector_test_constructors();
	vector_test_assign();
	vector_test_at();
	vector_test_brackets();
	vector_test_front();
}
