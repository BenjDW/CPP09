/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 06:25:33 by bde-wits          #+#    #+#             */
/*   Updated: 2025/05/02 07:48:09 by bde-wits         ###   ########.fr       */
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
		void				pair(std::vector<std::pair<int, int> > &pairs);
		void				pair_deq(std::deque<std::pair<int, int> > &pairs);
		int					first_verif(char **argv);

		void				algo_vec();
		std::vector<int> 	vec_tri;
		clock_t 			start_vec;
		clock_t 			end_vec;
		void				algo_deque();
		std::deque<int> 	deq_tri;
		clock_t 			start_deq;
		clock_t 			end_deq;
};

int	PmergeMe::first_verif(char **argv)
{
	int i = 0;
	int value;
	std::string arg(argv[i]);

	while (argv[++i] != NULL)
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

void	PmergeMe::pair(std::vector<std::pair<int, int> > &pairs)
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

void	PmergeMe::algo_vec()
{
	start_vec = clock();
	std::vector<std::pair<int, int>> pairs;
	int temp;
	int value;

	pair(pairs);

	for (size_t i = 0; i < pairs.size(); ++i)
		vec_tri.push_back(pairs[i].first);

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

	for (size_t i = 0; i < pairs.size(); ++i)
	{
		if (pairs[i].second == -1)
			continue;
		value = pairs[i].second;

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
	end_vec = clock();
}

void	PmergeMe::pair_deq(std::deque<std::pair<int, int> > &pairs)
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

void PmergeMe::algo_deque()
{
	start_deq = clock();
	std::deque<std::pair<int, int> > pairs;
	int temp;
	int value;

	pair_deq(pairs);

	for (size_t i = 0; i < pairs.size(); ++i)
		deq_tri.push_back(pairs[i].first);

	for (size_t i = 1; i < deq_tri.size(); ++i)
	{
		temp = deq_tri[i];
		size_t j = i;
		while (j > 0 && deq_tri[j - 1] > temp)
		{
			deq_tri[j] = deq_tri[j - 1];
			--j;
		}
		deq_tri[j] = temp;
	}

	for (size_t i = 0; i < pairs.size(); ++i)
	{
		if (pairs[i].second == -1)
			continue;
		value = pairs[i].second;

		size_t left = 0;
		size_t right = deq_tri.size();
		while (left < right)
		{
			size_t mid = (left + right) / 2;
			if (deq_tri[mid] < value)
				left = mid + 1;
			else
				right = mid;
		}
		deq_tri.insert(deq_tri.begin() + left, value);
	}
	end_deq = clock();
}

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}
