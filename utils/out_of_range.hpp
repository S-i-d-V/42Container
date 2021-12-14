#ifndef OUT_OF_RANGE_HPP
#define OUT_OF_RANGE_HPP

#include <iostream>
#include <iomanip>

namespace ft{
	class out_of_range : public std::exception{
		char const* what() const throw(){
			return ("Index out of the vector.");
		}
	};
}

#endif