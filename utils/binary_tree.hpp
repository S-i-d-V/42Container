/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:34:52 by user42            #+#    #+#             */
/*   Updated: 2022/02/01 12:48:34 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*****************************************************************************/
/*                                Includes                                   */
/*****************************************************************************/

#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <cstring>

/*****************************************************************************/
/*                              Namespace FT                                 */
/*****************************************************************************/

namespace ft{

	/*****************************************************************************/
	/*                                Includes                                   */
	/*****************************************************************************/

	template<class T>
	class nodeBT{

			public:
			/*****************************************************************************/
	    	/*                              Members types                                */
	    	/*****************************************************************************/

			//Typedefs
			typedef enum 	{RED, BLACK}			color_node;
			typedef			T						value_type;
			typedef			nodeBT<value_type>		*pointer;
			typedef			nodeBT<value_type>		&reference;

			//Public members
			value_type								_data;
			pointer									_left;
			pointer									_right;
			pointer									_parent;
			color_node								_color;

			/*****************************************************************************/
			/*                               Constructors                                */
			/*****************************************************************************/

			nodeBT() : _data(), _left(NULL), _right(NULL), _parent(NULL), _color(BLACK){}

			nodeBT(value_type data, pointer left, pointer right, pointer parent) : _data(data), _left(left), _right(right), _parent(parent), _color(BLACK){}

			nodeBT(T const &src){
				*this = src;
			}

			/*****************************************************************************/
			/*                                Destructors                                */
			/*****************************************************************************/

			~nodeBT(){}

			/*****************************************************************************/
			/*                           Operators overloads                             */
			/*****************************************************************************/

			reference	operator=(T const &rhs){
				_data = rhs._data;
				_left = rhs._left;
				_right = rhs._right;
				_parent = rhs._parent;
				_color = rhs._color;
			}

			/*****************************************************************************/
			/*                                Functions                                  */
			/*****************************************************************************/

			void		insert(value_type key);
			pointer		search(value_type key);
			void		destroy_tree();

	};
 
}

#endif