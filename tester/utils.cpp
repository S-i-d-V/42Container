/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 02:51:49 by user42            #+#    #+#             */
/*   Updated: 2022/01/10 15:14:39 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.hpp"

bool	print_ok(){
	std::cout << "\033[32;1mOK\033" << std::endl;
	return true;
}

bool	print_ko(){
	std::cout << "\033[31;1mKO\033" << std::endl;
	return false;
}

bool	print_function_ok(){
	std::cout << "\033[34;1mFunction : \033[32;1mOK\033[0m" << std::endl;
	return true;
}

bool	print_function_ko(){
	std::cout << "\033[34;1mFunction : \033[31;1mKO\033[0m" << std::endl;
	return false;
}

bool	print_container_ok(){
	std::cout << "\033[32;1m   ___            _          _                    ___   _  __\033[0m" << std::endl;
	std::cout << "\033[32;1m  / __| ___  _ _ | |_  __ _ (_) _ _   ___  _ _   / _ \\ | |/ /\033[0m" << std::endl;
	std::cout << "\033[32;1m | (__ / _ \\| ' \\|  _|/ _` || || ' \\ / -_)| '_| | (_) || ' < \033[0m" << std::endl;
	std::cout << "\033[32;1m  \\___|\\___/|_||_|\\__|\\__,_||_||_||_|\\___||_|    \\___/ |_|\\_\\\033[0m" << std::endl;
	std::cout << "\033[32;1m                                                             \033[0m" << std::endl;
	return true;
}

bool	print_container_ko(){
	std::cout << "\033[31;1m   ___            _          _                   _  __ ___  \033[0m" << std::endl;
	std::cout << "\033[31;1m  / __| ___  _ _ | |_  __ _ (_) _ _   ___  _ _  | |/ // _ \\ \033[0m" << std::endl;
	std::cout << "\033[31;1m | (__ / _ \\| ' \\|  _|/ _` || || ' \\ / -_)| '_| | ' <| (_) |\033[0m" << std::endl;
	std::cout << "\033[31;1m  \\___|\\___/|_||_|\\__|\\__,_||_||_||_|\\___||_|   |_|\\_\\___/ \033[0m" << std::endl;
	std::cout << "\033[31;1m                                                             \033[0m" << std::endl;
	return false;
}

void	print_vector(){
	std::cout << "\033[34;1m********************************************************************\033[0m" << std::endl;
	std::cout << "\033[34;1m*                            \033[33;1mVector\033[34;1m                                *\033[0m" << std::endl;
	std::cout << "\033[34;1m********************************************************************\033[0m" << std::endl;
	std::cout << std::endl;
}

void	print_stack(){
	std::cout << "\033[34;1m********************************************************************\033[0m" << std::endl;
	std::cout << "\033[34;1m*                             \033[33;1mStack\033[34;1m                                *\033[0m" << std::endl;
	std::cout << "\033[34;1m********************************************************************\033[0m" << std::endl;
	std::cout << std::endl;
}

void	print_map(){
	std::cout << "\033[34;1m********************************************************************\033[0m" << std::endl;
	std::cout << "\033[34;1m*                             \033[33;1m Map \033[34;1m                                *\033[0m" << std::endl;
	std::cout << "\033[34;1m********************************************************************\033[0m" << std::endl;
	std::cout << std::endl;
}