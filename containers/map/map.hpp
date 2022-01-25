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

//Iterators
#include "vector_iterator.hpp"
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
	template <class Key, class T, class Compare = std::less<key_type>, class Alloc = std::allocator<T> >
	class map{

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
	    //typedef		        ft::map_iterator<T>								iterator;
	    //typedef		        ft::map_iterator<T const>						const_iterator;
	    //typedef		        ft::reverse_iterator<iterator>					reverse_iterator;
	    //typedef		        ft::reverse_iterator<const_iterator>			const_reverse_iterator;

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

    };//end of map class

}//end of namespace ft

#endif//End of the header