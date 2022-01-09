/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_push.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:41:46 by user42            #+#    #+#             */
/*   Updated: 2022/01/09 01:10:46 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.hpp"

bool	push_single_element_stack(){
	std::cout << "\033[0;1mTest 1\033[0m - ";
	std::stack<int>		rstack;
	ft::stack<int>		mstack;

	//std test
	std::time_t time1 = std::time(NULL);
	rstack.push(1);
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	mstack.push(1);
	time2 = std::time(NULL) - time2;

	//get diff time
	std::time_t diff = time2 - time1;

	//ret
	if (rstack.top() == mstack.top() || rstack.size() == mstack.size()){
		std::cout << "\033[32mOK\033[0m - \033[33m" << diff << " ms\033[0m" << std::endl;
		return true;
	}
	std::cout << "\033[31mKO\033[0m" << std::endl;
	return false;
}

bool	push_on_cleared_stack(){
	std::cout << "\033[0;1mTest 2\033[0m - ";
	std::stack<int>		rstack;
	ft::stack<int>		mstack;
	rstack.push(0);
	mstack.push(0);
	rstack.pop();
	mstack.pop();

	//std test
	std::time_t time1 = std::time(NULL);
	rstack.push(1);
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	mstack.push(1);
	time2 = std::time(NULL) - time2;

	//get diff time
	std::time_t diff = time2 - time1;

	//ret
	if (rstack.top() == mstack.top() || rstack.size() == mstack.size()){
		std::cout << "\033[32mOK\033[0m - \033[33m" << diff << " ms\033[0m" << std::endl;
		return true;
	}
	std::cout << "\033[31mKO\033[0m" << std::endl;
	return false;
}

bool	push_1000_element_stack(){
	std::cout << "\033[0;1mTest 3\033[0m - ";
	std::stack<int>		rstack;
	ft::stack<int>		mstack;

	//std test
	std::time_t time1 = std::time(NULL);
	for (int i = 0; i < 1000; i++)
		rstack.push(i);
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	for (int i = 0; i < 1000; i++)
		mstack.push(i);
	time2 = std::time(NULL) - time2;

	//get diff time
	std::time_t diff = time2 - time1;

	//ret
	for (int i = 0; i < 999; i++){
		if (rstack.top() != mstack.top() || rstack.size() != mstack.size()){
			std::cout << "\033[31mKO\033[0m" << std::endl;
			return false;
		}
		rstack.pop();
		mstack.pop();
	}
	std::cout << "\033[32mOK\033[0m - \033[33m" << diff << " ms\033[0m" << std::endl;
	return true;
}

bool	push_10000000_element_stack(){
	std::cout << "\033[0;1mTest 4\033[0m - ";
	std::stack<int>		rstack;
	ft::stack<int>		mstack;

	//std test
	std::time_t time1 = std::time(NULL);
	for (int i = 0; i < 10000000; i++)
		rstack.push(i);
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	for (int i = 0; i < 10000000; i++)
		mstack.push(i);
	time2 = std::time(NULL) - time2;

	//get diff time
	std::time_t diff = time2 - time1;

	//ret
	for (int i = 0; i < 9999999; i++){
		if (rstack.top() != mstack.top() || rstack.size() != mstack.size()){
			std::cout << "\033[31mKO\033[0m" << std::endl;
			return false;
		}
		rstack.pop();
		mstack.pop();
	}
	std::cout << "\033[32mOK\033[0m - \033[33m" << diff << " ms\033[0m" << std::endl;
	return true;
}

bool	push_test_stack(){
	std::cout << std::endl << "\033[34;1mPush() :\033[0m" << std::endl;
	bool ret = true;
	if (push_single_element_stack() == false)
		ret = false;
	if (push_on_cleared_stack() == false)
		ret = false;
	if (push_1000_element_stack() == false)
		ret = false;
	if (push_10000000_element_stack() == false)
		ret = false;
	if (ret == false)
		return (print_function_ko());
	else
		return (print_function_ok());
}