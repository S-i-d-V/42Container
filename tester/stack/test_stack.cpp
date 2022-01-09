/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 02:50:25 by user42            #+#    #+#             */
/*   Updated: 2022/01/09 01:10:46 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tester.hpp"

bool		test_stack(){
	bool ret = true;

	print_stack();
	if (empty_test_stack() == false)
		ret = false;
	if (size_test_stack() == false)
		ret = false;
	if (top_test_stack() == false)
		ret = false;
	if (push_test_stack() == false)
		ret = false;
	if (pop_test_stack() == false)
		ret = false;
	if (ret == false)
		return (print_container_ko());
	else
		return (print_container_ok());
}