/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areyes-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 21:13:42 by areyes-v          #+#    #+#             */
/*   Updated: 2018/07/07 21:13:49 by areyes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef struct	s_stack
{
	int		stack[100];
	int		top;
}				t_stack;

void			push(int x, t_stack *s);
int				pop(t_stack *s);
int				empty(t_stack *s);

#endif
