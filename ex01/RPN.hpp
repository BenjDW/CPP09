/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 12:00:55 by bde-wits          #+#    #+#             */
/*   Updated: 2025/04/19 05:58:28 by bde-wits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <ostream>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <stack>

// Vous devez créer un programme avec ces contraintes:
// • Votre programme doit prendre en argument une expression mathématique en notation polonaise inversée.
// • Les chiffres utilisés dans cette opération et transmis en tant qu’arguments seront
// toujours inférieurs à 10. Le calcul lui-même ainsi que le résultat ne tiennent pas
// compte de cette règle.
// • Votre programme doit traiter cette expression et afficher le résultat correct sur la
// sortie standard.
// • Si une erreur se produit pendant l’exécution du programme, un message d’erreur
// doit être affiché sur la sortie d’erreur.
// • Votre programme doit être capable de gérer les opérations avec ces opérateurs: "+
// - / *".

class RPN
{
	private:
		
	public:
		RPN();
		~RPN();
		// std::string 	str;
		std::stack<int> stack;
		int				result;
		bool			is_signe(char c);
		void			apply_op(std::string str, std::string::iterator it_str);
};

//verif si y a un signe et donc applique le comportement associe
bool RPN::is_signe(char c)
{
	if (c != '-' && c != '+' && c != '/' && c != '*')
		return (false);
	else
		return (true);
}

void	RPN::apply_op(std::string str, std::string::iterator it_str)
{
	int one;
	int	two;
	int result;

	if (stack.size() != 2)
		std::cerr << "error need 2 number with one opérator" << std::endl, exit(1);
	else
	{
		one = stack.top();
		stack.pop();
		two = stack.top();
		if (*it_str == '+')
			result = one + two;
		else if (*it_str == '-')
			result = one - two;
		else if (*it_str == '/')
			result = one / two;
		else if (*it_str == '*')
			result = one * two;
	}
	stack.push(result);
}

RPN::RPN()
{
}

RPN::~RPN()
{
}
