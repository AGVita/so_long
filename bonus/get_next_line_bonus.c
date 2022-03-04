/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzarquon <rzarquon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 05:22:28 by rzarquon          #+#    #+#             */
/*   Updated: 2022/02/27 20:49:49 by rzarquon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../include/so_long_bonus.h"

char	*end_of_line(char	*reminder)
{
	int		i;
	char	*lastline;

	i = 0;
	if (!reminder[i])
		return (NULL);
	while (reminder[i] && reminder[i] != '\n')
		i++;
	lastline = (char *)malloc(sizeof(char) * (i + 2));
	if (!lastline)
		return (NULL);
	i = 0;
	while (reminder[i] && reminder[i] != '\n')
	{
		lastline[i] = reminder[i];
		i++;
	}
	if (reminder[i] == '\n' || lastline[ft_strlen(lastline) - 1] != '\n')
	{
		lastline[i] = '\n';
		i++;
	}
	lastline[i] = '\0';
	return (lastline);
}

char	*first_cut(int fd, char	*reminder)
{
	char	*buffer;
	int		rb;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	rb = 1;
	while (rb != 0 && !ft_strchr(reminder, '\n'))
	{	
		rb = read(fd, buffer, BUFFER_SIZE);
		if (rb == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[rb] = '\0';
		reminder = ft_strjoin(reminder, buffer);
	}		
	free(buffer);
	return (reminder);
}

char	*new_reminder(char	*reminder)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	while (reminder[i] && reminder[i] != '\n')
		i++;
	if (!reminder[i])
	{
		free(reminder);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * (ft_strlen(reminder) - i + 1));
	if (!s)
		return (NULL);
	i++;
	j = 0;
	while (reminder[i] != '\0')
		s[j++] = reminder[i++];
	free(reminder);
	s[j] = '\0';
	return (s);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*reminder;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	reminder = first_cut(fd, reminder);
	if (!reminder)
		return (NULL);
	line = end_of_line(reminder);
	reminder = new_reminder(reminder);
	return (line);
}
