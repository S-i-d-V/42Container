/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_access.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 02:47:04 by user42            #+#    #+#             */
/*   Updated: 2022/01/13 13:39:09 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.hpp"

bool	access_front_vector(){
	std::cout << "\033[0;1mTest 1\033[0m - ";
	std::vector<int>		rvect;
	ft::vector<int>			mvect;
	for (int i = 0; i < 10; i++){
		rvect.push_back(i);
		mvect.push_back(i);
	}

	//std test
	std::time_t time1 = std::time(NULL);
	int ret1 = rvect.front();
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	int ret2 = mvect.front();
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

bool	access_back_vector(){
	std::cout << "\033[0;1mTest 2\033[0m - ";
	std::vector<int>		rvect;
	ft::vector<int>			mvect;
	for (int i = 0; i < 10; i++){
		rvect.push_back(i);
		mvect.push_back(i);
	}

	//std test
	std::time_t time1 = std::time(NULL);
	int ret1 = rvect.back();
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	int ret2 = mvect.back();
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

bool	access_at_vector(){
	std::cout << "\033[0;1mTest 3\033[0m - ";
	std::vector<int>		rvect;
	ft::vector<int>			mvect;
	for (int i = 0; i < 10; i++){
		rvect.push_back(i);
		mvect.push_back(i);
	}

	//std test
	std::time_t time1 = std::time(NULL);
	int ret1 = rvect.at(5);
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	int ret2 = mvect.at(5);
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

bool	access_at_out_vector(){
	std::cout << "\033[0;1mTest 4\033[0m - ";
	std::vector<int>		rvect;
	ft::vector<int>			mvect;
	for (int i = 0; i < 10; i++){
		rvect.push_back(i);
		mvect.push_back(i);
	}

	//std test
	std::time_t time1 = std::time(NULL);
	int ret1;
	try {
		ret1 = rvect.at(15);
	}
	catch (std::exception const &e){
		ret1 = -999;
	}
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	int ret2;
	try {
		ret2 = mvect.at(15);
	}
	catch (std::exception const &e){
		ret2 = -999;
	}
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

bool	access_operator_vector(){
	std::cout << "\033[0;1mTest 5\033[0m - ";
	std::vector<int>		rvect;
	ft::vector<int>			mvect;
	for (int i = 0; i < 10; i++){
		rvect.push_back(i);
		mvect.push_back(i);
	}

	//std test
	std::time_t time1 = std::time(NULL);
	int ret1 = rvect[5];
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	int ret2 = mvect[5];
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

bool	access_test_vector(){
	std::cout << std::endl << "\033[34;1mAccess :\033[0m" << std::endl;
	bool ret = true;
	if (access_front_vector() == false)
		ret = false;
	if (access_back_vector() == false)
		ret = false;
	if (access_at_vector() == false)
		ret = false;
	if (access_at_out_vector() == false)
		ret = false;
	if (access_operator_vector() == false)
		ret = false;
	if (ret == false)
		return (print_function_ko());
	else
		return (print_function_ok());	
}