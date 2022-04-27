/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:56:07 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/04/27 00:38:42 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*part_swap(t_node *stack, int line)
{
	int	swap_num;
	int	swap_list;

	if (line >= 2)
	{
		swap_num = stack->num;
		swap_list = stack->is_list;
		stack->num = stack->next->num;
		stack->is_list = stack->next->is_list;
		stack->next->num = swap_num;
		stack->next->is_list = swap_list;
	}
	return (stack);
}

t_node	*movement_swap(t_node **stack, char name_stack)
{
	int		line;

	line = ft_nodeline(*stack);
	if (line >= 2)
	{
		*stack = part_swap(*stack, line);
		if (name_stack == 'a')
			write (1, "sa\n", 3);
		else
			write (1, "sb\n", 3);
	}
	return (*stack);
}

t_node	*delone(t_node *stack, char *check)
{
	t_node	*tmp1;
	t_node	*tmp2;

	tmp1 = stack;
	if (!ft_strcmp(check, "up"))
	{
		stack = tmp1->next;
		free(tmp1);
		tmp1 = NULL;
	}
	else
	{
		while (tmp1->next != NULL)
		{
			tmp2 = tmp1;
			tmp1 = tmp1->next;
		}
		tmp2->next = NULL;
		free(tmp1);
	}
	return (stack);
}

t_node	*movement_rotation(t_pswap *stc, t_node *stack, char *type)
{
	stc = first_last(stc, stack, type);
	if (!ft_strcmp(type, "down"))
	{
		add_front_node(&stack, stc);
		stack = delone(stack, "down");
	}
	else
	{
		add_back_node(&stack, stc);
		stack = delone(stack, "up");
	}
	return (stack);
}

void	to_a(t_pswap *stc, t_node **stack1, t_node **stack2)
{
	int	line_b;
	int	position_max_b;

	while (ft_nodeline(*stack2))
	{
		line_b = ft_nodeline(*stack2);
		position_max_b = index_max_number(*stack2);
		if (position_max_b <= (line_b / 2))
		{
			while ((*stack2)->is_list != line_b)
			{
				*stack2 = movement_rotation(stc, *stack2, "up");
				write (1, "rb\n", 3);
			}
		}
		else
			part_to_a(stc, stack2, line_b);
		ft_pa(stc, stack1, stack2);
	}
}
