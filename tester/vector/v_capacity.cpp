/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_capacity.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:05:17 by user42            #+#    #+#             */
/*   Updated: 2022/01/10 20:19:43 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.hpp"

bool	capacity_empty_vector(){
	std::cout << "\033[0;1mTest 1\033[0m - ";
	std::vector<int>		rvect;
	ft::vector<int>			mvect;

	//std test
	std::time_t time1 = std::time(NULL);
	double ret1 = rvect.capacity();
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
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

bool	capacity_cleared_vector(){
	std::cout << "\033[0;1mTest 2\033[0m - ";
	std::vector<int>		rvect;
	ft::vector<int>			mvect;

	rvect.assign(25, 1);
	mvect.assign(25, 1);
	rvect.clear();
	mvect.clear();

	//std test
	std::time_t time1 = std::time(NULL);
	double ret1 = rvect.capacity();
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
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

bool	capacity_reserved_zero_vector(){
	std::cout << "\033[0;1mTest 3\033[0m - ";
	std::vector<int>		rvect;
	ft::vector<int>			mvect;

	rvect.assign(25, 1);
	mvect.assign(25, 1);
	rvect.clear();
	mvect.clear();
	rvect.reserve(0);
	mvect.reserve(0);

	//std test
	std::time_t time1 = std::time(NULL);
	double ret1 = rvect.capacity();
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
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

bool	capacity_1elem_vector(){
	std::cout << "\033[0;1mTest 4\033[0m - ";
	std::vector<int>		rvect;
	ft::vector<int>			mvect;

	rvect.push_back(1);
	mvect.push_back(1);

	//std test
	std::time_t time1 = std::time(NULL);
	double ret1 = rvect.capacity();
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
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

bool	capacity_multiple_realoccation_vector(){
	std::cout << "\033[0;1mTest 5\033[0m - ";
	std::vector<int>		rvect;
	ft::vector<int>			mvect;
	for (int i = 0; i < 10; i++){
		rvect.push_back(1);
		mvect.push_back(1);
	}

	//std test
	std::time_t time1 = std::time(NULL);
	double ret1 = rvect.capacity();
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
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

bool	capacity_filled_vector(){
	std::cout << "\033[0;1mTest 6\033[0m - ";
	std::vector<int>		rvect(5, 0);
	ft::vector<int>			mvect(5, 0);

	//std test
	std::time_t time1 = std::time(NULL);
	double ret1 = rvect.capacity();
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
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

bool	capacity_filled_cleared_vector(){
	std::cout << "\033[0;1mTest 7\033[0m - ";
	std::vector<int>		rvect(5, 0);
	ft::vector<int>			mvect(5, 0);
	rvect.clear();
	mvect.clear();

	//std test
	std::time_t time1 = std::time(NULL);
	double ret1 = rvect.capacity();
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
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

bool	capacity_insert_realoc_vector(){
	std::cout << "\033[0;1mTest 8\033[0m - ";
	std::vector<int>		rvect;
	ft::vector<int>			mvect;
	for (int i = 0; i < 10; i++){
		rvect.push_back(1);
		mvect.push_back(1);
	}
	rvect.insert(rvect.begin(), 32, 5);
	mvect.insert(mvect.begin(), 32, 5);

	//std test
	std::time_t time1 = std::time(NULL);
	double ret1 = rvect.capacity();
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
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

bool	capacity_insert_bigrealoc_vector(){
	std::cout << "\033[0;1mTest 9\033[0m - ";
	std::vector<int>		rvect;
	ft::vector<int>			mvect;
	for (int i = 0; i < 10; i++){
		rvect.push_back(1);
		mvect.push_back(1);
	}
	rvect.insert(rvect.begin(), 320, 5);
	mvect.insert(mvect.begin(), 320, 5);

	//std test
	std::time_t time1 = std::time(NULL);
	double ret1 = rvect.capacity();
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
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

bool	capacity_test_vector(){
	std::cout << std::endl << "\033[34;1mCapacity() :\033[0m" << std::endl;
	bool ret = true;
	if (capacity_empty_vector() == false)
		ret = false;
	if (capacity_cleared_vector() == false)
		ret = false;
	if (capacity_reserved_zero_vector() == false)
		ret = false;
	if (capacity_1elem_vector() == false)
		ret = false;
	if (capacity_multiple_realoccation_vector() == false)
		ret = false;
	if (capacity_filled_vector() == false)
		ret = false;
	if (capacity_filled_cleared_vector() == false)
		ret = false;
	if (capacity_insert_realoc_vector() == false)
		ret = false;
	if (capacity_insert_bigrealoc_vector() == false)
		ret = false;
	if (ret == false)
		return (print_function_ko());
	else
		return (print_function_ok());	
}