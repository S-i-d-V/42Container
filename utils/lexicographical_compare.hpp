/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 20:52:15 by user42            #+#    #+#             */
/*   Updated: 2022/02/10 12:38:26 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*****************************************************************************/
/*                                Includes                                   */
/*****************************************************************************/

#ifndef LEXICOGRAPHICAL_COMPARE_HPP
#define LEXICOGRAPHICAL_COMPARE_HPP

/*****************************************************************************/
/*                              Namespace FT                                 */
/*****************************************************************************/

namespace ft{

	/*****************************************************************************/
	/*                            Compare function                               */
	/*****************************************************************************/

	template <class inputIterator1, class inputIterator2>
	bool	lexicographical_compare(inputIterator1 first1, inputIterator1 last1, inputIterator2 first2, inputIterator2 last2){
		while (first1 != last1){
			if (first2 == last2 || *first2 < *first1)
				return (false);
			else if (*first1 < *first2)
				return (true);
			++first1;
			++first2;
		}
		return (first2 != last2);
	}
 
}

#endif