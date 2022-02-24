/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 22:24:31 by user42            #+#    #+#             */
/*   Updated: 2022/02/22 02:30:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Protection of the header
#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

/*****************************************************************************/
/*                                Includes                                   */
/*****************************************************************************/

//Headers needed for iterators
#include <cstddef>
#include <iterator>

/*****************************************************************************/
/*                              Namespace FT                                 */
/*****************************************************************************/

namespace ft{
	/*****************************************************************************/
	/*                           map_iterator Class                           */
	/*****************************************************************************/

	template<class nodeType, class valueType>
	class map_iterator{

	/*****************************************************************************/
	/*                               Public members                              */
	/*****************************************************************************/

	public:

		/*****************************************************************************/
		/*                              Members types                                */
		/*****************************************************************************/

		typedef nodeType						node_type;
		typedef valueType						value_type;
		typedef std::ptrdiff_t					difference_type;
		typedef value_type*						pointer;
		typedef value_type&						reference;
		typedef std::bidirectional_iterator_tag	iterator_category;


		/*****************************************************************************/
		/*                               Constructors                                */
		/*****************************************************************************/

		map_iterator(): _valPtr(NULL), _end(NULL) {
			return;
		}

		map_iterator(node_type *ptr): _valPtr(ptr), _end(NULL) {
			return;
		}

		map_iterator(node_type *ptr, node_type *sentry): _valPtr(ptr), _end(sentry) {
			return;
		}


		map_iterator(const map_iterator &copy){
			*this = copy;
			return;
		}

		/*****************************************************************************/
		/*                               Constructors                                */
		/*****************************************************************************/

		~map_iterator() {
			return;
		}

		/*****************************************************************************/
		/*                            Operator overloads                             */
		/*****************************************************************************/

		map_iterator	&operator=(const map_iterator &other){
			_valPtr = other._valPtr;
			_end = other._end;
			return (*this);
		}


		reference	operator*(void){
			return (_valPtr->_data);
		}

		const value_type	&operator*(void) const{
			return (_valPtr->_data);
		}


		value_type	*operator->(void){
			return (&operator*());
		}

		const value_type	*operator->(void) const{
			return (&operator*());
		}


		map_iterator	operator++(int){
			map_iterator	it(*this);

			if (_valPtr == _end && _end->_parent != NULL)
				_valPtr = getMin(_valPtr->_parent);
			else if (_valPtr->_right == _end){
				node_type	*parent = _valPtr->_parent;

				while (parent != NULL && _valPtr == parent->_right){
					_valPtr = parent;
					parent = parent->_parent;
				}
				if (parent == NULL)
					_valPtr = _end;
				else
					_valPtr = parent;
			}
			else
				_valPtr = getMin(_valPtr->_right);
			return (it);
		}

		map_iterator	&operator++(void){
			if (_valPtr == _end && _end->_parent != NULL){
				_valPtr = getMin(_valPtr->_parent);
				return (*this);
			}
			else if (_valPtr->_right == _end){
				node_type	*parent = _valPtr->_parent;

				while (parent != NULL && _valPtr == parent->_right){
					_valPtr = parent;
					parent = parent->_parent;
				}
				if (parent == NULL)
					_valPtr = _end;
				else
					_valPtr = parent;
				return (*this);
			}
			else{
				_valPtr = getMin(_valPtr->_right);
				return (*this);
			}
		}


		map_iterator	operator--(int){
			map_iterator	it(*this);

			if (_valPtr == _end && _end->_parent != NULL)
				_valPtr = getMax(_valPtr->_parent);
			else if (_valPtr->_left == _end){
				node_type	*parent = _valPtr->_parent;

				while (parent != NULL && _valPtr == parent->_left){
					_valPtr = parent;
					parent = parent->_parent;
				}
				if (parent == NULL)
					_valPtr = _end;
				else
					_valPtr = parent;
			}
			else
				_valPtr = getMax(_valPtr->_left);
			return (it);
		}

		map_iterator	&operator--(void){
			if (_valPtr == _end && _end->_parent != NULL){
				_valPtr = getMax(_valPtr->_parent);
				return (*this);
			}
			else if (_valPtr->_left == _end){
				node_type	*parent = _valPtr->_parent;

				while (parent != NULL && _valPtr == parent->_left){
					_valPtr = parent;
					parent = parent->_parent;
				}
				if (parent == NULL)
					_valPtr = _end;
				else
					_valPtr = parent;
				return (*this);
			}
			else{
				_valPtr = getMax(_valPtr->_left);
				return (*this);
			}
		}


		/*****************************************************************************/
		/*                           Conversion operator                             */
		/*****************************************************************************/

		operator map_iterator<const nodeType, const valueType>(void) const{
			return (map_iterator<const nodeType, const valueType>(_valPtr, _end));
		}

		/*****************************************************************************/
		/*                           Underluying functions                           */
		/*****************************************************************************/

		node_type	*getMin(node_type *node){
			node_type	*_valPtr = node;

			while (_valPtr->_left != _end)
				_valPtr = _valPtr->_left;
			return (_valPtr);
		}


		node_type	*getMax(node_type *node){
			node_type	*_valPtr = node;

			while (_valPtr->_right != _end)
				_valPtr = _valPtr->_right;
			return (_valPtr);
		}


		/*****************************************************************************/
		/*                                 Members                                   */
		/*****************************************************************************/

		node_type			*_valPtr;
		node_type			*_end;
	};

	/*****************************************************************************/
	/*                           Non-members overloads                           */
	/*****************************************************************************/

	template<class Tx, class Ux, class Ty, class Uy>
	bool	operator==(const map_iterator<Tx, Ux> &x, const map_iterator<Ty, Uy> &y){
		if (x._valPtr == y._valPtr)
			return (true);
		return (false);
	}

	template<class Tx, class Ux, class Ty, class Uy>
	bool	operator!=(const map_iterator<Tx, Ux> &x, const map_iterator<Ty, Uy> &y){
		if (x._valPtr != y._valPtr)
			return (true);
		return (false);
	}
}

#endif
