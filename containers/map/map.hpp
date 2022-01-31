/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 20:54:46 by user42            #+#    #+#             */
/*   Updated: 2022/01/30 02:50:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Protection of the header
#ifndef MAP_HPP
#define MAP_HPP

/*****************************************************************************/
/*                                Includes                                   */
/*****************************************************************************/

//Utils headers
#include "../../utils/enable_if.hpp"
#include "../../utils/equal.hpp"
#include "../../utils/lexicographical_compare.hpp"
#include "../../utils/pair.hpp"
#include "../../utils/binary_tree.hpp"

//Iterators
#include "../../utils/reverse_iterator.hpp"

//Header needed by vector
#include <utility>
#include <memory>
#include <stdexcept>

/******************************************************************************/
/*                                Namespace FT                               */
/*****************************************************************************/
namespace ft{

	/*****************************************************************************/
	/*                                  Class map                                */
	/*****************************************************************************/
	template <class Key, class T, class Compare = std::less<key_type>, class Alloc = std::allocator<ft::pair<const Key, T> >
	class map{

		public:
		
        /*****************************************************************************/
	    /*                              Members types                                */
	    /*****************************************************************************/

	    //Defining basic types
        typedef		Key														key_type;
	    typedef		T														mapped_type;
        typedef     ft::pair<key_type const, mapped_type>                   value_type;
        typedef     Compare                                                 key_compare;
        typedef     
        typedef 	size_t													size_type;
	    typedef 	std::ptrdiff_t											difference_type;

        //Defining allocators types
	    typedef 	        Alloc 											allocator_type;
	    typedef typename	allocator_type::reference						reference;
	    typedef typename	allocator_type::const_reference					const_reference;
	    typedef typename	allocator_type::pointer						    pointer;
	    typedef typename	allocator_type::const_pointer					const_pointer;

	    //Defining iterators types
	    typedef		        ft::map_iterator<T>								iterator;
	    typedef		        ft::map_iterator<T const>						const_iterator;
	    typedef		        ft::reverse_iterator<iterator>					reverse_iterator;
	    typedef		        ft::reverse_iterator<const_iterator>			const_reverse_iterator;

		class value_compare: public std::binary_function<value_type, value_type, bool>{
			protected:
				key_compare _comp;
				value_compare(compare c) : comp(c){}

				public:
					bool		operator()(value_type const &lhs, value_type const &rhs){
						return (_comp(lhs.first, rhs.first));
					}
		}

        /*****************************************************************************/
		/*                               Constructors                                */
		/*****************************************************************************/

        //Default constructor
        explicit map (key_compare const &comp = key_compare(), allocator_type const &alloc = allocator_type());

        //Range constructor
        template <class inputIterator>
        map (InputIterator first, InputIterator last, key_compare const &comp = key_compare(), allocator_type const &alloc = allocator_type());

        //Copy constructor
        map (map const &src);

        /*****************************************************************************/
		/*                                Destructors                                */
		/*****************************************************************************/
		
        //Destructor
		~vector(){;

		/*****************************************************************************/
		/*                           Operators overloads                             */
		/*****************************************************************************/

		//Assignement operator
		map&		operator=(map const& rhs){

		/*****************************************************************************/
		/*                           Iterators functions                             */
		/*****************************************************************************/

		iterator				begin();

		const_iterator			begin() const;
		
		iterator				end();

		const_iterator				end() const;

		reverse_iterator		rbegin();

		const_reverse_iterator		rbegin() const;

		reverse_iterator		rend();

		const_reverse_iterator		rend() const;

		/*****************************************************************************/
		/*                            Capacity functions                             */
		/*****************************************************************************/

		//Return true if empty, false if not
		bool					empty()		const;

		//Return the number of elements of the container
		size_type				size()		const;

		//Return max number of element the container can hold
		size_type				max_size()	const;

		/*****************************************************************************/
		/*                         Elements access functions                         */
		/*****************************************************************************/

		//Access operator
		reference				operator[](size_type n);

		const_reference			operator[](size_type n) const;

		/*****************************************************************************/
		/*                            Modifiers functions                            */
		/*****************************************************************************/

		//Extend the container by inserting new element before the element pointed by position and increase the size by the number of elements.
		//1- Insert a single element
		ft::pair<iterator,bool>		insert(value_type const& val);
		
		//2- Insert n times val in the vector from position
		iterator					insert(iterator position, value_type const& val);

		//3- Insert a range of iterator in the vector from position
		template <class inputIterator>
		void					insert(inputIterator first, inputIterator last,
		typename ft::enable_if<!ft::is_integral<inputIterator>::value>::type* = 0);

		//Erase 1 elements or a range of elements.
		//1-Erase the element pointed by position on the vector 
		iterator				erase(iterator position);

		//2-
		size_type				erase(key_type const &k);

		//3-Erase every elements between first and last.
		iterator				erase(iterator first, iterator last);

		//Exchanges the content of the container by the content of src which is a container object of the same type.
		void					swap(map& x);

		//Remove all elements of the vector and put the size at 0
		void					clear();

		/*****************************************************************************/
		/*                            Observers functions                            */
		/*****************************************************************************/

		key_compare				key_comp() const;

		//value_compare			value_comp() const;

		/*****************************************************************************/
		/*                            Operations functions                           */
		/*****************************************************************************/

		iterator									find(key_type const &k);

		const_iterator								find(key_type const &k) const;

		size_type									find(key_type const &k) const;

		iterator									lower_bound(key_type const &k);

		const_iterator								lower_bound(key_type const &k) const;

		iterator									upper_bound(key_type const &k);

		const_iterator								upper_bound(key_type const &k) const;

		ft::pair<iterator, iterator>				equal_range(key_type const &k) const;

		ft::pair<const_iterator, const_iterator>	equal_range(key_type const &k) const;

		/*****************************************************************************/
		/*                            Allocator functions                            */
		/*****************************************************************************/

		allocator_type				get_allocator() const;

		/*****************************************************************************/
		/*                            Private members                                */
		/*****************************************************************************/

		private:

    };//end of map class

}//end of namespace ft

#endif//End of the header