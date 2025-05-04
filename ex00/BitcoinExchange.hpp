/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 10:36:13 by bde-wits          #+#    #+#             */
/*   Updated: 2025/05/04 10:14:16 by bde-wits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <ostream>
#include <iomanip>
#include <fstream>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <list>
#include <map>

// Votre programme doit respecter ces règles:
// • Le nom du programme est btc.
// • Votre programme doit prendre un fichier en argument.
// • Chaque ligne de ce fichier doit utiliser le format suivant: "date | valeur".
// • Une date valide sera toujours au format "Année-Mois-Jour" (YYYY-MM-DD).
// • Une valeur valide doit être soit un nombre à virgule flottante (float), ou un entier
// positif, compris entre 0 et 1000.

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
};

int	BitcoinExchange::verif_date()
{
	int year;
	int month;
	int day;
	int max_day = 31;

	if (this->date.length() != 10)
		return (1);

	for (size_t i = 0; i < this->date.length(); ++i)
	{
		if (i == 4 || i == 7)
		{
			if (this->date[i] != '-')
				return (1);
		}
		else if (!std::isdigit(this->date[i]))
			return (1);
	}

	std::string year_str = this->date.substr(0, 4);
	std::string month_str = this->date.substr(5, 2);
	std::string day_str = this->date.substr(8, 2);

	std::istringstream stream_year(year_str);
	std::istringstream stream_month(month_str);
	std::istringstream stream_day(day_str);

	if (!(stream_year >> year) || !(stream_month >> month) || !(stream_day >> day))
		return (1);
	if (month == 2)
	{
		bool bissextile = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		if (bissextile == true)
			max_day = 29;
		else
			max_day = 28;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		max_day = 30;
	if (day < 1 || day > max_day)
		return (1);

	return (0);
}

// recupere la data.csv et init la map
int	BitcoinExchange::init_csv()
{
	std::ifstream file("data.csv");
	std::string line;
	std::string date;
	std::string valuestr;
	// std::stringstream conv;
	long long	pos;

	if (!file.is_open())
		return (std::cerr << "Error: fichier introuvable data.csv" << std::endl, 1);
	std::getline(file, line);

	while (std::getline(file, line))
	{
		pos = line.find(',');
		if (pos == std::string::npos)
			return (std::cerr << "error : virgule manquante" << line << std::endl, 1);

		date = line.substr(0, pos);
		valuestr = line.substr(pos + 1);

		if (verif_date() == 1)
			return (std::cerr << "date invalid : " << date << std::endl, 1);

		std::stringstream conv(valuestr);
		conv >> this->value;
		if (conv.fail() || value < 0)
			return (std::cerr << "Valeur invalide dans CSV : " << valuestr << std::endl, 1);

		this->csv[date] = value;
	}

	file.close();
	return (0);
}

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}
