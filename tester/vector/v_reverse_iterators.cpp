/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_reverse_iterators.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 18:26:26 by user42            #+#    #+#             */
/*   Updated: 2022/01/18 14:43:02 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.hpp"

bool	reviterator_rbegin_vector(){
	std::cout << "\033[0;1mTest 1\033[0m - ";
	std::vector<int>	rvect(25, 5);
	ft::vector<int>		mvect(25, 5);

	//std test
	std::time_t time1 = std::time(NULL);
	int ret1 = *rvect.rbegin();
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	int ret2 = *mvect.rbegin();
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

bool	reviterator_rend_vector(){
	std::cout << "\033[0;1mTest 2\033[0m - ";
	std::vector<int>	rvect(25, 5);
	ft::vector<int>		mvect(25, 5);

	//std test
	std::time_t time1 = std::time(NULL);
	int ret1 = *rvect.rend();
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	int ret2 = *mvect.rend();
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

bool	reviterator_iterating_vector(){
	std::cout << "\033[0;1mTest 3\033[0m - ";
	std::vector<int>	rvect(25, 5);
	ft::vector<int>		mvect(25, 5);

	//std test
	std::time_t time1 = std::time(NULL);
	std::reverse_iterator<std::vector<int>::iterator> rrit = rvect.rbegin();
	std::reverse_iterator<std::vector<int>::iterator> rrite = rvect.rend();
	size_t ret1 = 0;
	while (rrit != rrite){
		rrit++;
		ret1++;
	}
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	ft::reverse_iterator<ft::vector<int>::iterator> mrit = mvect.rbegin();
	ft::reverse_iterator<ft::vector<int>::iterator> mrite = mvect.rend();
	size_t ret2 = 0;
	while (mrit != mrite){
		mrit++;
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

bool	reviterator_iterating_empty_vector(){
	std::cout << "\033[0;1mTest 4\033[0m - ";
	std::vector<int>	rvect;
	ft::vector<int>		mvect;

	//std test
	std::time_t time1 = std::time(NULL);
	std::reverse_iterator<std::vector<int>::iterator> rrit = rvect.rbegin();
	std::reverse_iterator<std::vector<int>::iterator> rrite = rvect.rend();
	size_t ret1 = 0;
	while (rrit != rrite){
		rrit++;
		ret1++;
	}
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	ft::reverse_iterator<ft::vector<int>::iterator> mrit = mvect.rbegin();
	ft::reverse_iterator<ft::vector<int>::iterator> mrite = mvect.rend();
	size_t ret2 = 0;
	while (mrit != mrite){
		mrit++;
		ret1++;
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

bool	reviterator_checking_vector(){
	std::cout << "\033[0;1mTest 5\033[0m - ";
	std::vector<int>	rvect(25, 0);
	ft::vector<int>		mvect(25, 0);
	
	//std test
	std::time_t time1 = std::time(NULL);
	std::reverse_iterator<std::vector<int>::iterator> rrit = rvect.rbegin();
	std::reverse_iterator<std::vector<int>::iterator> rrite = rvect.rend();
	bool ret1 = true;
	while (rrit != rrite){
		if (*rrit != 0)
			ret1 = false;
		rrit++;
	}
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	ft::reverse_iterator<ft::vector<int>::iterator> mrit = mvect.rbegin();
	ft::reverse_iterator<ft::vector<int>::iterator> mrite = mvect.rend();
	bool ret2 = true;
	while (mrit != mrite){
		if (*mrit != 0)
			ret2 = false;
		mrit++;
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

bool	reviterator_plus_overload_vector(){
	std::cout << "\033[0;1mTest 6\033[0m - ";
	std::vector<int>	rvect;
	ft::vector<int>		mvect;
	rvect.push_back(1);
	mvect.push_back(1);
	rvect.push_back(2);
	mvect.push_back(2);
	rvect.push_back(3);
	mvect.push_back(3);
	rvect.push_back(4);
	mvect.push_back(4);
	rvect.push_back(5);
	mvect.push_back(5);

	//std test
	std::time_t time1 = std::time(NULL);
	std::reverse_iterator<std::vector<int>::iterator> rrit = rvect.rbegin() + 3;
	int ret1 = *rrit;
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	ft::reverse_iterator<ft::vector<int>::iterator> mrit = mvect.rbegin() + 3;
	int ret2 = *mrit;
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

bool	reviterator_sub_overload_vector(){
	std::cout << "\033[0;1mTest 7\033[0m - ";
	std::vector<int>	rvect;
	ft::vector<int>		mvect;
	rvect.push_back(1);
	mvect.push_back(1);
	rvect.push_back(2);
	mvect.push_back(2);
	rvect.push_back(3);
	mvect.push_back(3);
	rvect.push_back(4);
	mvect.push_back(4);
	rvect.push_back(5);
	mvect.push_back(5);

	//std test
	std::time_t time1 = std::time(NULL);
	std::reverse_iterator<std::vector<int>::iterator> rrit = rvect.rend() - 3;
	int ret1 = *rrit;
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	ft::reverse_iterator<ft::vector<int>::iterator> mrit = mvect.rend() - 3;
	int ret2 = *mrit;
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

bool	reviterator_plusequal_overload_vector(){
	std::cout << "\033[0;1mTest 8\033[0m - ";
	std::vector<int>	rvect;
	ft::vector<int>		mvect;
	rvect.push_back(1);
	mvect.push_back(1);
	rvect.push_back(2);
	mvect.push_back(2);
	rvect.push_back(3);
	mvect.push_back(3);
	rvect.push_back(4);
	mvect.push_back(4);
	rvect.push_back(5);
	mvect.push_back(5);


	//std test
	std::time_t time1 = std::time(NULL);
	std::reverse_iterator<std::vector<int>::iterator> rrit = rvect.rbegin();
	rrit += 3;
	int ret1 = *rrit;
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	ft::reverse_iterator<ft::vector<int>::iterator> mrit = mvect.rbegin();
	mrit += 3;
	int ret2 = *mrit;
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

bool	reviterator_subequal_overload_vector(){
	std::cout << "\033[0;1mTest 9\033[0m - ";
	std::vector<int>	rvect;
	ft::vector<int>		mvect;
	rvect.push_back(1);
	mvect.push_back(1);
	rvect.push_back(2);
	mvect.push_back(2);
	rvect.push_back(3);
	mvect.push_back(3);
	rvect.push_back(4);
	mvect.push_back(4);
	rvect.push_back(5);
	mvect.push_back(5);

	//std test
	std::time_t time1 = std::time(NULL);
	std::reverse_iterator<std::vector<int>::iterator> rrit = rvect.rbegin();
	rrit -= 3;
	int ret1 = *rrit;
	time1 = std::time(NULL) - time1;

	//ft test
	std::time_t time2 = std::time(NULL);
	ft::reverse_iterator<ft::vector<int>::iterator> mrit = mvect.rbegin();
	mrit -= 3;
	int ret2 = *mrit;
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

bool	reviterator_test_vector(){
	std::cout  << std::endl << "\033[34;1mReverse_Iterators :\033[0m" << std::endl;
	bool ret = true;
	if (reviterator_rbegin_vector() == false)
		ret = false;
	if (reviterator_rend_vector() == false)
		ret = false;
	if (reviterator_iterating_vector() == false)
		ret = false;
	if (reviterator_iterating_empty_vector() == false)
		ret = false;
	if (reviterator_checking_vector() == false)
		ret = false;
	if (reviterator_plus_overload_vector() == false)
		ret = false;
	if (reviterator_sub_overload_vector() == false)
		ret = false;
	if (reviterator_plusequal_overload_vector() == false)
		ret = false;
	if (reviterator_subequal_overload_vector() == false)
		ret = false;
	if (ret == false)
		return (print_function_ko());
	else
		return (print_function_ok());
}