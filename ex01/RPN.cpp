/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-wits <bde-wits@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 12:00:52 by bde-wits          #+#    #+#             */
/*   Updated: 2025/05/02 09:23:48 by bde-wits         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool RPN::is_signe(char c)
{
	if (c != '-' && c != '+' && c != '/' && c != '*')
		return (false);
	else
		return (true);
}

int	RPN::apply_op(char op)
{
	int one;
	int	two;
	int result;

	if (stack.size() < 2)
		return (std::cerr << "error need 2 number with one opérator" << std::endl, 1);
	result = 0;
	one = stack.top();
	stack.pop();
	two = stack.top();
	stack.pop();

	if (op == '+')
		result = two + one;
	else if (op == '-')
		result = two - one;
	else if (op == '*')
		result = two * one;
	else if (op == '/')
	{
		if (one == 0)
			return (std::cerr << "Error: division by zero" << std::endl, 1);
		result = two / one;
	}
	stack.push(result);
	return (0);
}

RPN::RPN(const RPN &other)
{
	this->stack = other.stack;
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
		this->stack = other.stack;
	return *this;
}

RPN::RPN()
{
}

RPN::~RPN()
{
}