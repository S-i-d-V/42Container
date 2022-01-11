/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_resize.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 01:57:16 by user42            #+#    #+#             */
/*   Updated: 2022/01/11 02:43:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.hpp"

bool	 resize_empty_vector(){
	std::cout << "\033[0;1mTest 1\033[0m - ";
	std::vector<int>		rvect;
	ft::vector<int>			mvect;

	//std test
	std::time_t time1 = std::time(NULL);
	rvect.resize(10);
	time1 = std::time(NULL) - time1;
	double ret1 = rvect.size();

	//ft test
	std::time_t time2 = std::time(NULL);
	mvect.resize(10);
	time2 = std::time(NULL) - time2;
	double ret2 = mvect.size();

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

bool	 resize_zero_empty_vector(){
	std::cout << "\033[0;1mTest 2\033[0m - ";
	std::vector<int>		rvect;
	ft::vector<int>			mvect;

	//std test
	std::time_t time1 = std::time(NULL);
	rvect.resize(0);
	time1 = std::time(NULL) - time1;
	double ret1 = rvect.size();

	//ft test
	std::time_t time2 = std::time(NULL);
	mvect.resize(0);
	time2 = std::time(NULL) - time2;
	double ret2 = mvect.size();

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

bool	 resize_filled_vector(){
	std::cout << "\033[0;1mTest 3\033[0m - ";
	std::vector<int>		rvect(15, 0);
	ft::vector<int>			mvect(15, 0);

	//std test
	std::time_t time1 = std::time(NULL);
	rvect.resize(10);
	time1 = std::time(NULL) - time1;
	double ret1 = rvect.size();

	//ft test
	std::time_t time2 = std::time(NULL);
	mvect.resize(10);
	time2 = std::time(NULL) - time2;
	double ret2 = mvect.size();

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

bool	 resize_zero_filled_vector(){
	std::cout << "\033[0;1mTest 4\033[0m - ";
	std::vector<int>		rvect(15, 0);
	ft::vector<int>			mvect(15, 0);

	//std test
	std::time_t time1 = std::time(NULL);
	rvect.resize(0);
	time1 = std::time(NULL) - time1;
	double ret1 = rvect.size();

	//ft test
	std::time_t time2 = std::time(NULL);
	mvect.resize(0);
	time2 = std::time(NULL) - time2;
	double ret2 = mvect.size();

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

bool	 resize_cleared_vector(){
	std::cout << "\033[0;1mTest 5\033[0m - ";
	std::vector<int>		rvect(15, 0);
	ft::vector<int>			mvect(15, 0);
	rvect.clear();
	mvect.clear();

	//std test
	std::time_t time1 = std::time(NULL);
	rvect.resize(10);
	time1 = std::time(NULL) - time1;
	double ret1 = rvect.size();

	//ft test
	std::time_t time2 = std::time(NULL);
	mvect.resize(10);
	time2 = std::time(NULL) - time2;
	double ret2 = mvect.size();

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

bool	 resize_zero_cleared_vector(){
	std::cout << "\033[0;1mTest 6\033[0m - ";
	std::vector<int>		rvect(15, 0);
	ft::vector<int>			mvect(15, 0);
	rvect.clear();
	mvect.clear();

	//std test
	std::time_t time1 = std::time(NULL);
	rvect.resize(0);
	time1 = std::time(NULL) - time1;
	double ret1 = rvect.size();

	//ft test
	std::time_t time2 = std::time(NULL);
	mvect.resize(0);
	time2 = std::time(NULL) - time2;
	double ret2 = mvect.size();

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


bool	resize_test_vector(){
	std::cout << std::endl << "\033[34;1mResize() :\033[0m" << std::endl;
	bool ret = true;
	if (resize_empty_vector() == false)
		ret = false;
	if (resize_zero_empty_vector() == false)
		ret = false;
	if (resize_filled_vector() == false)
		ret = false;
	if (resize_zero_filled_vector() == false)
		ret = false;
	if (resize_cleared_vector() == false)
		ret = false;
	if (resize_zero_cleared_vector() == false)
		ret = false;
	if (ret == false)
		return (print_function_ko());
	else
		return (print_function_ok());	
}