/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 01:56:11 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/04/27 01:57:06 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	add_front_node(t_node **lst, int number)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		exit (1);
	new->num = number;
	new->next = *lst;
	*lst = new;
}
