#ifndef VECTOR_HPP
#define VECTOR_HPP

//Utils headers
#include "../../utils/enable_if.hpp"
#include "../../utils/out_of_range.hpp"
#include "../../utils/equal.hpp"
#include "../../utils/lexicographical_compare.hpp"

//Iterators
#include "vector_iterator.hpp"
#include "reverse_iterator.hpp"

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
			typedef		ft::vector_iterator<T>									iterator;
			typedef		ft::vector_iterator<T const>							const_iterator;
			typedef		ft::reverse_iterator<iterator>							reverse_iterator;
			typedef		ft::reverse_iterator<const_iterator>					const_reverse_iterator;


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
			reference	operator[](size_type n){
				return (_data[n]);
			}

			const_reference	operator[](size_type n) const{
				return (_data[n]);
			}
			

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

			//==========//
			// Modifier //
			//==========//

			//Assign new contents to the vector by replace current content and modifying its size.
				//By range of iterators
			template <class inputIterator>
			void					assign(inputIterator first, inputIterator last){
				//i clear the vector;
				clear();
				//i insert the range of iterator
				insert(begin(), first, last);
			}

				//Fill
			void					assign(size_type n, value_type const& val){
				//i clear the vector;
				clear();
				//i insert the range of iterator
				insert(begin(), n, val);
			}


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

	

			//Extend the container by inserting new element before the element at specified position and increase the size by the number of elements.
				//Single element
			iterator				insert(iterator position, value_type const& val){
				//get the index of the iterator in the vector
				difference_type index = &(*position) - &(*begin());
				//if the final size if bigger than capacity i realloc
				if (_size + 1 > _capacity)
					reserve(_capacity * 2);
				//i set an iterator pointing on the index got from position.
				iterator newPos(&_data[index]);
				//if the iterator isnt at the end of the vector, i shift every thing to the right
				if (newPos != end()){
					//i shift to 1 place all elements from the end to ther new position end + 1.
					for (iterator initialEnd(end()); initialEnd != newPos; initialEnd--)
						_alloc.construct(&(*(initialEnd)), *(initialEnd - 1));
				}
				//i put the elements to insert
				_alloc.construct(&(*newPos), val);
				//i increase the size
				_size += 1;
			}
			
				//Fill
			void					insert(iterator position, size_type n, value_type const& val){
				//get the index of the iterator in the vector
				difference_type index = &(*position) - &(*begin());
				//if the final size if bigger than capacity i realloc
				if (_size + n > _capacity && _size + n <= _capacity * 2)
					reserve(_capacity * 2);
				else if (_size + n > _capacity * 2)
					reserve(_size + n);
				//i set an iterator pointing on the index got from position.
				iterator newPos(&_data[index]);
				//if the iterator isnt at the end of the vector, i shift every thing to the right
				if (newPos != end()){
					//i shift to n place all elements from the end to ther new position end + n.
					for (iterator initialEnd(end()); initialEnd != newPos; initialEnd--)
						_alloc.construct(&(*(initialEnd + static_cast<int>(n) - 1)), *(initialEnd - 1));
				}
				//i put the elements to insert
				for (size_type i = 0; i < static_cast<int>(n); i++, newPos++)
					_alloc.construct(&(*newPos), val);
				//i increase the size
				_size += n;
			}

				//By range of iterators
			template <class inputIterator>
			void					insert(iterator position, inputIterator first, inputIterator last,
			typename ft::enable_if<!ft::is_integral<inputIterator>::value>::type* = 0){
				//get the index of the iterator in the vector
				difference_type index = &(*position) - &(*begin());
				//get the size of the range first last
				difference_type n = &(*last) - &(*first); 
				//if the final size if bigger than capacity i realloc
				if (_size + n > _capacity && _size + n <= _capacity * 2)
					reserve(_capacity * 2);
				else if (_size + n > _capacity * 2)
					reserve(_size + n);
				//i set an iterator pointing on the index got from position.
				iterator newPos(&_data[index]);
				//if the iterator isnt at the end of the vector, i shift every thing to the right
				if (newPos != end()){
					//i shift to n place all elements from the end to ther new position end + n.
					for (iterator initialEnd(end()); initialEnd != newPos; initialEnd--)
						_alloc.construct(&(*(initialEnd + static_cast<int>(n) - 1)), *(initialEnd - 1));
				}
				//i put the elements to insert
				while (first != last){
					_alloc.construct(&(*newPos), *first);
					first++;
					newPos++;
				}
				//i increase the size
				_size += n;
			}

			//Remove 1 or a range of elements from the container and reduce the container size by the number of elements removed.
				//Single element
			iterator				erase(iterator position){
				//get the index of the iterator in the vector
				difference_type index = &(*position) - &(*begin());
				//i set an iterator pointing on the index got from position.
				iterator newPos(&_data[index]);
				//if the iterator isnt at the end of the vector, i shift every thing to the left
				if (newPos != end()){
					//i shift to 1 place all elements from newpos to ther new position newpos + 1;
					while (newPos != end()){
						_alloc.construct(&(*(newPos)), *(newPos + 1));
						newPos++;
					}
				}
				//i destroy the last elements
				_alloc.destroy(&(*end()));
				//i decrease the size
				_size -= 1;
			}

				//By range of iterators
			iterator				erase(iterator first, iterator last){
				//get the index of the range in the vector
				difference_type index = &(*first) - &(*begin());
				//get the size of the range first last
				difference_type n = &(*last) - &(*first); 
				//i set an iterator pointing on the index got from position.
				iterator newPos(&_data[index]);
				//if the iterator isnt at the end of the vector, i shift every thing to the left
				if (newPos != end()){
					//i shift to 1 place all elements from newposto ther new position newPos + n.
					while (newPos != last){
						_alloc.destroy(&(*(newPos)));
						_alloc.construct(&(*(newPos)), *(newPos + n));
						newPos++;
					}
				}
				//i destroy the n last elements and decreaze the size;
				while (n > 0){
					_alloc.destroy(&(*end()));
					_size--;
					n--;
				}
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

			//===========//
			// Allocator //
			//===========//
				//Return a copy of the allocator object associated with the vector;
			allocator_type	get_allocator()		const{
				return (_alloc);
			}


		//=================//
		// Private members //
		//=================//
		private:
			size_type		_size;
			size_type		_capacity;
			value_type		*_data;
			allocator_type	_alloc;

	}; //end of vector class


	//====================//
	//Non-member overloads//
	//====================//

		//Comparaison operators
	template <class T, class Alloc>
	bool	operator==(vector<T, Alloc> const& lhs, vector<T, Alloc> const& rhs){
		if (lhs.size() == rhs.size())
			return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
		return (false);
	}

	template <class T, class Alloc>
	bool	operator!=(vector<T, Alloc> const& lhs, vector<T, Alloc> const& rhs){
		if (!(lhs == rhs))
			return (true);
		return (false);
	}

	template <class T, class Alloc>
	bool	operator<(vector<T, Alloc> const& lhs, vector<T, Alloc> const& rhs){
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class T, class Alloc>
	bool	operator<=(vector<T, Alloc> const& lhs, vector<T, Alloc> const& rhs){
		return (!(rhs < lhs));
	}

	template <class T, class Alloc>
	bool	operator>(vector<T, Alloc> const& lhs, vector<T, Alloc> const& rhs){
		return (rhs < lhs);
	}

	template <class T, class Alloc>
	bool	operator>=(vector<T, Alloc> const& lhs, vector<T, Alloc> const& rhs){
		return (!(lhs < rhs));
	}

		//Non-member swap
	template <class T, class Alloc>
	void	swap(vector<T, Alloc>& x, vector<T, Alloc>& y){
		vector<T, Alloc> tmp = x;
		x = y;
		y = tmp;
	}

}//end of namespace my

#endif