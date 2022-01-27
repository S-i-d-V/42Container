#include <iostream>
#include <algorithm>
#include <map>
#include <iterator>

int	main(){
	//empty
	std::cout << "Creating an empty map :" << std::endl;
	std::map<char, int> rmap;
	std::cout << rmap.empty() << std::endl;

	//fill
	std::cout << std::endl << "Inserting alphabet :" << std::endl;
	char c = 'a';
	for (int i = 1; i < 27; i++, c++){
		rmap.insert(std::pair<char, int>(c, i));
	}
	std::cout << "size()= " << rmap.size() << std::endl;
	std::cout << "max_size()= " << rmap.max_size() << std::endl;

	//print by iterating
	std::cout << std::endl << "Printing content" << std::endl;
	std::map<char, int>::iterator it;
	for (it = rmap.begin(); it != rmap.end(); it++)
		std::cout << it->first << " => " << it->second << std::endl;

	return (0);
}