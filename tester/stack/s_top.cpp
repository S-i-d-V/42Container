/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_top.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:18:02 by user42            #+#    #+#             */
/*   Updated: 2022/01/08 22:04:09 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_stack.hpp"

bool	top_single_elem_stack(){
	std::cout << "\033[0;1mTest 1\033[0m - ";
	std::stack<int>		rstack;
	ft::stack<int>		mstack;
	rstack.push(1);
	mstack.push(1);

	//std test
	std::time_t time1 = std::time(NULL);
	int ret1 = rstack.top();
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	int ret2 = mstack.top();
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

bool	top_filled_stack(){
	std::cout << "\033[0;1mTest 2\033[0m - ";
	std::stack<int>		rstack;
	ft::stack<int>		mstack;
	for (int i = 0; i < 10; i++){
		rstack.push(i);
		mstack.push(i);
	}

	//std test
	std::time_t time1 = std::time(NULL);
	int ret1 = rstack.top();
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	int ret2 = mstack.top();
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

bool	top_cleared_stack(){
	std::cout << "\033[0;1mTest 3\033[0m - ";
	std::stack<int>		rstack;
	ft::stack<int>		mstack;
	for (int i = 0; i < 10; i++){
		rstack.push(i);
		mstack.push(i);
	}

	//std test
	std::time_t time1 = std::time(NULL);
	int ret1 = rstack.top();
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	int ret2 = mstack.top();
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

bool	top_test_stack(){
	std::cout << std::endl << "\033[34;1mTop() :\033[0m" << std::endl;
	bool ret = true;
	if (top_single_elem_stack() == false)
		ret = false;
	if (top_filled_stack() == false)
		ret = false;
	if (top_cleared_stack() == false)
		ret = false;
	if (ret == false)
		return (print_function_ko());
	else
		return (print_function_ok());
}