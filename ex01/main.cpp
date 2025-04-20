/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 12:00:47 by bde-wits          #+#    #+#             */
/*   Updated: 2025/04/20 05:42:26 by bde-wits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iterator>

int main(int argc, char **argv)
{
	RPN						tic;
	std::string				str;
	std::string::iterator	it_str;

	if (argc != 2)
	{
		std::cerr << "./RPN int int operator" << std::endl;
		return (1);
	}
	else
	{
		str = argv[1];
		it_str = str.begin();
	}
	while(it_str != str.end())
	{
		if (std::isspace(*it_str))
			++it_str;
		if (tic.is_signe(*it_str))
		{
			if (tic.apply_op(*it_str) == 1)
				return (1);
		}
		else if (std::isdigit(*it_str))
			tic.stack.push(*it_str - '0');
		else
		{
			std::cerr << "Error" << std::endl;
			return (1);
		}
		it_str++;
	}
	if (tic.stack.size() != 1)
	{
		std::cerr << "Error" << std::endl;
		return (1);
	}
	std::cout << tic.stack.top() << std::endl;
}