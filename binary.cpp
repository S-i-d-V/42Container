#include "utils/binary_tree.hpp"

#include <iostream>
#include <cstring>

int	main(){
	ft::nodeBT<int> *root = new ft::nodeBT<int>(5, NULL, NULL, NULL);
	std::cout << "root : " << root->_data << std::endl;

	root->_left = new ft::nodeBT<int>(2, NULL, NULL, root);
	root->_right = new ft::nodeBT<int>(3, NULL, NULL, root);
	std::cout << "root->left : " << root->_left->_data << std::endl;
	std::cout << "root->right : " << root->_right->_data << std::endl;

	root->_left->_left = new ft::nodeBT<int>(3, NULL, NULL, root->_left);
	root->_left->_right = new ft::nodeBT<int>(6, NULL, NULL, root->_left);
	std::cout << "root->left->left : " << root->_left->_left->_data << std::endl;
	std::cout << "root->left->right : " << root->_left->_right->_data << std::endl;

	root->_right->_left = new ft::nodeBT<int>(7, NULL, NULL, root->_right);
	root->_right->_right = new ft::nodeBT<int>(11, NULL, NULL, root->_right);
	std::cout << "root->right->left : " << root->_right->_left->_data << std::endl;
	std::cout << "root->right->right : " << root->_right->_right->_data << std::endl;
}