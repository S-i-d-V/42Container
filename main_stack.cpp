#include "containers/stack/stack.hpp"

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <stack>

int	main(){
	std::cout << "Creating an empty stack :" << std::endl;
	std::stack<int> realstack;
	ft::stack<int> mystack;
	std::cout << "            My stack             |Real stack           " << std::endl;
	std::cout << std::left << std::setw(12) << "Size      = " << std::setw(20) << mystack.size() << " | " << std::setw(20) << realstack.size() << std::endl;
	std::cout << std::setw(12) << "Empty     = " << std::setw(20) << mystack.empty() << " | " << std::setw(20) << realstack.empty() << std::endl;

	std::cout << std::endl << "Pushing the number 1 :" << std::endl;
	realstack.push(1);
	mystack.push(1);
	std::cout << "            My stack             |Real stack           " << std::endl;
	std::cout << std::left << std::setw(12) << "Size      = " << std::setw(20) << mystack.size() << " | " << std::setw(20) << realstack.size() << std::endl;
	std::cout << std::setw(12) << "Empty     = " << std::setw(20) << mystack.empty() << " | " << std::setw(20) << realstack.empty() << std::endl;
	std::cout << std::setw(12) << "Top       = " << std::setw(20) << mystack.top() << " | " << std::setw(20) << realstack.top() << std::endl;

	std::cout << std::endl << "Pushing the number 2 :" << std::endl;
	realstack.push(2);
	mystack.push(2);
	std::cout << "            My stack             |Real stack           " << std::endl;
	std::cout << std::left << std::setw(12) << "Size      = " << std::setw(20) << mystack.size() << " | " << std::setw(20) << realstack.size() << std::endl;
	std::cout << std::setw(12) << "Empty     = " << std::setw(20) << mystack.empty() << " | " << std::setw(20) << realstack.empty() << std::endl;
	std::cout << std::setw(12) << "Top       = " << std::setw(20) << mystack.top() << " | " << std::setw(20) << realstack.top() << std::endl;

	std::cout << std::endl << "Popping the element on the top of the stack :" << std::endl;
	realstack.pop();
	mystack.pop();
	std::cout << "            My stack             |Real stack           " << std::endl;
	std::cout << std::left << std::setw(12) << "Size      = " << std::setw(20) << mystack.size() << " | " << std::setw(20) << realstack.size() << std::endl;
	std::cout << std::setw(12) << "Empty     = " << std::setw(20) << mystack.empty() << " | " << std::setw(20) << realstack.empty() << std::endl;
	std::cout << std::setw(12) << "Top       = " << std::setw(20) << mystack.top() << " | " << std::setw(20) << realstack.top() << std::endl;

	std::cout << std::endl << "Re-pushing the number 2 :" << std::endl;
	realstack.push(2);
	mystack.push(2);
	std::cout << "            My stack             |Real stack           " << std::endl;
	std::cout << std::left << std::setw(12) << "Size      = " << std::setw(20) << mystack.size() << " | " << std::setw(20) << realstack.size() << std::endl;
	std::cout << std::setw(12) << "Empty     = " << std::setw(20) << mystack.empty() << " | " << std::setw(20) << realstack.empty() << std::endl;
	std::cout << std::setw(12) << "Top       = " << std::setw(20) << mystack.top() << " | " << std::setw(20) << realstack.top() << std::endl;

	std::cout << std::endl << "Popping all the elements :" << std::endl;
	realstack.pop();
	mystack.pop();
	realstack.pop();
	mystack.pop();
	std::cout << "            My stack             |Real stack           " << std::endl;
	std::cout << std::left << std::setw(12) << "Size      = " << std::setw(20) << mystack.size() << " | " << std::setw(20) << realstack.size() << std::endl;
	std::cout << std::setw(12) << "Empty     = " << std::setw(20) << mystack.empty() << " | " << std::setw(20) << realstack.empty() << std::endl;
}