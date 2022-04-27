/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:52:46 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/04/26 22:40:31 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_join(t_pswap *stc)
{
	int		i;
	int		j;
	char	**num;
	char	*temp;

	i = 1;
	stc->tab = ft_strdup("");
	while (stc->argv[i])
	{
		j = 0;
		num = ft_split(stc->argv[i], ' ');
		if (num[0] == NULL)
			ft_error();
		while (num[j])
		{
			temp = pre_join(stc->tab, num[j]);
			stc->tab = pre_join(temp, " ");
			free(num[j]);
			j++;
		}
		free(num);
		i++;
	}
}

void	ft_check_arg(t_pswap *stc)
{
	int		i;
	int		j;
	char	**num;

	i = 1;
	while (stc->argv[i])
	{
		j = 0;
		num = ft_split(stc->argv[i], ' ');
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
	ft_join(stc);
	check_repeat(stc->tab);
}
