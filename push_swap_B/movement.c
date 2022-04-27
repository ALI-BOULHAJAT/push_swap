/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:13:24 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/04/27 01:55:30 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_node	*part_swap(t_node *stack, int line)
{
	int	swap_num;

	if (line >= 2)
	{
		swap_num = stack->num;
		stack->num = stack->next->num;
		stack->next->num = swap_num;
	}
	return (stack);
}

void	movement_rotation(t_node **stack, char *type)
{
	int	number;

	if (*stack != NULL)
	{
		number = first_last(*stack, type);
		if (!ft_strcmp(type, "down"))
		{
			add_front_node(stack, number);
			*stack = delone(*stack, "down");
		}
		else
		{
			add_back_node(stack, number);
			*stack = delone(*stack, "up");
		}
	}
}

void	movement_swap(t_node **stack)
{
	int		line;

	line = ft_nodeline(*stack);
	if (line >= 2)
	{
		*stack = part_swap(*stack, line);
	}
}

void	ft_pa(t_node **stack1, t_node **stack2)
{
	int	number;

	number = (*stack2)->num;
	add_front_node(stack1, number);
	*stack2 = delone(*stack2, "up");
}

void	ft_pb(t_node **stack1, t_node **stack2)
{
	int	number;

	number = (*stack1)->num;
	add_front_node(stack2, number);
	*stack1 = delone(*stack1, "up");
}
