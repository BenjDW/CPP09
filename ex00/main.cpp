/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 10:36:19 by bde-wits          #+#    #+#             */
/*   Updated: 2025/03/23 11:13:25 by bde-wits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Vous devez créer un programme qui affiche la valeur d’une certaine quantité de bitcoins
// à une certaine date.
// Ce programme doit utiliser une base de données au format CSV qui représentera le
// prix du bitcoin au fil du temps. Cette base de données est fournie avec le sujet.

// Le programme prendra en entrée une deuxième base de données stockant les différents
// prix / dates à évaluer.

// Votre programme doit respecter ces règles:
// • Le nom du programme est btc.
// • Votre programme doit prendre un fichier en argument.
// • Chaque ligne de ce fichier doit utiliser le format suivant: "date | valeur".
// • Une date valide sera toujours au format "Année-Mois-Jour" (YYYY-MM-DD).
// • Une valeur valide doit être soit un nombre à virgule flottante (float), ou un entier
// positif, compris entre 0 et 1000.

int	main(int argc, char **argv)
{
	
	if (argc != 3)// prend 2 base de données en entrées
		std::cerr << "Error arg attend : base_csv base_de_donnée" << std::endl;
	
}