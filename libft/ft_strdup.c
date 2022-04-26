/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 08:59:11 by aboulhaj          #+#    #+#             */
/*   Updated: 2021/11/10 17:50:31 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	l_s;
	int		i;

	l_s = ft_strlen((char *)s1);
	str = malloc((l_s + 1) * sizeof (char));
	i = 0;
	if (str == NULL)
		return (NULL);
	while (s1[i] && l_s)
	{
		str[i] = (char)s1[i];
		l_s--;
		i++;
	}
	str[i] = '\0';
	return (str);
}
