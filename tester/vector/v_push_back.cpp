/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_push_back.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:22:56 by user42            #+#    #+#             */
/*   Updated: 2022/01/13 14:28:26 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.hpp"

bool	push_back_empty_vector(){
	std::cout << "\033[0;1mTest 1\033[0m - ";
	std::vector<int>		rvect;
	ft::vector<int>		mvect;

	//std test
	std::time_t time1 = std::time(NULL);
	rvect.push_back(1);
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	mvect.push_back(1);
	time2 = std::time(NULL) - time2;

	//get diff time
	std::time_t diff = time2 - time1;

	//ret
	if (rvect.size() == mvect.size() && rvect.empty() == mvect.empty() && rvect.back() == mvect.back()){
		std::cout << "\033[32mOK\033[0m - \033[33m" << diff << " ms\033[0m" << std::endl;
		return true;
	}
	std::cout << "\033[31mKO\033[0m" << std::endl;
	return false;
}

bool	push_back_filled_vector(){
	std::cout << "\033[0;1mTest 2\033[0m - ";
	std::vector<int>		rvect(25, 2);
	ft::vector<int>		mvect(25, 2);

	//std test
	std::time_t time1 = std::time(NULL);
	rvect.push_back(1);
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	mvect.push_back(1);
	time2 = std::time(NULL) - time2;

	//get diff time
	std::time_t diff = time2 - time1;

	//ret
	if (rvect.size() == mvect.size() && rvect.empty() == mvect.empty() && rvect.back() == mvect.back()){
		std::cout << "\033[32mOK\033[0m - \033[33m" << diff << " ms\033[0m" << std::endl;
		return true;
	}
	std::cout << "\033[31mKO\033[0m" << std::endl;
	return false;
}

bool	push_back_cleared_vector(){
	std::cout << "\033[0;1mTest 3\033[0m - ";
	std::vector<int>		rvect(25, 2);
	ft::vector<int>		mvect(25, 2);
	mvect.clear();
	rvect.clear();

	//std test
	std::time_t time1 = std::time(NULL);
	rvect.push_back(1);
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	mvect.push_back(1);
	time2 = std::time(NULL) - time2;

	//get diff time
	std::time_t diff = time2 - time1;

	//ret
	if (rvect.size() == mvect.size() && rvect.empty() == mvect.empty() && rvect.back() == mvect.back()){
		std::cout << "\033[32mOK\033[0m - \033[33m" << diff << " ms\033[0m" << std::endl;
		return true;
	}
	std::cout << "\033[31mKO\033[0m" << std::endl;
	return false;
}

bool	push_back_test_vector(){
	std::cout << std::endl << "\033[34;1mPush_back() :\033[0m" << std::endl;
	bool ret = true;
	if (push_back_empty_vector() == false)
		ret = false;
	if (push_back_filled_vector() == false)
		ret = false;
	if (push_back_cleared_vector() == false)
		ret = false;
	if (ret == false)
		return (print_function_ko());
	else
		return (print_function_ok());
}