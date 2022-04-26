/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:38:57 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/04/26 17:44:30 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_min(t_node **stack1, t_pswap *stc)
{
	int	index;
	int	line;

	indexing(stack1);
	index = index_min_number(*stack1);
	line = ft_nodeline(*stack1);
	if (index <= (line / 2))
	{
		while (index - 1)
		{
			*stack1 = movement_rotation(stc, *stack1, "up");
			write (1, "ra\n", 3);
			index--;
		}
	}
	else
	{
		while (line - (index - 1))
		{
			*stack1 = movement_rotation(stc, *stack1, "down");
			write (1, "rra\n", 4);
			index++;
		}
	}
}

t_node	*sort_four(t_node *stack1, t_node **stack2, t_pswap *stc)
{
	find_min(&stack1, stc);
	ft_pb(stc, &stack1, stack2);
	stack1 = sort_three(stack1, stc);
	ft_pa(stc, &stack1, stack2);
	return (stack1);
}

t_node	*sort_five(t_node *stack1, t_node *stack2, t_pswap *stc)
{
	find_min(&stack1, stc);
	ft_pb(stc, &stack1, &stack2);
	stack1 = sort_four(stack1, &stack2, stc);
	ft_pa(stc, &stack1, &stack2);
	return (stack1);
}

t_node	*special_case(int ac, t_node *stack_a, t_node *stack_b, t_pswap *stc)
{
	if (ac == 3)
	{
		if (stack_a->num > stack_a->next->num)
			movement_swap(&stack_a, 'a');
	}
	else if (ac == 4)
		stack_a = sort_three(stack_a, stc);
	else if (ac == 5)
		stack_a = sort_four(stack_a, &stack_b, stc);
	else
		stack_a = sort_five(stack_a, stack_b, stc);
	return (stack_a);
}
