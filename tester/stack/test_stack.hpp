#ifndef TEST_STACK_HPP
#define TEST_STACK_HPP

//Utils headers
#include "../tester.hpp"

//stack empty test
bool	empty_empty_stack();
bool	empty_filled_stack();
bool	empty_cleared_filled_stack();
bool	empty_test_stack();

//stack size test
bool	size_empty_stack();
bool	size_filled_stack();
bool	size_test_stack();

//stack top test
bool	top_single_elem_stack();
bool	top_filled_stack();
bool	top_cleared_stack();
bool	top_test_stack();

//stack push test
bool	push_single_element_stack();
bool	push_on_cleared_stack();
bool	push_1000_element_stack();
bool	push_test_stack();

//stack pop test
bool	pop_single_element_stack();
bool	pop_1000_element_stack();
bool	pop_test_stack();

#endif