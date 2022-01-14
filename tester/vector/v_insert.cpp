/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_insert.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:06:40 by user42            #+#    #+#             */
/*   Updated: 2022/01/14 00:51:58 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.hpp"

bool	insert_elem_front_vector(){
	std::cout << "\033[0;1mTest 1\033[0m - ";
	std::vector<int>		rvect(25, 5);
	ft::vector<int>		mvect(25, 5);

	//std test
	std::time_t time1 = std::time(NULL);
	rvect.insert(rvect.begin(), 1);
	int ret1 = rvect.front();
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	mvect.insert(mvect.begin(), 1);
	int ret2 = mvect.front();
	time2 = std::time(NULL) - time2;

	//get diff time
	std::time_t diff = time2 - time1;

	//ret
	if (ret1 == ret2 && rvect.size() == mvect.size() && rvect.empty() == mvect.empty()){
		std::cout << "\033[32mOK\033[0m - \033[33m" << diff << " ms\033[0m" << std::endl;
		return true;
	}
	std::cout << "\033[31mKO\033[0m" << std::endl;
	return false;
}

bool	insert_elem_back_vector(){
	std::cout << "\033[0;1mTest 2\033[0m - ";
	std::vector<int>		rvect(25, 5);
	ft::vector<int>		mvect(25, 5);

	//std test
	std::time_t time1 = std::time(NULL);
	rvect.insert(rvect.end(), 1);
	int ret1 = rvect.back();
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	mvect.insert(mvect.end(), 1);
	int ret2 = mvect.back();
	time2 = std::time(NULL) - time2;

	//get diff time
	std::time_t diff = time2 - time1;

	//ret
	if (ret1 == ret2 && rvect.size() == mvect.size() && rvect.empty() == mvect.empty()){
		std::cout << "\033[32mOK\033[0m - \033[33m" << diff << " ms\033[0m" << std::endl;
		return true;
	}
	std::cout << "\033[31mKO\033[0m" << std::endl;
	return false;
}

bool	insert_elem_in_vector(){
	std::cout << "\033[0;1mTest 3\033[0m - ";
	std::vector<int>		rvect(25, 5);
	ft::vector<int>		mvect(25, 5);

	//std test
	std::time_t time1 = std::time(NULL);
	rvect.insert(rvect.begin() + 5, 1);
	int ret1 = *(rvect.begin() + 5);
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	mvect.insert(mvect.begin() + 5, 1);
	int ret2 = *(mvect.begin() + 5);
	time2 = std::time(NULL) - time2;

	//get diff time
	std::time_t diff = time2 - time1;

	//ret
	if (ret1 == ret2 && rvect.size() == mvect.size() && rvect.empty() == mvect.empty()){
		std::cout << "\033[32mOK\033[0m - \033[33m" << diff << " ms\033[0m" << std::endl;
		return true;
	}
	std::cout << "\033[31mKO\033[0m" << std::endl;
	return false;
}

bool	insert_fill_in_vector(){
	std::cout << "\033[0;1mTest 4\033[0m - ";
	std::vector<int>		rvect(25, 5);
	ft::vector<int>		mvect(25, 5);

	//std test
	std::time_t time1 = std::time(NULL);
	rvect.insert(rvect.begin() + 5, 10, 1);
	int ret1 = *(rvect.begin() + 5);
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	mvect.insert(mvect.begin() + 5, 10, 1);
	int ret2 = *(mvect.begin() + 5);
	time2 = std::time(NULL) - time2;

	//get diff time
	std::time_t diff = time2 - time1;

	//ret
	if (ret1 == ret2 && rvect.size() == mvect.size() && rvect.empty() == mvect.empty()){
		std::cout << "\033[32mOK\033[0m - \033[33m" << diff << " ms\033[0m" << std::endl;
		return true;
	}
	std::cout << "\033[31mKO\033[0m" << std::endl;
	return false;
}

bool	insert_fill_cleared_vector(){
	std::cout << "\033[0;1mTest 5\033[0m - ";
	std::vector<int>		rvect(25, 5);
	ft::vector<int>		mvect(25, 5);
	rvect.clear();
	mvect.clear();

	//std test
	std::time_t time1 = std::time(NULL);
	rvect.insert(rvect.begin(), 10, 1);
	int ret1 = *(rvect.begin());
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	mvect.insert(mvect.begin(), 10, 1);
	int ret2 = *(mvect.begin());
	time2 = std::time(NULL) - time2;

	//get diff time
	std::time_t diff = time2 - time1;

	//ret
	if (ret1 == ret2 && rvect.size() == mvect.size() && rvect.empty() == mvect.empty()){
		std::cout << "\033[32mOK\033[0m - \033[33m" << diff << " ms\033[0m" << std::endl;
		return true;
	}
	std::cout << "\033[31mKO\033[0m" << std::endl;
	return false;
}

bool	insert_range_in_vector(){
	std::cout << "\033[0;1mTest 6\033[0m - ";
	std::vector<int>		rvect(25, 5);
	ft::vector<int>		mvect(25, 5);

	//std test
	std::time_t time1 = std::time(NULL);
	std::vector<int>		rvect2(25, 2);
	rvect.insert(rvect.begin(), rvect2.begin(), rvect2.end());
	int ret1 = *(rvect.begin());
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	ft::vector<int>		mvect2(25, 2);
	mvect.insert(mvect.begin(), mvect2.begin(), mvect2.end());
	int ret2 = *(mvect.begin());
	time2 = std::time(NULL) - time2;

	//get diff time
	std::time_t diff = time2 - time1;

	//ret
	std::vector<int>::iterator rit = rvect.begin();
	ft::vector<int>::iterator mit = mvect.begin();
	while (rit != rvect.end() && mit != mvect.end()){
		if (*rit != *mit){
			std::cout << "\033[31mKO\033[0m" << std::endl;
			return false;
		}
		rit++;
		mit++;
	}
	if (ret1 == ret2 && rvect.size() == mvect.size() && rvect.empty() == mvect.empty()){
		std::cout << "\033[32mOK\033[0m - \033[33m" << diff << " ms\033[0m" << std::endl;
		return true;
	}
	std::cout << "\033[31mKO\033[0m" << std::endl;
	return false;
}

bool	insert_range_cleared_vector(){
	std::cout << "\033[0;1mTest 7\033[0m - ";
	std::vector<int>		rvect(25, 5);
	ft::vector<int>		mvect(25, 5);
	rvect.clear();
	mvect.clear();

	//std test
	std::time_t time1 = std::time(NULL);
	std::vector<int>		rvect2(25, 2);
	rvect.insert(rvect.begin(), rvect2.begin(), rvect2.end());
	int ret1 = *(rvect.begin());
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	ft::vector<int>		mvect2(25, 2);
	mvect.insert(mvect.begin(), mvect2.begin(), mvect2.end());
	int ret2 = *(mvect.begin());
	time2 = std::time(NULL) - time2;

	//get diff time
	std::time_t diff = time2 - time1;

	//ret
	std::vector<int>::iterator rit = rvect.begin();
	ft::vector<int>::iterator mit = mvect.begin();
	while (rit != rvect.end() && mit != mvect.end()){
		if (*rit != *mit){
			std::cout << "\033[31mKO\033[0m" << std::endl;
			return false;
		}
		rit++;
		mit++;
	}
	if (ret1 == ret2 && rvect.size() == mvect.size() && rvect.empty() == mvect.empty()){
		std::cout << "\033[32mOK\033[0m - \033[33m" << diff << " ms\033[0m" << std::endl;
		return true;
	}
	std::cout << "\033[31mKO\033[0m" << std::endl;
	return false;
}

bool	insert_range_empty_vector(){
	std::cout << "\033[0;1mTest 8\033[0m - ";
	std::vector<int>		rvect(25, 5);
	ft::vector<int>		mvect(25, 5);
	rvect.clear();
	mvect.clear();

	//std test
	std::time_t time1 = std::time(NULL);
	std::vector<int>		rvect2;
	rvect.insert(rvect.begin(), rvect2.begin(), rvect2.end());
	int ret1 = *(rvect.begin());
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	ft::vector<int>		mvect2;
	mvect.insert(mvect.begin(), mvect2.begin(), mvect2.end());
	int ret2 = *(mvect.begin());
	time2 = std::time(NULL) - time2;

	//get diff time
	std::time_t diff = time2 - time1;

	//ret
	std::vector<int>::iterator rit = rvect.begin();
	ft::vector<int>::iterator mit = mvect.begin();
	while (rit != rvect.end() && mit != mvect.end()){
		if (*rit != *mit){
			std::cout << "\033[31mKO\033[0m" << std::endl;
			return false;
		}
		rit++;
		mit++;
	}
	if (ret1 == ret2 && rvect.size() == mvect.size() && rvect.empty() == mvect.empty()){
		std::cout << "\033[32mOK\033[0m - \033[33m" << diff << " ms\033[0m" << std::endl;
		return true;
	}
	std::cout << "\033[31mKO\033[0m" << std::endl;
	return false;
}

bool	insert_performance_vector(){
	std::cout << "\033[0;1mTest 9\033[0m - ";
	std::vector<int>		rvect;
	ft::vector<int>			mvect;

	//std test
	std::time_t time1 = std::time(NULL);
	rvect.insert(rvect.begin(), 10000, 0);
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	mvect.insert(mvect.begin(), 10000, 0);
	time2 = std::time(NULL) - time2;

	//get diff time
	std::time_t diff = time2 - time1;

	//ret
	std::vector<int>::iterator rit = rvect.begin();
	ft::vector<int>::iterator mit = mvect.begin();
	while (rit != rvect.end() && mit != mvect.end()){
		if (*rit != *mit){
			std::cout << "\033[31mKO\033[0m" << std::endl;
			return false;
		}
		rit++;
		mit++;
	}
	if (rvect.size() == mvect.size() && rvect.empty() == mvect.empty()){
		std::cout << "\033[32mOK\033[0m - \033[33m" << diff << " ms\033[0m" << std::endl;
		return true;
	}
	std::cout << "\033[31mKO\033[0m" << std::endl;
	return false;
}

bool	insert_test_vector(){
	std::cout << std::endl << "\033[34;1mInsert() :\033[0m" << std::endl;
	bool ret = true;
	if (insert_elem_front_vector() == false)
		ret = false;
	if (insert_elem_back_vector() == false)
		ret = false;
	if (insert_elem_in_vector() == false)
		ret = false;
	if (insert_fill_in_vector() == false)
		ret = false;
	if (insert_fill_cleared_vector() == false)
		ret = false;
	if (insert_range_in_vector() == false)
		ret = false;
	if (insert_range_cleared_vector() == false)
		ret = false;
	if (insert_range_empty_vector() == false)
		ret = false;
	if (insert_performance_vector() == false)
		ret = false;
	if (ret == false)
		return (print_function_ko());
	else
		return (print_function_ok());
}