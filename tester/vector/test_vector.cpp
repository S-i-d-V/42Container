/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 01:13:21 by user42            #+#    #+#             */
/*   Updated: 2022/01/11 02:37:28 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.hpp"

bool		test_vector(){
	bool ret = true;

	print_vector();
	if (size_test_vector() == false)
		ret = false;
	if (max_size_test_vector() == false)
		ret = false;
	if (resize_test_vector() == false)
		ret = false;
	if (capacity_test_vector() == false)
		ret = false;
	if (ret == false)
		return (print_container_ko());
	else
		return (print_container_ok());
}