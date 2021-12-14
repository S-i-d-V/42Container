#include "containers/vector/vector.hpp"

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

int	main(){
	{
		std::cout << "Fill constructor :" << std::endl;
		std::vector<int> realvect2(5, 3);
		ft::vector<int> myvect(5, 3);

		//Test des return des fonctions membres
		std::cout << std::endl << "Member functions returns :" << std::endl;
		std::cout << std::endl << "            My vector            |Real vector          " << std::endl;
		std::cout << std::left << std::setw(12) << "Size      = " << std::setw(20) << myvect.size() << " | " << std::setw(20) << realvect2.size() << std::endl;
		std::cout << std::setw(12) << "Max_size  = " << std::setw(20) << myvect.max_size() << " | " << std::setw(20) << realvect2.max_size() << std::endl;
		std::cout << std::setw(12) << "Capacity  = " << std::setw(20) << myvect.capacity() << " | " << std::setw(20) << realvect2.capacity() << std::endl;
		std::cout << std::setw(12) << "Empty     = " << std::setw(20) << myvect.empty() << " | " << std::setw(20) << realvect2.empty() << std::endl;
		std::cout << std::setw(12) << "Front     = " << std::setw(20) << myvect.front() << " | " << std::setw(20) << realvect2.front() << std::endl;
		std::cout << std::setw(12) << "Back      = " << std::setw(20) << myvect.back() << " | " << std::setw(20) << realvect2.back() << std::endl;

		//Test des iterators
		std::cout << std::endl << "Content displayed by iterators :" << std::endl;
		ft::vector<int>::iterator it = myvect.begin();
		ft::vector<int>::iterator ite = myvect.end();
		int i = 0;
		while (it != ite){
			std::cout << "[" << i << "] " << *it  << std::endl;
			it++;
			i++;
		}

		//Test des iterators_const
		std::cout << std::endl << "Content displayed by const_iterators :" << std::endl;
		ft::vector<int>::const_iterator cit = myvect.cbegin();
		ft::vector<int>::const_iterator cite = myvect.cend();
		i = 0;
		while (cit != cite){
			std::cout << "[" << i << "] " << *cit  << std::endl;
			cit++;
			i++;
		}

		//Test des reverse_iterators
		std::cout << std::endl << "Content displayed by reverse_iterators :" << std::endl;
		ft::vector<int>::reverse_iterator rit = myvect.rbegin();
		ft::vector<int>::reverse_iterator rite = myvect.rend();
		i = 0;
		while (rit != rite){
			std::cout << "[" << i << "] " << *rit  << std::endl;
			rit++;
			i++;
		}

		//Test des const_reverse_iterators
		std::cout << std::endl << "Content displayed by const_reverse_iterators :" << std::endl;
		ft::vector<int>::const_reverse_iterator crit = myvect.crbegin();
		ft::vector<int>::const_reverse_iterator crite = myvect.crend();
		i = 0;
		while (crit != crite){
			std::cout << "[" << i << "] " << *crit  << std::endl;
			crit++;
			i++;
		}

	}

}