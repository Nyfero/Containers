#include "../class/utils.hpp"

void	stack_test_push_top() {
	annonce("Push Top");
	srand(time(NULL));
	
	std::stack<int> real;
	ft::stack<int> mine;
	
	for (int i = 0; i < 50; i++) {
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
	Test_success();
}

void	stack_test_size() {
	annonce("Size");
	srand(time(NULL));
	
	std::stack<int> real;
	ft::stack<int> mine;
	int k = rand() % 101;
	
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
	annonce("Pop Empty");
	srand(time(NULL));
	
	std::stack<int> real;
	ft::stack<int> mine;
	int k = rand() % 51;
	
	for (int i = 0; i < k; i++) {
		real.push(1);
		mine.push(1);
	}
	
	for (int i = 0; i < k; i++) {
		real.pop();
		mine.pop();
		if (real.size() != mine.size()) {
			std::cout << "Real stack: " << real.size() << std::endl;
			std::cout << "Mine stack: " << mine.size() << std::endl;
			return Test_failure();
		}
	}
	
	if ((real.empty() && !mine.empty()) || (!real.empty() && mine.empty())) {
		std::cout << "Real stack: " << real.size() << std::endl;
		std::cout << "Mine stack: " << mine.size() << std::endl;
		return Test_failure();
	}
	Test_success();
}

void stack_test_operators() {
	annonce("Operators");
	
	ft::stack<int> m1;
	ft::stack<int> m2;
	ft::stack<int> m3;
	
	m1.push(1);
	m2.push(2);
	m3.push(3);
	
	if (m1 == m2) {
		std::cout << m1.top() << " == " << m2.top() << std::endl;
		return Test_failure();
	}
	if (m1 != m1) {
		std::cout << m1.top() << " != " << m1.top() << std::endl;
		return Test_failure();
	}
	if (m1 > m2) {
		std::cout << m1.top() << " > " << m2.top() << std::endl;
		return Test_failure();
	}
	if (m1 >= m3) {
		std::cout << m1.top() << " >= " << m3.top() << std::endl;
		return Test_failure();
	}
	if (m3 < m1) {
		std::cout << m3.top() << " < " << m1.top() << std::endl;
		return Test_failure();
	}
	if (m2 <= m1) {
		std::cout << m2.top() << " <= " << m1.top() << std::endl;
		return Test_failure();
	}
	Test_success();
}

void	launch_stack() {
	stack_test_push_top();
	stack_test_size();
	stack_test_pop_empty();
	stack_test_operators();
}
