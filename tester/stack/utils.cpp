/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 02:51:49 by user42            #+#    #+#             */
/*   Updated: 2022/01/07 03:09:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_stack.hpp"

bool	print_ok(){
	std::cout << "\033[32;1mOK\033" << std::endl;
	return true;
}

bool	print_ko(){
	std::cout << "\033[31;1mKO\033" << std::endl;
	return false;
}

bool	print_function_ok(){
	std::cout << "\033[34;1mFunction : \033[32;1mOK\033" << std::endl;
	return true;
}

bool	print_function_ko(){
	std::cout << "\033[34;1mFunction : \033[31;1mKO\033" << std::endl;
	return false;
}