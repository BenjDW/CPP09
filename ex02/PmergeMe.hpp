/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 06:25:33 by bde-wits          #+#    #+#             */
/*   Updated: 2025/05/02 08:55:14 by bde-wits         ###   ########.fr       */
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
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
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
