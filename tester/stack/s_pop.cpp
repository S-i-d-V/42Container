/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_pop.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 22:07:04 by user42            #+#    #+#             */
/*   Updated: 2022/01/09 01:10:46 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.hpp"

bool	pop_single_element_stack(){
	std::cout << "\033[0;1mTest 1\033[0m - ";
	std::stack<int>		rstack;
	ft::stack<int>		mstack;
	rstack.push(1);
	mstack.push(1);

	//std test
	std::time_t time1 = std::time(NULL);
	rstack.pop();
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	mstack.pop();
	time2 = std::time(NULL) - time2;

	//get diff time
	std::time_t diff = time2 - time1;

	//ret
	if (rstack.size() != mstack.size()){
		std::cout << "\033[31mKO\033[0m" << std::endl;
		return false;
	}
	std::cout << "\033[32mOK\033[0m - \033[33m" << diff << " ms\033[0m" << std::endl;
	return true;
}

bool	pop_1000_element_stack(){
	std::cout << "\033[0;1mTest 2\033[0m - ";
	std::stack<int>		rstack;
	ft::stack<int>		mstack;
	for (int i = 0; i < 1000; i++)
		mstack.push(i);
	for (int i = 0; i < 1000; i++)
		rstack.push(i);

	//std test
	std::time_t time1 = std::time(NULL);
	for (int i = 0; i < 1000; i++)
		rstack.pop();
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	for (int i = 0; i < 1000; i++)
		mstack.pop();
	time2 = std::time(NULL) - time2;

	//get diff time
	std::time_t diff = time2 - time1;

	//ret
	if (rstack.size() != mstack.size()){
		std::cout << "\033[31mKO\033[0m" << std::endl;
		return false;
	}
	std::cout << "\033[32mOK\033[0m - \033[33m" << diff << " ms\033[0m" << std::endl;
	return true;
}

bool	pop_10000000_element_stack(){
	std::cout << "\033[0;1mTest 3\033[0m - ";
	std::stack<int>		rstack;
	ft::stack<int>		mstack;
	for (int i = 0; i < 10000000; i++)
		mstack.push(i);
	for (int i = 0; i < 10000000; i++)
		rstack.push(i);

	//std test
	std::time_t time1 = std::time(NULL);
	for (int i = 0; i < 10000000; i++)
		rstack.pop();
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	for (int i = 0; i < 10000000; i++)
		mstack.pop();
	time2 = std::time(NULL) - time2;

	//get diff time
	std::time_t diff = time2 - time1;

	//ret
	if (rstack.size() != mstack.size()){
		std::cout << "\033[31mKO\033[0m" << std::endl;
		return false;
	}
	std::cout << "\033[32mOK\033[0m - \033[33m" << diff << " ms\033[0m" << std::endl;
	return true;
}

bool	pop_test_stack(){
	std::cout << std::endl << "\033[34;1mPop() :\033[0m" << std::endl;
	bool ret = true;
	if (pop_single_element_stack() == false)
		ret = false;
	if (pop_1000_element_stack() == false)
		ret = false;
	if (pop_10000000_element_stack() == false)
		ret = false;
	if (ret == false)
		return (print_function_ko());
	else
		return (print_function_ok());
}