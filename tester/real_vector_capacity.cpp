//Header necessaire au fonctionnement de vector
#include <algorithm>
#include <iterator>
#include <vector>

//Header pour affichage
#include <iostream>
#include <iomanip>

void test_vector_func_size(){
	int nbTest = 1;

	std::cout << "size" << std::endl;
	/*Empty vector*/{
		std::vector<int> empty;
		std::cout << "[" << std::setw(2) << nbTest << "] " << empty.size() << std::endl;
	}
	nbTest++;
}

//Max_Size
void test_vector_func_maxsize(){
	int nbTest = 1;

	std::cout << "max_size" << std::endl;
	/*Empty vector*/{
		std::vector<int> empty;
		std::cout << "[" << std::setw(2) << nbTest << "] " << empty.max_size() << std::endl;
	}
	nbTest++;
}

//Resize
void test_vector_func_resize(){
	int nbTest = 1;

	std::cout << "resize" << std::endl;
	/*resize negative on empty vector*/{
		std::vector<int> empty;
		try {empty.resize(-1);}
		catch (std::length_error &e){
			std::cout << "[" << std::setw(2) << nbTest << "] " << "error" << std::endl;
		}
	}
	nbTest++;
	/*resize max_size + 1 on empty vector*/{
		std::vector<int> empty;
		try {empty.resize(empty.max_size() + 1);}
		catch (std::length_error &e){
			std::cout << "[" << std::setw(2) << nbTest << "] " << "error" << std::endl;
		}
	}
	nbTest++;
	/*resize 0 on empty vector*/{
		std::vector<int> empty;
		empty.resize(0);
		std::cout << "[" << std::setw(2) << nbTest << "] " << empty.size() << std::endl;
	}
	nbTest++;
	/*resize 10 on empty vector*/{
		std::vector<int> empty;
		empty.resize(10);
		std::cout << "[" << std::setw(2) << nbTest << "] " << empty.size() << std::endl;
	}
	nbTest++;
	/*resize 0 on filled vector*/{
		std::vector<int> filled(5, 0);
		filled.resize(0);
		std::cout << "[" << std::setw(2) << nbTest << "] " << filled.size() << std::endl;
	}
	nbTest++;
	/*resize 10 on filled vector of size 5*/{
		std::vector<int> filled(5, 0);
		filled.resize(10);
		std::cout << "[" << std::setw(2) << nbTest << "] " << filled.size() << std::endl;
	}
	nbTest++;
	/*resize 10 on filled vector of size 50*/{
		std::vector<int> filled(50, 0);
		filled.resize(10);
		std::cout << "[" << std::setw(2) << nbTest << "] " << filled.size() << std::endl;
	}
	nbTest++;
	/*resize 10 on filled vector of size 10*/{
		std::vector<int> filled(10, 0);
		filled.resize(10);
		std::cout << "[" << std::setw(2) << nbTest << "] " << filled.size() << std::endl;
	}
	nbTest++;
}

//Capacity
void test_vector_func_capacity(){
	int nbTest = 1;

	std::cout << "capacity" << std::endl;
	/*capacity on empty vector*/{
		std::vector<int> empty;
		std::cout << "[" << std::setw(2) << nbTest << "] " << empty.capacity() << std::endl;
	}
	nbTest++;
}

//Empty
void test_vector_func_empty(){
	int nbTest = 1;

	std::cout << "empty" << std::endl;
	/*empty on empty vector*/{
		std::vector<int> empty;
		std::cout << "[" << std::setw(2) << nbTest << "] " << empty.empty() << std::endl;
	}
	nbTest++;
	/*empty on empty reserved 10 vector*/{
		std::vector<int> empty;
		empty.reserve(10);
		std::cout << "[" << std::setw(2) << nbTest << "] " << empty.empty() << std::endl;
	}
	nbTest++;
	/*empty on filled vector*/{
		std::vector<int> filled(5, 0);
		std::cout << "[" << std::setw(2) << nbTest << "] " << filled.empty() << std::endl;
	}
	nbTest++;
	/*empty on erased vector*/{
		std::vector<int> filled(1, 0);
		filled.erase(filled.begin());
		std::cout << "[" << std::setw(2) << nbTest << "] " << filled.empty() << std::endl;
	}
	nbTest++;
	/*empty on cleared vector*/{
		std::vector<int> filled(5, 0);
		filled.clear();
		std::cout << "[" << std::setw(2) << nbTest << "] " << filled.empty() << std::endl;
	}
	nbTest++;
}

//Reserve
void test_vector_func_reserve(){
	int nbTest = 1;

	std::cout << "reserve" << std::endl;
	/*reserve negative on empty vector*/{
		std::vector<int> empty;
		try {empty.reserve(-1);}
		catch (std::length_error &e){
			std::cout << "[" << std::setw(2) << nbTest << "] " << "error" << std::endl;
		}
	}
	nbTest++;
	/*reserve max_size + 1 on empty vector*/{
		std::vector<int> empty;
		try {empty.reserve(empty.max_size() + 1);}
		catch (std::length_error &e){
			std::cout << "[" << std::setw(2) << nbTest << "] " << "error" << std::endl;
		}
	}
	nbTest++;
	/*reserve 0 on empty vector*/{
		std::vector<int> empty;
		empty.reserve(0);
		std::cout << "[" << std::setw(2) << nbTest << "] " << empty.capacity() << std::endl;
	}
	nbTest++;
	/*reserve 10 on empty vector*/{
		std::vector<int> empty;
		empty.reserve(10);
		std::cout << "[" << std::setw(2) << nbTest << "] " << empty.capacity() << std::endl;
	}
	nbTest++;
	/*reserve 0 on filled vector*/{
		std::vector<int> filled(5, 0);
		filled.reserve(0);
		std::cout << "[" << std::setw(2) << nbTest << "] " << filled.capacity() << std::endl;
	}
	nbTest++;
	/*reserve 10 on filled vector*/{
		std::vector<int> filled(5, 0);
		filled.reserve(10);
		std::cout << "[" << std::setw(2) << nbTest << "] " << filled.capacity() << std::endl;
	}
	nbTest++;
	/*reserve 0 on erased vector*/{
		std::vector<int> filled(1, 0);
		filled.erase(filled.begin());
		filled.reserve(0);
		std::cout << "[" << std::setw(2) << nbTest << "] " << filled.capacity() << std::endl;
	}
	nbTest++;
	/*reserve 10 on erased vector*/{
		std::vector<int> filled(1, 0);
		filled.erase(filled.begin());
		filled.reserve(10);
		std::cout << "[" << std::setw(2) << nbTest << "] " << filled.capacity() << std::endl;
	}
	nbTest++;
	/*reserve 0 on cleared vector*/{
		std::vector<int> filled(5, 0);
		filled.clear();
		filled.reserve(0);
		std::cout << "[" << std::setw(2) << nbTest << "] " << filled.capacity() << std::endl;
	}
	nbTest++;
	/*reserve 10 on cleared vector*/{
		std::vector<int> filled(5, 0);
		filled.clear();
		filled.reserve(10);
		std::cout << "[" << std::setw(2) << nbTest << "] " << filled.capacity() << std::endl;
	}
	nbTest++;
}

void	test_vector_capacity(){
	std::cout << "CAPACITY" << std::endl;
	//Size
	test_vector_func_size();
	//Max_Size
	test_vector_func_maxsize();
	//Resize
	test_vector_func_resize();
	//Capacity
	test_vector_func_capacity();
	//Empty
	test_vector_func_empty();
	//Reserve
	test_vector_func_reserve();
}

int main(){
	test_vector_capacity();
	return (0);
}