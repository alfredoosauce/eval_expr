/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helperfuncs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areyes-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 21:18:05 by areyes-v          #+#    #+#             */
/*   Updated: 2018/07/07 21:18:06 by areyes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERFUNCS_H
# define HELPERFUNCS_H
# include "stack.h"

void	ft_putchar(char c);
int		is_whitespace(char c);
void	ft_putnbr(int nb);
int		ft_atoi(char *str);
int		nbrlen(int nbr);
int		digits(int num);

void	close_paren_case(t_stack *g_opp, void (*do_op)(char c));
void	opperator_case(t_stack *g_opp, void (*do_op)(char c),
	int (*precedence)(char c1, char c2), char c);
void	operand_case(char *str, t_stack *g_nbr, int *numlen);

#endif
