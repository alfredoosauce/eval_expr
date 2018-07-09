/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areyes-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 22:15:18 by areyes-v          #+#    #+#             */
/*   Updated: 2018/07/07 22:15:20 by areyes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helperfunc.h"
#include "stack.h"

void 	close_paren_case(t_stack *g_opp, void (*do_op)(char c))
{
	while ((*g_opp).stack[(g_opp).top] != '(')
		do_op('.');
	pop(do_op)
}
void	opperator_case(t_stack *g_opp, void (*do_op)(char c),
				int (*precedence)(char c1, char c2), char c)
{
	while (!empty(*g_opp) &&
		(*precedence)((*g_opp).stack[(*g_opp).top], c))
		do_op('.');
	push(c, g_opp);
}

void	operand_case(char *str, t_stack *g_nbr, int *numlen)
{
	push(ft_atoi(str), g_nbr);
	*numlen = nbrlen(ft_atoi(str);
}
