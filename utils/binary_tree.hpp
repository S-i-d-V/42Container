/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 02:06:43 by user42            #+#    #+#             */
/*   Updated: 2022/02/25 16:16:33 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Protections of the header
#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

/*****************************************************************************/
/*                                Includes                                   */
/*****************************************************************************/

//Utils headers
#include <string>
#include <memory>
#include <stddef.h>

//Headers needed by binary tree
#include "iterator_traits.hpp"
#include "../containers/map/map_iterator.hpp"
#include "reverse_iterator.hpp"
#include "pair.hpp"
#include "equal.hpp"
#include "lexicographical_compare.hpp"

/*****************************************************************************/
/*                              Namespace FT                                 */
/*****************************************************************************/

namespace ft{
	//Definition of node_color
	typedef enum  {BLACK, RED}	node_color;

	/*****************************************************************************/
	/*                              NodeBT Class                                 */
	/*****************************************************************************/
	template<class T>
	class nodeBT{

	/*****************************************************************************/
	/*                               Public members                              */
	/*****************************************************************************/

	public:

		/*****************************************************************************/
		/*                              Members types                                */
		/*****************************************************************************/
		typedef T				value_type;
		typedef	nodeBT*			pointer;
		typedef	nodeBT&			reference;


		/*****************************************************************************/
		/*                               Constructors                                */
		/*****************************************************************************/

		//Default
		nodeBT(): _data(NULL), _color(BLACK), _left(NULL), _right(NULL), _parent(NULL) {
			return;
		}

		//Init
		nodeBT(value_type const &x): _data(x), _color(BLACK), _left(NULL), _right(NULL), _parent(NULL) {
			return;
		}

		//Copy
		nodeBT(nodeBT const &src): _data(src._data), _color(src._color), _left(src._left), _right(src._right), _parent(src._parent) {
			return;
		}

		/*****************************************************************************/
		/*                                Destructor                                 */
		/*****************************************************************************/

		//Destructor
		~nodeBT() {
			return;
		}

		/*****************************************************************************/
		/*                           Operator olverloads                             */
		/*****************************************************************************/

		//Assignement operator
		reference	operator=(reference rhs)
		{
			_data = rhs._data;
			_color = rhs._color;
			_left = rhs._left;
			_right = rhs._right;
			_parent = rhs._parent;
			return (*this);
		}

		/*****************************************************************************/
		/*                                 Members                                   */
		/*****************************************************************************/

		value_type	_data;
		node_color	_color;
		pointer		_left;
		pointer		_right;
		pointer		_parent;
	};




	/*****************************************************************************/
	/*                               treeRB Class                                */
	/*****************************************************************************/

	template<class T, class Compare = std::less<T>, class Allocator = std::allocator<ft::nodeBT<T> > >
	class treeRB{

	/*****************************************************************************/
	/*                               Public members                              */
	/*****************************************************************************/

	public:

		/*****************************************************************************/
		/*                              Members types                                */
		/*****************************************************************************/

		typedef T																		value_type;
		typedef nodeBT<value_type>														node_type;
		typedef Compare																	key_compare;
		typedef	size_t																	size_type;
		typedef std::ptrdiff_t															difference_type;

		typedef Allocator																allocator_type;
		typedef typename allocator_type::pointer										pointer;
		typedef typename allocator_type::const_pointer									const_pointer;
		typedef typename allocator_type::reference										reference;
		typedef typename allocator_type::const_reference								const_reference;

		typedef	typename ft::map_iterator<node_type, value_type>						iterator;
		typedef typename ft::map_iterator<node_type const, value_type const>			const_iterator;
		typedef ft::reverse_iterator<iterator>											reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>									const_reverse_iterator;


		/*****************************************************************************/
		/*                               Constructors                                */
		/*****************************************************************************/

		//Default
		explicit treeRB(Compare const &comp = key_compare(), Allocator const &alloc = Allocator()): _size(0), _alloc(alloc), _comp(comp){
			//allocation of the tNull node
			_tNull = _alloc.allocate(1);
			_alloc.construct(_tNull, value_type());
			_tNull->_left = NULL;
			_tNull->_right = NULL;
			_tNull->_color = BLACK;
			_root = _tNull;
			return;
		}

		//Copy
		treeRB(treeRB const &src): _size(0), _root(NULL){
			//allocation of the tNull node
			_tNull = _alloc.allocate(1);
			_alloc.construct(_tNull, value_type());
			_tNull->_left = NULL;
			_tNull->_right = NULL;
			_tNull->_color = BLACK;
			_root = _tNull;
			//copy of the three
			*this = src;
			return;
		}


		/*****************************************************************************/
		/*                                Destructors                                */
		/*****************************************************************************/

		//Destructor
		~treeRB(){
			clear();
			_alloc.destroy(_tNull);
			_alloc.deallocate(_tNull, 1);
			return;
		}


		/*****************************************************************************/
		/*                           Operator olverloads                             */
		/*****************************************************************************/

		//Assignement operator
		treeRB	&operator=(treeRB const &rhs){
			clear();
			
			const_iterator it = rhs.begin();
			while (it != rhs.end()){
				insert(it._valPtr->_data);
				it++;
			}
			return (*this);
		}


		/*****************************************************************************/
		/*                                Iterators                                  */
		/*****************************************************************************/

		iterator	begin(){
			return (iterator(getMin(_root), _tNull));
		}

		const_iterator	begin() const{
			return (const_iterator(getMin(_root), _tNull));
		}
		

		iterator	end(void){
			return (iterator(_tNull, _tNull));
		}

		const_iterator	end(void) const{
			return (const_iterator(_tNull, _tNull));
		}


		reverse_iterator	rbegin(){
			return (reverse_iterator(iterator(_tNull, _tNull)));
		}

		const_reverse_iterator	rbegin() const{
			return (const_reverse_iterator(const_iterator(_tNull, _tNull)));
		}


		reverse_iterator	rend(){
			return (reverse_iterator(iterator(getMin(_root), _tNull)));
		}

		const_reverse_iterator	rend() const{
			return (const_reverse_iterator(const_iterator(getMin(_root), _tNull)));
		}


		/*****************************************************************************/
		/*                                Modifiers                                  */
		/*****************************************************************************/

		//Insert an element
		ft::pair<iterator, bool>	insert(value_type const &val){
			//allocation of the node to insert
			pointer node = _alloc.allocate(1);
			_alloc.construct(node, val);
			node->_left = _tNull;
			node->_right = _tNull;
			node->_color = RED;
			//y be the leaf and x the root
			pointer	y = NULL;
			pointer x = _root;
			//i traverse from the root to the leafs and check if the key is already in the tree
			while (x != _tNull){
				y = x;
				if (_comp(node->_data, x->_data))
					x = x->_left;
				else if (_comp(x->_data, node->_data))
					x = x->_right;
				else
					//apairing the node with false because the key was already in
					return (ft::make_pair(x, false));
			}
			_size++;
			node->_parent = y;
			//if y is still NULL so the map is empty and he become the root
			if (y == NULL)
				_root = node;
			//else i put it on the left or right if he's lower or higher than y childs
			else if (_comp(node->_data, y->_data))
				y->_left = node;
			else
				y->_right = node;
			
			//if the three is empty and the inserted node is the root, he become black 
			if (node->_parent == NULL){
				node->_color = BLACK;
				_tNull->_parent = _root;
				return (ft::make_pair(node, true));
			}
			//if the inserted node if a child of the root, we dont need to fix the violations of balancing
			if (node->_parent->_parent == NULL){
				_tNull->_parent = _root;
				return (ft::make_pair(node, true));
			}
			//Fix violations of the rules caused by insert
			fixInsert(node);
			_tNull->_parent = _root;
			return (ft::make_pair(node, true));
		}

		//With hint
		iterator	insert(iterator position, value_type const &val){
			(void)position;
			return ((insert(val)).first);
		}

		//Delete an element
		void	erase(pointer toDelete){
			pointer		x;
			pointer		y = toDelete;
			node_color	originalColor = toDelete->_color;
			//if the left child of the node the delete is a leaf, i transplant the node on the right child
			if (toDelete->_left == _tNull){
				x = toDelete->_right;
				transplantNode(toDelete, toDelete->_right);
			}
			//if the right child of the node the delete is a leaf, i transplant the node on the left child
			else if (toDelete->_right == _tNull){
				x = toDelete->_left;
				transplantNode(toDelete, toDelete->_left);
			}
			//if none is a leaf, then we arent 
			else{
				y = getMin(toDelete->_right);
				originalColor = y->_color;
				x = y->_right;
				//if y is a child of the node to delete, y become the parent of x
				if (y->_parent == toDelete)
					x->_parent = y;
				//else i transplant y with his right child
				else{
					transplantNode(y, y->_right);
					y->_right = toDelete->_right;
					y->_right->_parent = y;
				}
				//then i transplant the node the del with y and assign the original color
				transplantNode(toDelete, y);
				y->_left = toDelete->_left;
				y->_left->_parent = y;
				y->_color = originalColor;
			}
			//Delete the node
			_alloc.destroy(toDelete);
			_alloc.deallocate(toDelete, 1);
			//Fix violations of the rules caused by insert
			if (originalColor == BLACK)
				fixErase(x);
			_size--;
			_tNull->_parent = _root;
		}


		//Swap the 2 elements
		void	swap(treeRB &rhs){
			std::swap(_root, rhs._root);
			std::swap(_tNull, rhs._tNull);
			std::swap(_size, rhs._size);
		}


		//Delete all elements in the map
		void	clear(){
			while (_root != _tNull)
				erase(_root);
		}

		/*****************************************************************************/
		/*                                Operations                                 */
		/*****************************************************************************/

		//Search an element with a key equivalent to k and return in iterator to it, if there is not it return an iterator to end()
		iterator	find(value_type const &val){
			pointer	ret = _root;

			while (ret != _tNull){
				if (_comp(val, ret->_data))
					ret = ret->_left;
				else if (_comp(ret->_data, val))
					ret = ret->_right;
				else
					return (ret);
			}
			return (end());
		}

		//Search an element with a key equivalent to k and return in const_iterator to it, if there is not it return an const_iterator to end()
		const_iterator	find(value_type const &val) const{
			pointer	ret = _root;

			while (ret != _tNull){
				if (_comp(val,ret->_data))
					ret = ret->_left;
				else if (_comp(ret->_data, val))
					ret = ret->_right;
				else
					return (ret);
			}
			return (end());
		}


		/*****************************************************************************/
		/*                           Underluying functions                           */
		/*****************************************************************************/

		//Insert the content of src at the place of dest
		void	transplantNode(pointer dest, pointer src){
			if (dest->_parent == NULL)
				_root = src;
			else if (dest == dest->_parent->_left)
				dest->_parent->_left = src;
			else
				dest->_parent->_right = src;
			src->_parent = dest->_parent;
		}

		//FixInsert start from the inserted node to the root to fix the violations of the rules
		void	fixInsert(pointer toInsert){
			pointer	z = NULL;
			while (toInsert->_parent->_color == RED){
				//if the parent of toInsert is the left grandson of toInsert too
				if (toInsert->_parent == toInsert->_parent->_parent->_right){
					z = toInsert->_parent->_parent->_left;
					//if the left child of the grand parent of z is red, both children become black and gp red
					if (z && z->_color == RED){
						z->_color = BLACK;
						toInsert->_parent->_color = BLACK;
						toInsert->_parent->_parent->_color = RED;
						toInsert = toInsert->_parent->_parent;
					}
					else{
						//if toInsert is left child of his parent, then i do a right-left rotation
						if (toInsert == toInsert->_parent->_left){
							toInsert = toInsert->_parent;
							rotateRight(toInsert);
						}
						//else i just do a left rotation
						toInsert->_parent->_color = BLACK;
						toInsert->_parent->_parent->_color = RED;
						rotateLeft(toInsert->_parent->_parent);
					}
				}
				//if the parent of toInsert is the right grandson of toInsert too
				else{
					z = toInsert->_parent->_parent->_right;
					//if the right child of the grand parent of z is red, both children become black and gp red
					if (z->_color == RED){
						z->_color = BLACK;
						toInsert->_parent->_color = BLACK;
						toInsert->_parent->_parent->_color = RED;
						toInsert = toInsert->_parent->_parent;
					}
					else{
						//if toInsert is left right of his parent, then i do a left-right rotation
						if (toInsert == toInsert->_parent->_right){
							toInsert = toInsert->_parent;
							rotateLeft(toInsert);
						}
						//else i just do a right rotation
						toInsert->_parent->_color = BLACK;
						toInsert->_parent->_parent->_color = RED;
						rotateRight(toInsert->_parent->_parent);
					}
				}
				if (toInsert == _root)
					break;
			}
			//the root is allways a black node
			_root->_color = BLACK;
		}


		//FixErase start from the inserted node to the root to fix the violations of the rules
		void	fixErase(pointer x){
			pointer	w;

			//i traverse the tree to the root
			while (x != _root && x->_color == BLACK){
				//if x is the right child of his parent
				if (x == x->_parent->_left){
					//i assign to w the right child
					w = x->_parent->_right;
					//if w is RED, he come black and his parent become red then we apply left rotation
					if (w->_color == RED){
						w->_color = BLACK;
						x->_parent->_color = RED;
						rotateLeft(x->_parent);
						w = x->_parent->_right;
					}

					//if both childs are black, w become red and x become his own parent
					if (w->_left->_color == BLACK && w->_right->_color == BLACK){
						w->_color = RED;
						x = x->_parent;
					}
					else{
						//if the right child is black, then i do a right-left rotation
						if (w->_right->_color == BLACK){
							w->_left->_color = BLACK;
							w->_color = RED;
							rotateRight(w);
							w = x->_parent->_right;
						}
						//if both a red, both become black and i do a leftrotation
						w->_color = x->_parent->_color;
						x->_parent->_color = BLACK;
						w->_right->_color = BLACK;
						rotateLeft(x->_parent);
						x = _root;
					}
				}
				else{
					//i assign to w the left child
					w = x->_parent->_left;
					//if w is RED, he come black and his parent become red then we apply right rotation
					if (w->_color == RED){
						w->_color = BLACK;
						x->_parent->_color = RED;
						rotateRight(x->_parent);
						w = x->_parent->_left;
					}

					//if both childs are black, w become red and x become his own parent
					if (w->_right->_color == BLACK && w->_left->_color == BLACK){
						w->_color = RED;
						x = x->_parent;
					}
					else{
						//if the right child is black, then i do a left-right rotation
						if (w->_left->_color == BLACK){
							w->_right->_color = BLACK;
							w->_color = RED;
							rotateLeft(w);
							w = x->_parent->_left;
						}
						//if both a red, both become black and i do a right rotation
						w->_color = x->_parent->_color;
						x->_parent->_color = BLACK;
						w->_left->_color = BLACK;
						rotateRight(x->_parent);
						x = _root;
					}
				}
			}
			//x is the root so we set it to black
			x->_color = BLACK;
		}
		

		//Make a left rotation
		void	rotateLeft(pointer x){
			//y is the right subtree of x
			pointer	y = x->_right;
			x->_right = y->_left;
			//if y has a left substree, x become the parent of the left subtree of y
			if (y->_left != _tNull)
				y->_left->_parent = x;
			y->_parent = x->_parent;
			//if x got no parent, he become the root
			if (x->_parent == NULL)
				_root = y;
			//else if x is the left child of his parent, y become the left child of his parent
			else if (x == x->_parent->_left)
				x->_parent->_left = y;
			//else y become the right child of x's parent
			else
				x->_parent->_right = y;
			y->_left = x;
			//y become parent of x
			x->_parent = y;
		}


		//Make a left rotation
		void	rotateRight(pointer x){
			//y is the parent of x
			pointer	y = x->_left;
			x->_left = y->_right;
			//if x got a right subtree, y become the parent of the right subtree of x
			if (y->_right != _tNull)
				y->_right->_parent = x;
			y->_parent = x->_parent;
			//if y got no parent, x become the root
			if (x->_parent == NULL)
				_root = y;
			//else if y is the right child of his parent, x become the right child of his parent
			else if (x == x->_parent->_right)
				x->_parent->_right = y;
			//else x become the left child of x's parent
			else
				x->_parent->_left = y;
			y->_right = x;
			//y become parent of x
			x->_parent = y;
		}

		//Get the min from node to the most little
		pointer	getMin(pointer node) const{
			pointer	ret = node;

			if (ret != _tNull){
				while (ret->_left != _tNull)
					ret = ret->_left;
			}
			return (ret);
		}

		/*****************************************************************************/
		/*                                 Members                                   */
		/*****************************************************************************/

		size_type					_size;
		pointer						_root;
		pointer						_tNull;
		allocator_type				_alloc;
		key_compare					_comp;

	}; // class treeRB

	/*****************************************************************************/
	/*                           Non-members functions                           */
	/*****************************************************************************/

	template<class T, class Compare, class Allocator>
	void	swap(treeRB<T, Compare, Allocator> const &lhs, treeRB<T, Compare, Allocator> const &rhs){
		lhs.swap(rhs);
	}
} // namespace ft

#endif