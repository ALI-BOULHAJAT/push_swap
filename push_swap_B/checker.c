/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:09:02 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/04/27 01:53:05 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	double_movement(t_node **stack_a, t_node **stack_b, char *type)
{
	if (!ft_strcmp(type, "ss\n"))
	{
		movement_swap(stack_a);
		movement_swap(stack_b);
	}
	else if (!ft_strcmp(type, "rr\n"))
	{
		movement_rotation(stack_a, "up");
		movement_rotation(stack_b, "up");
	}
	else if (!ft_strcmp(type, "rrr\n"))
	{
		movement_rotation(stack_a, "down");
		movement_rotation(stack_b, "down");
	}
	else
		ft_error();
}

void	run_movement(t_node **stack_a, t_node **stack_b, char *type)
{
	if (!ft_strcmp(type, "ra\n"))
		movement_rotation(stack_a, "up");
	else if (!ft_strcmp(type, "rra\n"))
		movement_rotation(stack_a, "down");
	else if (!ft_strcmp(type, "rb\n"))
		movement_rotation(stack_b, "up");
	else if (!ft_strcmp(type, "rrb\n"))
		movement_rotation(stack_b, "down");
	else if (!ft_strcmp(type, "sa\n"))
		movement_swap(stack_a);
	else if (!ft_strcmp(type, "sb\n"))
		movement_swap(stack_b);
	else if (!ft_strcmp(type, "pa\n"))
		ft_pa(stack_a, stack_b);
	else if (!ft_strcmp(type, "pb\n"))
		ft_pb(stack_a, stack_b);
	else
		double_movement(stack_a, stack_b, type);
}

int	is_sort(t_node *stack_a)
{
	while (stack_a != NULL && stack_a->next != NULL)
	{
		if (stack_a->num > stack_a->next->num)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

void	ft_sorting(t_node **stack_a, t_node **stack_b)
{
	char	*buffer;

	while (1)
	{
		buffer = get_next_line(0);
		if (buffer == NULL)
		{
			free(buffer);
			break ;
		}
		run_movement(stack_a, stack_b, buffer);
		free(buffer);
	}
}

int	main(int ac, char **av)
{
	char	*tab;
	t_node	*stack_a;
	t_node	*stack_b;
	int		line;

	stack_a = NULL;
	stack_b = NULL;
	if (ac > 1)
	{
		tab = ft_check_arg(av);
		ft_parcing(tab, &stack_a);
		line = ft_nodeline(stack_a);
		ft_sorting(&stack_a, &stack_b);
		if (is_sort(stack_a) && (line == ft_nodeline(stack_a)))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	ft_free(&stack_a, &stack_b);
}
