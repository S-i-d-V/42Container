#ifndef TEST_VECTOR_HPP
#define TEST_VECTOR_HPP

//Utils headers
#include "../tester.hpp"

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

#endif