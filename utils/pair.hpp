/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 20:52:22 by user42            #+#    #+#             */
/*   Updated: 2022/02/27 21:51:51 by user42           ###   ########.fr       */
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
        pair(): first(first_type()), second(second_type()){
            return;
        }

		pair(T1 const lhs, T2 const rhs):first(lhs), second(rhs){}

        //Copy
        template<class U1,class U2>
        pair(pair<U1, U2> const &src): first(src.first), second(src.second){}

        /*****************************************************************************/
		/*                           Operators overloads                             */
		/*****************************************************************************/

        //Assignation operator overload
        pair& operator=(pair const& pr){
            first = pr.first;
            second = pr.second;
            return (*this);
        }

		/*****************************************************************************/
		/*                           Conversion overload                             */
		/*****************************************************************************/

		operator	pair<first_type const, second_type const>() const{
			return (pair<first_type const, second_type const>(first, second));
		}

    };//End of struct pair

    /*****************************************************************************/
	/*                          Comparaison overloads                            */
	/*****************************************************************************/

    template <class T1, class T2>
    bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
        if (lhs.first == rhs.first && lhs.second == rhs.second)
			return (true);
		return (false);
    }

    template <class T1, class T2>
    bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
        return (!(lhs == rhs));
    }
    template <class T1, class T2>
    bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
        if (lhs.first < rhs.first)
			return (true);
		if (lhs.second < rhs.second)
			return (true);
		return (false);
    }

    template <class T1, class T2>
    bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
        return (lhs < rhs || lhs == rhs);
    }

    template <class T1, class T2>
    bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
        return (rhs < lhs);
    }

    template <class T1, class T2>
    bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
        return (lhs > rhs || lhs == rhs);
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