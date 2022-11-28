#include "../class/utils.hpp"

void	map_test_constructors() {
	title("\e[95m-Constructors-\e[39m");

	annonce("Default constructor");

	// long time = get_time();
	// std::map<int> real;
	// real.push_back(44);
	// real.push_back(-34);
	// real.push_back(112);
	// long real_time = get_time() - time;
	//
	// time = get_time();
	// ft::map<int>		mine;
	// mine.push_back(44);
	// mine.push_back(-34);
	// mine.push_back(112);
	// long mine_time = get_time() - time;
	// Test_performance(real_time, mine_time);
	//
	// annonce("Fill constructor");
	//
	// time = get_time();
	// std::map<int>		real1(3, 42);
	// real_time = get_time() - time;
	//
	// time = get_time();
	// ft::map<int>		mine1(3, 42);
	// mine_time = get_time() - time;
	// if (!ft::equal(real1.begin(), real1.end(), mine1.begin())) {
	// 	std::cout << "Mine map: " << mine1.size() << std::endl;
	// 	return Test_failure();
	// }
	// Test_performance(real_time, mine_time);
	//
	// annonce("Range constructor");
	//
	// time = get_time();
	// std::map<int>		real2(real1.begin(), real1.end());
	// real_time = get_time() - time;
	//
	// time = get_time();
	// ft::map<int>	mine2(mine.begin(), mine.end());
	// mine_time = get_time() - time;
	// if (!ft::equal(mine.begin(), mine.end(), mine2.begin())) {
	// 	return Test_failure();
	// }
	// Test_performance(real_time, mine_time);
	//
	// annonce("Copy constructor");
	//
	// time = get_time();
	// std::map<int>		real3(real2);
	// real_time = get_time() - time;
	//
	// time = get_time();
	// ft::map<int> mine3(mine);
	// mine_time = get_time() - time;
	// if (!ft::equal(mine.begin(), mine.end(), mine3.begin())) {
	// 	return Test_failure();
	// }
	// Test_performance(real_time, mine_time);
	//
	// annonce("Operator =");
	//
	// time = get_time();
	// std::map<int>		real4 = real3;
	// real_time = get_time() - time;
	//
	// time = get_time();
	// ft::map<int> mine4 = mine;
	// mine_time = get_time() - time;
	// if (!ft::equal(mine.begin(), mine.end(), mine4.begin())) {
	// 	return Test_failure();
	// }
	// Test_performance(real_time, mine_time);
}

void launch_map() {
  // map_test_constructors();
};
