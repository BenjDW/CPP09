/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 06:25:42 by bde-wits          #+#    #+#             */
/*   Updated: 2025/05/02 09:17:24 by bde-wits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	PmergeMe::first_verif(char **argv)
{
	int i = 0;
	int value;
	std::string arg(argv[i]);

	while (argv[++i] != NULL)
	{
		arg = argv[i];
		value = 0;
		for (size_t j = 0; j < arg.length(); j++)
		{
			if (!std::isdigit(arg[j]))
				return (std::cerr << "Error: only positive integers are allowed: " << arg << std::endl, 1);
		}
		for (size_t j = 0; j < arg.length(); j++)
		{
			value = value * 10 + (arg[j] - '0');
		}
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
	std::vector<std::pair<int, int> > pairs;
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

PmergeMe::PmergeMe(const PmergeMe &other)
{
	this->vec = other.vec;
	this->deq = other.deq;
	this->vec_tri = other.vec_tri;
	this->deq_tri = other.deq_tri;
	this->start_vec = other.start_vec;
	this->end_vec = other.end_vec;
	this->start_deq = other.start_deq;
	this->end_deq = other.end_deq;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		this->vec = other.vec;
		this->deq = other.deq;
		this->vec_tri = other.vec_tri;
		this->deq_tri = other.deq_tri;
		this->start_vec = other.start_vec;
		this->end_vec = other.end_vec;
		this->start_deq = other.start_deq;
		this->end_deq = other.end_deq;
	}
	return *this;
}

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}