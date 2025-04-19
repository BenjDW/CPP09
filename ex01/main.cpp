/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 12:00:47 by bde-wits          #+#    #+#             */
/*   Updated: 2025/04/19 07:46:49 by bde-wits         ###   ########.fr       */
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
		return ;
	}
	else
	{
		str = argv[1];
		it_str = str.begin();
	}
	// while(!str.empty() && it_str != str.end())
	// {
	// 	if (*it_str != '42' && *it_str != '43' && *it_str != '47' && *it_str != '32' && *it_str > '57' && *it_str < '48')
	// 	{
	// 		std::cout << "error caractere invalid format value : 5 5 +" << std::endl;
	// 		return ;
	// 	}
	// 	it_str++;
	// }
	// it_str = str.begin();
	while(it_str != str.end())
	{
		if (std::isspace(*it_str))
		{
			++it_str;
			// continue;
		}
		if (tic.is_signe(*it_str))
			tic.apply_op(*it_str);
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