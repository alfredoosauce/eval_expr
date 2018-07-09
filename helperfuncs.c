/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helperfunc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areyes-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 19:29:57 by areyes-v          #+#    #+#             */
/*   Updated: 2018/07/07 19:29:59 by areyes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr(147483648);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(nb *= -1);
	}
	else
	{
		if (nb >= 10)
			ft_putnbr(nb / 10);
		ft_putchar((nb % 10) + '0');
	}
}

int		ft_atoi(char *str)
{
	int sign;
	int result;

	sign = 1;
	result = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
					|| *str == '\r')
		str++;
	if (*str == '-')
	{
		sign = 0;
		str++;
	}
	else
	{
		while (*str <= '9' && *str >= '0')
		{
			result *= 10;
			result = (sign ? result + (*str - '0') : result - (*str - '0'));
			str++;
		}
	}
	return (result);
}

int		nbrlen(int nbr)
{
	int count;

	count = 0;
	if (nbr == 0)
		return (0);
	else
	{
		while (nbr != 0)
		{
			nbr /= 10;
			count++;
		}
	}
	return (count);
}
