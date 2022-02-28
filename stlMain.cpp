/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stlMain.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 02:57:34 by user42            #+#    #+#             */
/*   Updated: 2022/02/28 03:14:47 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>

#include <utility>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
//for vector underluying test
#include <deque>
#include <iterator>

#define TESTED_NAMESPACE std
std::string tested_namespace = "std";

/*****************************************************************************/
/*                                 Utils                                     */
/*****************************************************************************/

void	printVSize(int nb, TESTED_NAMESPACE::vector<int> vect1, TESTED_NAMESPACE::vector<int> vect2, TESTED_NAMESPACE::vector<int> vect3, TESTED_NAMESPACE::vector<int> vect4){
	std::cout << "##################### TEST" << nb << " ####################" << std::endl;
	std::cout << "size: " << vect1.size() << " | empty: " << vect1.empty() << " | capacity: " << vect1.capacity() << std::endl;
	std::cout << "size: " << vect2.size() << " | empty: " << vect2.empty() << " | capacity: " << vect2.capacity() << std::endl;
	std::cout << "size: " << vect3.size() << " | empty: " << vect3.empty() << " | capacity: " << vect3.capacity() << std::endl;
	std::cout << "size: " << vect4.size() << " | empty: " << vect4.empty() << " | capacity: " << vect4.capacity() << std::endl;
	std::cout << std::endl;
}

void	printSSize(int nb, TESTED_NAMESPACE::stack<int> stack1, TESTED_NAMESPACE::stack<int> stack2){
	std::cout << "##################### TEST" << nb << " ####################" << std::endl;
	std::cout << "size: " << stack1.size() << " | empty: " << stack1.empty() << std::endl;
	std::cout << "size: " << stack2.size() << " | empty: " << stack2.empty() << std::endl;
	std::cout << std::endl;
}

void	printUSize(int nb, TESTED_NAMESPACE::stack<int, std::deque<int> > stack1, TESTED_NAMESPACE::stack<int, std::deque<int> > stack2){
	std::cout << "##################### TEST" << nb << " ####################" << std::endl;
	std::cout << "size: " << stack1.size() << " | empty: " << stack1.empty() << std::endl;
	std::cout << "size: " << stack2.size() << " | empty: " << stack2.empty() << std::endl;
	std::cout << std::endl;
}

void	printMSize(int nb, TESTED_NAMESPACE::map<int, std::string> map1, TESTED_NAMESPACE::map<int, std::string> map2, TESTED_NAMESPACE::map<int, std::string> map3, TESTED_NAMESPACE::map<int, std::string> map4){
	std::cout << "##################### TEST" << nb << " ####################" << std::endl;
	std::cout << "size: " << map1.size() << " | empty: " << map1.empty() << std::endl;
	std::cout << "size: " << map2.size() << " | empty: " << map2.empty() << std::endl;
	std::cout << "size: " << map3.size() << " | empty: " << map3.empty() << std::endl;
	std::cout << "size: " << map4.size() << " | empty: " << map4.empty() << std::endl;
	std::cout << std::endl;
}

/*****************************************************************************/
/*                                Vector                                     */
/*****************************************************************************/

//CAPACITY
void vector_capacity_test(){
	//vector constructor
	TESTED_NAMESPACE::vector<int> vect1(10, 1);
	TESTED_NAMESPACE::vector<int> vect2(vect1.begin(), vect1.end());
	TESTED_NAMESPACE::vector<int> vect3(vect1);
	TESTED_NAMESPACE::vector<int> vect4;
	//assignement operator
	vect2 = vect1;
	vect4 = vect1;
	printVSize(0, vect1, vect2, vect3, vect4);

	//check content
	std::cout << "RANGE CONTENT" << std::endl;
	for (TESTED_NAMESPACE::vector<int>::iterator it = vect2.begin(); it != vect2.end(); it++)
		std::cout << *it << std::endl;
	std::cout << std::endl;

	//clear vect2 for empty test
	vect2.clear();

	//reserve 17
	vect1.reserve(17);
	vect2.reserve(17);
	vect3.reserve(17);
	vect4.reserve(17);
	printVSize(1, vect1, vect2, vect3, vect4);

	//resize
	vect1.resize(17);
	vect2.resize(17);
	vect3.resize(17);
	vect4.resize(17);
	printVSize(2, vect1, vect2, vect3, vect4);

	std::cout << "RESIZED CONTENT" << std::endl;
	for (TESTED_NAMESPACE::vector<int>::iterator it = vect3.begin(); it != vect3.end(); it++)
		std::cout << *it << std::endl;
	std::cout << std::endl;

	//resize
	vect1.resize(1700);
	vect2.resize(1700);
	vect3.resize(1700);
	vect4.resize(1700);
	printVSize(3, vect1, vect2, vect3, vect4);

	//clear
	vect1.clear();
	vect2.clear();
	vect3.clear();
	vect4.clear();
	printVSize(4, vect1, vect2, vect3, vect4);

	//resize 0
	vect1.resize(0);
	vect2.resize(0);
	vect3.resize(0);
	vect4.resize(0);
	printVSize(5, vect1, vect2, vect3, vect4);

	//reserve
	vect1.reserve(0);
	vect2.reserve(0);
	vect3.reserve(0);
	vect4.reserve(0);
	printVSize(6, vect1, vect2, vect3, vect4);
}

//ELEMENT ACCESS
void vector_access_test(){
	//vector constructor
	TESTED_NAMESPACE::vector<int> vect1(15, 2);
	TESTED_NAMESPACE::vector<int> vect2(vect1.begin(), vect1.end());
	TESTED_NAMESPACE::vector<int> vect3(vect1);
	TESTED_NAMESPACE::vector<int> vect4;
	//assignement operator
	vect2 = vect1;
	vect4 = vect1;

	//clear vect2 for empty test
	vect2.clear();

	//operator[]
	std::cout << "##################### TEST" << 0 << " ####################" << std::endl;
	std::cout << vect1[0] << vect1[1] << std::endl;
	std::cout << vect2[0] << vect2[1] << std::endl;
	std::cout << vect3[0] << vect3[1] << std::endl;
	std::cout << vect4[0] << vect4[1] << std::endl;
	std::cout << std::endl;

	//operator[] const
	std::cout << "##################### TEST" << 1 << " ####################" << std::endl;
	int const ret1 = vect1[0];int const ret2 = vect2[0];int const ret3 = vect3[0];int const ret4 = vect4[0];
	int const ret11 = vect1[1];int const ret22 = vect2[1];int const ret33 = vect3[1];int const ret44 = vect4[1];
	std::cout << ret1 << " | " << ret11 << std::endl;
	std::cout << ret2 << " | " << ret22 << std::endl;
	std::cout << ret3 << " | " << ret33 << std::endl;
	std::cout << ret4 << " | " << ret44 << std::endl;
	std::cout << std::endl;

	//at
	std::cout << "##################### TEST" << 2 << " ####################" << std::endl;
	for (int i = 0; i < 15; i++){
		std::cout << vect1.at(i) << std::endl;
		try{
			std::cout << vect2.at(i) << std::endl;
		}
		catch (std::exception &e){
			std::cout << "error" << std::endl;
		}
		std::cout << vect3.at(i) << std::endl;
		std::cout << vect4.at(i) << std::endl;
	}
	std::cout << std::endl;

	//front back
	std::cout << "##################### TEST" << 3 << " ####################" << std::endl;
	std::cout << vect1.front() << vect1.back() << std::endl;
	try{
		std::cout << vect2.front() << vect2.back() << std::endl;
	}
	catch (std::exception &e){
		std::cout << "error" << std::endl;
	}
	std::cout << vect3.front() << vect3.back() << std::endl;
	std::cout << vect4.front() << vect4.back() << std::endl;
	std::cout << std::endl;

	//front back const
	std::cout << "##################### TEST" << 4 << " ####################" << std::endl;
	int const front11 = vect1.front();int const back11 = vect1.back();
	int tmpfront22;int tmpback22;
	try{
		int const front22 = vect1.front(); int const back22 = vect1.back();
		tmpfront22 = front22;tmpback22 = back22;
	}
	catch (std::exception &e){
		tmpfront22 = -1; tmpback22 = -1;
	}
	int const front33 = vect1.front();int const back33 = vect1.back();
	int const front44 = vect1.front();int const back44 = vect1.back();
	std::cout << front11 << back11 << std::endl;
	if (tmpfront22 != -1 || tmpback22 != -1)
		std::cout << tmpfront22 << tmpback22 << std::endl;
	else
		std::cout << "error" << std::endl;
	std::cout << front33 << back33 << std::endl;
	std::cout << front44 << back44 << std::endl;
	std::cout << std::endl;
}

//MODIFIERS
void vector_modifiers_test(){
	//vector constructor
	TESTED_NAMESPACE::vector<int> vect1;
	TESTED_NAMESPACE::vector<int> vect2;
	TESTED_NAMESPACE::vector<int> vect3;
	TESTED_NAMESPACE::vector<int> vect4;

	//insert single element
	for(int i = 0; i < 50000; i++)
		vect1.insert(vect1.end(), i);
	std::cout << "INSERTED CONTENT" << std::endl;
	//push_back
	for(int i = 0; i < 19; i++)
		vect2.push_back(i);
	//insert range
	vect3.insert(vect3.begin(), vect1.begin(), vect1.end());
	//insert multiple
	vect4.insert(vect4.begin(), 10000, 1);
	printVSize(0, vect1, vect2, vect3, vect4);

	//assignement operator
	vect4 = vect3;
	printVSize(1, vect1, vect2, vect3, vect4);

	//pop_back
	for (int i = 0; i < 49758; i++){
		vect1.pop_back();
		if (i < 8){
			vect2.pop_back();
			vect3.pop_back();
			vect4.pop_back();
		}
	}
	printVSize(2, vect1, vect2, vect3, vect4);

	//assign
	vect1.assign(vect1.begin(), vect1.end() - 76);
	vect2.assign(vect1.begin(), vect1.end() - 12);
	vect3.assign(15, 2);
	vect4.assign(10000, 0);
	printVSize(3, vect1, vect2, vect3, vect4);

	//swap
	vect1.swap(vect2);
	TESTED_NAMESPACE::vector<int>::iterator it1 = vect3.begin();
	TESTED_NAMESPACE::vector<int>::const_iterator ite1 = vect3.end();
	TESTED_NAMESPACE::vector<int>::iterator it2 = vect4.begin();
	TESTED_NAMESPACE::vector<int>::const_iterator ite2 = vect4.end();
	vect3.swap(vect4);
	//comparaison const non const
	bool ret = it1 != ite1;
	std::cout << *it1 << " | " << *ite1 << " | " << ret << std::endl;
	ret = it2 != ite2;
	std::cout << *it2 << " | " << *ite2 << " | " << ret << std::endl;
	printVSize(4, vect1, vect2, vect3, vect4);

	//clear
	vect1.clear();
	vect2.clear();
	vect3.clear();
	vect4.clear();
	printVSize(5, vect1, vect2, vect3, vect4);

	{
		std::cout << "##################### TEST" << 5 << " ####################" << std::endl;
		for (int i = 0; i < 10; i++){
			vect1.push_back(1);
			std::cout << vect1.capacity() << std::endl;
		}
		std::cout << std::endl;
	}
}

void	vector_comparaison_test(){
	TESTED_NAMESPACE::vector<int> vect1(10, 5);
	TESTED_NAMESPACE::vector<int> vect2;
	vect2.push_back(1);
	TESTED_NAMESPACE::vector<int> vect3(15, 5);
	TESTED_NAMESPACE::vector<int> vect4;

	//comparaison
	for (int i = 0; i < 19; i++)
		vect3.push_back(i);
	bool ret = vect1 < vect2;
	std::cout << ret << std::endl;
	ret = vect1 > vect2;
	std::cout << ret << std::endl;
	ret = vect3 <= vect3;
	std::cout << ret << std::endl;
	ret = vect4 >= vect3;
	std::cout << ret << std::endl;
	ret = vect2 == vect3;
	std::cout << ret << std::endl;
	ret = vect3 != vect3;
	std::cout << ret << std::endl;
	printVSize(1, vect1, vect2, vect3, vect4);
}

void	vector_test(){
	//capacity
	clock_t ticks = clock();
	vector_capacity_test();
  	ticks = clock() - ticks;
  	std::cout << tested_namespace << "'s execution time on vector's capacity test :" << ((float)ticks) / CLOCKS_PER_SEC << std::endl << std::endl;

	//element access
	ticks = clock();
	vector_access_test();
  	ticks = clock() - ticks;
  	std::cout << tested_namespace << "'s execution time on vector's access test:" << ((float)ticks) / CLOCKS_PER_SEC << std::endl << std::endl;

	//modifiers
	ticks = clock();
	vector_modifiers_test();
  	ticks = clock() - ticks;
  	std::cout << tested_namespace << "'s execution time on vector's modifiers test:" << ((float)ticks) / CLOCKS_PER_SEC << std::endl << std::endl;

	//comparaison
	std::cout << "COMPARAISON" << std::endl;
	vector_comparaison_test();
}

/*****************************************************************************/
/*                                 Stack                                     */
/*****************************************************************************/

void	stack_members_test(){
	TESTED_NAMESPACE::stack<int> stack1;
	TESTED_NAMESPACE::stack<int> stack2;
	printSSize(0, stack1, stack2);

	//push
	for (int i = 0; i < 7; i++){
		stack1.push(i);
		stack2.push(i);
	}
	stack2.push(8);
	printSSize(0, stack1, stack2);

	//top
	std::cout << stack1.top() << std::endl;
	std::cout << stack2.top() << std::endl;
	printSSize(1, stack1, stack2);

	//pop
	for (int i = 0; i < 2; i++){
		stack1.pop();
		stack2.pop();
	}
	printSSize(2, stack1, stack2);

	//top
	std::cout << stack1.top() << std::endl;
	std::cout << stack2.top() << std::endl;
	printSSize(3, stack1, stack2);

	//push
	for (int i = 0; i < 79000; i++){
		stack1.push(i);
		stack2.push(i);
	}
	printSSize(4, stack1, stack2);

	//pop
	for (int i = 0; i < 79000; i++){
		stack1.pop();
		stack2.pop();
	}
	printSSize(5, stack1, stack2);
}

void	stack_underluying_test(){
	TESTED_NAMESPACE::stack<int, std::deque<int> > stack1;
	TESTED_NAMESPACE::stack<int, std::deque<int> > stack2;
	printUSize(0, stack1, stack2);

	//push
	for (int i = 0; i < 7; i++){
		stack1.push(i);
		stack2.push(i);
	}
	stack2.push(8);
	printUSize(0, stack1, stack2);

	//top
	std::cout << stack1.top() << std::endl;
	std::cout << stack2.top() << std::endl;
	printUSize(1, stack1, stack2);

	//pop
	for (int i = 0; i < 2; i++){
		stack1.pop();
		stack2.pop();
	}
	printUSize(2, stack1, stack2);

	//top
	std::cout << stack1.top() << std::endl;
	std::cout << stack2.top() << std::endl;
	printUSize(3, stack1, stack2);

	//push
	for (int i = 0; i < 79000; i++){
		stack1.push(i);
		stack2.push(i);
	}
	printUSize(4, stack1, stack2);

	//pop
	for (int i = 0; i < 79000; i++){
		stack1.pop();
		stack2.pop();
	}
	printUSize(5, stack1, stack2);
}

void	stack_comparaison_test(){
	TESTED_NAMESPACE::stack<int> stack1;
	TESTED_NAMESPACE::stack<int> stack2;
	stack2.push(1);

	//comparaison
	for (int i = 0; i < 19; i++)
		stack1.push(i);
	bool ret = stack1 < stack2;
	std::cout << ret << std::endl;
	ret = stack2 > stack2;
	std::cout << ret << std::endl;
	ret = stack1 <= stack2;
	std::cout << ret << std::endl;
	ret = stack2 >= stack1;
	std::cout << ret << std::endl;
	ret = stack1 == stack2;
	std::cout << ret << std::endl;
	ret = stack2 != stack2;
	std::cout << ret << std::endl;
	printSSize(0, stack1, stack2);
}

void	stack_test(){
	//members
	clock_t ticks = clock();
	stack_members_test();
	ticks = clock() - ticks;
  	std::cout << tested_namespace << "'s execution time on stack's test :" << ((float)ticks) / CLOCKS_PER_SEC << std::endl << std::endl;

	//underluying
	ticks = clock();
	stack_underluying_test();
	ticks = clock() - ticks;
  	std::cout << tested_namespace << "'s execution time on stack's underluing test :" << ((float)ticks) / CLOCKS_PER_SEC << std::endl << std::endl;

	//comparaison
	std::cout << "COMPARAISON" << std::endl;
	stack_comparaison_test();
}

/*****************************************************************************/
/*                                  Map                                     */
/*****************************************************************************/

//ELEMENT ACCESS
void map_access_test(){
	//map constructor
	TESTED_NAMESPACE::map<int, std::string> map1;
	for(int i = 0; i < 50000; i++){
		TESTED_NAMESPACE::pair<int, std::string> pair = TESTED_NAMESPACE::make_pair(i, "Key");
		map1.insert(pair);
	}
	TESTED_NAMESPACE::map<int, std::string> map2(map1.begin(), map1.end());
	TESTED_NAMESPACE::map<int, std::string> map3(map2.begin(), map2.begin()++);
	for(int i = 0; i < 4; i++){
		TESTED_NAMESPACE::pair<int, std::string> pair = TESTED_NAMESPACE::make_pair(i * -1, "yeK");
		map3.insert(pair);
	}
	TESTED_NAMESPACE::map<int, std::string> map4(map3);
	printMSize(0, map1, map2, map3, map4);


	//operator[]
	std::cout << "##################### TEST" << 0 << " ####################" << std::endl;
	std::cout << map1[1] << std::endl;
	std::cout << map2[2] << std::endl;
	std::cout << map3[-1] << std::endl;
	std::cout << map4[-2] << std::endl;
	std::cout << std::endl;

	//operator[] const
	std::cout << "##################### TEST" << 1 << " ####################" << std::endl;
	std::string const ret1 = map1[1];std::string const ret2 = map2[2];std::string const ret3 = map3[-1];std::string const ret4 = map4[-2];
	std::cout << ret1 << std::endl;
	std::cout << ret2 << std::endl;
	std::cout << ret3 << std::endl;
	std::cout << ret4 << std::endl;
	std::cout << std::endl;
}

//MODIFIERS
void map_modifiers_test(){
	//map constructor
	TESTED_NAMESPACE::map<int, std::string> map1;
	for(int i = 0; i < 50000; i++){
		TESTED_NAMESPACE::pair<int, std::string> pair = TESTED_NAMESPACE::make_pair(i, "Key");
		map1.insert(pair);
	}
	TESTED_NAMESPACE::map<int, std::string> map2(map1.begin(), map1.end());
	TESTED_NAMESPACE::map<int, std::string> map3(map2.begin(), map2.begin()++);
	for(int i = 0; i < 4; i++){
		TESTED_NAMESPACE::pair<int, std::string> pair = TESTED_NAMESPACE::make_pair(i * -1, "yeK");
		map3.insert(pair);
	}
	TESTED_NAMESPACE::map<int, std::string> map4(map3);
	printMSize(0, map1, map2, map3, map4);


	std::cout << "INSERTED CONTENT" << std::endl;
	for (TESTED_NAMESPACE::map<int, std::string>::iterator it = map4.begin(); it != map4.end(); it++)
		std::cout << (*it).first << " | " << (*it).second << std::endl;
	printMSize(1, map1, map2, map3, map4);

	//erase
	map1.erase(map1.begin(), map1.end());
	map2.erase(map2.begin(), map2.end());
	while (map3.size() != 0){
		map3.erase(map3.begin());
		map4.erase(map4.begin());
	}
	printMSize(2, map1, map2, map3, map4);

	//swap
	map1.swap(map2);
	TESTED_NAMESPACE::map<int, std::string>::iterator it1 = map3.begin();
	TESTED_NAMESPACE::map<int, std::string>::const_iterator ite1 = map3.end();
	TESTED_NAMESPACE::map<int, std::string>::iterator it2 = map4.begin();
	TESTED_NAMESPACE::map<int, std::string>::const_iterator ite2 = map4.end();
	map3.swap(map4);
	//comparaison const non const
	bool ret = it1 != ite1;
	std::cout << ret << std::endl;
	ret = it2 != ite2;
	std::cout << ret << std::endl;
	printMSize(3, map1, map2, map3, map4);

	//clear
	map1.clear();
	map2.clear();
	map3.clear();
	map4.clear();
	printMSize(4, map1, map2, map3, map4);

}

void map_operations_test(){
	//map constructor
	TESTED_NAMESPACE::map<int, std::string> map1;
	for(int i = 0; i < 50000; i++){
		TESTED_NAMESPACE::pair<int, std::string> pair = TESTED_NAMESPACE::make_pair(i, "Key");
		map1.insert(pair);
	}
	TESTED_NAMESPACE::map<int, std::string> map2(map1.begin(), map1.end());
	TESTED_NAMESPACE::map<int, std::string> map3(map2.begin(), map2.begin()++);
	for(int i = 0; i < 4; i++){
		TESTED_NAMESPACE::pair<int, std::string> pair = TESTED_NAMESPACE::make_pair(i * -1, "yeK");
		map3.insert(pair);
	}
	//assignement operator
	TESTED_NAMESPACE::map<int, std::string> map4 = map3;
	printMSize(0, map1, map2, map3, map4);

	//find
	TESTED_NAMESPACE::map<int, std::string>::iterator it1 = map1.find(1);
	TESTED_NAMESPACE::map<int, std::string>::const_iterator it2 = map2.find(2);
	TESTED_NAMESPACE::map<int, std::string>::iterator it3 = map3.find(-1);
	TESTED_NAMESPACE::map<int, std::string>::const_iterator it4 = map4.find(-2);
	std::cout << (*it1).second << std::endl;
	std::cout << (*it2).second << std::endl;
	std::cout << (*it3).second << std::endl;
	std::cout << (*it4).second << std::endl;
	printMSize(1, map1, map2, map3, map4);

	//count
	std::cout << map1.count(1) << std::endl;
	std::cout << map2.count(2) << std::endl;
	std::cout << map3.count(-1) << std::endl;
	std::cout << map4.count(-646) << std::endl;
	printMSize(2, map1, map2, map3, map4);

	//lower_bound
	it1 = map1.lower_bound(15);
	TESTED_NAMESPACE::map<int, std::string>::const_iterator it22 = map2.lower_bound(2000);
	it3 = map3.lower_bound(-1);
	TESTED_NAMESPACE::map<int, std::string>::const_iterator it44 = map4.lower_bound(5000);
	std::cout << (*it1).second << std::endl;
	std::cout << (*it22).second << std::endl;
	std::cout << (*it3).second << std::endl;
	std::cout << (*it44).second << std::endl;
	printMSize(3, map1, map2, map3, map4);

	//upper_bound
	it1 = map1.upper_bound(15);
	TESTED_NAMESPACE::map<int, std::string>::const_iterator it222 = map2.upper_bound(2000);
	it3 = map3.upper_bound(-1);
	TESTED_NAMESPACE::map<int, std::string>::const_iterator it444 = map4.upper_bound(5000);
	std::cout << (*it1).second << std::endl;
	std::cout << (*it222).second << std::endl;
	std::cout << (*it3).second << std::endl;
	std::cout << (*it444).second << std::endl;
	printMSize(4, map1, map2, map3, map4);

	//equal_range
	TESTED_NAMESPACE::pair<TESTED_NAMESPACE::map<int, std::string>::iterator, TESTED_NAMESPACE::map<int, std::string>::iterator> pair1 = map1.equal_range(15);
	TESTED_NAMESPACE::pair<TESTED_NAMESPACE::map<int, std::string>::const_iterator, TESTED_NAMESPACE::map<int, std::string>::const_iterator> pair2 = map2.equal_range(2000);
	std::cout << pair1.first->first << std::endl;
	std::cout << pair2.first->first << std::endl;
	printMSize(5, map1, map2, map3, map4);
}

void	map_comparaison_test(){
	TESTED_NAMESPACE::map<int, std::string> map1;
	for(int i = 0; i < 29; i++){
		TESTED_NAMESPACE::pair<int, std::string> pair = TESTED_NAMESPACE::make_pair(i, "Key");
		map1.insert(pair);
	}
	TESTED_NAMESPACE::map<int, std::string> map2(map1.begin(), map1.end());
	TESTED_NAMESPACE::map<int, std::string> map3(map2.begin(), map2.begin()++);
	for(int i = 0; i < 4; i++){
		TESTED_NAMESPACE::pair<int, std::string> pair = TESTED_NAMESPACE::make_pair(i * -1, "yeK");
		map3.insert(pair);
	}
	TESTED_NAMESPACE::map<int, std::string> map4(map3);
	printMSize(0, map1, map2, map3, map4);

	//comparaison
	bool ret = map1 < map2;
	std::cout << ret << std::endl;
	ret = map1 > map2;
	std::cout << ret << std::endl;
	ret = map3 <= map3;
	std::cout << ret << std::endl;
	ret = map4 >= map3;
	std::cout << ret << std::endl;
	ret = map2 == map3;
	std::cout << ret << std::endl;
	ret = map3 != map3;
	std::cout << ret << std::endl;
	printMSize(1, map1, map2, map3, map4);
}

void	map_test(){
	//modifiers
	clock_t ticks = clock();
	map_modifiers_test();
  	ticks = clock() - ticks;
  	std::cout << tested_namespace << "'s execution time on map's modifiers test:" << ((float)ticks) / CLOCKS_PER_SEC << std::endl << std::endl;

	//element access
	ticks = clock();
	map_access_test();
  	ticks = clock() - ticks;
	std::cout << tested_namespace << "'s execution time on map's access test:" << ((float)ticks) / CLOCKS_PER_SEC << std::endl << std::endl;

	//operations
	ticks = clock();
	map_operations_test();
  	ticks = clock() - ticks;
	std::cout << tested_namespace << "'s execution time on map's operations test:" << ((float)ticks) / CLOCKS_PER_SEC << std::endl << std::endl;

	//comparaison
	std::cout << "COMPARAISON" << std::endl;
	map_comparaison_test();
}

/*****************************************************************************/
/*                                  Main                                     */
/*****************************************************************************/

int main(){
	//Vector TEST
	vector_test();

	//Stack TEST
	stack_test();

	//Map TEST
	map_test();
}