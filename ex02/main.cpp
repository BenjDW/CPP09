/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 06:25:14 by bde-wits          #+#    #+#             */
/*   Updated: 2025/04/30 09:30:17 by bde-wits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	PmergeMe	sort;
	if (argc < 2)
		return (std::cerr << "Error number of arg" << std::endl, 1);
	if (sort.first_verif(argv) == 1)
		return (1);
	sort.algo_vec();
	// sort.algo_deque();
	
	return (0);
}