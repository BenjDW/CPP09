/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 06:25:33 by bde-wits          #+#    #+#             */
/*   Updated: 2025/04/30 08:02:40 by bde-wits         ###   ########.fr       */
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
#include <string>
#include <utility>
#include <ctime>

class PmergeMe
{
	private:

	public:
		PmergeMe();
		~PmergeMe();
		std::vector<int>	vec;
		std::deque<int>		deq;
		void				pair(std::vector<std::pair<int, int>> pairs);
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

void	PmergeMe::pair(std::vector<std::pair<int, int>> pairs)
{
	for (size_t i = 0; i + 1 < vec.size(); i += 2)
	{
		int a = vec[i];
		int b = vec[i + 1];
		if (a < b)
			pairs.push_back(std::make_pair(b, a));
		else
			pairs.push_back(std::make_pair(a, b));
	}
	if (vec.size() % 2 != 0)
		pairs.push_back(std::make_pair(vec[vec.size() - 1], -1));	
}

//exec part
void	PmergeMe::algo_vec()
{
	// clock_t start = clock();

	//créer les paires (max, min)
	std::vector<std::pair<int, int>> pairs;
	std::vector<int> vec_tri;
	int temp;
	pair(pairs);

	//trier les max (premiers des paires)
	for (size_t i = 0; i < pairs.size(); ++i)
		vec_tri.push_back(pairs[i].first);

	//Insertion sort
	for (size_t i = 1; i < vec_tri.size(); ++i)
	{
		temp = vec_tri[i];
		size_t j = i;
		while (j > 0 && vec_tri[j - 1] > temp)
		{
			vec_tri[j] = vec_tri[j - 1];
			--j;
		}
		vec_tri[j] = temp;
	}

	// Étape 3 : insertion des min dans l'ordre Jacobsthal
	// std::vector<int> pending;
	// for (size_t i = 0; i < pairs.size(); ++i)
	// {
	// 	if (pairs[i].second != -1)
	// 		pending.push_back(pairs[i].second);
	// }

	// // Génération des indices Jacobsthal
	// std::vector<size_t> insert_order;
	// size_t j1 = 1, j2 = 1;
	// while (j2 < pending.size())
	// {
	// 	insert_order.push_back(j2);
	// 	size_t next = j2 + 2 * j1;
	// 	j1 = j2;
	// 	j2 = next;
	// }
	// for (size_t i = 0; i < pending.size(); ++i)
	// {
	// 	if (std::find(insert_order.begin(), insert_order.end(), i) == insert_order.end())
	// 		insert_order.push_back(i);
	// }

	// Insertion avec recherche binaire
	// for (size_t i = 0; i < insert_order.size(); ++i)
	// {
	// 	if (insert_order[i] >= pending.size())
	// 		continue;
	// 	int value = pending[insert_order[i]];
	// 	size_t left = 0;
	// 	size_t right = vec_tri.size();
	// 	while (left < right)
	// 	{
	// 		size_t mid = (left + right) / 2;
	// 		if (vec_tri[mid] < value)
	// 			left = mid + 1;
	// 		else
	// 			right = mid;
	// 	}
	// 	vec_tri.insert(vec_tri.begin() + left, value);
	// }
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		if (pairs[i].second == -1)
			continue;
		int value = pairs[i].second;

		// Recherche binaire pour trouver l'emplacement d'insertion
		size_t left = 0;
		size_t right = vec_tri.size();
		while (left < right)
		{
			size_t mid = (left + right) / 2;
			if (vec_tri[mid] < value)
				left = mid + 1;
			else
				right = mid;
		}
		vec_tri.insert(vec_tri.begin() + left, value);
	}
}

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}
