/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 17:33:11 by user42            #+#    #+#             */
/*   Updated: 2022/01/11 02:33:21 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Protection of the header
#ifndef VECTOR_HPP
#define VECTOR_HPP

/*****************************************************************************/
/*                                Includes                                   */
/*****************************************************************************/

//Utils headers
#include "../../utils/enable_if.hpp"
#include "../../utils/equal.hpp"
#include "../../utils/lexicographical_compare.hpp"

//Iterators
#include "vector_iterator.hpp"
#include "reverse_iterator.hpp"

//Header needed by vector
#include <utility>
#include <memory>
#include <stdexcept>

/*****************************************************************************/
/*                                Namespace FT                               */
/*****************************************************************************/
namespace ft{

	/*****************************************************************************/
	/*                                Class vector                               */
	/*****************************************************************************/
	template < typename T, class Alloc = std::allocator<T> >
	class vector{

		/*****************************************************************************/
		/*                             Public members                                */
		/*****************************************************************************/
	    public:

			/*****************************************************************************/
			/*                              Members types                                */
			/*****************************************************************************/

			//Defining every types
			typedef		T														value_type;
			typedef 	Alloc 													allocator_type;
			typedef 	T&														reference;
	    	typedef 	T const&												const_reference;
			typedef 	T*														pointer;
			typedef 	T const*												const_pointer;
			typedef 	size_t													size_type;
	    	typedef 	std::ptrdiff_t											difference_type;

			//Defining every iterators
			typedef		ft::vector_iterator<T>									iterator;
			typedef		ft::vector_iterator<T const>							const_iterator;
			typedef		ft::reverse_iterator<iterator>							reverse_iterator;
			typedef		ft::reverse_iterator<const_iterator>					const_reverse_iterator;


			/*****************************************************************************/
			/*                               Constructors                                */
			/*****************************************************************************/

			//Default constructor (Build an empty container with no elements)
			explicit	vector(allocator_type const& alloc = allocator_type()) : _alloc(alloc){
				_size = 0;
				_capacity = 0;
    			_data = _alloc.allocate(_size);
    			return;
			}

			//Fill (Build an array with <n> times <val> stocked in)
			explicit	vector(size_type n, value_type const& val, allocator_type const& alloc = allocator_type()) : _alloc(alloc){
				_size = n;
				_capacity = n;
    			_data = _alloc.allocate(_size);

				for (size_type i = 0; i < _size; i++)
					_alloc.construct(&_data[i], val);
    			return;
			}

			//Range (Build a contaiener with as many elements in the range)
			template <class inputIterator>
			vector(inputIterator first, inputIterator last, allocator_type const& alloc = allocator_type(),
			typename ft::enable_if<!ft::is_integral<inputIterator>::value>::type* = 0) : _alloc(alloc){
				for (inputIterator	tmp(first); tmp != last; tmp++)
					_size++;
				_data = _alloc.allocate(_size);
				for (size_type i = 0; first != last; i++, first++)
					_alloc.construct(&_data[i], *first);
   				return;
			}

			//Copy
			vector(vector const& src){
				_alloc = src._alloc;
				_size = src._size;
				_capacity = src._capacity;
				_data = _alloc.allocate(_capacity);
				for (size_type i = 0; i < _size; i++)
					_alloc.construct(&_data[i], src._data[i]);
				return;
			}

			/*****************************************************************************/
			/*                                Destructors                                */
			/*****************************************************************************/
			
			~vector(){
				for (int i = _size - 1; i >= 0; i--){
					_alloc.destroy(&_data[i]);
					_size--;
				}
				_alloc.deallocate(_data, _capacity);
				_capacity = 0;
				return;
			}

			/*****************************************************************************/
			/*                           Operators overloads                             */
			/*****************************************************************************/

			//Assignement operator
			vector&		operator=(vector const& rhs){
				return (*this);
			}

			//Access operator
			reference	operator[](size_type n){
				return (_data[n]);
			}

			const_reference	operator[](size_type n) const{
				return (_data[n]);
			}
			

			/*****************************************************************************/
			/*                           Iterators functions                             */
			/*****************************************************************************/

			iterator				begin(){
				return (iterator(_data));
			}

			iterator				end(){
				return (iterator(_data + _size));
			}

			reverse_iterator		rbegin(){
				return (reverse_iterator(_data + _size));
			}

			reverse_iterator		rend(){
				return (reverse_iterator(_data));
			}

			/*****************************************************************************/
			/*                            Capacity functions                             */
			/*****************************************************************************/

			//Return the number of elements of the container
			size_type				size()		const{
				return (_size);
			}

			//Return max number of element the container can hold
			size_type				max_size()	const{
				return (_alloc.max_size());
			}

			//Return the size (in elements) allocated storage capacity in the container
			size_type				capacity()	const{
				return (_capacity);
			}

			//Return true if empty, false if not
			bool					empty()		const{
				if (_size == 0)
					return (true);
				return (false);
			}

			//Resize the container so that it contains n elements;
			void					resize(size_type n, value_type val = value_type()){
				if (n < _size){
					while (_size != n)
						erase(end());
				}
				else if (n > _size && n <= _capacity){
					while (_size < n)
						push_back(val);
				}
				else if (n > _capacity){
					size_type tmpSize = _size;
					reserve(n);
					for (size_type i = tmpSize; i < n; i++)
						push_back(val);
				}
			}

			//Request that the container capacity be at least enough to contain n elements
			void					reserve(size_type n){
				if (n > max_size())
					throw std::length_error("vector: reserve: length_error");
				if (n > _capacity){
					value_type *tmp = NULL;
					tmp = _alloc.allocate(n);
					for (size_type i = 0; i < _size; i++)
						_alloc.construct(&tmp[i], _data[i]);
					_alloc.deallocate(_data, _capacity);
					_capacity = n;
					_data = tmp;
				}
			}

			/*****************************************************************************/
			/*                         Elements access functions                         */
			/*****************************************************************************/

			//Return a reference to the elements at positon n in the container
			reference				at(size_type n){
				if (_size == 0 || n > _size || n < 0)
					throw std::out_of_range();
				return (_data[n]);
			}

			const_reference			at(size_type n)	const{
				if (_size == 0 || n > _size || n < 0)
					throw std::out_of_range();
				return (_data[n]);
			}

			//Return a reference to the first elements in the container.
			reference				front(){
				return (_data[0]);
			}

			const_reference			front()			const{
				return (_data[0]);
			}

			//Return a reference to the last elements in the container.
			reference				back(){
				return (_data[_size - 1]);
			}

			const_reference			back()			const{
				return (_data[_size - 1]);
			}

			/*****************************************************************************/
			/*                            Modifiers functions                            */
			/*****************************************************************************/

			//Clear the content and assign a new content to the vector.
			//1-Assign a new content from a range of iterators
			template <class inputIterator>
			void					assign(inputIterator first, inputIterator last){
				clear();
				insert(begin(), first, last);
			}

			//1-Assign n times val as new content
			void					assign(size_type n, value_type const& val){
				clear();
				insert(begin(), n, val);
			}

			//Add a new element at the end of the container and increases the storage space only if the new size surpasses the current capacity
			void					push_back(value_type const& val){
				if (_size + 1 <= _capacity){
					_alloc.construct(&_data[_size], val);
					_size++;
				}
				else{
					if (_capacity != 0)
						reserve(_capacity * 2);
					else{
						_data = _alloc.allocate(1);
						_capacity = 1;
					}
					push_back(val);
				}
			}

			//Destroy the last element in the container and reduce the size by one.
			void					pop_back(){
				_alloc.destroy(&_data[_size]);
				_size--;
			}

			//Extend the container by inserting new element before the element pointed by position and increase the size by the number of elements.
			//1- Insert a single element
			iterator				insert(iterator position, value_type const& val){
				difference_type index = &(*position) - &(*begin());
				if (_size + 1 > _capacity)
					reserve(_capacity * 2);
				iterator newPos(&_data[index]);
				if (newPos != end()){
					for (iterator initialEnd(end()); initialEnd != newPos; initialEnd--)
						_alloc.construct(&(*(initialEnd)), *(initialEnd - 1));
				}
				_alloc.construct(&(*newPos), val);
				_size += 1;
			}
			
			//2- Insert n times val in the vector from position
			void					insert(iterator position, size_type n, value_type const& val){
				difference_type index = &(*position) - &(*begin());
				if (_size + n > _capacity && _size + n <= _capacity * 2)
					reserve(_capacity * 2);
				else if (_size + n > _capacity * 2)
					reserve(_size + n);
				iterator newPos(&_data[index]);
				if (newPos != end()){
					for (iterator initialEnd(end()); initialEnd != newPos; initialEnd--)
						_alloc.construct(&(*(initialEnd + static_cast<int>(n) - 1)), *(initialEnd - 1));
				}
				for (size_type i = 0; i < n; i++, newPos++)
					_alloc.construct(&(*newPos), val);
				_size += n;
			}

			//3- Insert a range of iterator in the vector from position
			template <class inputIterator>
			void					insert(iterator position, inputIterator first, inputIterator last,
			typename ft::enable_if<!ft::is_integral<inputIterator>::value>::type* = 0){
				difference_type index = &(*position) - &(*begin());
				difference_type n = &(*last) - &(*first); 
				if (_size + n > _capacity && _size + n <= _capacity * 2)
					reserve(_capacity * 2);
				else if (_size + n > _capacity * 2)
					reserve(_size + n);
				iterator newPos(&_data[index]);
				if (newPos != end()){
					for (iterator initialEnd(end()); initialEnd != newPos; initialEnd--)
						_alloc.construct(&(*(initialEnd + static_cast<int>(n) - 1)), *(initialEnd - 1));
				}
				while (first != last){
					_alloc.construct(&(*newPos), *first);
					first++;
					newPos++;
				}
				_size += n;
			}

			//Erase 1 elements or a range of elements.
			//1-Erase the element pointed by position on the vector 
			iterator				erase(iterator position){
				difference_type index = &(*position) - &(*begin());
				iterator newPos(&_data[index]);
				iterator ret = NULL;
				if (newPos != end()){
					ret = newPos + 1;
					while (newPos != end()){
						_alloc.construct(&(*(newPos)), *(newPos + 1));
						newPos++;
					}
				}
				_alloc.destroy(&(*end()));
				_size -= 1;
				if (ret == NULL)
					ret = end();
				return (ret);
			}

			//2-Erase every elements between first and last.
			iterator				erase(iterator first, iterator last){
				difference_type index = &(*first) - &(*begin());
				difference_type n = &(*last) - &(*first); 
				iterator newPos(&_data[index]);
				iterator ret = NULL;
				if (newPos != end()){
					ret = newPos + 1;
					while (newPos != last){
						_alloc.destroy(&(*(newPos)));
						_alloc.construct(&(*(newPos)), *(newPos + n));
						newPos++;
					}
				}
				while (n > 0){
					_alloc.destroy(&(*end()));
					_size--;
					n--;
				}
				if (ret == NULL)
					ret = end();
				return (ret);
			}

			//Exchanges the content of the container by the content of src which is a container object of the same type.
			void					swap(vector& x);

			//Remove all elements of the vector and put the size at 0
			void					clear(){
				for (int i = _size - 1; i >= 0; i--){
					_alloc.destroy(&_data[i]);
					_size--;
				}
			}

			/*****************************************************************************/
			/*                            Allocator functions                            */
			/*****************************************************************************/

			//Return a copy of the allocator object associated with the vector;
			allocator_type	get_allocator()		const{
				return (_alloc);
			}


		/*****************************************************************************/
		/*                            Private members                                */
		/*****************************************************************************/

		private:
			size_type		_size;
			size_type		_capacity;
			value_type		*_data;
			allocator_type	_alloc;

	}; //end of vector class

	/*****************************************************************************/
	/*                           Non-members functions                           */
	/*****************************************************************************/

	//Swap the 2 elements
	template <class T, class Alloc>
	void	swap(vector<T, Alloc>& x, vector<T, Alloc>& y){
		vector<T, Alloc> tmp = x;
		x = y;
		y = tmp;
	}

	/*****************************************************************************/
	/*                          Comparaisons overloads                           */
	/*****************************************************************************/

	//Equal operator
	template <class T, class Alloc>
	bool	operator==(vector<T, Alloc> const& lhs, vector<T, Alloc> const& rhs){
		if (lhs.size() == rhs.size())
			return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
		return (false);
	}

	//Not equal operator
	template <class T, class Alloc>
	bool	operator!=(vector<T, Alloc> const& lhs, vector<T, Alloc> const& rhs){
		if (!(lhs == rhs))
			return (true);
		return (false);
	}

	//Inferior operator
	template <class T, class Alloc>
	bool	operator<(vector<T, Alloc> const& lhs, vector<T, Alloc> const& rhs){
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	//Equal or inferor operator
	template <class T, class Alloc>
	bool	operator<=(vector<T, Alloc> const& lhs, vector<T, Alloc> const& rhs){
		return (!(rhs < lhs));
	}

	//Superior operator
	template <class T, class Alloc>
	bool	operator>(vector<T, Alloc> const& lhs, vector<T, Alloc> const& rhs){
		return (rhs < lhs);
	}

	//Equal or superior operator
	template <class T, class Alloc>
	bool	operator>=(vector<T, Alloc> const& lhs, vector<T, Alloc> const& rhs){
		return (!(lhs < rhs));
	}

}//end of namespace my

#endif//End of the header