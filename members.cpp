#include "containers/vector/vector.hpp"

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

int	main(){
    std::vector<int> realvect;
	ft::vector<int> myvect;

    //Test des return des fonctions membres
	std::cout << std::endl << "Member functions returns :" << std::endl;
	std::cout << std::endl << "            My vector            |Real vector          " << std::endl;
	std::cout << std::left << std::setw(12) << "Size      = " << std::setw(20) << myvect.size() << " | " << std::setw(20) << realvect.size() << std::endl;
	std::cout << std::setw(12) << "Max_size  = " << std::setw(20) << myvect.max_size() << " | " << std::setw(20) << realvect.max_size() << std::endl;
	std::cout << std::setw(12) << "Capacity  = " << std::setw(20) << myvect.capacity() << " | " << std::setw(20) << realvect.capacity() << std::endl;
	std::cout << std::setw(12) << "Empty     = " << std::setw(20) << myvect.empty() << " | " << std::setw(20) << realvect.empty() << std::endl;

	std::cout << std::endl << "Pushing back '42' :" << std::endl;
	realvect.push_back(42);
	myvect.push_back(42);

	//Test des return des fonctions membres
	std::cout << std::endl << "Member functions returns :" << std::endl;
	std::cout << std::endl << "            My vector            |Real vector          " << std::endl;
	std::cout << std::left << std::setw(12) << "Size      = " << std::setw(20) << myvect.size() << " | " << std::setw(20) << realvect.size() << std::endl;
	std::cout << std::setw(12) << "Max_size  = " << std::setw(20) << myvect.max_size() << " | " << std::setw(20) << realvect.max_size() << std::endl;
	std::cout << std::setw(12) << "Capacity  = " << std::setw(20) << myvect.capacity() << " | " << std::setw(20) << realvect.capacity() << std::endl;
	std::cout << std::setw(12) << "Empty     = " << std::setw(20) << myvect.empty() << " | " << std::setw(20) << realvect.empty() << std::endl;

	std::cout << std::endl << "Pushing back '0' :" << std::endl;
	realvect.push_back(0);
	myvect.push_back(0);

	//Test des return des fonctions membres
	std::cout << std::endl << "Member functions returns :" << std::endl;
	std::cout << std::endl << "            My vector            |Real vector          " << std::endl;
	std::cout << std::left << std::setw(12) << "Size      = " << std::setw(20) << myvect.size() << " | " << std::setw(20) << realvect.size() << std::endl;
	std::cout << std::setw(12) << "Max_size  = " << std::setw(20) << myvect.max_size() << " | " << std::setw(20) << realvect.max_size() << std::endl;
	std::cout << std::setw(12) << "Capacity  = " << std::setw(20) << myvect.capacity() << " | " << std::setw(20) << realvect.capacity() << std::endl;
	std::cout << std::setw(12) << "Empty     = " << std::setw(20) << myvect.empty() << " | " << std::setw(20) << realvect.empty() << std::endl;

	std::cout << std::endl << "Pushing back '42' :" << std::endl;
	realvect.push_back(-1);
	myvect.push_back(-1);

	//Test des return des fonctions membres
	std::cout << std::endl << "Member functions returns :" << std::endl;
	std::cout << std::endl << "            My vector            |Real vector          " << std::endl;
	std::cout << std::left << std::setw(12) << "Size      = " << std::setw(20) << myvect.size() << " | " << std::setw(20) << realvect.size() << std::endl;
	std::cout << std::setw(12) << "Max_size  = " << std::setw(20) << myvect.max_size() << " | " << std::setw(20) << realvect.max_size() << std::endl;
	std::cout << std::setw(12) << "Capacity  = " << std::setw(20) << myvect.capacity() << " | " << std::setw(20) << realvect.capacity() << std::endl;
	std::cout << std::setw(12) << "Empty     = " << std::setw(20) << myvect.empty() << " | " << std::setw(20) << realvect.empty() << std::endl;
}