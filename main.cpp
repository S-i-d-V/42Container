#include "includes/myVector.hpp"

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

int	main(){
	//Default constructor
	{
		std::cout << "Default constructor :" << std::endl;
		std::vector<int> realvect1;
		ft::vector<int> myvect1;

		std::cout << std::endl << "            My vector            |Real vector          " << std::endl;
		std::cout << std::left << std::setw(12) << "Size      = " << std::setw(20) << myvect1.size() << " | " << std::setw(20) << realvect1.size() << std::endl;
		std::cout << std::setw(12) << "Max_size  = " << std::setw(20) << myvect1.max_size() << " | " << std::setw(20) << realvect1.max_size() << std::endl;
	}

	//Fill constructor
	{
		std::cout << std::endl << "Fill constructor :" << std::endl;
		std::vector<int> realvect2(5, 0);
		ft::vector<int> myvect2(5, 0);

		std::cout << std::endl << "            My vector            |Real vector          " << std::endl;
		std::cout << std::left << std::setw(12) << "Size      = " << std::setw(20) << myvect2.size() << " | " << std::setw(20) << realvect2.size() << std::endl;
		std::cout << std::setw(12) << "Max_size  = " << std::setw(20) << myvect2.max_size() << " | " << std::setw(20) << realvect2.max_size() << std::endl;
	}

	//Range constructor
	{
		std::cout << std::endl << "Range constructor :" << std::endl;
		std::vector<int> realvect3(5, 1);
		ft::vector<int> myvect3(realvect3.begin(), realvect3.end());
	}

}