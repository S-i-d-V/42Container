#include "includes/myVector.hpp"

#include <iostream>
#include <algorithm>
#include <vector>

int	main(){
	//Default constructor
	{
		std::cout << "Default constructor :" << std::endl;
		ft::vector<int> myvect1;
	}

	//Fill constructor
	{
		std::cout << std::endl << "Fill constructor :" << std::endl;
		ft::vector<int> myvect2(5, 0);
	}

	//Range constructor
	{
		std::cout << std::endl << "Range constructor :" << std::endl;
		std::vector<int> realvect3(5, 0);
		ft::vector<int> myvect3(realvect3.begin(), realvect3.end());
	}

}