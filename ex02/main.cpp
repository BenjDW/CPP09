/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 06:25:14 by bde-wits          #+#    #+#             */
/*   Updated: 2025/05/02 07:32:37 by bde-wits         ###   ########.fr       */
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
	std::cout << "before :";
	for (size_t i = 0; i < sort.vec.size(); i++)
	{
		std::cout << sort.vec[i] << " ";
	}
	std::cout << std::endl;
	sort.algo_vec();
	sort.algo_deque();
	std::cout << "after :";
	for (size_t i = 0; i < sort.vec_tri.size(); i++)
	{
		std::cout << sort.vec_tri[i] << " ";
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of " << sort.vec_tri.size() << " elements with std::vector : " << static_cast<double>(sort.end_vec - sort.start_vec) * 1000000 / CLOCKS_PER_SEC << " us" << std::endl;
	std::cout << "Time to process a range of " << sort.vec_tri.size() << " elements with std::deque : " << static_cast<double>(sort.end_deq - sort.start_vec) * 1000000 / CLOCKS_PER_SEC << " us" << std::endl;
	
	return (0);
}