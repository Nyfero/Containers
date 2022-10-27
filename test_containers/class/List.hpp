#ifndef LIST_HPP
# define LIST_HPP

# define FT ft

# include <vector>
# include <deque>
# include <stack>
# include <list>
# include <set>
# include <map>
# include <stack>
# include <queue>
# include <string>
# include <iostream>
# include <iomanip>
# include <algorithm>
# include <csignal>
# include <unistd.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <fstream>
# include <iterator>
# include "Tester.hpp"
# include "../../containers/class/iterators/iterator_traits.hpp"
# include "../../containers/class/iterators/reverse_iterator.hpp"
# include "../../containers/class/side_func/enable_if.hpp"
# include "../../containers/class/side_func/equal.hpp"
# include "../../containers/class/side_func/is_integral.hpp"
# include "../../containers/class/side_func/lexicographical_compare.hpp"
# include "../../containers/class/stack.hpp"
# include "../../containers/class/vector.hpp"


/****************************/
/*****      VECTOR      *****/
/****************************/

// int	vector_launch(); // launch all functions to test vector
//
// int	vector_capacity();
// int	vector_reserve();
//
//
// int	vector_resize();



/*************************/
/*****      MAP      *****/
/*************************/



/***************************/
/*****      STACK      *****/
/***************************/

int	stack_launch();

int	stack_constructor();
int	stack_constructor_assign();

int	stack_top();

int	stack_empty();
int	stack_size();

int	stack_push();
int	stack_pop();

int	stack_operator_equ();
int	stack_operator_diff();
int	stack_operator_inf();
int	stack_operator_einf();
int	stack_operator_supp();
int	stack_operator_esupp();

#endif
