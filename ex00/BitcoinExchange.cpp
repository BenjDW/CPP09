/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 10:36:17 by bde-wits          #+#    #+#             */
/*   Updated: 2025/05/04 11:04:42 by bde-wits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


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

int	BitcoinExchange::init_csv()
{
	std::ifstream file("data.csv");
	std::string line;
	std::string date;
	std::string valuestr;
	std::string::size_type pos;

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
		this->date = date;
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

int BitcoinExchange::parse_input(const std::string &file)
{
	std::ifstream input(file.c_str());
	std::string line;
	size_t pos;
	float value;
	float result;
	
	if (!input.is_open())
		return (std::cerr << "Error: file introuvable : " << file << std::endl, 1);

	std::getline(input, line);
	while (std::getline(input, line))
	{
		if (line.empty())
			continue;

		pos = line.find(" | ");
		if (pos == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string line_date = line.substr(0, pos);
		std::string value_str = line.substr(pos + 3);
		std::istringstream stream_value(value_str);

		this->date = line_date;
		if (this->verif_date() == 1)
		{
			std::cerr << "Error: bad date => " << line_date << std::endl;
			continue;
		}

		if (!(stream_value >> value))
		{
			std::cerr << "Error: not a number => " << value_str << std::endl;
			continue;
		}

		if (value < 0)
		{
			std::cerr << "Error: not a positive number => " << value_str << std::endl;
			continue;
		}
		if (value > 1000)
		{
			std::cerr << "Error: too large a number => " << value_str << std::endl;
			continue;
		}

		std::map<std::string, float>::const_iterator it = this->csv.lower_bound(line_date);
		if (it == this->csv.end() || it->first != line_date)
		{
			if (it != this->csv.begin())
				--it;
			else
			{
				std::cerr << "Error: no data available for date => " << line_date << std::endl;
				continue;
			}
		}

		result = value * it->second;
		std::cout << line_date << " => " << value << " = " << result << std::endl;
	}

	input.close();
	return (0);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cpy)
{
	*this = cpy;
}

BitcoinExchange BitcoinExchange::operator=(const BitcoinExchange &cpy)
{
	if (this != &cpy)
	{
		this->csv = cpy.csv;
		this->value = cpy.value;
		this->date = cpy.date;
	}
	return *this;
}

BitcoinExchange::BitcoinExchange() : value(0.0f), date("")
{
}

BitcoinExchange::~BitcoinExchange()
{
}
