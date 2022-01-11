/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_size.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 01:57:16 by user42            #+#    #+#             */
/*   Updated: 2022/01/11 22:04:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.hpp"

bool	size_empty_vector(){
	std::cout << "\033[0;1mTest 1\033[0m - ";
	std::vector<int>		rvect;
	ft::vector<int>			mvect;

	//std test
	std::time_t time1 = std::time(NULL);
	double ret1 = rvect.size();
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	double ret2 = mvect.size();
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

bool	size_filled_vector(){
	std::cout << "\033[0;1mTest 2\033[0m - ";
	std::vector<int>		rvect(25, 1);
	ft::vector<int>			mvect(25, 1);

	//std test
	std::time_t time1 = std::time(NULL);
	double ret1 = rvect.size();
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	double ret2 = mvect.size();
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

bool	size_cleared_vector(){
	std::cout << "\033[0;1mTest 3\033[0m - ";
	std::vector<int>		rvect(25, 1);
	ft::vector<int>			mvect(25, 1);
	rvect.clear();
	mvect.clear();

	//std test
	std::time_t time1 = std::time(NULL);
	double ret1 = rvect.size();
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	double ret2 = mvect.size();
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

bool	size_resize_zero_vector(){
	std::cout << "\033[0;1mTest 4\033[0m - ";
	std::vector<int>		rvect(25, 1);
	ft::vector<int>			mvect(25, 1);
	rvect.resize(0);
	mvect.resize(0);
	
	//std test
	std::time_t time1 = std::time(NULL);
	double ret1 = rvect.size();
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	double ret2 = mvect.size();
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

bool	size_resized_vector(){
	std::cout << "\033[0;1mTest 5\033[0m - ";
	std::vector<int>		rvect(25, 1);
	ft::vector<int>			mvect(25, 1);
	rvect.clear();
	mvect.clear();
	rvect.resize(10);
	mvect.resize(10);

	//std test
	std::time_t time1 = std::time(NULL);
	double ret1 = rvect.size();
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	double ret2 = mvect.size();
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

bool	size_test_vector(){
	std::cout << std::endl << "\033[34;1mSize() :\033[0m" << std::endl;
	bool ret = true;
	if (size_empty_vector() == false)
		ret = false;
	if (size_filled_vector() == false)
		ret = false;
	if (size_cleared_vector() == false)
		ret = false;
	if (size_resize_zero_vector() == false)
		ret = false;
	if (size_resized_vector() == false)
		ret = false;
	if (ret == false)
		return (print_function_ko());
	else
		return (print_function_ok());	
}