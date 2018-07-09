/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackfuncs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areyes-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 21:23:45 by areyes-v          #+#    #+#             */
/*   Updated: 2018/07/07 21:23:57 by areyes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	push(int x, t_stack *s)
{
	s->top += 1;
	s->stack[s->top] = x;
}

int		pop(t_stack *s)
{
	int num;

	num = 0;
	if (s->top == -1)
		return (0);
	else
	{
		num = s->stack[s->top];
		s->top -= 1;
		return (num);
	}
}

int		empty(t_stack *s)
{
	return (s->top == -1);
}
