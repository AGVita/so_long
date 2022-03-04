/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarquon <rzarquon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 05:24:06 by rzarquon          #+#    #+#             */
/*   Updated: 2022/02/27 20:49:30 by rzarquon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../include/so_long_bonus.h"

size_t	ft_strlen(char	*s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
		++i;
	return (i);
}

char	*ft_strchr(char	*s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strnstr(char *haystack, char *needle, size_t len)
{	
	char	*dest;
	size_t	i;
	int		j;
	int		count;

	dest = (char *)haystack;
	count = 0;
	if (ft_strlen(needle) == 0)
		return (dest);
	while (dest[count] != '\0' && len != 0)
	{	
		i = 0;
		j = count;
		while (needle[i] == dest[j] && i < len)
		{	
			i++;
			j++;
			if (needle[i] == '\0')
				return ((char *)&dest[j - i]);
		}
		count++;
		len--;
	}
	return (NULL);
}

char	*ft_strjoin(char	*s1, char	*s2)
{
	int		i;
	int		j;
	char	*res;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i] != '\0')
			res[i] = s1[i];
	while (s2[j] != '\0')
		res[i++] = s2[j++];
	res[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free (s1);
	return (res);
}
