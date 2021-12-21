#include "containers/vector/vector.hpp"

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

int	main(){
	std::vector<int> realvect(5, 3);
	ft::vector<int> myvect(5, 3);

	//Test des iterators
	std::cout << "Content displayed by iterators :" << std::endl;
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

	//Test des reverse_iterators
	std::cout << std::endl << "Content displayed by reverse_iterators :" << std::endl;
	ft::vector<int>::reverse_iterator rit = myvect.rbegin();
	ft::vector<int>::reverse_iterator rite = myvect.rend();
	std::vector<int>::reverse_iterator real_rit = realvect.rbegin();
	std::vector<int>::reverse_iterator real_rite = realvect.rend();
	std::cout << "REAL | rbegin : " << *real_rit << " - " << &(*(real_rit.base())) << " | rend : " << *real_rite << " - " << &(*(real_rite.base())) << std::endl; 
	std::cout << "MINE | rbegin : " << *rit << " - " << &(*(rit.base())) << " | rend : " << *rite << " - " << &(*(rite.base())) << std::endl << std::endl;

	i = 0;
	while (real_rit != real_rite){
		std::cout << "[" << i << "] " << *rit << " - " << &(*rit) << " | " << *real_rit << " - " << &(*real_rit) << std::endl;
		rit++;
		real_rit++;
		i++;
	}
}