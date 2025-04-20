/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 06:25:33 by bde-wits          #+#    #+#             */
/*   Updated: 2025/04/20 09:34:47 by bde-wits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <ostream>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <vector>
#include <deque>

class PmergeMe
{
	private:

	public:
		PmergeMe();
		~PmergeMe();
		std::vector<int>	vec;
		std::deque<int>		deq;
		int					first_verif(char **argv);

		void				algo_vec();
		void				algo_deque();
};

//parsing part
// int	PmergeMe::first_verif(char **argv)
// {
// 	int limit = 0;
	
// 	while (argv != NULL)
// 		limit++;
// 	for (size_t i = 1; i < limit; i++)
// 	{
// 		int j = 1;

// 		if (!std::isdigit(std::atoi(argv[i])))
// 			return (std::cerr << "Error : only numeric number needed" << std::endl, 1);
// 		while (argv[j] != NULL)
// 		{
// 			if (j == i)
// 				j++;
// 			if (std::atoi(argv[i]) == std::atoi(argv[j]))
// 				return (std::cerr << "Error : int en double detected" << std::endl, 1);
// 		}
// 		vec.push_back(std::atoi(argv[i]));
// 		deq.push_back(std::atoi(argv[i]));
// 	}
// }

int	PmergeMe::first_verif(char **argv)
{
	int i = 1;
	int value;
	std::string arg(argv[i]);

	while (argv[i] != NULL)
	{
		arg = argv[i];
		for (size_t j = 0; j < arg.length(); j++)
		{
			if (!std::isdigit(arg[j]))
				return (std::cerr << "Error: only positive integers are allowed: " << arg << std::endl, 1);
		}
		value = std::atoi(argv[i]);
		for (size_t k = 0; k < vec.size(); k++)
		{
			if (vec[k] == value)
				return (std::cerr << "Error: duplicate value detected: " << value << std::endl, 1);
		}
		vec.push_back(value);
		deq.push_back(value);
	}
	return (0);
}

void	PmergeMe::algo_vec()
{
	
}

void	PmergeMe::algo_deque()
{

}

//exec part
// int	PmergeMe::ft_algo()
// {

// }

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}
