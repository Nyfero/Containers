#include "../class/utils.hpp"

void	stack_test_push_top() {
	title("\e[95m-Push Top-\e[39m");
	srand(time(NULL));
	
	std::stack<int> real;
	ft::stack<int> mine;
	
	annonce("Push 50 elements");
	for (int i = 0; i < 50; i++) {
		int k = rand() % 2147483647;
		if (i % 2)
			k *= -1;
		real.push(k);
		mine.push(k);
	}
	Test_success();

	annonce("Top");
	if (real.top() != mine.top()) {
		std::cout << "Real stack: " << real.top() << std::endl;
		std::cout << "Mine stack: " << mine.top() << std::endl;
		return Test_failure();
	}
	Test_success();
}

void	stack_test_size() {
	title("\e[95m-Size-\e[39m");
	srand(time(NULL));
	
	std::stack<int> real;
	ft::stack<int> mine;
	int k = rand() % 101;
	
	annonce("Push between 0 and 100 elements and check size");
	for (int i = 0; i < k; i++) {
		real.push(1);
		mine.push(1);
		if (real.size() != mine.size()) {
			std::cout << "Real stack: " << real.size() << std::endl;
			std::cout << "Mine stack: " << mine.size() << std::endl;
			return Test_failure();
		}
	}
	Test_success();
}

void stack_test_pop_empty() {
	title("\e[95m-Pop Empty-\e[39m");
	srand(time(NULL));
	
	std::stack<int> real;
	ft::stack<int> mine;
	int k = rand() % 51;
	
	for (int i = 0; i < k; i++) {
		real.push(1);
		mine.push(1);
	}
	
	annonce("Pop");
	for (int i = 0; i < k; i++) {
		real.pop();
		mine.pop();
		if (real.size() != mine.size()) {
			std::cout << "Real stack: " << real.size() << std::endl;
			std::cout << "Mine stack: " << mine.size() << std::endl;
			return Test_failure();
		}
	}
	Test_success();
	
	annonce("Empty");
	if ((real.empty() && !mine.empty()) || (!real.empty() && mine.empty())) {
		std::cout << "Real stack: " << real.size() << std::endl;
		std::cout << "Mine stack: " << mine.size() << std::endl;
		return Test_failure();
	}
	Test_success();
}

void stack_test_operators() {
	title("\e[95m-Operators-\e[39m");
	
	ft::stack<int> m1;
	ft::stack<int> m2;
	ft::stack<int> m3;
	
	m1.push(1);
	m2.push(2);
	m3.push(3);
	
	annonce("Operator ==");
	if (m1 == m2) {
		std::cout << m1.top() << " == " << m2.top() << std::endl;
		return Test_failure();
	}
	Test_success();

	annonce("Operator !=");
	if (m1 != m1) {
		std::cout << m1.top() << " != " << m1.top() << std::endl;
		return Test_failure();
	}
	Test_success();

	annonce("Operator >");
	if (m1 > m2) {
		std::cout << m1.top() << " > " << m2.top() << std::endl;
		return Test_failure();
	}
	Test_success();

	annonce("Operator >=");
	if (m1 >= m3) {
		std::cout << m1.top() << " >= " << m3.top() << std::endl;
		return Test_failure();
	}
	Test_success();

	annonce("Operator <");
	if (m3 < m1) {
		std::cout << m3.top() << " < " << m1.top() << std::endl;
		return Test_failure();
	}
	Test_success();

	annonce("Operator <=");
	if (m2 <= m1) {
		std::cout << m2.top() << " <= " << m1.top() << std::endl;
		return Test_failure();
	}
	Test_success();
}

void	stack_test_copy() {
	title("\e[95m-Copy-\e[39m");
	srand(time(NULL));
	
	std::stack<int> real;
	ft::stack<int> mine;
	
	for (int i = 0; i < 4; i++) {
		int k = rand() % 2147483647;
		if (i % 2)
			k *= -1;
		real.push(k);
		mine.push(k);
	
		if (real.top() != mine.top()) {
			std::cout << "Real stack: " << real.top() << std::endl;
			std::cout << "Mine stack: " << mine.top() << std::endl;
			return Test_failure();
		}
	}
	
	annonce("Copy constructor");
	std::stack<int> real2(real);
	ft::stack<int> mine2(mine);
	if (real2.top() != mine2.top()) {
		std::cout << "Real stack: " << real2.top() << std::endl;
		std::cout << "Mine stack: " << mine2.top() << std::endl;
		return Test_failure();
	}
	Test_success();
	
	annonce("Operator =");
	std::stack<int> real3 = real;
	ft::stack<int> mine3 = mine;
	if (real3.top() != mine3.top()) {
		std::cout << "Real stack: " << real3.top() << std::endl;
		std::cout << "Mine stack: " << mine3.top() << std::endl;
		return Test_failure();
	}
	Test_success();
}

void	launch_stack() {
	stack_test_push_top();
	stack_test_size();
	stack_test_pop_empty();
	stack_test_operators();
	stack_test_copy();
}
