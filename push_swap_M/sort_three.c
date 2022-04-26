/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:46:18 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/04/26 16:49:28 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*else_three(t_pswap *stc, t_node *stack)
{
	int	first;
	int	second;
	int	third;

	first = stack->num;
	second = stack->next->num;
	third = stack->next->next->num;
	if (third > second)
		return (stack);
	else if (first > third)
	{
		write(1, "rra\n", 4);
		stack = movement_rotation(stc, stack, "down");
	}
	else
	{
		stack = movement_swap(&stack, 'a');
		write(1, "ra\n", 3);
		stack = movement_rotation(stc, stack, "up");
	}
	return (stack);
}

void	if_three(t_pswap *stc, t_node **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->num;
	second = (*stack)->next->num;
	third = (*stack)->next->next->num;
	if (third > first)
		*stack = movement_swap(stack, 'a');
	else if (second < third)
	{
		write(1, "ra\n", 3);
		*stack = movement_rotation(stc, *stack, "up");
	}
	else
	{
		write(1, "ra\n", 3);
		*stack = movement_rotation(stc, *stack, "up");
		*stack = movement_swap(stack, 'a');
	}
}

t_node	*sort_three(t_node *stack, t_pswap *stc)
{
	int	first;
	int	second;
	int	third;

	first = stack->num;
	second = stack->next->num;
	third = stack->next->next->num;
	if (first > second)
		if_three(stc, &stack);
	else
		stack = else_three(stc, stack);
	return (stack);
}
