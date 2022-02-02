/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugtheven <ugtheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 15:34:52 by user42            #+#    #+#             */
/*   Updated: 2022/02/02 12:33:16 by ugtheven         ###   ########.fr       */
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




	/*****************************************************************************/
	/*                                Class treeRB                               */
	/*****************************************************************************/
	template <class T>
	class treeRB{

		public:
        /*****************************************************************************/
	    /*                              Members types                                */
	    /*****************************************************************************/

	    //Defining basic types
	    typedef		T								value_type;
		typedef		T								*pointer;
		typedef		T								&reference;
        typedef 	size_t							size_type;
	    typedef 	std::ptrdiff_t					difference_type;
		typedef		nodeBT							node;

        /*****************************************************************************/
		/*                               Constructors                                */
		/*****************************************************************************/

        //Default constructor
        treeRB(): _size(0), _root(NULL), _begin(NULL), _end(NULL){}

        //Copy constructor
        treeRB(treeRB const &src){
			*this = src;
		}

        /*****************************************************************************/
		/*                                Destructors                                */
		/*****************************************************************************/
		
        //Destructor
		~vector();

		/*****************************************************************************/
		/*                           Operators overloads                             */
		/*****************************************************************************/

		//Assignement operator
		reference		operator=(treeRB const& rhs){
			_size = rhs._size;
			_root = rhs._root;
			_begin = rhs._begin;
			_end = rhs._end;
			return (*this);
		}

		/*****************************************************************************/
		/*                            Capacity functions                             */
		/*****************************************************************************/

		//Return true if empty, false if not
		bool						empty()		const{
			if (_size == 0)
				return (true);
			return (false);
		}

		//Return the number of elements of the three
		size_type					size()		const{
			return (_size);
		}

		/*****************************************************************************/
		/*                         Elements access functions                         */
		/*****************************************************************************/

		//Access operator
		reference					operator[](size_type n);

		const_reference				operator[](size_type n) const;

	

		/*****************************************************************************/
		/*                               Tree functions                              */
		/*****************************************************************************/

		void	rotateLeft(node *&root, node *&ptr){
			node *ptr_right = ptr->_right;
			ptr->_right = ptr_right->_left;

			if (ptr->_right != NULL)
				ptr->_right->_parent = ptr;

			ptr_right->_parent = ptr->_parent;

			if (ptr->_parent == NULL)
				_root = ptr_right;
			else if (ptr == ptr->_parent->_right)
				ptr->_parent->_left = ptr_right;
			else
				ptr->_parent->_right = ptr_right;
			ptr_right->_left = ptr;
			ptr->_parent = ptr_right;
		}

		void	rotateRight(node *&root, node *&ptr){
			node *ptr_left = ptr->_left;
			ptr->_left = ptr_left->_right;

			if (ptr->_left != NULL)
				ptr->_left->_parent = ptr;

			ptr_left->_parent = ptr->_parent;

			if (ptr->_parent == NULL)
				_root = ptr_left;
			else if (ptr == ptr->_parent->_left)
				ptr->_parent->_left = ptr_left;
			else
				ptr->_parent->_right = ptr_left;
			ptr_left->_right = ptr;
			ptr->_parent = ptr_left;
		}

		/*****************************************************************************/
	    /*                              Members types                                */
	    /*****************************************************************************/

		size_type		*_size;
		node			*_root;
		node			*_begin;
		node			*_end;

    };//end of treeRB class

}//end of namespace ft

#endif//End of the header
 
}

#endif