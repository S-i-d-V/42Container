#include "containers/vector/vector.hpp"

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

int	main(){
    std::vector<int> realvect;
	ft::vector<int> myvect;

    //Test des return des fonctions membres
	std::cout << "            My vector            |Real vector          " << std::endl;
	std::cout << std::left << std::setw(12) << "Size      = " << std::setw(20) << myvect.size() << " | " << std::setw(20) << realvect.size() << std::endl;
	std::cout << std::setw(12) << "Max_size  = " << std::setw(20) << myvect.max_size() << " | " << std::setw(20) << realvect.max_size() << std::endl;
	std::cout << std::setw(12) << "Capacity  = " << std::setw(20) << myvect.capacity() << " | " << std::setw(20) << realvect.capacity() << std::endl;
	std::cout << std::setw(12) << "Empty     = " << std::setw(20) << myvect.empty() << " | " << std::setw(20) << realvect.empty() << std::endl;

	std::cout << std::endl << "Pushing back '42' :" << std::endl;
	realvect.push_back(42);
	myvect.push_back(42);

	//Test des return des fonctions membres
	std::cout << "            My vector            |Real vector          " << std::endl;
	std::cout << std::left << std::setw(12) << "Size      = " << std::setw(20) << myvect.size() << " | " << std::setw(20) << realvect.size() << std::endl;
	std::cout << std::setw(12) << "Max_size  = " << std::setw(20) << myvect.max_size() << " | " << std::setw(20) << realvect.max_size() << std::endl;
	std::cout << std::setw(12) << "Capacity  = " << std::setw(20) << myvect.capacity() << " | " << std::setw(20) << realvect.capacity() << std::endl;
	std::cout << std::setw(12) << "Empty     = " << std::setw(20) << myvect.empty() << " | " << std::setw(20) << realvect.empty() << std::endl;
	std::cout << std::setw(12) << "Front     = " << std::setw(20) << myvect.front() << " | " << std::setw(20) << realvect.front() << std::endl;
	std::cout << std::setw(12) << "Back      = " << std::setw(20) << myvect.back() << " | " << std::setw(20) << realvect.back() << std::endl;

	std::cout << std::endl << "Pushing back '0' :" << std::endl;
	realvect.push_back(0);
	myvect.push_back(0);

	std::cout << "            My vector            |Real vector          " << std::endl;
	std::cout << std::left << std::setw(12) << "Size      = " << std::setw(20) << myvect.size() << " | " << std::setw(20) << realvect.size() << std::endl;
	std::cout << std::setw(12) << "Max_size  = " << std::setw(20) << myvect.max_size() << " | " << std::setw(20) << realvect.max_size() << std::endl;
	std::cout << std::setw(12) << "Capacity  = " << std::setw(20) << myvect.capacity() << " | " << std::setw(20) << realvect.capacity() << std::endl;
	std::cout << std::setw(12) << "Empty     = " << std::setw(20) << myvect.empty() << " | " << std::setw(20) << realvect.empty() << std::endl;
	std::cout << std::setw(12) << "Front     = " << std::setw(20) << myvect.front() << " | " << std::setw(20) << realvect.front() << std::endl;
	std::cout << std::setw(12) << "Back      = " << std::setw(20) << myvect.back() << " | " << std::setw(20) << realvect.back() << std::endl;

	std::cout << std::endl << "Pushing back '-1' :" << std::endl;
	realvect.push_back(-1);
	myvect.push_back(-1);

	std::cout << "            My vector            |Real vector          " << std::endl;
	std::cout << std::left << std::setw(12) << "Size      = " << std::setw(20) << myvect.size() << " | " << std::setw(20) << realvect.size() << std::endl;
	std::cout << std::setw(12) << "Max_size  = " << std::setw(20) << myvect.max_size() << " | " << std::setw(20) << realvect.max_size() << std::endl;
	std::cout << std::setw(12) << "Capacity  = " << std::setw(20) << myvect.capacity() << " | " << std::setw(20) << realvect.capacity() << std::endl;
	std::cout << std::setw(12) << "Empty     = " << std::setw(20) << myvect.empty() << " | " << std::setw(20) << realvect.empty() << std::endl;
	std::cout << std::setw(12) << "Front     = " << std::setw(20) << myvect.front() << " | " << std::setw(20) << realvect.front() << std::endl;
	std::cout << std::setw(12) << "Back      = " << std::setw(20) << myvect.back() << " | " << std::setw(20) << realvect.back() << std::endl;

	std::cout << std::endl << "Popping back '-1' :" << std::endl;
	realvect.pop_back();
	myvect.pop_back();

	std::cout << "            My vector            |Real vector          " << std::endl;
	std::cout << std::left << std::setw(12) << "Size      = " << std::setw(20) << myvect.size() << " | " << std::setw(20) << realvect.size() << std::endl;
	std::cout << std::setw(12) << "Max_size  = " << std::setw(20) << myvect.max_size() << " | " << std::setw(20) << realvect.max_size() << std::endl;
	std::cout << std::setw(12) << "Capacity  = " << std::setw(20) << myvect.capacity() << " | " << std::setw(20) << realvect.capacity() << std::endl;
	std::cout << std::setw(12) << "Empty     = " << std::setw(20) << myvect.empty() << " | " << std::setw(20) << realvect.empty() << std::endl;
	std::cout << std::setw(12) << "Front     = " << std::setw(20) << myvect.front() << " | " << std::setw(20) << realvect.front() << std::endl;
	std::cout << std::setw(12) << "Back      = " << std::setw(20) << myvect.back() << " | " << std::setw(20) << realvect.back() << std::endl;

	std::cout << std::endl << "Pushing back '1' :" << std::endl;
	realvect.push_back(1);
	myvect.push_back(1);

	std::cout << "            My vector            |Real vector          " << std::endl;
	std::cout << std::left << std::setw(12) << "Size      = " << std::setw(20) << myvect.size() << " | " << std::setw(20) << realvect.size() << std::endl;
	std::cout << std::setw(12) << "Max_size  = " << std::setw(20) << myvect.max_size() << " | " << std::setw(20) << realvect.max_size() << std::endl;
	std::cout << std::setw(12) << "Capacity  = " << std::setw(20) << myvect.capacity() << " | " << std::setw(20) << realvect.capacity() << std::endl;
	std::cout << std::setw(12) << "Empty     = " << std::setw(20) << myvect.empty() << " | " << std::setw(20) << realvect.empty() << std::endl;
	std::cout << std::setw(12) << "Front     = " << std::setw(20) << myvect.front() << " | " << std::setw(20) << realvect.front() << std::endl;
	std::cout << std::setw(12) << "Back      = " << std::setw(20) << myvect.back() << " | " << std::setw(20) << realvect.back() << std::endl;

	std::cout << std::endl << "Pushing back '2' :" << std::endl;
	realvect.push_back(2);
	myvect.push_back(2);

	std::cout << "            My vector            |Real vector          " << std::endl;
	std::cout << std::left << std::setw(12) << "Size      = " << std::setw(20) << myvect.size() << " | " << std::setw(20) << realvect.size() << std::endl;
	std::cout << std::setw(12) << "Max_size  = " << std::setw(20) << myvect.max_size() << " | " << std::setw(20) << realvect.max_size() << std::endl;
	std::cout << std::setw(12) << "Capacity  = " << std::setw(20) << myvect.capacity() << " | " << std::setw(20) << realvect.capacity() << std::endl;
	std::cout << std::setw(12) << "Empty     = " << std::setw(20) << myvect.empty() << " | " << std::setw(20) << realvect.empty() << std::endl;
	std::cout << std::setw(12) << "Front     = " << std::setw(20) << myvect.front() << " | " << std::setw(20) << realvect.front() << std::endl;
	std::cout << std::setw(12) << "Back      = " << std::setw(20) << myvect.back() << " | " << std::setw(20) << realvect.back() << std::endl;

	std::cout << std::endl << "Displaying vector content :" << std::endl;
	ft::vector<int>::iterator it = myvect.begin();
	ft::vector<int>::iterator ite = myvect.end();
	std::vector<int>::iterator real_it = realvect.begin();
	std::vector<int>::iterator real_ite = realvect.end();
	int i = 0;
	while (it != ite){
		std::cout << "[" << i << "] " << *it << " | " << *real_it << std::endl;
		it++;
		real_it++;
		i++;
	}

	std::cout << std::endl << "Pushing back '3' :" << std::endl;
	realvect.push_back(3);
	myvect.push_back(3);

	std::cout << "            My vector            |Real vector          " << std::endl;
	std::cout << std::left << std::setw(12) << "Size      = " << std::setw(20) << myvect.size() << " | " << std::setw(20) << realvect.size() << std::endl;
	std::cout << std::setw(12) << "Max_size  = " << std::setw(20) << myvect.max_size() << " | " << std::setw(20) << realvect.max_size() << std::endl;
	std::cout << std::setw(12) << "Capacity  = " << std::setw(20) << myvect.capacity() << " | " << std::setw(20) << realvect.capacity() << std::endl;
	std::cout << std::setw(12) << "Empty     = " << std::setw(20) << myvect.empty() << " | " << std::setw(20) << realvect.empty() << std::endl;
	std::cout << std::setw(12) << "Front     = " << std::setw(20) << myvect.front() << " | " << std::setw(20) << realvect.front() << std::endl;
	std::cout << std::setw(12) << "Back      = " << std::setw(20) << myvect.back() << " | " << std::setw(20) << realvect.back() << std::endl;

	std::cout << std::endl << "Resize to 2 :" << std::endl;
	realvect.resize(2);
	myvect.resize(2);

	std::cout << "            My vector            |Real vector          " << std::endl;
	std::cout << std::left << std::setw(12) << "Size      = " << std::setw(20) << myvect.size() << " | " << std::setw(20) << realvect.size() << std::endl;
	std::cout << std::setw(12) << "Max_size  = " << std::setw(20) << myvect.max_size() << " | " << std::setw(20) << realvect.max_size() << std::endl;
	std::cout << std::setw(12) << "Capacity  = " << std::setw(20) << myvect.capacity() << " | " << std::setw(20) << realvect.capacity() << std::endl;
	std::cout << std::setw(12) << "Empty     = " << std::setw(20) << myvect.empty() << " | " << std::setw(20) << realvect.empty() << std::endl;
	std::cout << std::setw(12) << "Front     = " << std::setw(20) << myvect.front() << " | " << std::setw(20) << realvect.front() << std::endl;
	std::cout << std::setw(12) << "Back      = " << std::setw(20) << myvect.back() << " | " << std::setw(20) << realvect.back() << std::endl;

	std::cout << std::endl << "Resize to 10 :" << std::endl;
	realvect.resize(10);
	myvect.resize(10);

	std::cout << "            My vector            |Real vector          " << std::endl;
	std::cout << std::left << std::setw(12) << "Size      = " << std::setw(20) << myvect.size() << " | " << std::setw(20) << realvect.size() << std::endl;
	std::cout << std::setw(12) << "Max_size  = " << std::setw(20) << myvect.max_size() << " | " << std::setw(20) << realvect.max_size() << std::endl;
	std::cout << std::setw(12) << "Capacity  = " << std::setw(20) << myvect.capacity() << " | " << std::setw(20) << realvect.capacity() << std::endl;
	std::cout << std::setw(12) << "Empty     = " << std::setw(20) << myvect.empty() << " | " << std::setw(20) << realvect.empty() << std::endl;
	std::cout << std::setw(12) << "Front     = " << std::setw(20) << myvect.front() << " | " << std::setw(20) << realvect.front() << std::endl;
	std::cout << std::setw(12) << "Back      = " << std::setw(20) << myvect.back() << " | " << std::setw(20) << realvect.back() << std::endl;


	std::cout << std::endl << "Clearing :" << std::endl;
	realvect.clear();
	myvect.clear();

	std::cout << "            My vector            |Real vector          " << std::endl;
	std::cout << std::left << std::setw(12) << "Size      = " << std::setw(20) << myvect.size() << " | " << std::setw(20) << realvect.size() << std::endl;
	std::cout << std::setw(12) << "Max_size  = " << std::setw(20) << myvect.max_size() << " | " << std::setw(20) << realvect.max_size() << std::endl;
	std::cout << std::setw(12) << "Capacity  = " << std::setw(20) << myvect.capacity() << " | " << std::setw(20) << realvect.capacity() << std::endl;
	std::cout << std::setw(12) << "Empty     = " << std::setw(20) << myvect.empty() << " | " << std::setw(20) << realvect.empty() << std::endl;
}