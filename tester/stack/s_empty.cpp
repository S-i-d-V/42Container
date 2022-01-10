/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_empty.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 02:43:24 by user42            #+#    #+#             */
/*   Updated: 2022/01/10 14:53:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.hpp"

bool	empty_empty_stack(){
	std::cout << "\033[0;1mTest 1\033[0m - ";
	std::stack<int>		rstack;
	ft::stack<int>		mstack;

	//std test
	std::time_t time1 = std::time(NULL);
	bool ret1 = rstack.empty();
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	bool ret2 = mstack.empty();
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

bool	empty_filled_stack(){
	std::cout << "\033[0;1mTest 2\033[0m - ";
	std::stack<int>		rstack;
	ft::stack<int>		mstack;
	for (int i = 0; i < 10; i++){
		rstack.push(i);
		mstack.push(i);
	}

	//std test
	std::time_t time1 = std::time(NULL);
	bool ret1 = rstack.empty();
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	bool ret2 = mstack.empty();
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

bool	empty_cleared_filled_stack(){
	std::cout << "\033[0;1mTest 3\033[0m - ";
	std::stack<int>		rstack;
	ft::stack<int>		mstack;
	for (int i = 0; i < 10; i++){
		rstack.push(i);
		mstack.push(i);
	}
	for (int i = 0; i < 10; i++){
		rstack.pop();
		mstack.pop();
	}
	
	//std test
	std::time_t time1 = std::time(NULL);
	bool ret1 = rstack.empty();
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	bool ret2 = mstack.empty();
	time2 = std::time(NULL) - time2;

	//get diff time
	std::time_t diff = (time1 - time2);

	//ret
	if (ret1 == ret2){
		std::cout << "\033[32mOK\033[0m - \033[33m" << diff << " ms\033[0m" << std::endl;
		return true;
	}
	std::cout << "\033[31mKO\033[0m" << std::endl;
	return false;
}

bool	empty_test_stack(){
	std::cout << "\033[34;1mEmpty() :\033[0m" << std::endl;
	bool ret = true;
	if (empty_empty_stack() == false)
		ret = false;
	if (empty_filled_stack() == false)
		ret = false;
	if (empty_cleared_filled_stack() == false)
		ret = false;
	if (ret == false)
		return (print_function_ko());
	else
		return (print_function_ok());
}
