/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 01:51:37 by user42            #+#    #+#             */
/*   Updated: 2022/02/24 00:22:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Protections of the header
#ifndef MAP_HPP
#define MAP_HPP

/*****************************************************************************/
/*                                Includes                                   */
/*****************************************************************************/

//Utils header
#include <memory>
#include <iostream>
#include <sstream>
#include <string>
#include <limits>
#include <stddef.h>
#include <functional>

//Headers needed by map
#include "../../utils/reverse_iterator.hpp"
#include "../../utils/binary_tree.hpp"
#include "../../utils/equal.hpp"
#include "../../utils/lexicographical_compare.hpp"
#include "../../utils/pair.hpp"
#include "../../utils/iterator_traits.hpp"
#include "../../utils/enable_if.hpp"

/*****************************************************************************/
/*                              Namespace FT                                 */
/*****************************************************************************/

namespace ft{

	/*****************************************************************************/
	/*                                Map Class                                  */
	/*****************************************************************************/

	template<class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<Key, T> > >
	class map{

		/*****************************************************************************/
		/*                              Public members                               */
		/*****************************************************************************/

		public:

		/*****************************************************************************/
		/*                              Members types                                */
		/*****************************************************************************/
		
		typedef Key														key_type;
		typedef T														mapped_type;
		typedef ft::pair<key_type const, mapped_type>					value_type;
		typedef Compare													key_compare;
		typedef Allocator												allocator_type;

		typedef typename ft::treeRB<value_type>::reference				reference;
		typedef typename ft::treeRB<value_type>::const_reference		const_reference;
		typedef typename ft::treeRB<value_type>::pointer				pointer;
		typedef typename ft::treeRB<value_type>::const_pointer			const_pointer;

		typedef	typename ft::treeRB<value_type>::iterator				iterator;
		typedef typename ft::treeRB<value_type>::const_iterator			const_iterator;
		typedef ft::reverse_iterator<iterator>							reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;

		typedef	std::size_t												size_type;
		typedef std::ptrdiff_t											difference_type;
		

		class value_compare: public std::binary_function<value_type, value_type, bool>{
			protected:
		    key_compare _comp;

			public:
			value_compare(key_compare comp = key_compare()): _comp(comp) {}
			
			bool operator()(value_type const &lhs, value_type const &rhs) const {
				return (_comp(lhs.first, rhs.first));
			}
		};

		/*****************************************************************************/
		/*                               Constructors                                */
		/*****************************************************************************/
		
		//Default
		explicit map (key_compare const &comp = key_compare(), allocator_type const &alloc = allocator_type()): _comp(comp), _alloc(alloc){
			return;
		}

		//Range (Build a map from a range of iterator)
		template <class inputIterator>
		map(inputIterator first, inputIterator last, key_compare const &comp = key_compare(), allocator_type const &alloc = allocator_type()): _comp(comp), _alloc(alloc){
			insert(first, last);
			return;
		}

		//Copy (Build a map from another map)
		map(map const &src){
			*this = src;
			return;
		}

		/*****************************************************************************/
		/*                                Destructors                                */
		/*****************************************************************************/

		//Destructor
		~map(){
			return;
		}

		/*****************************************************************************/
		/*                           Operator olverloads                             */
		/*****************************************************************************/

		//Assignement operator
		map	&operator=(map const &rhs){
			_comp = rhs._comp;
			_tree = rhs._tree;
			return (*this);
		}
		

		/*****************************************************************************/
		/*                                Iterators                                  */
		/*****************************************************************************/

		iterator	begin(){
			return (_tree.begin());
		}

		const_iterator	begin() const{
			return (_tree.begin());
		}


		iterator	end(){
			return (_tree.end());
		}

		const_iterator	end() const{
			return (_tree.end());
		}


		reverse_iterator	rbegin(){
			return (_tree.rbegin());
		}

		const_reverse_iterator	rbegin() const{
			return (_tree.rbegin());
		}


		reverse_iterator	rend(){
			return (_tree.rend());
		}

		const_reverse_iterator	rend() const{
			return (_tree.rend());
		}


		/*****************************************************************************/
		/*                                Capacity                                   */
		/*****************************************************************************/

		//Return true if empty, false if not
		bool	empty() const{
			if (size() == 0)
				return (true);
			return (false);
		}


		//Return the number of elements of the container
		size_type	size() const{
			return (_tree._size);
		}


		//Return the max number of elements the container can hold
		size_type	max_size() const{
			return (_tree._alloc.max_size());
		}


		/*****************************************************************************/
		/*                             Element access                                */
		/*****************************************************************************/

		//Return a reference is k is matching with a key in the map
		mapped_type	&operator[](key_type const &k){
			return ((insert(ft::make_pair(k, mapped_type()))).first->second);
		}

		/*****************************************************************************/
		/*                                Modifiers                                  */
		/*****************************************************************************/

		//Single element
		ft::pair<iterator, bool>	insert(value_type const &val){
			return (_tree.insert(val));
		}

		//With hint
		iterator	insert(iterator position, value_type const &val){
			(void)position;
			return ((insert(val)).first);
		}

		//Range
		template<class inputIterator>
		void		insert(inputIterator first, inputIterator last, typename ft::enable_if<!ft::is_integral<inputIterator>::value, inputIterator>::type* = 0){
			while (first != last){
				insert(*first);
				first++;
			}
		}


		//Hint
		void	erase(iterator position){
			if (position != end()){
				_tree.erase(position._valPtr);
			}
		}

		//Search key
		size_type	erase(key_type const &k){
			iterator	it = find(k);
			
			if (it == end())
				return (0);
			else{
				_tree.erase(it._valPtr);
				return (1);
			}
		}
		
		//Range
		void	erase(iterator first, iterator last){
			iterator	it;

			while (first != last){
				it = first;
				++first;
				erase(it);
			}
		}


		//Swap the 2 elements
		void	swap(map &x){
			_tree.swap(x._tree);
		}


		//Delete all elements in the map
		void	clear(){
			_tree.clear();
		}


		/*****************************************************************************/
		/*                                 Observers                                 */
		/*****************************************************************************/

		//Return a copy of the comparison object used to compare keys
		key_compare	key_comp() const{
			return (key_compare());
		}


		//Return a copy of the comparison object used to compare values
		value_compare	value_comp() const{
			return (value_compare());
		}


		/*****************************************************************************/
		/*                                Operations                                 */
		/*****************************************************************************/


		//Search an element with a key equivalent to k and return in iterator to it, if there is not it return an iterator to end()
		iterator	find(key_type const &k){
			return (_tree.find(ft::make_pair(k, mapped_type())));
		}

		//Search an element with a key equivalent to k and return in const_iterator to it, if there is not it return an const_iterator to end()
		const_iterator	find(key_type const &k) const{
			return (_tree.find(ft::make_pair(k, mapped_type())));
		}


		//Search in the map elements with a key equivalent to k and return the number of matches ( 0 or 1 )
		size_type	count(key_type const &k) const{
			if (find(k) == end())
				return (0);
			return (1);
		}


		iterator	lower_bound(key_type const &k){
			iterator it = begin();

			while (it != end()){
				if (!(_comp(it._valPtr->_data, k)))
					return (it);
				it++;
			}
			return (end());
		}

		const_iterator	 lower_bound(key_type const &k) const{
			const_iterator it = begin();

			while (it != end()){
				if (!(_comp(it._valPtr->_data, k)))
					return (it);
				it++;
			}
			return (end());
		}


		iterator	upper_bound(key_type const &k){
			iterator it = begin();

			while (it != end()){
				if (!(_comp(it._valPtr->_data, k)) && _comp(k, it._valPtr->_data))
					return (it);
				it++;
			}
			return (end());
		}

		const_iterator	upper_bound(key_type const &k) const{
			const_iterator it = begin();

			while (it != end()){
				if (!(_comp(it._valPtr->_data, k)) && _comp(k, it._valPtr->_data))
					return (it);
				it++;
			}
			return (end());
		}


		ft::pair<iterator, iterator>	equal_range(key_type const &k){
			ft::pair<iterator, iterator>	range;

			range.first = lower_bound(k);
			range.second = upper_bound(k);
			return (range);
		}

		ft::pair<const_iterator, const_iterator>	equal_range(key_type const &k) const{
			ft::pair<const_iterator, const_iterator>	range;

			range.first = lower_bound(k);
			range.second = upper_bound(k);
			return (range);
		}


		/*****************************************************************************/
		/*                                 Allocator                                 */
		/*****************************************************************************/

		//Return a copy of the allocator object associated with the map;
		allocator_type	get_allocator() const{
			return (_alloc);
		}

		/*****************************************************************************/
		/*                                 Members                                   */
		/*****************************************************************************/
		private:
		key_compare								_comp;
		allocator_type							_alloc;
		treeRB<value_type, value_compare>		_tree;
	};

	/*****************************************************************************/
	/*                           Non-members overloads                           */
	/*****************************************************************************/

	template<class Key, class T, class Compare, class Allocator>
	bool	operator==(map<Key, T, Compare, Allocator> const &lhs, map<Key, T, Compare, Allocator> const &rhs){
		if (lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template<class Key, class T, class Compare, class Allocator>
	bool	operator!=(map<Key, T, Compare, Allocator> const &lhs, map<Key, T, Compare, Allocator> const &rhs){
		return (!(lhs == rhs));
	}

	template<class Key, class T, class Compare, class Allocator>
	bool	operator<(map<Key, T, Compare, Allocator> const &lhs, map<Key, T, Compare, Allocator> const &rhs){
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template<class Key, class T, class Compare, class Allocator>
	bool	operator<=(map<Key, T, Compare, Allocator> const &lhs, map<Key, T, Compare, Allocator> const &rhs){
		return (lhs == rhs || lhs < rhs);
	}

	template<class Key, class T, class Compare, class Allocator>
	bool	operator>(map<Key, T, Compare, Allocator> const &lhs, map<Key, T, Compare, Allocator> const &rhs){
		return (rhs < lhs);
	}

	template<class Key, class T, class Compare, class Allocator>
	bool	operator>=(map<Key, T, Compare, Allocator> const &lhs, map<Key, T, Compare, Allocator> const &rhs){
		return (lhs == rhs || rhs < lhs);
	}

}

#endif