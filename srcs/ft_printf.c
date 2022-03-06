/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarquon <rzarquon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 16:26:31 by rzarquon          #+#    #+#             */
/*   Updated: 2022/03/05 16:38:45 by rzarquon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	print_perc(void)
{
	write (1, "%", 1);
	return (1);
}

int	start_parser(va_list ap, char c)
{
	int	i;

	i = 0;
	if (c == 'c')
		i = print_char(va_arg(ap, int));
	if (c == 's')
		i = print_string(va_arg(ap, char *));
	if (c == 'd' || c == 'i')
		i = print_integer(va_arg(ap, int), 0);
	if (c == 'u')
		i = print_integer(va_arg(ap, unsigned int), 0);
	if (c == 'x')
		i = print_xx(va_arg(ap, unsigned int), 0);
	if (c == 'X')
		i = print_xu(va_arg(ap, unsigned int), 0);
	if (c == 'p')
	{
		write (1, "0x", 2);
		i = print_xx((unsigned long)va_arg(ap, void *), 0) + 2;
	}
	if (c == '%')
	{
		i = print_perc();
	}
	return (i);
}

int	ft_printf(const char *s, ...)
{	
	unsigned int	count;
	va_list			ap;

	count = 0;
	va_start(ap, s);
	while (*s)
	{
		if (*s != '%')
		{
			write(1, s, 1);
			count++;
		}
		else
		{
			count += start_parser(ap, *++s);
		}
		s++;
	}
	va_end(ap);
	return (count);
}
