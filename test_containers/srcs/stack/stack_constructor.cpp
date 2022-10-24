#include "../../class/List.hpp"

int	stack_constructor() {

	// Basic types
	try {
		ft::stack<bool> a;
		ft::stack<char> b;
		ft::stack<wchar_t> c;
		ft::stack<short> d;
		ft::stack<int> e;
		ft::stack<long> f;
		ft::stack<long long> g;
		ft::stack<unsigned char> h;
		ft::stack<unsigned short> i;
		ft::stack<unsigned int> j;
		ft::stack<unsigned long long> k;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	// Container types
	try {
		ft::stack<std::vector<bool>> a;
		ft::stack<std::deque<bool>> b;
		ft::stack<std::list<bool>> c;
		ft::stack<std::set<bool>> d;
		ft::stack<std::map<std::string, bool>> e;
		ft::stack<std::multiset<bool>> f;
		ft::stack<std::multimap<std::string, bool>> g;
		ft::stack<std::queue<bool>> h;
		ft::stack<std::priority_queue<bool>> i;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return (0);
}
