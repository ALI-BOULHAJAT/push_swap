/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:09:02 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/04/26 19:02:35 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_error(void)
{
	write (2, "Error", 6);
	exit(1);
}

void    double_movement(t_node **stack_a, t_node **stack_b, char *type)
{
    if (!ft_strcmp(type, "ss"))
    {
        movement_swap(stack_a);
        movement_swap(stack_b);
    }
    else if (!ft_strcmp(type, "rr"))
    {
        movement_rotation(stack_a, "up");
        movement_rotation(stack_b, "up");
    }
    else if (!ft_strcmp(type, "rrr"))
    {
        movement_rotation(stack_a, "down");
        movement_rotation(stack_b, "down");
    }
    else
        ft_error();
}

void   run_movement(t_node **stack_a, t_node **stack_b, char *type)
{
    if (!ft_strcmp(type, "ra"))
        movement_rotation(stack_a, "up");
    else if (!ft_strcmp(type, "rra"))
        movement_rotation(stack_a, "down");
    else if (!ft_strcmp(type, "rb"))
        movement_rotation(stack_b, "up");
    else if (!ft_strcmp(type, "rrb"))
        movement_rotation(stack_b, "down");
    else if (!ft_strcmp(type, "sa"))
        movement_swap(stack_a);
    else if (!ft_strcmp(type, "sb"))
        movement_swap(stack_b);
    else if (!ft_strcmp(type, "pa"))
        ft_pa(&stack_a, &stack_b);
    else if (!ft_strcmp(type, "pb"))
        ft_pb(&stack_a, &stack_b);
    else
        double_movement(stack_a, stack_b, type);
}

int main(int ac, char **av)
{
    t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac > 1)
	{
		ft_check_arg(stc);
		ft_parcing(stc, &stack_a);
}