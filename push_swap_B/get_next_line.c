/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 23:00:43 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/04/27 00:27:50 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	l_s;
	int		i;

	l_s = ft_strlen((char *)s1);
	str = malloc((l_s + 1) * sizeof (char));
	i = 0;
	if (!str)
		exit(1);
	while (s1[i] && l_s)
	{
		str[i] = (char)s1[i];
		l_s--;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	char	buff[1];
	char	line[999999];
	int		i;
	int		n;

	line[0] = 0;
	i = 0;
	if (fd < 0)
		return (NULL);
	n = read(fd, buff, 1);
	while (n > 0)
	{
		line[i++] = buff[0];
		line[i] = '\0';
		if (buff[0] == '\n')
			return (ft_strdup(line));
		n = read(fd, buff, 1);
	}
	if (!line[0])
		return (NULL);
	return (ft_strdup(line));
}
