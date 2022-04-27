/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:52:46 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/04/27 01:54:15 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*check_null(char *str)
{
	int	i;

	i = 0;
	while (str[i] == '0')
		i++;
	return (&str[i]);
}

void	check_repeat(char *str)
{
	int		i;
	char	**tab;
	int		j;

	i = 0;
	tab = ft_split(str, ' ');
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (!(ft_numcmp(tab[i], tab[j])))
				ft_error();
			j++;
		}
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	*pre_join(char *s1, char *s2)
{
	char	*tab;

	tab = ft_strjoin(s1, s2);
	free (s1);
	return (tab);
}

char	*ft_join(char **av)
{
	int		i;
	int		j;
	char	*tab;
	char	**num;
	char	*temp;

	i = 1;
	tab = ft_strdup("");
	while (av[i])
	{
		j = 0;
		num = ft_split(av[i], ' ');
		if (num[0] == NULL)
			ft_error();
		while (num[j])
		{
			temp = pre_join(tab, num[j]);
			tab = pre_join(temp, " ");
			free(num[j]);
			j++;
		}
		free(num);
		i++;
	}
	return (tab);
}

char	*ft_check_arg(char **av)
{
	int		i;
	int		j;
	char	**num;
	char	*tab;

	i = 1;
	while (av[i])
	{
		j = 0;
		num = ft_split(av[i], ' ');
		while (num[j])
		{
			if (!ft_isnumber(num[j]))
				ft_error();
			free(num[j]);
			j++;
		}
		free(num);
		i++;
	}
	tab = ft_join(av);
	check_repeat(tab);
	return (tab);
}
