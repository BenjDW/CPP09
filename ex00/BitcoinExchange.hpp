/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 10:36:13 by bde-wits          #+#    #+#             */
/*   Updated: 2025/05/04 11:01:46 by bde-wits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <ostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cctype>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <list>
#include <map>

class BitcoinExchange
{
	private:
		
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &cpy);
		BitcoinExchange	operator=(const BitcoinExchange &cpy);
		~BitcoinExchange();
		std::map<std::string, float>	csv;
		float							value;
		std::string						date;

		int	init_csv();
		int	verif_date();
		int parse_input(const std::string &file);
};
