#include "containers/vector/vector.hpp"

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

int	main(){
    std::vector<int> realvect;
	ft::vector<int> myvect;

	std::cout << "            My vector            |Real vector          " << std::endl;
	std::cout << std::left << std::setw(12) << "Size      = " << std::setw(20) << myvect.size() << " | " << std::setw(20) << realvect.size() << std::endl;
	std::cout << std::setw(12) << "Max_size  = " << std::setw(20) << myvect.max_size() << " | " << std::setw(20) << realvect.max_size() << std::endl;
	std::cout << std::setw(12) << "Capacity  = " << std::setw(20) << myvect.capacity() << " | " << std::setw(20) << realvect.capacity() << std::endl;
	std::cout << std::setw(12) << "Empty     = " << std::setw(20) << myvect.empty() << " | " << std::setw(20) << realvect.empty() << std::endl;

	std::cout << std::endl << "Pushing back '42' :" << std::endl;
	realvect.push_back(42);
	myvect.push_back(42);

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

	std::cout << std::endl << "Inserting 10 at the beginning:" << std::endl;
	realvect.insert(realvect.end() - 1, 10);
	myvect.insert(myvect.end() - 1, 10);

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