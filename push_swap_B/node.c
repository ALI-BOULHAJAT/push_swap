/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:28:12 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/04/27 01:56:57 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_node	*ft_newnode(int num)
{
	t_node	*data;

	data = (t_node *) malloc(sizeof(t_node));
	if (!data)
		exit(1);
	data->num = num;
	data->next = NULL;
	return (data);
}

int	first_last(t_node *stack, char *type)
{
	t_node	*cpy;
	int		number;

	cpy = stack;
	if (!ft_strcmp(type, "down"))
	{
		while (cpy->next != NULL)
			cpy = cpy->next;
	}
	number = cpy->num;
	return (number);
}

t_node	*node_last(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
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

void	add_back_node(t_node **lst, int number)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		exit (1);
	new->num = number;
	new->next = NULL;
	if (*lst == NULL)
		*lst = new;
	else
		node_last(*lst)->next = new;
}
