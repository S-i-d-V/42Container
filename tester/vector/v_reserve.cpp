/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_reserve.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:47:29 by user42            #+#    #+#             */
/*   Updated: 2022/01/11 22:13:32 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.hpp"

bool	reserve_empty_vector(){
	std::cout << "\033[0;1mTest 1\033[0m - ";
	std::vector<int>		rvect;
	ft::vector<int>			mvect;

	//std test
	std::time_t time1 = std::time(NULL);
	rvect.reserve(10);
	double ret1 = rvect.capacity();
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	mvect.reserve(10);
	double ret2 = mvect.capacity();
	time2 = std::time(NULL) - time2;

	//get diff time
	std::time_t diff = time2 - time1;

	//ret
	if (ret1 == ret2){
		std::cout << "\033[32mOK\033[0m - \033[33m" << diff << " ms\033[0m" << std::endl;
		return true;
	}
	std::cout << "\033[31mKO\033[0m" << std::endl;
	return false;
}

bool	reserve_zero_empty_vector(){
	std::cout << "\033[0;1mTest 2\033[0m - ";
	std::vector<int>		rvect;
	ft::vector<int>			mvect;

	//std test
	std::time_t time1 = std::time(NULL);
	rvect.reserve(0);
	double ret1 = rvect.capacity();
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	mvect.reserve(0);
	double ret2 = mvect.capacity();
	time2 = std::time(NULL) - time2;

	//get diff time
	std::time_t diff = time2 - time1;

	//ret
	if (ret1 == ret2){
		std::cout << "\033[32mOK\033[0m - \033[33m" << diff << " ms\033[0m" << std::endl;
		return true;
	}
	std::cout << "\033[31mKO\033[0m" << std::endl;
	return false;
}

bool	reserve_filled_vector(){
	std::cout << "\033[0;1mTest 3\033[0m - ";
	std::vector<int>		rvect(25 , 0);
	ft::vector<int>			mvect(25 , 0);

	//std test
	std::time_t time1 = std::time(NULL);
	rvect.reserve(32);
	double ret1 = rvect.capacity();
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	mvect.reserve(32);
	double ret2 = mvect.capacity();
	time2 = std::time(NULL) - time2;

	//get diff time
	std::time_t diff = time2 - time1;

	//ret
	if (ret1 == ret2){
		std::cout << "\033[32mOK\033[0m - \033[33m" << diff << " ms\033[0m" << std::endl;
		return true;
	}
	std::cout << "\033[31mKO\033[0m" << std::endl;
	return false;
}

bool	reserve_zero_filled_vector(){
	std::cout << "\033[0;1mTest 4\033[0m - ";
	std::vector<int>		rvect(25, 5);
	ft::vector<int>			mvect(25, 5);

	//std test
	std::time_t time1 = std::time(NULL);
	rvect.reserve(0);
	double ret1 = rvect.capacity();
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	mvect.reserve(0);
	double ret2 = mvect.capacity();
	time2 = std::time(NULL) - time2;

	//get diff time
	std::time_t diff = time2 - time1;

	//ret
	if (ret1 == ret2){
		std::cout << "\033[32mOK\033[0m - \033[33m" << diff << " ms\033[0m" << std::endl;
		return true;
	}
	std::cout << "\033[31mKO\033[0m" << std::endl;
	return false;
}

bool	reserve_max_size_vector(){
	std::cout << "\033[0;1mTest 5\033[0m - ";
	std::vector<int>		rvect(5, 0);
	ft::vector<int>			mvect(5, 0);

	//std test
	std::time_t time1 = std::time(NULL);
	double ret1;
	try {
		rvect.reserve(rvect.max_size());
		ret1 = rvect.capacity();
	}
	catch (std::bad_alloc){
		ret1 = 0;
	}
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	double ret2;
	try {
		mvect.reserve(mvect.max_size());
		ret2 = mvect.capacity();
	}
	catch (std::bad_alloc){
		ret2 = 0;
	}
	time2 = std::time(NULL) - time2;

	//get diff time
	std::time_t diff = time2 - time1;

	//ret
	if (ret1 == ret2){
		std::cout << "\033[32mOK\033[0m - \033[33m" << diff << " ms\033[0m" << std::endl;
		return true;
	}
	std::cout << "\033[31mKO\033[0m" << std::endl;
	return false;
}

bool	reserve_more_maxsize_vector(){
	std::cout << "\033[0;1mTest 6\033[0m - ";
	std::vector<int>		rvect(5, 0);
	ft::vector<int>			mvect(5, 0);

	//std test
	std::time_t time1 = std::time(NULL);
	double ret1;
	try {
		rvect.reserve(rvect.max_size() + 1);
		ret1 = rvect.capacity();
	}
	catch (std::length_error){
		ret1 = 0;
	}
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	double ret2;
	try {
		mvect.reserve(mvect.max_size() + 1);
		ret2 = mvect.capacity();
	}
	catch (std::length_error){
		ret2 = 0;
	}
	time2 = std::time(NULL) - time2;

	//get diff time
	std::time_t diff = time2 - time1;

	//ret
	if (ret1 == ret2){
		std::cout << "\033[32mOK\033[0m - \033[33m" << diff << " ms\033[0m" << std::endl;
		return true;
	}
	std::cout << "\033[31mKO\033[0m" << std::endl;
	return false;
}

bool	reserve_zero_cleared_vector(){
	std::cout << "\033[0;1mTest 7\033[0m - ";
	std::vector<int>		rvect(5, 0);
	ft::vector<int>			mvect(5, 0);
	rvect.clear();
	mvect.clear();

	//std test
	std::time_t time1 = std::time(NULL);
	rvect.reserve(0);
	double ret1 = rvect.capacity();
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	mvect.reserve(0);
	double ret2 = mvect.capacity();
	time2 = std::time(NULL) - time2;

	//get diff time
	std::time_t diff = time2 - time1;

	//ret
	if (ret1 == ret2){
		std::cout << "\033[32mOK\033[0m - \033[33m" << diff << " ms\033[0m" << std::endl;
		return true;
	}
	std::cout << "\033[31mKO\033[0m" << std::endl;
	return false;
}

bool	reserve_cleared_vector(){
	std::cout << "\033[0;1mTest 8\033[0m - ";
	std::vector<int>		rvect(5, 0);
	ft::vector<int>			mvect(5, 0);
	rvect.clear();
	mvect.clear();

	//std test
	std::time_t time1 = std::time(NULL);
	rvect.reserve(10);
	double ret1 = rvect.capacity();
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	mvect.reserve(10);
	double ret2 = mvect.capacity();
	time2 = std::time(NULL) - time2;

	//get diff time
	std::time_t diff = time2 - time1;

	//ret
	if (ret1 == ret2){
		std::cout << "\033[32mOK\033[0m - \033[33m" << diff << " ms\033[0m" << std::endl;
		return true;
	}
	std::cout << "\033[31mKO\033[0m" << std::endl;
	return false;
}

bool	reserve_test_vector(){
	std::cout << std::endl << "\033[34;1mReserve() :\033[0m" << std::endl;
	bool ret = true;
	if (reserve_empty_vector() == false)
		ret = false;
	if (reserve_zero_empty_vector() == false)
		ret = false;
	if (reserve_filled_vector() == false)
		ret = false;
	if (reserve_zero_filled_vector() == false)
		ret = false;
	if (reserve_max_size_vector() == false)
		ret = false;
	if (reserve_more_maxsize_vector() == false)
		ret = false;
	if (reserve_zero_cleared_vector() == false)
		ret = false;
	if (reserve_cleared_vector() == false)
		ret = false;
	if (ret == false)
		return (print_function_ko());
	else
		return (print_function_ok());	
}