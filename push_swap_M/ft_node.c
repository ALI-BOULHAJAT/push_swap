/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:46:59 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/04/27 00:24:52 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_newnode(t_pswap *stc)
{
	t_node	*data;

	data = (t_node *) malloc(sizeof(t_node));
	if (!data)
		exit(1);
	data->num = stc->num;
	data->is_list = stc->is_list;
	data->next = NULL;
	return (data);
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

void	add_back_node(t_node **lst, t_pswap *stc)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		exit (1);
	new->num = stc->num;
	new->is_list = stc->is_list;
	new->next = NULL;
	if (*lst == NULL)
		*lst = new;
	else
		node_last(*lst)->next = new;
}

void	add_front_node(t_node **lst, t_pswap *stc)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		exit (1);
	new->num = stc->num;
	new->is_list = stc->is_list;
	new->next = *lst;
	*lst = new;
}

t_pswap	*first_last(t_pswap *stc, t_node *stack, char *type)
{
	t_node	*cpy;

	cpy = stack;
	if (!ft_strcmp(type, "down"))
	{
		while (cpy->next != NULL)
			cpy = cpy->next;
	}
	stc->num = cpy->num;
	stc->is_list = cpy->is_list;
	return (stc);
}
