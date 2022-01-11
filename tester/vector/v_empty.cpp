/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_empty.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:41:01 by user42            #+#    #+#             */
/*   Updated: 2022/01/11 17:16:47 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.hpp"

bool	empty_empty_vector(){
	std::cout << "\033[0;1mTest 1\033[0m - ";
	std::vector<int>		rvect;
	ft::vector<int>		mvect;

	//std test
	std::time_t time1 = std::time(NULL);
	bool ret1 = rvect.empty();
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	bool ret2 = mvect.empty();
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

bool	empty_filled_vector(){
	std::cout << "\033[0;1mTest 2\033[0m - ";
	std::vector<int>		rvect(25, 0);
	ft::vector<int>		mvect(25, 0);

	//std test
	std::time_t time1 = std::time(NULL);
	bool ret1 = rvect.empty();
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	bool ret2 = mvect.empty();
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

bool	empty_cleared_filled_vector(){
	std::cout << "\033[0;1mTest 3\033[0m - ";
	std::vector<int>		rvect(25, 0);
	ft::vector<int>		mvect(25, 0);
	rvect.clear();
	mvect.clear();
	
	//std test
	std::time_t time1 = std::time(NULL);
	bool ret1 = rvect.empty();
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	bool ret2 = mvect.empty();
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

bool	empty_test_vector(){
	std::cout << std::endl << "\033[34;1mEmpty() :\033[0m" << std::endl;
	bool ret = true;
	if (empty_empty_vector() == false)
		ret = false;
	if (empty_filled_vector() == false)
		ret = false;
	if (empty_cleared_filled_vector() == false)
		ret = false;
	if (ret == false)
		return (print_function_ko());
	else
		return (print_function_ok());
}