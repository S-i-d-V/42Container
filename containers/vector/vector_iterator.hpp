/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 18:06:02 by user42            #+#    #+#             */
/*   Updated: 2021/12/30 18:10:16 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Protection of the header
#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

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
	/*                          Class vector iterator                            */
	/*****************************************************************************/
	template <class T>
	class vector_iterator{

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
			typedef	typename	std::random_access_iterator_tag			iterator_category;

			/*****************************************************************************/
			/*                               Constructors                                */
			/*****************************************************************************/

			//Default constructor
			vector_iterator(){
				_valPtr = NULL;
				return;
			}

			vector_iterator(T *valPtr){
				_valPtr = valPtr;
				return;
			}

			vector_iterator(vector_iterator const& src){
				*this = src;
				return;
			}

			/*****************************************************************************/
			/*                                Destructors                                */
			/*****************************************************************************/

			~vector_iterator(){
				return;
			}

			/*****************************************************************************/
			/*                           Operators overloads                             */
			/*****************************************************************************/

			//Assignement operator
			vector_iterator<T> &operator=(vector_iterator<T> const &rhs){
				_valPtr = rhs._valPtr;
				return (*this);
			}

			//Pointer operator
			pointer	operator->() const{
				return (_valPtr);
			}

			//Dereferencement pointer operator
			reference	operator*() const{
				return (*_valPtr);
			}

			reference	operator[](size_t i){
				return (_valPtr[i]);
			}

			//Increment operator prefixe it++;
			vector_iterator<T> &operator++(){
				++_valPtr;
				return (*this);
			}

			//Increment operator postfixe ++it; 
			vector_iterator<T> operator++(int){
				vector_iterator tmp;
				tmp._valPtr = _valPtr++;
				return (tmp);
			}

			//Increment operator prefixe it--;
			vector_iterator<T> &operator--(){
				--_valPtr;
				return (*this);
			}

			//Decrement operator postfixe --it; 
			vector_iterator<T> operator--(int){
				vector_iterator tmp;
				tmp._valPtr = _valPtr--;
				return (tmp);
			}

			//Addition operator
			difference_type operator+(vector_iterator const &rhs) const{
				return (_valPtr + rhs._valPtr);
			}

			//Substraction operator
			difference_type operator-(vector_iterator const &rhs) const{
				return (_valPtr - rhs._valPtr);
			}

			//Addition operator
			vector_iterator<T> operator+(difference_type n){
				vector_iterator tmp(_valPtr + n);
				return (tmp);
			}

			//Substraction operator
			vector_iterator<T> operator-(difference_type n){
				vector_iterator tmp(_valPtr - n);
				return (tmp);
			}

			//Plus equal operaor
			vector_iterator<T> &operator+=(int n){
				_valPtr += n;
				return (*this);
			}

			//Sub equal operator
			vector_iterator<T> &operator-=(int n){
				_valPtr -= n;
				return (*this);
			}

			/*****************************************************************************/
			/*                          Comparaisons overloads                           */
			/*****************************************************************************/

			//Equal operator
			bool operator==(vector_iterator const& rhs) const{
				if (_valPtr == rhs._valPtr)
					return (true);
				return (false);
			}

			//Non-equal operator
			bool operator!=(vector_iterator const& rhs) const{
				if (_valPtr != rhs._valPtr)
					return (true);
				return (false);
			}

			//Superior or equal operator
			bool operator>=(vector_iterator const& rhs) const{
				if (_valPtr >= rhs._valPtr)
					return (true);
				return (false);
			}

			//Inferior or equal operator
			bool operator<=(vector_iterator const& rhs) const{
				if (_valPtr <= rhs._valPtr)
					return (true);
				return (false);
			}

			//Superior operator
			bool operator>(vector_iterator const& rhs) const{
				if (_valPtr > rhs._valPtr)
					return (true);
				return (false);
			}

			//Inferior operator
			bool operator<(vector_iterator const& rhs) const{
				if (_valPtr < rhs._valPtr)
					return (true);
				return (false);
			}

		/*****************************************************************************/
		/*                            Private members                                */
		/*****************************************************************************/
		private:
			T *_valPtr;

	}; //End of vector_iterator class;

} //End of namespace ft

#endif//End of the header