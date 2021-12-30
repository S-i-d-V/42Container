/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 17:33:17 by user42            #+#    #+#             */
/*   Updated: 2021/12/30 18:04:33 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Protection of the header
#ifndef STACK_HPP
#define STACK_HPP

/*****************************************************************************/
/*                                Includes                                   */
/*****************************************************************************/

//Underlying include
#include "../vector/vector.hpp"

/*****************************************************************************/
/*                                Namespace FT                               */
/*****************************************************************************/
namespace ft{

	/*****************************************************************************/
	/*                                Class stack                                */
	/*****************************************************************************/
	template < typename T, class Container = vector<T> >
	class stack{

		/*****************************************************************************/
		/*                             Public members                                */
		/*****************************************************************************/
	    public:

			/*****************************************************************************/
			/*                              Members types                                */
			/*****************************************************************************/

			//Defining every types
			typedef					T						value_type;
			typedef					Container				container_type;
			typedef typename		Container::size_type	size_type;

			/*****************************************************************************/
			/*                               Constructors                                */
			/*****************************************************************************/

			explicit			stack (container_type const& cntr = container_type()) : _data(cntr){}

			/*****************************************************************************/
			/*                            Capacity functions                             */
			/*****************************************************************************/

			//Return true or false if empy or not.
			bool				empty()	const{
				return (_data.empty());
			}

			//Return the numbers of elements in the stack
			size_type			size()	const{
				return (_data.size());
			}

			/*****************************************************************************/
			/*                         Elements access functions                         */
			/*****************************************************************************/

			//Return a reference to the top element in the stack
			value_type&			top(){
				return (_data.back());
			}

			/*****************************************************************************/
			/*                            Modifiers functions                            */
			/*****************************************************************************/

			//Push an element on the top of the stack (the end of the vector)
			void				push(value_type const& val){
				_data.push_back(val);
			}

			//Pop an element on the top of the stack (the end of the vector)
			void				pop(){
				_data.pop_back();
			}

		/*****************************************************************************/
		/*                            Private members                                */
		/*****************************************************************************/
	    private:
			container_type	_data;

	};//End of stack class

	/*****************************************************************************/
	/*                          Comparaisons overloads                           */
	/*****************************************************************************/

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

#endif//End of the header