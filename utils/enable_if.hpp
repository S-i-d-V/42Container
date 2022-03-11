/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 20:52:10 by user42            #+#    #+#             */
/*   Updated: 2022/03/11 02:19:02 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
#define ENABLE_IF_HPP

/*****************************************************************************/
/*                              Namespace FT                                 */
/*****************************************************************************/

namespace ft{
	
	/*****************************************************************************/
	/*                              Struct SNIFAE                                */
	/*****************************************************************************/

	template <bool isInt, class T = void>
	struct enable_if{};

	template<class T>
	struct enable_if<true, T>{
		typedef T type;
	};

	template <typename T>
	struct	is_integral{
		static const bool value = false;
	};

	template <>
	struct	is_integral<bool>{
		static const bool value = true;
	};

	template <>
	struct	is_integral<char>{
		static const bool value = true;
	};

	template <>
	struct	is_integral<short>{
		static const bool value = true;
	};

	template <>
	struct	is_integral<int>{
		static const bool value = true;
	};

	template <>
	struct	is_integral<long>{
		static const bool value = true;
	};

	template <>
	struct	is_integral<long long>{
		static const bool value = true;
	};

	template <>
	struct	is_integral<unsigned char>{
		static const bool value = true;
	};

	template <>
	struct	is_integral<unsigned short>{
		static const bool value = true;
	};

	template <>
	struct	is_integral<unsigned int>{
		static const bool value = true;
	};

	template <>
	struct	is_integral<unsigned long>{
		static const bool value = true;
	};

	template <>
	struct	is_integral<unsigned long long>{
		static const bool value = true;
	};
}

#endif