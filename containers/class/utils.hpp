#pragma once

#ifndef UTILS_HPP
# define UTILS_HPP

# include <iostream>
# include <string>
# include <deque>
# include <stdlib.h>
# include <sstream>
# include <sys/time.h>
# include <unistd.h>
# include <cstddef>

# include "iterator_traits.hpp"
# include "reverse_iterator.hpp"
# include "enable_if.hpp"
# include "equal.hpp"
# include "is_integral.hpp"
# include "lexicographical_compare.hpp"
# include "vector_iterators.hpp"

// STD lib
# include <stack>
# include <vector>
# include <map>

// FT lib
# include "stack.hpp"
# include "vector.hpp"
// # include "map.hpp"

template <typename T>
struct Node {
        T       data;
        Node    *left;
        Node    *right;
        Node    *parent;
        int     height;

};

void	title(std::string str);
void	annonce(std::string msg);
void	Test_failure();
void	Test_performance(long real_time, long mine_time);
void	Test_success();
void	Test_timeout();
long	get_time();

int     int_max(int a, int b);
template <typename T>
Node <T>   *newNode(T data);
template <typename T>
int     height(Node <T> *N);
template <typename T>
Node <T>   *rightRotate(Node <T> *y);
template <typename T>
Node <T>   *leftRotate(Node <T> *x);
template <typename T>
int     getBalance(Node <T> *N);
template <typename T>
Node <T>   *insert(Node <T> *node, T data);
template<typename T>
Node <T>   *minValueNode(Node <T> *node);
template<typename T>
Node <T>   *deleteNode(Node <T> *root, T data);
template <typename T>
void printTree(Node <T>*root, std::string indent, bool last);


void	launch_stack();

void	launch_vector();
void	launch_vector_iterators();

#endif /* UTILS_HPP */
