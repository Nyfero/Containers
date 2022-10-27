#include "../../class/List.hpp"

int	stack_constructor_assign() {
	
	// Basic types
	try {
		FT::stack<bool> a;
		FT::stack<bool> b(a);
		FT::stack<char> c;
		FT::stack<char> d(c);
		FT::stack<wchar_t> e;
		FT::stack<wchar_t> f(e);
		FT::stack<short> g;
		FT::stack<short> h(g);
		FT::stack<int> i;
		FT::stack<int> j(i);
		FT::stack<long> k;
		FT::stack<long> l(k);
		FT::stack<long long> m;
		FT::stack<long long> n(m);
		FT::stack<unsigned char> o;
		FT::stack<unsigned char> p(o);
		FT::stack<unsigned short> q;
		FT::stack<unsigned short> r(q);
		FT::stack<unsigned int> s;
		FT::stack<unsigned int> t(s);
		FT::stack<unsigned long long> u;
		FT::stack<unsigned long long> v(u);
	}
	catch (const std::exception& e) {
		std::cerr << "\e[91mBasic types failed\e[39m" << std::endl;
		return (1);
	}

	// Container types
	try {
		FT::stack<std::vector<bool>> a;
		ft::stack<std::vector<bool>> b(a);
		FT::stack<std::deque<bool>> c;
		FT::stack<std::deque<bool>> d(c);
		FT::stack<std::list<bool>> e;
		FT::stack<std::list<bool>> f(e);
		FT::stack<std::set<bool>> g;
		FT::stack<std::set<bool>> h(g);
		FT::stack<std::map<std::string, bool>> i;
		FT::stack<std::map<std::string, bool>> j(i);
		FT::stack<std::multiset<bool>> k;
		FT::stack<std::multiset<bool>> l(k);
		FT::stack<std::multimap<std::string, bool>> m;
		FT::stack<std::multimap<std::string, bool>> n(m);
		FT::stack<std::queue<bool>> o;
		FT::stack<std::queue<bool>> p(o);
		FT::stack<std::priority_queue<bool>> q;
		FT::stack<std::priority_queue<bool>> r(q);
	}
	catch (const std::exception& e) {
		std::cerr << "\e[91mContainer types failed\e[39m" << std::endl;
		return (1);
	}
	
	// Stack Container Assign succeeded
	return (0);
}
