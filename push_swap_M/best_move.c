/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:50:21 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/04/26 17:45:10 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_nodeline(t_node *stack)
{
	int	i;

	i = 0;
	if (stack != NULL)
	{
		while (stack->next != NULL)
		{
			stack = stack->next;
			i++;
		}
		i++;
	}
	return (i);
}

int	index_min_number(t_node *stack)
{
	int	index;

	index = 0;
	while (stack != NULL)
	{
		if (stack->is_list == 1)
		{
			index++;
			break ;
		}
		stack = stack->next;
		index++;
	}
	return (index);
}

int	index_max_number(t_node *stack)
{
	int	index;
	int	line;

	index = 0;
	line = ft_nodeline(stack);
	while (stack != NULL)
	{
		if (stack->is_list == line)
		{
			index++;
			break ;
		}
		index++;
		stack = stack->next;
	}
	return (index);
}

t_node	*best_move(t_pswap*stc, t_node *stack1, t_node *stack2)
{
	to_b(stc, &stack1, &stack2);
	to_a(stc, &stack1, &stack2);
	return (stack1);
}
