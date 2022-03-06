/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarquon <rzarquon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 16:32:22 by rzarquon          #+#    #+#             */
/*   Updated: 2022/03/05 17:23:14 by rzarquon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../include/so_long_bonus.h"

static int	leni(int i)
{	
	int	count;

	count = 0;
	if (i == 0)
		count++;
	if (i < 0)
		count++;
	while (i != 0)
	{
		i /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*nbr;
	int		len;

	len = leni(n);
	nbr = malloc(sizeof(char) * (len + 1));
	if (!nbr)
		return (NULL);
	nbr[len--] = '\0';
	if (n == 0)
		nbr[0] = '0';
	if (n < 0)
	{
		nbr[0] = '-';
		n = -n;
	}	
	while (n)
	{
		nbr[len] = '0' + (n % 10);
		n /= 10;
		len--;
	}
	return (nbr);
}
