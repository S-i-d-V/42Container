/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 02:50:25 by user42            #+#    #+#             */
/*   Updated: 2022/01/08 22:40:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_stack.hpp"

int		main(){
	print_stack();
	empty_test_stack();
	size_test_stack();
	top_test_stack();
	push_test_stack();
	pop_test_stack();
}