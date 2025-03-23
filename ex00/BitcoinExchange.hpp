/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 10:36:13 by bde-wits          #+#    #+#             */
/*   Updated: 2025/03/23 11:13:20 by bde-wits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <ostream>
#include <iomanip>
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
	
};

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}
