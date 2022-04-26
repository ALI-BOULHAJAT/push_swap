/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:38:56 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/04/26 17:59:11 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write (2, "Error", 6);
	exit(1);
}

void	ft_parcing(t_pswap *stc, t_node **stack_A)
{
	int		i;
	int		j;
	char	**num;
	t_node	**cpy;

	i = 1;
	j = 0;
	cpy = stack_A;
	num = ft_split(stc->tab, ' ');
	stc->num = ft_atoi(num[j]);
	free(num[j]);
	*stack_A = ft_newnode(stc);
	j++;
	while (num[j])
	{
		stc->num = ft_atoi(num[j]);
		add_back_node(stack_A, stc);
		free(num[j]);
		j++;
	}
	free(num);
	free(stc->tab);
}

void	ft_free(t_node **stack_a, t_node **stack_b, t_pswap *stc)
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
	free(stc);
}

int	main(int ac, char **av)
{
	t_pswap	*stc;
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	stc = NULL;
	if (ac > 1)
	{
		stc = (t_pswap *)malloc(sizeof(t_pswap));
		stc->argv = av;
		stc->num = 0;
		stc->is_list = 0;
		ft_check_arg(stc);
		ft_parcing(stc, &stack_a);
		if (ac > 2 && ac <= 6)
			stack_a = special_case(ac, stack_a, stack_b, stc);
		else
			stack_a = best_move(stc, stack_a, stack_b);
	}
	else
		ft_error();
	ft_free(&stack_a, &stack_b, stc);
	return (0);
}
