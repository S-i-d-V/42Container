#include "includes/myVector.hpp"

#include <iostream>
#include <algorithm>
#include <vector>

int	main(){
	//Default constructor
	//Construit un container vector vide;
	std::cout << "Constructeur (Default):" << std::endl;
	std::vector<int>	vect1;
	//Display
	std::vector<int>::iterator it = vect1.begin();
	std::vector<int>::iterator ite = vect1.end();
	while (it != ite){
		printf("%d ", *it);
		it++;
	}
	printf("\n\n");

	//Fill constructor
	//Construit un container vector contenant 5 fois (premier arg) la valeur 0 (deuxieme arg);
	std::cout << "Constructeur (Fill) :" << std::endl;
	std::vector<int>	vect2(5, 0);
	//Display
	it = vect2.begin();
	ite = vect2.end();
	while (it != ite){
		printf("%d ", *it);
		it++;
	}
	printf("\n\n");

	//Range constructor
	//Construit un container a partir des elements allant de first (premier arg) a last (deuxieme arg)
	std::cout << "Constructeur (Range) :" << std::endl;
	std::vector<int>	vect3(vect2.begin(), vect2.end());
	//Display
	it = vect3.begin();
	ite = vect3.end();
	while (it != ite){
		printf("%d ", *it);
		it++;
	}
	printf("\n\n");

	//Copy constructor
	//Construit une copy du container src (premier arg);
	std::cout << "Constructeur (Copy) :" << std::endl;
	std::vector<int>	vect4(vect3);
	//Display
	it = vect4.begin();
	ite = vect4.end();
	while (it != ite){
		printf("%d ", *it);
		it++;
	}
	printf("\n\n");

	return (0);	
}