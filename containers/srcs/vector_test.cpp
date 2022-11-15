#include "../class/utils.hpp"

void	vector_test_constructors() {
	title("\e[95m-Constructors-\e[39m");

	annonce("Default constructor");
	ft::vector<int>		mine;
	mine.push_back(44);
	mine.push_back(-34);
	mine.push_back(112);
	Test_success();

	annonce("Fill constructor");
	ft::vector<int>		mine1(3, 42);
	if (mine1.size() != 3) {
		std::cout << "Mine vector: " << mine1.size() << std::endl;
		return Test_failure();
	}
	Test_success();

	annonce("Range constructor");
	ft::vector<int>	mine2(mine.begin(), mine.end());
	if (!ft::equal(mine.begin(), mine.end(), mine2.begin())) {
		return Test_failure();
	}
	Test_success();
	
	annonce("Copy constructor");
	ft::vector<int> mine3(mine);
	if (!ft::equal(mine.begin(), mine.end(), mine3.begin())) {
		return Test_failure();
	}
	Test_success();
	
	annonce("Operator =");
	ft::vector<int> mine4 = mine;
	if (!ft::equal(mine.begin(), mine.end(), mine4.begin())) {
		return Test_failure();
	}
	Test_success();
}

void vector_test_assign() {
	title("\e[95m-Assign-\e[39m");
	srand(time(NULL));
	
	std::vector<int>	real;
	ft::vector<int>		mine;

	annonce("Assign 1000 value");
	int i = rand() % 2147483647;
	real.assign(1000,i);
	mine.assign(1000,i);
	if (!ft::equal(real.begin(), real.end(), mine.begin())) {
		std::cout << "Real vector: " << real.size() << std::endl;
		std::cout << "Mine vector: " << mine.size() << std::endl;
		return Test_failure();
	}
	Test_success();

	annonce("Assign 1000000 value");
	i = rand() % 2147483647;
	real.assign(1000000,i);
	mine.assign(1000000,i);
	if (!ft::equal(real.begin(), real.end(), mine.begin())) {
		std::cout << "Real vector: " << real.size() << std::endl;
		std::cout << "Mine vector: " << mine.size() << std::endl;
		return Test_failure();
	}
	Test_success();
	
	std::vector<int>	real2;
	ft::vector<int>		mine2;
	
	annonce("Assign range");
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
	title("\e[95m-At-\e[39m");
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
	
	annonce("At in range");
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
	Test_success();
	
	annonce("At negative");
	try {
		int must_fail = mine.at(-1);
		std::cout << "At(-1) ? " << must_fail << std::endl;
		return Test_failure();
	}
	catch (const std::exception& e) {
		;
	}
	Test_success();

	annonce("At out of range");
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
	title("\e[95m-Brackets []-\e[39m");
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
	
	annonce("Brackets in range");
	for (int k = 0; k < 3; k++) {
		int i = rand() % 10;
		if (real[i] != mine[i]) {
			std::cout << "Real vector: " << real[i] << std::endl;
			std::cout << "Mine vector: " << mine[i] << std::endl;
			return Test_failure();
		}
	}
	Test_success();
	
	annonce("Brackets negative");
	if (real[-1] != mine[-1]) {
		std::cout << "Real vector: " << real[-1] << std::endl;
		std::cout << "Mine vector: " << mine[-1] << std::endl;
		return Test_failure();
	}
	Test_success();
	
	annonce("Brackets out of range");
	if (real[10] != mine[10]) {
		std::cout << "Real vector: " << real[10] << std::endl;
		std::cout << "Mine vector: " << mine[10] << std::endl;
		return Test_failure();
	}
	Test_success();
}

void	vector_test_front() {
	title("\e[95m-Front-\e[39m");
	srand(time(NULL));
	
	std::vector<int>	real;
	ft::vector<int>		mine;
	int n = rand() % 2147483647;
	
	annonce("Front with one element");
	real.push_back(n);
	mine.push_back(n);
	if (real.front() != mine.front()) {
		std::cout << "Real vector: " << real.front() << std::endl;
		std::cout << "Mine vector: " << mine.front() << std::endl;
		return Test_failure();
	}
	Test_success();
	
	annonce("Front with 11 elements");
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

void	vector_test_back() {
	title("\e[95m-Back-\e[39m");
	srand(time(NULL));
	
	std::vector<int>	real;
	ft::vector<int>		mine;
	int n = rand() % 2147483647;
	
	annonce("Back with one element");
	real.push_back(n);
	mine.push_back(n);
	if (real.back() != mine.back()) {
		std::cout << "Real vector: " << real.back() << std::endl;
		std::cout << "Mine vector: " << mine.back() << std::endl;
		return Test_failure();
	}
	Test_success();
	
	annonce("Back with 11 elements");
	for (int i = 0; i < 10; i++) {
		n = rand() % 2147483647;
		real.push_back(n);
		mine.push_back(n);
	}
	if (real.back() != mine.back()) {
		std::cout << "Real vector: " << real.back() << std::endl;
		std::cout << "Mine vector: " << mine.back() << std::endl;
		return Test_failure();
	}
	Test_success();
}

void	vector_test_data() {
	title("\e[95m-Data-\e[39m");
	srand(time(NULL));
	
	std::vector<int>	real;
	ft::vector<int>		mine;
	int n = rand() % 2147483647;
	
	annonce("Data with one element");
	real.push_back(n);
	mine.push_back(n);
	if (*(real.data()) != *(mine.data())) {
		std::cout << "Real vector: " << real.data() << std::endl;
		std::cout << "Mine vector: " << mine.data() << std::endl;
		return Test_failure();
	}
	Test_success();
	
	annonce("Data with 11 elements");
	for (int i = 0; i < 10; i++) {
		n = rand() % 2147483647;
		real.push_back(n);
		mine.push_back(n);
	}
	if (*(real.data()) != *(mine.data())) {
		std::cout << "Real vector: " << real.data() << std::endl;
		std::cout << "Mine vector: " << mine.data() << std::endl;
		return Test_failure();
	}
	Test_success();
}

void	vector_test_empty() {
	title("\e[95m-Empty-\e[39m");

	std::vector<int>	real;
	ft::vector<int>		mine;

	annonce("Empty with no element");
	if (real.empty() != mine.empty()) {
		std::cout << "Real vector: " << real.empty() << std::endl;
		std::cout << "Mine vector: " << mine.empty() << std::endl;
		return Test_failure();
	}
	Test_success();

	annonce("Empty with one element");
	real.push_back(1);
	mine.push_back(1);
	if (real.empty() != mine.empty()) {
		std::cout << "Real vector: " << real.empty() << std::endl;
		std::cout << "Mine vector: " << mine.empty() << std::endl;
		return Test_failure();
	}
	Test_success();
}

void	vector_test_size() {
	title("\e[95m-Size-\e[39m");
	srand(time(NULL));
	
	std::vector<int>	real;
	ft::vector<int>		mine;
	
	annonce("Size with no element");
	if (real.size() != mine.size()) {
		std::cout << "Real vector: " << real.size() << std::endl;
		std::cout << "Mine vector: " << mine.size() << std::endl;
		return Test_failure();
	}
	Test_success();
	
	annonce("Size with one element");
	real.push_back(1);
	mine.push_back(1);
	if (real.size() != mine.size()) {
		std::cout << "Real vector: " << real.size() << std::endl;
		std::cout << "Mine vector: " << mine.size() << std::endl;
		return Test_failure();
	}
	Test_success();
	
	annonce("Size beetwen 1 and 1000");
	int n = (rand() % 1000) + 1;
	for (int i = 0; i < n; i++) {
		real.push_back(1);
		mine.push_back(1);
	}
	if (real.size() != mine.size()) {
		std::cout << "Real vector: " << real.size() << std::endl;
		std::cout << "Mine vector: " << mine.size() << std::endl;
		return Test_failure();
	}
	Test_success();
}

void	vector_test_max_size() {
	title("\e[95m-Max_size-\e[39m");
	srand(time(NULL));
	
	std::vector<int>	real;
	ft::vector<int>		mine;
	
	annonce("Max_size");
	if (real.max_size() != mine.max_size()) {
		std::cout << "Real vector: " << real.max_size() << std::endl;
		std::cout << "Mine vector: " << mine.max_size() << std::endl;
		return Test_failure();
	}
	Test_success();
}

void	vector_test_reserve() {
	title("\e[95m-Reserve-\e[39m");
	srand(time(NULL));
	
	std::vector<int>	real;
	ft::vector<int>		mine;
	
	annonce("Reserve with 0");
	real.reserve(0);
	mine.reserve(0);
	if (real.capacity() != mine.capacity()) {
		std::cout << "Real vector: " << real.capacity() << std::endl;
		std::cout << "Mine vector: " << mine.capacity() << std::endl;
		return Test_failure();
	}
	Test_success();
	
	annonce("Reserve with 1");
	real.reserve(1);
	mine.reserve(1);
	if (real.capacity() != mine.capacity()) {
		std::cout << "Real vector: " << real.capacity() << std::endl;
		std::cout << "Mine vector: " << mine.capacity() << std::endl;
		return Test_failure();
	}
	Test_success();
	
	annonce("Reserve with 1000");
	real.reserve(1000);
	mine.reserve(1000);
	if (real.capacity() != mine.capacity()) {
		std::cout << "Real vector: " << real.capacity() << std::endl;
		std::cout << "Mine vector: " << mine.capacity() << std::endl;
		return Test_failure();
	}
	Test_success();

	annonce("Reserve with 1000000");
	real.reserve(1000000);
	mine.reserve(1000000);
	if (real.capacity() != mine.capacity()) {
		std::cout << "Real vector: " << real.capacity() << std::endl;
		std::cout << "Mine vector: " << mine.capacity() << std::endl;
		return Test_failure();
	}
	Test_success();
}

void	vector_test_capacity() {
	title("\e[95m-Capacity-\e[39m");
	srand(time(NULL));
	
	std::vector<int>	real;
	ft::vector<int>		mine;
	
	annonce("Capacity with 0");
	if (real.capacity() != mine.capacity()) {
		std::cout << "Real vector: " << real.capacity() << std::endl;
		std::cout << "Mine vector: " << mine.capacity() << std::endl;
		return Test_failure();
	}
	Test_success();
	
	annonce("Capacity with 1");
	real.push_back(1);
	mine.push_back(1);
	if (real.capacity() != mine.capacity()) {
		std::cout << "Real vector: " << real.capacity() << std::endl;
		std::cout << "Mine vector: " << mine.capacity() << std::endl;
		return Test_failure();
	}
	Test_success();
	
	annonce("Capacity with 1000");
	for (int i = 0; i < 1000; i++) {
		real.push_back(1);
		mine.push_back(1);
	}
	if (real.capacity() != mine.capacity()) {
		std::cout << "Real vector: " << real.capacity() << std::endl;
		std::cout << "Mine vector: " << mine.capacity() << std::endl;
		return Test_failure();
	}
	Test_success();
}

void	vector_test_clear() {
	title("\e[95m-Clear-\e[39m");
	srand(time(NULL));
	
	std::vector<int>	real;
	ft::vector<int>		mine;
	
	annonce("Clear with 0");
	real.clear();
	mine.clear();
	if (real.size() != mine.size()) {
		std::cout << "Real vector: " << real.size() << std::endl;
		std::cout << "Mine vector: " << mine.size() << std::endl;
		return Test_failure();
	}
	Test_success();
	
	annonce("Clear with 1");
	real.push_back(1);
	mine.push_back(1);
	real.clear();
	mine.clear();
	if (real.size() != mine.size()) {
		std::cout << "Real vector: " << real.size() << std::endl;
		std::cout << "Mine vector: " << mine.size() << std::endl;
		return Test_failure();
	}
	Test_success();
	
	annonce("Clear with 1000");
	for (int i = 0; i < 1000; i++) {
		real.push_back(1);
		mine.push_back(1);
	}
	real.clear();
	mine.clear();
	if (real.size() != mine.size()) {
		std::cout << "Real vector: " << real.size() << std::endl;
		std::cout << "Mine vector: " << mine.size() << std::endl;
		return Test_failure();
	}
	Test_success();
}

void	vector_test_insert() {
	title("\e[95m-Insert-\e[39m");
	srand(time(NULL));
	
	std::vector<int>	real;
	ft::vector<int>		mine;
	
	annonce("Insert with 1");
	real.insert(real.begin(), 1);
	mine.insert(mine.begin(), 1);
	if (real.size() != mine.size()) {
		std::cout << "Real vector: " << real.size() << std::endl;
		std::cout << "Mine vector: " << mine.size() << std::endl;
		return Test_failure();
	}
	Test_success();
	
	annonce("Insert with 1000");
	real.insert(real.begin(), 1000, 1);
	mine.insert(mine.begin(), 1000, 1);
	if (real.size() != mine.size()) {
		std::cout << "Real vector: " << real.size() << std::endl;
		std::cout << "Mine vector: " << mine.size() << std::endl;
		return Test_failure();
	}
	Test_success();

	std::vector<int>	real2;
	ft::vector<int>		mine2;

	annonce("Insert with range");
	real2.insert(real2.begin(), real.begin(), real.end());
	mine2.insert(mine2.begin(), mine.begin(), mine.end());
	if (real2.size() != mine2.size()) {
		std::cout << "Real vector: " << real2.size() << std::endl;
		std::cout << "Mine vector: " << mine2.size() << std::endl;
		return Test_failure();
	}
	Test_success();
}

void launch_vector() {
	// vector_test_constructors();
	// vector_test_assign();
	// vector_test_at();
	// vector_test_brackets();
	// vector_test_front();
	// vector_test_back();
	// vector_test_data();
	// vector_test_empty();
	// vector_test_size();
	// vector_test_max_size();
	// vector_test_reserve();
	// vector_test_capacity();
	// vector_test_clear();
	vector_test_insert();
}
