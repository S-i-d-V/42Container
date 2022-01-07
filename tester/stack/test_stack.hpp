#ifndef TEST_STACK_HPP
#define TEST_STACK_HPP

//Utils headers
#include <iostream>
#include <ctime>

//Stacks headers
#include <algorithm>
#include <stack>
#include "../../containers/stack/stack.hpp"

//utils
bool	print_ok();
bool	print_ko();
bool	print_function_ok();
bool	print_function_ko();

//stack empty test
bool	empty_stack();
bool	filled_stack();
bool	cleared_filled_stack();
bool	stack_empty_test();

//stack size test
bool	size_empty_stack();
bool	stack_size_test();

#endif