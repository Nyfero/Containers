#include "../../class/List.hpp"


using namespace MyContainerTester;

int	stack_launch() {
	std::vector<Tester>	list;

	try {
		// Initiate all my test
		Tester a("Stack Constructors", "stack()", &stack_constructor);
		Tester b("Stack Constructors", "stack = ", &stack_constructor_assign);
		Tester c("Stack Access", "top()", &stack_top);
		Tester d("Stack Capacity", "empty()", &stack_empty);
		Tester e("Stack Capacity", "size()", &stack_size);
		Tester f("Stack Modifiers", "push()", &stack_push);
		Tester g("Stack Modifiers", "pop()", &stack_pop);
		Tester h("Stack Operators", "stack =! ", &stack_operator_diff);
		Tester i("Stack Operators", "stack < ", &stack_operator_inf);
		Tester j("Stack Operators", "stack <= ", &stack_operator_einf);
		Tester k("Stack Operators", "stack > ", &stack_operator_supp);
		Tester l("Stack Operators", "stack <= ", &stack_operator_esupp);

		// Add all my tests to my test list
		list.push_back(a);
		list.push_back(b);
		list.push_back(c);
		list.push_back(d);
		list.push_back(e);
		list.push_back(f);
		list.push_back(g);
		list.push_back(h);
		list.push_back(i);
		list.push_back(j);
		list.push_back(k);
		list.push_back(l);

	}
	catch (const std::exception& e){
		// Throw an error message if a test's initialization failed
		std::cout << e.what() << std::endl;
		return (1);
	}

	// Run the tests
	list.at(0).RunTest(list);
	return (0);
}
