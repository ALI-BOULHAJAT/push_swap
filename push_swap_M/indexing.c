/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:55:16 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/04/26 17:53:28 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*sorting_arr(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (size - i)
	{
		j = i + 1;
		while (size - j)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (tab);
}

int	*stack_to_arry(t_node *stack, int *tab)
{
	int	i;

	i = 0;
	while (stack != NULL)
	{
		tab[i] = stack->num;
		stack = stack->next;
		i++;
	}
	tab[i] = 'NULL';
	return (tab);
}

int	arry_sort(t_node *stack, int **tab)
{
	int		size;
	int		i;
	t_node	*cpy;

	cpy = stack;
	size = 0;
	i = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		size++;
	}
	*tab = (int *)malloc(sizeof(int) * (size + 1));
	if (!*tab)
		exit(1);
	stack = cpy;
	*tab = stack_to_arry(stack, *tab);
	*tab = sorting_arr(*tab, size);
	return (size);
}

void	indexing(t_node **stack)
{
	t_node	*cpy;
	int		index;
	int		*tab;
	int		i;

	cpy = *stack;
	i = 0;
	index = arry_sort(*stack, &tab);
	*stack = cpy;
	while (*stack != NULL)
	{
		if (tab[i] == (*stack)->num)
		{
			(*stack)->is_list = i + 1;
			*stack = cpy;
			i++;
		}
		else
			*stack = (*stack)->next;
	}
	*stack = cpy;
	free(tab);
}
