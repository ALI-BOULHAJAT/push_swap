/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:10:08 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/04/26 18:41:07 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include "../libft/libft.h"
# include <limits.h>

typedef struct pswap
{
	int		argc;
	char	**argv;
	char	*tab;
	int		num;
	int		range_i;
	int		range_j;
	int		is_list;

}	t_pswap;

typedef struct node
{
	int			num;
	// int			is_list;
	struct node	*next;

}	t_node;

int		first_last(t_node *stack, char *type);
t_node	*node_last(t_node *lst);
t_node	*delone(t_node *stack, char *check);
void	add_back_node(t_node **lst, int number);
void	add_front_node(t_node **lst, int number);

t_node	*movement_rotation(t_node *stack, char *type);
t_node	*movement_swap(t_node **stack);
void	ft_pa(t_node **stack1, t_node **stack2);
void	ft_pb(t_node **stack1, t_node **stack2);


#endif