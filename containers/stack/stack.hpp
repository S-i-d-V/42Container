#ifndef STACK_HPP
#define STACK_HPP

//Underlying include
#include "../vector/vector.hpp"

//============//
//namespace ft//
//============//
namespace ft{
	//===========//
	//stack class//
	//===========//
	template < typename T, class Container = vector<T> >
	class stack{

		//==============//
		//Public members//
		//==============//
	    public:

			//==================//
			//Typedef / typename//
			//==================//

			//value_type is the type that represent T
			typedef					T						value_type;
			typedef					Container				container_type;
			typedef typename		Container::size_type	size_type;

			//===========//
			//Constructor//
			//===========//

			explicit			stack (container_type const& cntr = container_type()) : _data(cntr){}

			//==========//
			// Capacity //
			//==========//

			//Return true or false if empy or not.
			bool				empty()	const{
				return (_data.empty());
			}

			//Return the numbers of elements in the stack
			size_type			size()	const{
				return (_data.size());
			}

			//========//
			// Access //
			//========//

			//Return a reference to the top element in the stack
			value_type&			top(){
				return (_data.back());
			}

			//===========//
			// Modifiers //
			//===========//

			//Push an element on the top of the stack (the end of the vector)
			void				push(value_type const& val){
				_data.push_back(val);
			}

			//Pop an element on the top of the stack (the end of the vector)
			void				pop(){
				_data.pop_back();
			}

		//===============//
		//Private members//
		//===============//
	    private:
			container_type	_data;

	};//End of stack class

	//====================//
	//Non-member overloads//
	//====================//

		//Comparaison operators
	template <class T, class Container>
	bool	operator==(stack<T, Container> const& lhs, stack<T, Container> const& rhs){
		return (lhs._data == rhs._data);
	}

	template <class T, class Container>
	bool	operator!=(stack<T, Container> const& lhs, stack<T, Container> const& rhs){
		return (lhs._data != rhs._data);
	}

	template <class T, class Container>
	bool	operator<(stack<T, Container> const& lhs, stack<T, Container> const& rhs){
		return (lhs._data < rhs._data);
	}

	template <class T, class Container>
	bool	operator<=(stack<T, Container> const& lhs, stack<T, Container> const& rhs){
		return (lhs._data <= rhs._data);
	}

	template <class T, class Container>
	bool	operator>(stack<T, Container> const& lhs, stack<T, Container> const& rhs){
		return (lhs._data > rhs._data);
	}

	template <class T, class Container>
	bool	operator>=(stack<T, Container> const& lhs, stack<T, Container> const& rhs){
		return (lhs._data >= rhs._data);
	}

}//End of namespace ft

#endif