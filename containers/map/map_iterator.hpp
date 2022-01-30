/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 02:16:09 by user42            #+#    #+#             */
/*   Updated: 2022/01/30 02:48:50 by user42           ###   ########.fr       */
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
/*                                Namespace FT                               */
/*****************************************************************************/
namespace ft{

	/*****************************************************************************/
	/*                            Class map iterator                             */
	/*****************************************************************************/
	template <class T>
	class map_iterator{

		/*****************************************************************************/
		/*                             Public members                                */
		/*****************************************************************************/
		public:

			/*****************************************************************************/
			/*                              Members types                                */
			/*****************************************************************************/

			typedef typename	std::ptrdiff_t							difference_type;
			typedef				T										value_type;
			typedef 			T&										reference;
			typedef 			T*										pointer;
			typedef	typename	std::bidirectional_iterator_tag			iterator_category;

			/*****************************************************************************/
			/*                               Constructors                                */
			/*****************************************************************************/

			//Default constructor
			map_iterator();

			map_iterator(pointer valPtr);

			map_iterator(map_iterator<T> const& src);

			/*****************************************************************************/
			/*                                Destructors                                */
			/*****************************************************************************/

			~map_iterator(){
				return;
			}

			/*****************************************************************************/
			/*                           Operators conversion                            */
			/*****************************************************************************/

			//Conversion operator
			operator		map_iterator<T const>() const;

			/*****************************************************************************/
			/*                           Operators overloads                             */
			/*****************************************************************************/

			//Assignement operator
			map_iterator<T>		&operator=(map_iterator<T> const &rhs);

			//Pointer operator
			pointer				operator->() const;

			//Dereferencement pointer operator
			reference			operator*() const;

			reference			operator[](size_t index);

			//Increment operator prefixe it++;
			map_iterator<T>	&operator++();

			//Increment operator postfixe ++it; 
			map_iterator<T> operator++(int);

			//Increment operator prefixe it--;
			map_iterator<T> &operator--();

			//Decrement operator postfixe --it; 
			map_iterator<T> operator--(int);

			//Addition operator
			difference_type operator+(map_iterator<T> const &rhs) const;

			//Substraction operator
			difference_type operator-(map_iterator<T> const &rhs) const;

			//Addition operator
			map_iterator<T> operator+(difference_type n);

			//Substraction operator
			map_iterator<T> operator-(difference_type n);

			//Plus equal operaor
			map_iterator<T> &operator+=(difference_type n);

			//Sub equal operator
			map_iterator<T> &operator-=(difference_type n);

			/*****************************************************************************/
			/*                          Comparaisons overloads                           */
			/*****************************************************************************/

			//Equal operator
			bool operator==(map_iterator<T> const& rhs) const;

			//Non-equal operator
			bool operator!=(map_iterator<T> const& rhs) const;

			//Superior or equal operator
			bool operator>=(map_iterator<T> const& rhs) const;

			//Inferior or equal operator
			bool operator<=(map_iterator<T> const& rhs) const;

			//Superior operator
			bool operator>(map_iterator<T> const& rhs) const;

			//Inferior operator
			bool operator<(map_iterator<T> const& rhs) const;

		/*****************************************************************************/
		/*                            Private members                                */
		/*****************************************************************************/
		//private:
			pointer _valPtr;

	}; //End of map_iterator class;

	template <class T1, class T2>
	bool	operator==(map_iterator<T1> const &lhs, map_iterator<T2> const &rhs);

	template <class T1, class T2>
	bool	operator!=(map_iterator<T1> const &lhs, map_iterator<T2> const &rhs);

	template <class T1, class T2>
	bool	operator>(map_iterator<T1> const &lhs, map_iterator<T2> const &rhs);

	template <class T1, class T2>
	bool	operator>=(map_iterator<T1> const &lhs, map_iterator<T2> const &rhs);

	template <class T1, class T2>
	bool	operator<(map_iterator<T1> const &lhs, map_iterator<T2> const &rhs);

	template <class T1, class T2>
	bool	operator<=(map_iterator<T1> const &lhs, map_iterator<T2> const &rhs);

} //End of namespace ft

template <class T>
ft::map_iterator<T> operator+(int n, ft::map_iterator<T> const &rhs);

template <class T>
ft::map_iterator<T> operator-(int n, ft::map_iterator<T> const &rhs);

#endif//End of the header