#include "../class/utils.hpp"

void	map_test_constructors() {
	title("\e[95m-Constructors-\e[39m");

	annonce("Default constructor");

	long time = get_time();
	std::map<char, int> real;
	real['a'] = 44;
	real['b'] = -34;
	real['c'] = 112;
	long real_time = get_time() - time;

	time = get_time();
	ft::map<char, int>		mine;
	mine['a'] = 44;
	mine['b'] = -34;
	mine['c'] = 112;
	long mine_time = get_time() - time;
	if (real.size() != mine.size()) {
		std::cout << "Real map: " << real.size() << std::endl;
		std::cout << "Mine map: " << mine.size() << std::endl;
		return Test_failure();
	}
	Test_performance(real_time, mine_time);

	annonce("Range constructor");

	time = get_time();
	std::map<char, int>		real2(real.begin(), real.end());
	real_time = get_time() - time;

	time = get_time();
	ft::map<char, int>	mine2(mine.begin(), mine.end());
	mine_time = get_time() - time;
	if (!ft::equal(mine.begin(), mine.end(), mine2.begin()) || mine2.size() != real2.size()) {
		std::cout << "Real map: " << real.size() << std::endl;
		std::cout << "Mine map: " << mine.size() << std::endl;
		return Test_failure();
	}
	Test_performance(real_time, mine_time);

	annonce("Copy constructor");

	time = get_time();
	std::map<char, int>		real3(real2);
	real_time = get_time() - time;

	time = get_time();
	ft::map<char, int> mine3(mine);
	mine_time = get_time() - time;
	if (!ft::equal(mine.begin(), mine.end(), mine3.begin()) || mine3.size() != real3.size()) {
		std::cout << "Real map: " << real.size() << std::endl;
		std::cout << "Mine map: " << mine.size() << std::endl;
		return Test_failure();
	}
	Test_performance(real_time, mine_time);

	annonce("Operator =");

	time = get_time();
	std::map<char, int>		real4 = real3;
	real_time = get_time() - time;

	time = get_time();
	ft::map<char, int> mine4 = mine;
	mine_time = get_time() - time;
	if (!ft::equal(mine.begin(), mine.end(), mine4.begin()) || mine4.size() != real4.size()) {
		std::cout << "Real map: " << real.size() << std::endl;
		std::cout << "Mine map: " << mine.size() << std::endl;
		return Test_failure();
	}
	Test_performance(real_time, mine_time);
};

void	map_test_at() {
	title("\e[95m-At-\e[39m");

	std::map<int, int> real;
	for (int i = 0; i < 10; i++) {
			real.insert(std::pair<int, int>(i, i));
	}
	ft::map<int, int>		mine;
	for (int i = 0; i < 10; i++) {
			mine.insert(ft::pair<int, int>(i, i));
	}

	annonce("At in range");
	try {
		for (int k = 0; k < 10; k++) {
			if (real.at(k) != mine.at(k)) {
				std::cout << "Real map: " << real.at(k) << std::endl;
				std::cout << "Mine map: " << mine.at(k) << std::endl;
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
};

void	map_test_bracket() {
		title("\e[95m-Brackets []-\e[39m");

	std::map<int, int> real;
	for (int i = 0; i < 10; i++) {
			real.insert(std::pair<int, int>(i, i));
	}
	ft::map<int, int>		mine;
	for (int i = 0; i < 10; i++) {
			mine.insert(ft::pair<int, int>(i, i));
	}

	annonce("Brackets in range");
	for (int k = 0; k < 10; k++) {
		if (real[k] != mine[k]) {
			std::cout << "Real map: " << real[k] << std::endl;
			std::cout << "Mine map: " << mine[k] << std::endl;
			return Test_failure();
		}
	}
	Test_success();

	// Portable programs should never call this function with an argument n that is out of range, since this causes undefined behavior

	annonce("Brackets negative");
	if (real[-1] != mine[-1]) {
		std::cout << "Real map: " << real[-1] << std::endl;
		std::cout << "Mine map: " << mine[-1] << std::endl;
		return Test_failure();
	}
	Test_success();

	annonce("Brackets out of range");
	if (real[10] != mine[10]) {
		std::cout << "Real map: " << real[10] << std::endl;
		std::cout << "Mine map: " << mine[10] << std::endl;
		return Test_failure();
	}
	Test_success();
};

void	map_test_empty() {
	title("\e[95m-Empty-\e[39m");

	std::map<int, int>	real;
	ft::map<int, int>		mine;

	annonce("Empty with no element");
	if (real.empty() != mine.empty()) {
		std::cout << "Real map: " << real.empty() << std::endl;
		std::cout << "Mine map: " << mine.empty() << std::endl;
		return Test_failure();
	}
	Test_success();

	annonce("Empty with one element");
	real.insert(std::pair<int, int>(1, 1));
	mine.insert(ft::pair<int, int>(1, 1));
	if (real.empty() != mine.empty()) {
		std::cout << "Real map: " << real.empty() << std::endl;
		std::cout << "Mine map: " << mine.empty() << std::endl;
		return Test_failure();
	}
	Test_success();
};

void	map_test_size() {
	title("\e[95m-Size-\e[39m");
	srand(time(NULL));

	std::map<int, int>	real;
	ft::map<int, int>		mine;

	annonce("Size with no element");
	if (real.size() != mine.size()) {
		std::cout << "Real map: " << real.size() << std::endl;
		std::cout << "Mine map: " << mine.size() << std::endl;
		return Test_failure();
	}
	Test_success();

	annonce("Size with one element");
	real.insert(std::pair<int, int>(1, 1));
	mine.insert(ft::pair<int, int>(1, 1));
	if (real.size() != mine.size()) {
		std::cout << "Real map: " << real.size() << std::endl;
		std::cout << "Mine map: " << mine.size() << std::endl;
		return Test_failure();
	}
	Test_success();

	annonce("Size beetwen 1 and 1000");
	int n = (rand() % 1000) + 1;
	for (int i = 0; i < n; i++) {
		real.insert(std::pair<int, int>(i, i));
		mine.insert(ft::pair<int, int>(i, i));
	}
	if (real.size() != mine.size()) {
		std::cout << "Real map: " << real.size() << std::endl;
		std::cout << "Mine map: " << mine.size() << std::endl;
		return Test_failure();
	}
	Test_success();
};

// void	map_test_max_size() {
// 	title("\e[95m-Max_size-\e[39m");
// 	srand(time(NULL));
//
// 	std::map<int, int>	real;
// 	ft::map<int, int>		mine;
//
// 	annonce("Max_size");
// 	if (real.max_size() != mine.max_size()) {
// 		std::cout << "Real map: " << real.max_size() << std::endl;
// 		std::cout << "Mine map: " << mine.max_size() << std::endl;
// 		return Test_failure();
// 	}
// 	Test_success();
// };

void launch_map() {
  map_test_constructors();
	map_test_at();
	map_test_bracket();
	map_test_empty();
	map_test_size();
	// map_test_max_size();
};
