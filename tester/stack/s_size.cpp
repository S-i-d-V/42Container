/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_size.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 02:43:24 by user42            #+#    #+#             */
/*   Updated: 2022/01/07 03:09:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_stack.hpp"

bool	size_empty_stack(){
	std::cout << "\033[0;1mTest 1\033[0m - ";
	std::stack<int>		rstack;
	ft::stack<int>		mstack;

	//std test
	std::time_t time1 = std::time(NULL);
	int ret1 = rstack.size();
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	int ret2 = mstack.size();
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

bool	stack_size_test(){
	std::cout << std::endl << "\033[34;1mSize() :\033[0m" << std::endl;
	if (size_empty_stack() == false)
		return (print_function_ko());
	return (print_function_ok());
}