/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarquon <rzarquon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 16:28:37 by rzarquon          #+#    #+#             */
/*   Updated: 2022/03/05 16:38:48 by rzarquon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	print_char(int c)
{
	write (1, &c, 1);
	return (1);
}

int	print_string(char	*s)
{
	int	count;

	if (s == NULL)
		s = "(null)";
	count = 0;
	if (!s)
		return (0);
	while (*s)
	{
		print_char(*s);
		s++;
		count++;
	}
	return (count);
}

int	print_integer(long n, int count)
{
	unsigned int	buff;

	if (n == 0)
		count = 1;
	if (n < 0)
	{
		count++;
		print_char('-');
		n *= -1;
	}
	buff = n;
	while (buff > 0)
	{
		count++;
		buff /= 10;
	}
	if (n > 9)
	{
		print_integer(n / 10, 0);
		print_char(n % 10 + '0');
	}
	else
		print_char(n + '0');
	return (count);
}

int	print_xx(unsigned long n, int count)
{
	unsigned long	buff;

	buff = n;
	while (buff > 0)
	{
		count++;
		buff /= 16;
	}
	if (n >= 16)
		print_xx(n / 16, 0);
	print_char(HEX[n % 16]);
	if (n == 0)
		return (1);
	return (count);
}

int	print_xu(unsigned int n, int count)
{
	unsigned int	buff;

	buff = n;
	while (buff > 0)
	{
		count++;
		buff /= 16;
	}
	if (n >= 16)
		print_xu(n / 16, 0);
	print_char(HEXU[n % 16]);
	if (n == 0)
		return (1);
	return (count);
}
