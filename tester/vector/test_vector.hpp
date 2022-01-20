#ifndef TEST_VECTOR_HPP
#define TEST_VECTOR_HPP

//Utils headers
#include "../tester.hpp"

//ITERATORS
//iterarators test
bool	iterator_begin_vector();
bool	iterator_end_vector();
bool	iterator_iterating_vector();
bool	iterator_iterating_empty_vector();
bool	iterator_checking_vector();
bool	iterator_checking_cleared_vector();
bool	iterator_plusequal_overload_vector();
bool	iterator_subequal_overload_vector();
bool	iterator_test_vector();

//reverse iterator test
bool	reviterator_rbegin_vector();
bool	reviterator_rend_vector();
bool	reviterator_iterating_vector();
bool	reviterator_iterating_empty_vector();
bool	reviterator_checking_vector();
bool	reviterator_checking_cleared_vector();
bool	reviterator_plusequal_overload_vector();
bool	reviterator_subequal_overload_vector();
bool	reviterator_test_vector();

//CAPACITY
//size test
bool	size_empty_vector();
bool	size_filled_vector();
bool	size_cleared_vector();
bool	size_resize_zero_vector();
bool	size_resized_vector();
bool	size_test_vector();

//max size test
bool	max_size_empty_vector();
bool	max_size_pushed_vector();
bool	max_size_insert_vector();
bool	max_size_cleared_vector();
bool	max_size_test_vector();

//resize test
bool	resize_empty_vector();
bool	resize_zero_empty_vector();
bool	resize_filled_vector();
bool	resize_zero_filled_vector();
bool	resize_cleared_vector();
bool	resize_zero_cleared_vector();
bool	resize_test_vector();

//capacity test
bool	capacity_empty_vector();
bool	capacity_cleared_vector();
bool	capacity_reserved_zero_vector();
bool	capacity_1elem_vector();
bool	capacity_multiple_realoccation_vector();
bool	capacity_filled_vector();
bool	capacity_filled_cleared_vector();
bool	capacity_test_vector();

//empty test
bool	empty_empty_vector();
bool	empty_filled_vector();
bool	empty_cleared_filled_vector();
bool	empty_test_vector();

//reserve test
bool	reserve_empty_vector();
bool	reserve_zero_empty_vector();
bool	reserve_filled_vector();
bool	reserve_zero_filled_vector();
bool	reserve_max_size_vector();
bool	reserve_more_maxsize_vector();
bool	reserve_zero_cleared_vector();
bool	reserve_cleared_vector();
bool	reserve_test_vector();

//ELEMENT ACCESS
//access test
bool	access_front_empty_vector();
bool	access_front_vector();
bool	access_back_empty_vector();
bool	access_back_vector();
bool	access_at_empty_vector();
bool	access_at_vector();
bool	access_at_out_vector();
bool	access_test_vector();

//MODIFIERS
//assign test
bool	assign_range_vector();
bool	assign_range_empty_vector();
bool	assign_empty_vector();
bool	assign_empty_range_empty_vector();
bool	assign_filled_empty_vector();
bool	assign_nothing_empty_vector();
bool	assign_performance_vector();
bool	assign_test_vector();

//push_back test
bool	push_back_empty_vector();
bool	push_back_filled_vector();
bool	push_back_cleared_vector();
bool	push_back_test_vector();

//pop_back test
bool	pop_back_empty_vector();
bool	pop_back_filled_vector();
bool	pop_back_cleared_vector();
bool	pop_back_test_vector();

//insert test
bool	insert_elem_front_vector();
bool	insert_elem_back_vector();
bool	insert_elem_in_vector();
bool	insert_elem_fill_vector();
bool	insert_test_vector();

//erase test
bool	erase_entire_filled_vector();
bool	erase_part_filled_vector();
bool	erase_last_element_vector();
bool	erase_first_element_vector();
bool	erase_test_vector();

//clear test
bool	clear_empty_vector();
bool	clear_filled_vector();
bool	clear_cleared_vector();
bool	clear_test_vector();

#endif