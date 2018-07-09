/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areyes-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 14:39:59 by areyes-v          #+#    #+#             */
/*   Updated: 2018/07/07 14:40:00 by areyes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "helperfuncs.h"

t_stack g_opp;
t_stack g_nbr;

void	do_op(char opp)
{
	int opperator;
	int num1;
	int num2;
	int result;

	opperator = '+';
	if (opp == '.')
		opperator = pop(&g_opp);
	num2 = pop(&g_nbr);
	num1 = pop(&g_nbr);
	result = 0;
	if (opperator == '+')
		result = num1 + num2;
	if (opperator == '-')
		result = num1 - num2;
	if (opperator == '/')
		result = num1 / num2;
	if (opperator == '*')
		result = num1 * num2;
	if (opperator == '%')
		result = num1 % num2;
	push(result, &g_nbr);
}

int		is_opperator(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

int		precedence(char c1, char c2)
{
	int opp1;
	int opp2;

	opp1 = -1;
	opp2 = -1;
	if (c1 == '+' || c1 == '-')
		opp1 = 0;
	if (c1 == '*' || c1 == '/' || c1 == '%')
		opp1 = 1;
	if (c2 == '+' || c2 == '-')
		opp2 = 0;
	if (c2 == '*' || c2 == '/' || c2 == '%')
		opp2 = 1;
	return (opp1 >= opp2);
}

int		eval_exprssion(char *str)
{
	int i;
	int numlen;

	g_opp.top = -1;
	g_nbr.top = -1;
	i = 0;
	while (str[i] != '\0')
	{
		numlen = 0;
		if (ft_atoi(&str[i]) != 0 || str[i] == '0')
			operand_case(&str[i], &g_nbr, &numlen);
		else if (str[i] == '(')
			push(str[i], &g_opp);
		else if (str[i] == ')')
			close_paren_case(&g_opp, &do_op);
		else if (is_opperator(str[i]))
			opperator_case(&g_opp, &do_op, &precedence, str[i]);
		i += (1 + numlen);
	}
	while (!empty(&g_opp))
		do_op('.');
	while (g_nbr.top > 0)
		do_op('+');
	return (!empty(&g_nbr)) ? (g_nbr.stack[g_nbr.top]) : 0;
}
