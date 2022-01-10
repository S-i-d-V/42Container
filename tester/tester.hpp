#ifndef TESTER_HPP
#define TESTER_HPP

//Utils headers
#include <iostream>
#include <ctime>

//Algorithm headers
#include <algorithm>

//Stack headers
#include <stack>
#include "../containers/stack/stack.hpp"

//Vector headers
#include <vector>
#include "../containers/vector/vector.hpp"

//Test containers headers
#include "stack/test_stack.hpp"
#include "vector/test_vector.hpp"

//utils
void	print_vector();
void	print_stack();
void	print_map();
bool	print_ok();
bool	print_ko();
bool	print_function_ok();
bool	print_function_ko();
bool	print_container_ok();
bool	print_container_ko();

//testers
bool	test_vector();
bool	test_stack();
bool	test_map();

#endif