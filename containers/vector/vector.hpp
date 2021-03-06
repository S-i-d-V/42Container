/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 17:33:11 by user42            #+#    #+#             */
/*   Updated: 2022/02/28 01:15:43 by user42           ###   ########.fr       */
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
#include "../../utils/reverse_iterator.hpp"

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
			explicit	vector(allocator_type const& alloc = allocator_type()) : _size(0), _capacity(0), _data(NULL), _alloc(alloc){
    			return;
			}

			//Fill (Build an array with <n> times <val> stocked in)
			explicit	vector(size_type n, value_type const& val = value_type(), allocator_type const& alloc = allocator_type()) : _size(0), _capacity(0), _data(NULL), _alloc(alloc){
				assign(n, val);
    			return;
			}

			//Range (Build a contaiener with as many elements in the range)
			template <class inputIterator>
			vector(inputIterator first, inputIterator last, allocator_type const& alloc = allocator_type(),
			typename ft::enable_if<!ft::is_integral<inputIterator>::value>::type* = 0) : _size(0), _capacity(0), _data(NULL), _alloc(alloc){
				assign(first, last);
   				return;
			}

			//Copy
			vector(vector const& src): _size(0), _capacity(0), _data(NULL){
				*this = src;
				return;
			}

			/*****************************************************************************/
			/*                                Destructors                                */
			/*****************************************************************************/
			
			~vector(){
				clear();
				_alloc.deallocate(_data, _capacity);
				_capacity = 0;
				return;
			}

			/*****************************************************************************/
			/*                           Operators overloads                             */
			/*****************************************************************************/

			//Assignement operator
			vector&		operator=(vector const& rhs){
				assign(rhs.begin(), rhs.end());
				return (*this);
			}
			
			/*****************************************************************************/
			/*                           Iterators functions                             */
			/*****************************************************************************/

			iterator				begin(){
				return (iterator(_data));
			}

			const_iterator			begin() const{
				return (const_iterator(_data));
			}

			iterator				end(){
				return (iterator(&_data[_size]));
			}

			const_iterator				end() const{
				return (const_iterator(&_data[_size]));
			}

			reverse_iterator		rbegin(){
				return (reverse_iterator(&_data[_size]));
			}

			const_reverse_iterator		rbegin() const{
				return (const_reverse_iterator(&_data[_size]));
			}

			reverse_iterator		rend(){
				return (reverse_iterator(_data));
			}

			const_reverse_iterator		rend() const{
				return (const_reverse_iterator(_data));
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
				if (n < size())
					erase(begin() + n, end());
				else if (n > size())
					insert(end(), n - size(), val);
			}

			//Request that the container capacity be at least enough to contain n elements
			void					reserve(size_type n){
				if (n > max_size())
					throw std::length_error("vector: reserve: length_error");
				else if (n == max_size())
					throw std::bad_alloc();
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
					throw std::out_of_range("vector: at: out_of_range");
				return (_data[n]);
			}

			const_reference			at(size_type n)	const{
				if (_size == 0 || n > _size || n < 0)
					throw std::out_of_range("vector: at: out_of_range");
				return (_data[n]);
			}

			//Return a reference to the first elements in the container.
			reference				front(){
				return (*_data);
			}

			const_reference			front()			const{
				return (*_data);
			}

			//Return a reference to the last elements in the container.
			reference				back(){
				return (_data[_size - 1]);
			}

			const_reference			back()			const{
				return (_data[_size - 1]);
			}

			//Access operator
			reference	operator[](size_type n){
				return (_data[n]);
			}

			const_reference	operator[](size_type n) const{
				return (_data[n]);
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
				if (_size + 1 <= _capacity)
					insert(end(), val);
				else{
					if (_capacity != 0)
						reserve(_capacity * 2);
					else{
						_data = _alloc.allocate(1);
						_capacity = 1;
					}
					insert(end(), val);
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
				difference_type index = position - begin();
				insert(position, 1, val);
				return (&_data[index]);
			}
			
			//2- Insert n times val in the vector from position
			void					insert(iterator position, size_type n, value_type const& val){
				difference_type index = position - begin();
				if (_size + n > _capacity && _size + n <= _capacity * 2)
					reserve(_capacity * 2);
				else if (_size + n > _capacity * 2)
					reserve(_size + n);
				iterator tmpEnd = end();
				_size += n;
				iterator pos = iterator(&_data[index]);
				if (pos != tmpEnd){
					for (size_t i = 0; end() - i != pos; i++)
						_alloc.construct(&(*(end() - i - 1)), *(tmpEnd - i - 1));
				}
				for (size_t i = 0; i < n; i++, pos++)
					_alloc.construct(pos._valPtr, val);
			}

			//3- Insert a range of iterator in the vector from position
			template <class inputIterator>
			void					insert(iterator position, inputIterator first, inputIterator last, typename ft::enable_if<!ft::is_integral<inputIterator>::value>::type* = 0){
				difference_type index = position - begin();
				difference_type size = std::distance(first, last);
				if (_size + size > _capacity && _size + size <= _capacity * 2)
					reserve(_capacity * 2);
				else if (_size + size > _capacity * 2)
					reserve(_size + size);
				iterator tmpEnd = end();
				_size += size;
				iterator pos = iterator(&_data[index]);
				if (pos != tmpEnd){
					for (size_t i = 0; end() - i != pos; i++)
						_alloc.construct(&(*(end() - i - 1)), *(tmpEnd - i - 1));
				}
				//for (; first != last; first++, pos++)
				//	_alloc.construct(pos._valPtr, *first);
				while (first != last){
					_alloc.construct(pos._valPtr, *first);
					first++;
					pos++;
				}
			}

			//Erase 1 elements or a range of elements.
			//1-Erase the element pointed by position on the vector 
			iterator				erase(iterator position){
				return(erase(position, position + 1));
			}

			//2-Erase every elements between first and last.
			iterator				erase(iterator first, iterator last){
				iterator tmpFirst = first;

				if (first != last){
					while (last != end()){
						_alloc.construct(tmpFirst._valPtr, *last);
						last++;
						tmpFirst++;
					}
					size_type tmpSize = _size;
					while (tmpFirst != end()){
						_alloc.destroy(tmpFirst._valPtr);
						tmpFirst++;
						tmpSize--;
					}
					_size = tmpSize;
				}
				return (first);
			}

			//Exchanges the content of the container by the content of src which is a container object of the same type.
			void					swap(vector& x){
				allocator_type	tmpAlloc = _alloc;
				size_type		tmpCapacity = _capacity;
				size_type		tmpSize = _size;
				value_type		*tmpData = _data;

				_alloc = x._alloc;
				_capacity = x._capacity;
				_size = x._size;
				_data = x._data;

				x._alloc = tmpAlloc;
				x._capacity = tmpCapacity;
				x._size = tmpSize;
				x._data = tmpData;
			}

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
		x.swap(y);
	}

	/*****************************************************************************/
	/*                          Comparaisons overloads                           */
	/*****************************************************************************/

	//Equal operator
	template <class T, class Alloc>
	bool	operator==(vector<T, Alloc> const& lhs, vector<T, Alloc> const& rhs){
		if (lhs.size() == rhs.size())
			return (ft::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
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