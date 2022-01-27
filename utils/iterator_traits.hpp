/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 20:51:57 by user42            #+#    #+#             */
/*   Updated: 2022/01/27 15:41:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*****************************************************************************/
/*                                Includes                                   */
/*****************************************************************************/

#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

/*****************************************************************************/
/*                              Namespace FT                                 */
/*****************************************************************************/

namespace ft{

    /*****************************************************************************/
	/*                                Iterators                                  */
	/*****************************************************************************/
	template <typename Iterator>
    struct iterator_traits{
        /*****************************************************************************/
		/*                              Members types                                */
		/*****************************************************************************/
        typedef typename	Iterator::difference_type           difference_type;
        typedef typename	Iterator::value_type                value_type;
        typedef typename	Iterator::pointer                   pointer;
        typedef typename	Iterator::reference                 reference;
        typedef typename	Iterator::iterator_category         iterator_category;
    };

    /*****************************************************************************/
	/*                                 Pointer                                   */
	/*****************************************************************************/
	template <typename T>
    struct iterator_traits<T*>{
        /*****************************************************************************/
		/*                              Members types                                */
		/*****************************************************************************/
        typedef	typename	std::ptrdiff_t                      difference_type;
        typedef				T                                   value_type;
        typedef				T*                                  pointer;
        typedef				T&                                  reference;
        typedef	typename	std::random_access_iterator_tag     iterator_category;
    };

	/*****************************************************************************/
	/*                             Const Pointer                                 */
	/*****************************************************************************/
	template <typename T>
    struct iterator_traits<T const*>{
        /*****************************************************************************/
		/*                              Members types                                */
		/*****************************************************************************/
        typedef	typename	std::ptrdiff_t                      difference_type;
        typedef				T                                   value_type;
        typedef				T const*                            pointer;
        typedef				T const&                            reference;
        typedef	typename	std::random_access_iterator_tag     iterator_category;
    };

}

#endif