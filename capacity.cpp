#include "containers/vector/vector.hpp"

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

int	main(){
	std::cout << "Constructor" << std::endl;
	std::vector<int> a;
	ft::vector<int> b;

	std::cout << std::endl << "J'initialise un vecteur vide." << std::endl;
	std::cout << std::left << std::setw(12) << "           " << std::setw(12) << "Real vector" << " | " << std::setw(12) << "My vector" << std::endl;
	std::cout << std::left << std::setw(12) << "           " << std::setw(12) << a.capacity() << " | " << std::setw(12) << b.capacity() << std::endl;

	int oldcapacity = a.capacity();

	for (int i = 1; i <= 10; i++){
		a.push_back(i);
		std::cout << std::endl << "J'ajoute : " << i << std::endl;
		std::cout << std::left << std::setw(12) << "           " << std::setw(12) << "Real vector" << " | " << std::setw(12) << "My vector" << std::endl;
		std::cout << std::left << std::setw(12) << "           " << std::setw(12) << a.capacity() << " | " << std::setw(12) << b.capacity() << std::endl;
		oldcapacity = a.capacity();
	}

	std::cout << std::endl << "Mon vecteur contient 20 chiffres." << std::endl;
	std::cout << std::left << std::setw(12) << "           " << std::setw(12) << "Real vector" << " | " << std::setw(12) << "My vector" << std::endl;
	std::cout << std::left << std::setw(12) << "           " << std::setw(12) << a.capacity() << " | " << std::setw(12) << b.capacity() << std::endl;

	std::cout << std::endl << "Destructor" << std::endl;
	return (0);
}