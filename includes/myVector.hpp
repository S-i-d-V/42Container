#ifndef MYVECTOR_HPP
#define MYVECTOR_HPP

#include <utility>
#include <memory>

//============//
//namespace ft//
//============//
namespace ft{

	template < typename _Tp, typename _Allocator = std::allocator<_Tp> >
	class vector{

		//==============//
		//Public members//
		//==============//
	    public:

			//==================//
			//Typedef / typename//
			//==================//
			//value_type is the type that represent _Tp
			typedef				_Tp														value_type;

			//allocator_type is the type that represent std::allocator
			typedef 			_Allocator 												allocator_type;

			//define types of std::allocator as ours
			typedef typename 	allocator_type::reference								reference;
	    	typedef typename 	allocator_type::const_reference							const_reference;
			typedef typename 	allocator_type::size_type								size_type;
	    	typedef typename 	allocator_type::difference_type							difference_type;
			typedef typename	allocator_type::pointer									pointer;
			typedef typename	allocator_type::const_pointer							const_pointer;

			//define iterators as ours
			//typedef typename	std::iterator<random_access_iterator_tag, value_type>	iterator;

			//=======================//
			//Constructors/Destructor//
			//=======================//
			//Default constructor (Build an empty container with no elements)
			explicit	vector(allocator_type const& alloc = allocator_type());
			//Fill (Build an array with <count> times <val> stocked in)
			explicit	vector(size_type n, value_type const& val, allocator_type const& alloc = allocator_type());
			//Range (Build a contaienerwith as many elements in the range)
			template <class InputIterator>
						vector(InputIterator first, InputIterator last, allocator_type const& alloc = allocator_type());
			//Copy
						vector(vector const& src);

			//Destructor
						~vector();

			//==================//
			//Operator overloads//
			//==================//
			//Assignement operator
			vector&		operator=(vector const& rhs);

			//Access operator
			reference	operator[](size_type n);
			const_reference	operator[](size_type n) const;

			//===========//
			// Iterators //
			//===========//
			//normal
			iterator				begin();
			iterator				end();
			reverse_iterator		rbegin();
			reverse_iterator		rend();
			//const
			const_iterator			cbegin()	const;
			const_iterator			cend()		const;
			const_reverse_iterator	crbegin()	const;
			const_reverse_iterator	crend()		const;



		//===============//
		//Private members//
		//===============//
		private:
			size_type _n;
			value_type const& _val;
			allocator_type const& _alloc;

	}; //end of vector class

}//end of namespace my

#endif