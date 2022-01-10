/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 01:13:21 by user42            #+#    #+#             */
/*   Updated: 2022/01/10 15:13:46 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.hpp"

bool		test_map(){
	bool ret = false;

	print_map();
	if (ret == false)
		return (print_container_ko());
	else
		return (print_container_ok());
}