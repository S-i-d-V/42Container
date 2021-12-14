#ifndef MYVECTOR_HPP
#define MYVECTOR_HPP

//Utils headers
#include "../../utils/enable_if.hpp"
#include "../../utils/out_of_range.hpp"

//Iterators
#include "vectorIterator.hpp"
#include "vectorReverseIterator.hpp"

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
			typedef				T																	value_type;

			//allocator_type is the type that represent std::allocator
			typedef 			Alloc 																allocator_type;

			//define types of std::allocator as ours
			typedef typename 	allocator_type::reference											reference;
	    	typedef typename 	allocator_type::const_reference										const_reference;
			typedef typename	allocator_type::pointer												pointer;
			typedef typename	allocator_type::const_pointer										const_pointer;

			typedef typename 	allocator_type::size_type											size_type;
	    	typedef typename 	allocator_type::difference_type										difference_type;

			//define iterators type as ours
			typedef				ft::vectorIterator<T>												iterator;
			typedef				ft::vectorIterator<T const>											const_iterator;
			typedef				ft::vectorReverseIterator<T>										reverse_iterator;
			typedef				ft::vectorReverseIterator<T const>									const_reverse_iterator;


			//=======================//
			//Constructors/Destructor//
			//=======================//

			//Default constructor (Build an empty container with no elements)
			explicit	vector(allocator_type const& alloc = allocator_type()) : _alloc(alloc){
				std::cout << "Default constructor called" << std::endl;
				_size = 0;
				_capacity = 0;
    			_data = _alloc.allocate(_size);
    			return;
			}

			//Fill (Build an array with <count> times <val> stocked in)
			explicit	vector(size_type n, value_type const& val, allocator_type const& alloc = allocator_type()) : _alloc(alloc){
				std::cout << "Fill constructor called" << std::endl;
				_size = n;
				_capacity = n;
    			_data = _alloc.allocate(_size);

				for (int i = 0; i < _size; i++)
					_alloc.construct(&_data[i], val);
    			return;
			}

			//Range (Build a contaienerwith as many elements in the range)
			template <class inputIterator>
			vector(inputIterator first, inputIterator last, allocator_type const& alloc = allocator_type(),
			typename ft::enable_if<!ft::is_integral<inputIterator>::value>::type* = 0) : _alloc(alloc){
				std::cout << "Range constructor called" << std::endl;
   				return;
			}

			//Copy
			vector(vector const& src){
				std::cout << "Range constructor called" << std::endl;
				return;
			}

			//Destructor
			~vector(){
				std::cout << "Destructor called" << std::endl;
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

				//normal
			iterator				begin(){
				return (iterator(_data));
			}

			iterator				end(){
				return (iterator(_data + _size));
			}

			reverse_iterator		rbegin(){
				return (reverse_iterator(_data + _size - 1));
			}

			reverse_iterator		rend(){
				return (reverse_iterator(_data));
			}


			//const
			const_iterator			cbegin()	const{
				return (const_iterator(_data));
			}

			const_iterator			cend()		const{
				return (const_iterator(_data + _size));
			}

			const_reverse_iterator	crbegin()	const{
				return (const_reverse_iterator(_data + _size - 1));
			}

			const_reverse_iterator	crend()		const{
				return (const_reverse_iterator(_data));
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
			//size_type				capacity()	const{
			//	
			//}

			//Return true if empty, false if not
			bool					empty()		const{
				if (_size == 0)
					return (true);
				return (false);
			}

	/*

			//Resize the container so that it contains n elements;
			void					resize(size_type n, value_type val = value_type());

			//Request that the container capacity be at least enough to contain n elements
			void					reserve(size_type n);

			//Reduce the capacity of the container to fit its size (number of elements);
			void					shrink_to_fit();


	*/

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
				//Add a new element at the end of the container and increases the storage space only if the new size surpasses the current capacity
			void					push_back(value_type const& val);
				//Destroy the last element in the container and reduce the size by one.
			void					pop_back(value_type const& val);
				//Extend the container by inserting new element before the element at specified position and increase the size by the number of elements.
					//Single element
			iterator				insert(iterator position, value_type const& val);
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
				//Exchanges the content of the container by the content of src which is a container object of the same type.
			void					swap(vector& x);
				//Remove all elements of the vector and put the size at 0
			void					clear();
				//Extend the container by inserting a new element at position.
			template <class... Args>
			iterator				emplace(const position, Args&&... args);
				//Extend the container by inserting a new element at the end right after current last element.
			template <class... Args>
			iterator				emplace(const position, Args&&... args);


			//===========//
			// Allocator //
			//===========//
				//Return a copy of the allocator object associated with the vector;
			allocator_type	get_Alloc()		const;

	*/

		//=================//
		// Private members //
		//=================//
		private:
			size_type		_size;
			size_type		_capacity;
			value_type		*_data;
			allocator_type	_alloc;
			value_type		*_start;
			value_type 		*_end;

	}; //end of vector class

/*
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
	void	swap(vector<T, Alloc>& x, vector<T, Alloc>& y);

*/

}//end of namespace my

//#include "myVector.ipp"

#endif