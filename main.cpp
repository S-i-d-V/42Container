#include "includes/myVector.hpp"

#include <iostream>
#include <algorithm>
#include <vector>

int	main(){
	//My vector
	//Default constructor
	ft::vector<int> myvect1;
	ft::vector<int>::iterator it = myvect1.begin();
	ft::vector<int>::iterator ite = myvect1.end();
	//Fill constructor
	ft::vector<int> myvect2(5, 0);
	it = myvect2.begin();
	ite = myvect2.end();
	//Range constructor
	ft::vector<int> myvect3(it, ite);
	//Copy constructor
	ft::vector<int> myvect4(myvect3);
}