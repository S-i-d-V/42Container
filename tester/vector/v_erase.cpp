/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_erase.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:45:19 by user42            #+#    #+#             */
/*   Updated: 2022/01/13 15:04:44 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.hpp"

bool	erase_entire_filled_vector(){
	std::cout << "\033[0;1mTest 1\033[0m - ";
	std::vector<int>		rvect(25, 5);
	ft::vector<int>		mvect(25, 5);

	//std test
	std::time_t time1 = std::time(NULL);
	rvect.erase(rvect.begin(), rvect.end());
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	mvect.erase(mvect.begin(), mvect.end());
	time2 = std::time(NULL) - time2;

	//get diff time
	std::time_t diff = time2 - time1;

	//ret
	if (rvect.size() == mvect.size() && rvect.empty() == mvect.empty()){
		std::cout << "\033[32mOK\033[0m - \033[33m" << diff << " ms\033[0m" << std::endl;
		return true;
	}
	std::cout << "\033[31mKO\033[0m" << std::endl;
	return false;
}

bool	erase_part_filled_vector(){
	std::cout << "\033[0;1mTest 2\033[0m - ";
	std::vector<int>		rvect(25, 5);
	ft::vector<int>		mvect(25, 5);

	//std test
	std::time_t time1 = std::time(NULL);
	rvect.erase(rvect.begin(), rvect.begin() + 3);
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	mvect.erase(mvect.begin(), mvect.begin() + 3);
	time2 = std::time(NULL) - time2;

	//get diff time
	std::time_t diff = time2 - time1;

	//ret
	if (rvect.size() == mvect.size() && rvect.empty() == mvect.empty()){
		std::cout << "\033[32mOK\033[0m - \033[33m" << diff << " ms\033[0m" << std::endl;
		return true;
	}
	std::cout << "\033[31mKO\033[0m" << std::endl;
	return false;
}

bool	erase_last_element_vector(){
	std::cout << "\033[0;1mTest 2\033[0m - ";
	std::vector<int>		rvect;
	ft::vector<int>		mvect;
	rvect.push_back(1);
	mvect.push_back(1);
	rvect.push_back(2);
	mvect.push_back(2);
	rvect.push_back(3);
	mvect.push_back(3);

	//std test
	std::time_t time1 = std::time(NULL);
	rvect.erase(rvect.end() - 1);
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	mvect.erase(mvect.end() - 1);
	time2 = std::time(NULL) - time2;

	//get diff time
	std::time_t diff = time2 - time1;

	//ret
	if (rvect.size() == mvect.size() && rvect.empty() == mvect.empty()){
		std::cout << "\033[32mOK\033[0m - \033[33m" << diff << " ms\033[0m" << std::endl;
		return true;
	}
	std::cout << "\033[31mKO\033[0m" << std::endl;
	return false;
}

bool	erase_first_element_vector(){
	std::cout << "\033[0;1mTest 2\033[0m - ";
	std::vector<int>		rvect;
	ft::vector<int>		mvect;
	rvect.push_back(1);
	mvect.push_back(1);
	rvect.push_back(2);
	mvect.push_back(2);
	rvect.push_back(3);
	mvect.push_back(3);

	//std test
	std::time_t time1 = std::time(NULL);
	rvect.erase(rvect.begin());
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	mvect.erase(mvect.begin());
	time2 = std::time(NULL) - time2;

	//get diff time
	std::time_t diff = time2 - time1;

	//ret
	if (rvect.size() == mvect.size() && rvect.empty() == mvect.empty()){
		std::cout << "\033[32mOK\033[0m - \033[33m" << diff << " ms\033[0m" << std::endl;
		return true;
	}
	std::cout << "\033[31mKO\033[0m" << std::endl;
	return false;
}

bool	erase_test_vector(){
	std::cout << std::endl << "\033[34;1mErase() :\033[0m" << std::endl;
	bool ret = true;
	if (erase_entire_filled_vector() == false)
		ret = false;
	if (erase_part_filled_vector() == false)
		ret = false;
	if (erase_last_element_vector() == false)
		ret = false;
	if (erase_first_element_vector() == false)
		ret = false;
	if (ret == false)
		return (print_function_ko());
	else
		return (print_function_ok());
}