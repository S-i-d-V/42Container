/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_max_size.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:05:17 by user42            #+#    #+#             */
/*   Updated: 2022/01/11 02:34:23 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.hpp"

bool	max_size_empty_vector(){
	std::cout << "\033[0;1mTest 1\033[0m - ";
	std::vector<int>		rvect;
	ft::vector<int>			mvect;

	//std test
	std::time_t time1 = std::time(NULL);
	double ret1 = rvect.max_size();
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	double ret2 = mvect.max_size();
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

bool	max_size_pushed_vector(){
	std::cout << "\033[0;1mTest 2\033[0m - ";
	std::vector<int>		rvect;
	ft::vector<int>			mvect;
	rvect.push_back(1);
	mvect.push_back(1);

	//std test
	std::time_t time1 = std::time(NULL);
	double ret1 = rvect.max_size();
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	double ret2 = mvect.max_size();
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

bool	max_size_insert_vector(){
	std::cout << "\033[0;1mTest 3\033[0m - ";
	std::vector<int>		rvect;
	ft::vector<int>			mvect;
	rvect.assign(25, 1);
	mvect.assign(25, 1);

	//std test
	std::time_t time1 = std::time(NULL);
	double ret1 = rvect.max_size();
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	double ret2 = mvect.max_size();
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

bool	max_size_cleared_vector(){
	std::cout << "\033[0;1mTest 4\033[0m - ";
	std::vector<int>		rvect;
	ft::vector<int>			mvect;
	rvect.assign(25, 1);
	mvect.assign(25, 1);
	rvect.clear();
	mvect.clear();

	//std test
	std::time_t time1 = std::time(NULL);
	double ret1 = rvect.max_size();
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	double ret2 = mvect.max_size();
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

bool	max_size_test_vector(){
	std::cout << std::endl << "\033[34;1mMax_Size() :\033[0m" << std::endl;
	bool ret = true;
	if (max_size_empty_vector() == false)
		ret = false;
	if (max_size_pushed_vector() == false)
		ret = false;
	if (max_size_insert_vector() == false)
		ret = false;
	if (max_size_cleared_vector() == false)
		ret = false;
	if (ret == false)
		return (print_function_ko());
	else
		return (print_function_ok());	
}