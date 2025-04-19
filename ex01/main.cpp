/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 12:00:47 by bde-wits          #+#    #+#             */
/*   Updated: 2025/04/19 05:59:15 by bde-wits         ###   ########.fr       */
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
		return ;
	else
	{
		str = argv[1];
		it_str = str.begin();
	}
	while(!str.empty() && it_str != str.end())
	{
		if (*it_str != '42' && *it_str != '43' && *it_str != '47' && *it_str != '32' && *it_str > '57' && *it_str < '48')
		{
			std::cout << "error caractere invalid format value : 5 5 +" << std::endl;
			return ;
		}
		it_str++;
	}
	it_str = str.begin();
	while(!str.empty() && it_str != str.end())
	{
		if (tic.is_signe(*it_str))
			tic.apply_op(str, it_str);
		if (str.empty() && it_str != str.end())
			tic.stack.push(*it_str - '0');
		it_str++;
	}
	// tic.stack.push();
	// tic.stack.pop();
	std::cout << tic.stack.top() << std::endl;
}