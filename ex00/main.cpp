/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 10:36:19 by bde-wits          #+#    #+#             */
/*   Updated: 2025/05/04 10:56:25 by bde-wits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	std::map<std::string, float>	imput;
	BitcoinExchange					data;

	if (argc != 2)
		return (std::cerr << "Error arg: 'base_de_donne.txt'" << std::endl, 1);
	if (data.init_csv() == 1)
		return 1;
	if (data.parse_input(argv[1]) == 1)
		return 1;
}