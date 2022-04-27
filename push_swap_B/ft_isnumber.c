/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:54:53 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/04/27 01:53:19 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_isnumber(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		ft_error();
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_numcmp(const char *s1, const char *s2)
{
	int	src1;
	int	src2;
	int	i;

	src1 = ft_atoi(s1);
	src2 = ft_atoi(s2);
	i = 0;
	return (src1 - src2);
}

void	ft_parcing(char *line, t_node **stack_A)
{
	int		i;
	int		j;
	char	**tab;
	int		num;
	t_node	**cpy;

	i = 1;
	j = 0;
	cpy = stack_A;
	tab = ft_split(line, ' ');
	num = ft_atoi(tab[j]);
	free(tab[j]);
	*stack_A = ft_newnode(num);
	j++;
	while (tab[j])
	{
		num = ft_atoi(tab[j]);
		add_back_node(stack_A, num);
		free(tab[j]);
		j++;
	}
	free(line);
	free(tab);
}

void	ft_free(t_node **stack_a, t_node **stack_b)
{
	t_node	*cpy;

	while (*stack_a != NULL)
	{
		cpy = *stack_a;
		*stack_a = (*stack_a)->next;
		free (cpy);
	}
	while (*stack_b != NULL)
	{
		cpy = *stack_b;
		*stack_b = (*stack_b)->next;
		free (cpy);
	}
	*stack_b = NULL;
}

void	ft_error(void)
{
	write (2, "Error\n", 7);
	exit(1);
}
