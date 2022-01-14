/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_assign.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 00:37:39 by user42            #+#    #+#             */
/*   Updated: 2022/01/14 00:46:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.hpp"

bool	assign_range_vector(){
	std::cout << "\033[0;1mTest 1\033[0m - ";
	std::vector<int>		rvect(25, 5);
	ft::vector<int>			mvect(25, 5);

	//std test
	std::time_t time1 = std::time(NULL);
	std::vector<int>		rvect2(25, 2);
	rvect.assign(rvect2.begin(), rvect2.end());
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	ft::vector<int>			mvect2(25, 2);
	mvect.assign(mvect2.begin(), mvect2.end());
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

bool	assign_range_empty_vector(){
	std::cout << "\033[0;1mTest 2\033[0m - ";
	std::vector<int>		rvect(25, 5);
	ft::vector<int>			mvect(25, 5);

	//std test
	std::time_t time1 = std::time(NULL);
	std::vector<int>		rvect2;
	rvect.assign(rvect2.begin(), rvect2.end());
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	ft::vector<int>			mvect2;
	mvect.assign(mvect2.begin(), mvect2.end());
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

bool	assign_empty_vector(){
	std::cout << "\033[0;1mTest 3\033[0m - ";
	std::vector<int>		rvect;
	ft::vector<int>			mvect;

	//std test
	std::time_t time1 = std::time(NULL);
	std::vector<int>		rvect2(25, 2);
	rvect.assign(rvect2.begin(), rvect2.end());
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	ft::vector<int>			mvect2(25, 2);
	mvect.assign(mvect2.begin(), mvect2.end());
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

bool	assign_empty_range_empty_vector(){
	std::cout << "\033[0;1mTest 4\033[0m - ";
	std::vector<int>		rvect;
	ft::vector<int>			mvect;

	//std test
	std::time_t time1 = std::time(NULL);
	std::vector<int>		rvect2;
	rvect.assign(rvect2.begin(), rvect2.end());
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	ft::vector<int>			mvect2;
	mvect.assign(mvect2.begin(), mvect2.end());
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

bool	assign_filled_empty_vector(){
	std::cout << "\033[0;1mTest 5\033[0m - ";
	std::vector<int>		rvect;
	ft::vector<int>			mvect;

	//std test
	std::time_t time1 = std::time(NULL);
	rvect.assign(25, 2);
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	mvect.assign(25, 2);
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

bool	assign_nothing_empty_vector(){
	std::cout << "\033[0;1mTest 6\033[0m - ";
	std::vector<int>		rvect;
	ft::vector<int>			mvect;

	//std test
	std::time_t time1 = std::time(NULL);
	rvect.assign(0, 0);
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	mvect.assign(0, 0);
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

bool	assign_perfomance_vector(){
	std::cout << "\033[0;1mTest 7\033[0m - ";
	std::vector<int>		rvect;
	ft::vector<int>			mvect;

	//std test
	std::time_t time1 = std::time(NULL);
	rvect.assign(10000, 0);
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	mvect.assign(10000, 0);
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

bool	assign_test_vector(){
	std::cout << std::endl << "\033[34;1mAssign() :\033[0m" << std::endl;
	bool ret = true;
	if (assign_range_vector() == false)
		ret = false;
	if (assign_range_empty_vector() == false)
		ret = false;
	if (assign_empty_vector() == false)
		ret = false;
	if (assign_empty_range_empty_vector() == false)
		ret = false;
	if (assign_filled_empty_vector() == false)
		ret = false;
	if (assign_nothing_empty_vector() == false)
		ret = false;
	if (assign_perfomance_vector() == false)
		ret = false;
	if (ret == false)
		return (print_function_ko());
	else
		return (print_function_ok());
}