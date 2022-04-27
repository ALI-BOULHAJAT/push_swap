/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:52:35 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/04/27 00:36:44 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_pswap *stc, t_node **stack1, t_node **stack2)
{
	stc->num = (*stack2)->num;
	stc->is_list = (*stack2)->is_list;
	add_front_node(stack1, stc);
	*stack2 = delone(*stack2, "up");
	write (1, "pa\n", 3);
}

void	ft_pb(t_pswap *stc, t_node **stack1, t_node **stack2)
{
	stc->num = (*stack1)->num;
	stc->is_list = (*stack1)->is_list;
	add_front_node(stack2, stc);
	*stack1 = delone(*stack1, "up");
	write (1, "pb\n", 3);
}

static void	part_to_b(t_pswap *stc, t_node **stack1, t_node **stack2)
{
	if ((*stack1)->is_list < (stc->range_i + stc->range_j))
	{
		ft_pb(stc, stack1, stack2);
		if (ft_nodeline(*stack2) > 2)
		{
			if ((*stack2)->is_list < (*stack2)->next->is_list)
				*stack2 = movement_swap(stack2, 'b');
		}
		stc->range_i++;
	}
	else
	{
		*stack1 = movement_rotation(stc, *stack1, "up");
		write (1, "ra\n", 3);
	}
}

void	part_to_a(t_pswap *stc, t_node **stack2, int line_b)
{
	while ((*stack2)->is_list != line_b)
	{
		*stack2 = movement_rotation(stc, *stack2, "down");
		write (1, "rrb\n", 4);
	}
}

void	to_b(t_pswap *stc, t_node **stack1, t_node **stack2)
{
	indexing(stack1);
	stc->range_i = 2;
	if (ft_nodeline(*stack1) > 250)
		stc->range_j = 25;
	else
		stc->range_j = 15;
	while (ft_nodeline(*stack1))
	{
		if ((*stack1)->is_list < stc->range_i)
		{
			ft_pb(stc, stack1, stack2);
			*stack2 = movement_rotation(stc, *stack2, "up");
			write (1, "rb\n", 3);
			stc->range_i++;
		}
		else
			part_to_b(stc, stack1, stack2);
	}
}
