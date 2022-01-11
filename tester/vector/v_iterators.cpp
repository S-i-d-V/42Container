/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_iterators.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:26:26 by user42            #+#    #+#             */
/*   Updated: 2022/01/12 00:09:29 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.hpp"

bool	iterator_begin_vector(){
	std::cout << "\033[0;1mTest 1\033[0m - ";
	std::vector<int>	rvect(25, 5);
	ft::vector<int>		mvect(25, 5);

	//std test
	std::time_t time1 = std::time(NULL);
	int ret1 = *rvect.begin();
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	int ret2 = *mvect.begin();
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

bool	iterator_end_vector(){
	std::cout << "\033[0;1mTest 2\033[0m - ";
	std::vector<int>	rvect(25, 5);
	ft::vector<int>		mvect(25, 5);

	//std test
	std::time_t time1 = std::time(NULL);
	int ret1 = *rvect.end();
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	int ret2 = *mvect.end();
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

bool	iterator_iterating_vector(){
	std::cout << "\033[0;1mTest 3\033[0m - ";
	std::vector<int>	rvect(25, 5);
	ft::vector<int>		mvect(25, 5);

	//std test
	std::time_t time1 = std::time(NULL);
	std::vector<int>::iterator rit = rvect.begin();
	size_t ret1 = 0;
	while (rit != rvect.end()){
		rit++;
		ret1++;
	}
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	ft::vector<int>::iterator mit = mvect.begin();
	size_t ret2 = 0;
	while (mit != mvect.end()){
		mit++;
		ret2++;
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

bool	iterator_iterating_empty_vector(){
	std::cout << "\033[0;1mTest 4\033[0m - ";
	std::vector<int>	rvect;
	ft::vector<int>		mvect;

	//std test
	std::time_t time1 = std::time(NULL);
	//int ret1 = *rvect.begin();
	std::vector<int>::iterator rit = rvect.begin();
	size_t ret1 = 0;
	while (rit != rvect.end()){
		rit++;
		ret1++;
	}
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	ft::vector<int>::iterator mit = mvect.begin();
	size_t ret2 = 0;
	while (mit != mvect.end()){
		mit++;
		ret2++;
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

bool	iterator_checking_vector(){
	std::cout << "\033[0;1mTest 5\033[0m - ";
	std::vector<int>	rvect(25, 0);
	ft::vector<int>		mvect(25, 0);
	
	//std test
	std::time_t time1 = std::time(NULL);
	//int ret1 = *rvect.begin();
	std::vector<int>::iterator rit = rvect.begin();
	bool ret1 = true;
	while (rit != rvect.end()){
		if (*rit != 0)
			ret1 = false;
		rit++;
	}
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	ft::vector<int>::iterator mit = mvect.begin();
	bool ret2 = true;
	while (mit != mvect.end()){
		if (*mit != 0)
			ret1 = false;
		mit++;
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

bool	iterator_checking_cleared_vector(){
	std::cout << "\033[0;1mTest 6\033[0m - ";
	std::vector<int>	rvect(25, 0);
	ft::vector<int>		mvect(25, 0);
	mvect.clear();
	rvect.clear();

	//std test
	std::time_t time1 = std::time(NULL);
	//int ret1 = *rvect.begin();
	std::vector<int>::iterator rit = rvect.begin();
	bool ret1 = true;
	while (rit != rvect.end()){
		if (*rit != 0)
			ret1 = false;
		rit++;
	}
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	ft::vector<int>::iterator mit = mvect.begin();
	bool ret2 = true;
	while (mit != mvect.end()){
		if (*mit != 0)
			ret1 = false;
		mit++;
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

bool	iterator_plus_overload_vector(){
	std::cout << "\033[0;1mTest 6\033[0m - ";
	std::vector<int>	rvect(25, 5);
	ft::vector<int>		mvect(25, 5);
	mvect.clear();
	rvect.clear();

	//std test
	std::time_t time1 = std::time(NULL);
	//int ret1 = *rvect.begin();
	std::vector<int>::iterator rit = rvect.begin();
	int ret1 = *(rit + 3);
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	ft::vector<int>::iterator mit = mvect.begin();
	int ret2 = *(mit + 3);
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

bool	iterator_sub_overload_vector(){
	std::cout << "\033[0;1mTest 7\033[0m - ";
	std::vector<int>	rvect(25, 5);
	ft::vector<int>		mvect(25, 5);
	mvect.clear();
	rvect.clear();

	//std test
	std::time_t time1 = std::time(NULL);
	std::vector<int>::iterator rit = rvect.end();
	int ret1 = *(rit - 3);
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	ft::vector<int>::iterator mit = mvect.end();
	int ret2 = *(mit - 3);
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

bool	iterator_plusequal_overload_vector(){
	std::cout << "\033[0;1mTest 8\033[0m - ";
	std::vector<int>	rvect(25, 5);
	ft::vector<int>		mvect(25, 5);
	mvect.clear();
	rvect.clear();

	//std test
	std::time_t time1 = std::time(NULL);
	std::vector<int>::iterator rit = rvect.begin();
	rit += 3;
	int ret1 = *rit;
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	ft::vector<int>::iterator mit = mvect.begin();
	mit += 3;
	int ret2 = *mit;
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

bool	iterator_subequal_overload_vector(){
	std::cout << "\033[0;1mTest 9\033[0m - ";
	std::vector<int>	rvect(25, 5);
	ft::vector<int>		mvect(25, 5);
	mvect.clear();
	rvect.clear();

	//std test
	std::time_t time1 = std::time(NULL);
	std::vector<int>::iterator rit = rvect.end();
	rit -= 3;
	int ret1 = *rit;
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	ft::vector<int>::iterator mit = mvect.end();
	mit -= 3;
	int ret2 = *mit;
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

bool	iterator_test_vector(){
	std::cout  << "\033[34;1mIterators :\033[0m" << std::endl;
	bool ret = true;
	if (iterator_begin_vector() == false)
		ret = false;
	if (iterator_end_vector() == false)
		ret = false;
	if (iterator_iterating_vector() == false)
		ret = false;
	if (iterator_iterating_empty_vector() == false)
		ret = false;
	if (iterator_checking_vector() == false)
		ret = false;
	if (iterator_checking_cleared_vector() == false)
		ret = false;
	if (iterator_plus_overload_vector() == false)
		ret = false;
	if (iterator_sub_overload_vector() == false)
		ret = false;
	if (iterator_plusequal_overload_vector() == false)
		ret = false;
	if (iterator_subequal_overload_vector() == false)
		ret = false;
	if (ret == false)
		return (print_function_ko());
	else
		return (print_function_ok());
}