/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 20:52:05 by user42            #+#    #+#             */
/*   Updated: 2022/02/16 02:17:43 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUAL_HPP
#define EQUAL_HPP

/*****************************************************************************/
/*                              Namespace FT                                 */
/*****************************************************************************/

namespace ft{

	/*****************************************************************************/
	/*                              Equal function                               */
	/*****************************************************************************/

	template <class inputIterator1, class inputIterator2>
	bool	equal(inputIterator1 first1, inputIterator1 last1, inputIterator2 first2, inputIterator2 last2){
		while (first1 != last1 && first2 != last2){
			if (!(*first1 == *first2))
				return (false);
			++first1;
			++first2;
		}
		return (true);
	}
 
}

#endif