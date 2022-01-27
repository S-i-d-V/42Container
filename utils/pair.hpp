/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 20:52:22 by user42            #+#    #+#             */
/*   Updated: 2022/01/27 15:41:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*****************************************************************************/
/*                                Includes                                   */
/*****************************************************************************/

#ifndef PAIR_HPP
#define PAIR_HPP

/*****************************************************************************/
/*                              Namespace FT                                 */
/*****************************************************************************/
namespace ft{

	/*****************************************************************************/
	/*                               Struct PAIR                                 */
	/*****************************************************************************/
	template <class T1, class T2>
    struct pair{

        /*****************************************************************************/
		/*                             Members types                                 */
		/*****************************************************************************/
        typedef     T1      first_type;
        typedef     T2      second_type;

        first_type          first;
        second_type         second;

        /*****************************************************************************/
		/*                              Constructors                                 */
		/*****************************************************************************/

        //Default
        pair(){
            first = 0
            second = 0;
            return;
        }

        //Copy
        template<class U,class V>
        pair(pair const<U, V>& pr){
            *this = pr;
            return;
        }

        //Initialization
        pair(first_type const& a, second_type const&b){
            first = a;
            second = b;
            return;
        }

        /*****************************************************************************/
		/*                           Operators overloads                             */
		/*****************************************************************************/

        //Assignation operator overload
        pair& operator=(pair const& pr){
            first = pr.first;
            second = pr.second;
            return (*this);
        }
    };//End of struct pair

    /*****************************************************************************/
	/*                          Comparaison overloads                            */
	/*****************************************************************************/

    template <class T1, class T2>
    bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
        return (lhs.first == rhs.first && lhs.second == rhs.second);
    }

    template <class T1, class T2>
    bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
        return (!(lhs == rhs));
    }
    template <class T1, class T2>
    bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
        return (lhs.first < rhs.first || (!(lhs.first < rhs.first) && lhs.second < rhs.second));
    }

    template <class T1, class T2>
    bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
        return (!(rhs < lhs));
    }

    template <class T1, class T2>
    bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
        return (rhs < lhs);
    }

    template <class T1, class T2>
    bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
        return (!(lhs < rhs));
    }

    /*****************************************************************************/
	/*                           Non-member functions                            */
	/*****************************************************************************/

    template <class T1, class T2>
    pair<T1, T2>       make_pair(T1 x, T2 y){
        return (pair<T1, T2>(x,y));
    }

}//End of namespace

#endif