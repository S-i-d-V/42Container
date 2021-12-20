#ifndef MYVECTOR_HPP
#define MYVECTOR_HPP

//Utils headers
#include "../../utils/enable_if.hpp"
#include "../../utils/out_of_range.hpp"

//Iterators
#include "vectorIterator.hpp"
#include "reverseIterator.hpp"

//Header needed by vector
#include <utility>
#include <memory>

//Header temporaires
#include <iostream>
#include <limits>

//============//
//namespace ft//
//============//
namespace ft{
	//============//
	//vector class//
	//============//
	template < typename T, class Alloc = std::allocator<T> >
	class vector{

		//==============//
		//Public members//
		//==============//
	    public:

			//==================//
			//Typedef / typename//
			//==================//

			//value_type is the type that represent T
			typedef		T														value_type;

			//allocator_type is the type that represent std::allocator
			typedef 	Alloc 													allocator_type;

			//define types of std::allocator as ours
			typedef 	T&														reference;
	    	typedef 	T const&												const_reference;
			typedef 	T*														pointer;
			typedef 	T const*												const_pointer;

			typedef 	size_t													size_type;
	    	typedef 	std::ptrdiff_t											difference_type;

			//define iterators type as ours
			typedef		ft::vectorIterator<T>									iterator;
			typedef		ft::vectorIterator<T const>								const_iterator;
			typedef		ft::reverseIterator<iterator>							reverse_iterator;
			typedef		ft::reverseIterator<const_iterator>						const_reverse_iterator;


			//=======================//
			//Constructors/Destructor//
			//=======================//

			//Default constructor (Build an empty container with no elements)
			explicit	vector(allocator_type const& alloc = allocator_type()) : _alloc(alloc){
				_size = 0;
				_capacity = 0;
    			_data = _alloc.allocate(_size);
    			return;
			}

			//Fill (Build an array with <count> times <val> stocked in)
			explicit	vector(size_type n, value_type const& val, allocator_type const& alloc = allocator_type()) : _alloc(alloc){
				_size = n;
				_capacity = n;
    			_data = _alloc.allocate(_size);

				for (int i = 0; i < _size; i++)
					_alloc.construct(&_data[i], val);
    			return;
			}

			//Range (Build a contaiener with as many elements in the range)
			template <class inputIterator>
			vector(inputIterator first, inputIterator last, allocator_type const& alloc = allocator_type(),
			typename ft::enable_if<!ft::is_integral<inputIterator>::value>::type* = 0) : _alloc(alloc){
   				return;
			}

			//Copy
			vector(vector const& src){
				_alloc = src._alloc;
				_size = src._size;
				_capacity = src._capacity;
				_data = _alloc.allocate(_capacity);
				for (int i = 0; i < _size; i++)
					_alloc.construct(&_data[i], src._data[i]);
				return;
			}

			//Destructor
			~vector(){
				for (int i = _size - 1; i >= 0; i--){
					_alloc.destroy(&_data[i]);
					_size--;
				}
				_alloc.deallocate(_data, _capacity);
				_capacity = 0;
				return;
			}

			//==================//
			//Operator overloads//
			//==================//

			//Assignement operator
			vector&		operator=(vector const& rhs){
				return (*this);
			}

			//Access operator
			//reference	operator[](size_type n);
			//const_reference	operator[](size_type n) const;
			

			//===========//
			// Iterators //
			//===========//

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

			//==========//
			// Capacity //
			//==========//

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
					for (int i = _size - 1; i >= n; i--){
						_alloc.destroy(&_data[i]);
						_size--;
					}
				}
				else if (n > _size && n <= _capacity){
					while (_size < n)
						push_back(0);
				}
				else if (n > _capacity){
					int tmpSize = _size;
					reserve(n);
					for (int i = tmpSize; i < n; i++)
						push_back(0);
				}
			}

			//Request that the container capacity be at least enough to contain n elements
			void					reserve(size_type n){
				if (n > _capacity){
					value_type *tmp = NULL;
					tmp = _alloc.allocate(n);
					for (int i = 0; i < _size; i++)
						_alloc.construct(&tmp[i], _data[i]);
					_alloc.deallocate(_data, _capacity);
					_capacity = n;
					_data = tmp;
				}
			}

			//================//
			// Element access //
			//================//

			//Return a reference to the elements at positon n in the container
			reference				at(size_type n){
				if (_size == 0 || n > _size || n < 0)
					throw out_of_range();
				return (_data[n]);
			}

			const_reference			at(size_type n)	const{
				if (_size == 0 || n > _size || n < 0)
					throw out_of_range();
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

	/*

			//==========//
			// Modifier //
			//==========//

			//Assign new contents to the vector by replace current content and modifying its size.
				//By range of iterators
			template <class inputIterator>
			void					assign(inputIterator first, inputIterator last);

				//Fill
			void					assign(size_type n, value_type const& val);

	*/

			//Add a new element at the end of the container and increases the storage space only if the new size surpasses the current capacity
			void					push_back(value_type const& val){
				//Pas besoin de reallocation
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

	/*

			//Extend the container by inserting new element before the element at specified position and increase the size by the number of elements.
				//Single element
			iterator				insert(iterator position, value_type const& val){

			}
			
				//Fill
			void					insert(iterator position, size_type n, value_type const& val);

				//By range of iterators
			template <class inputIterator>
			void					insert(iterator position, inputIterator first, inputIterator last);

			//Remove 1 or a range of elements from the container and reduce the container size by the number of elements removed.
				//Single element
			iterator				erase(iterator position);

				//By range of iterators
			iterator				erase(iterator first, iterator last);

	*/

			//Exchanges the content of the container by the content of src which is a container object of the same type.
			void					swap(vector& x);

			//Remove all elements of the vector and put the size at 0
			void					clear(){
				for (int i = _size - 1; i >= 0; i--){
					_alloc.destroy(&_data[i]);
					_size--;
				}
			}


			//===========//
			// Allocator //
			//===========//
				//Return a copy of the allocator object associated with the vector;
			//allocator_type	get_Alloc()		const;


		//=================//
		// Private members //
		//=================//
		private:
			size_type		_size;
			size_type		_capacity;
			value_type		*_data;
			allocator_type	_alloc;

	}; //end of vector class


	//=======================//
	// Non-members operators //
	//=======================//

		//Comparaison operators

	template <class T, class Alloc>
	bool	operator==(vector<T, Alloc> const& lhs, vector<T, Alloc> const& rhs);

	template <class T, class Alloc>
	bool	operator!=(vector<T, Alloc> const& lhs, vector<T, Alloc> const& rhs);

	template <class T, class Alloc>
	bool	operator<(vector<T, Alloc> const& lhs, vector<T, Alloc> const& rhs);

	template <class T, class Alloc>
	bool	operator<=(vector<T, Alloc> const& lhs, vector<T, Alloc> const& rhs);

	template <class T, class Alloc>
	bool	operator>(vector<T, Alloc> const& lhs, vector<T, Alloc> const& rhs);

	template <class T, class Alloc>
	bool	operator>=(vector<T, Alloc> const& lhs, vector<T, Alloc> const& rhs);

		//Non-member swap
	//void	swap(vector<T, Alloc>& x, vector<T, Alloc>& y);

}//end of namespace my

#endif