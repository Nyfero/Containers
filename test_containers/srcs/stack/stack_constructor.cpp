#include "../../class/List.hpp"

int	stack_constructor() {

	// Basic types
	try {
		FT::stack<bool> a;
		FT::stack<char> b;
		FT::stack<wchar_t> c;
		FT::stack<short> d;
		FT::stack<int> e;
		FT::stack<long> f;
		FT::stack<long long> g;
		FT::stack<unsigned char> h;
		FT::stack<unsigned short> i;
		FT::stack<unsigned int> j;
		FT::stack<unsigned long long> k;
	}
	catch (const std::exception& e) {
		std::cerr << "\e[91mBasic types failed\e[39m" << std::endl;
		return (1);
	}

	// Container types
	try {
		FT::stack<std::vector<bool>> a;
		FT::stack<std::deque<bool>> b;
		FT::stack<std::list<bool>> c;
		FT::stack<std::set<bool>> d;
		FT::stack<std::map<std::string, bool>> e;
		FT::stack<std::multiset<bool>> f;
		FT::stack<std::multimap<std::string, bool>> g;
		FT::stack<std::queue<bool>> h;
		FT::stack<std::priority_queue<bool>> i;
	}
	catch (const std::exception& e) {
		std::cerr << "\e[91mContainer types failed\e[39m" << std::endl;
		return (1);
	}

	// Stack Constructors succeeded
	return (0);
}
