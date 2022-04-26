/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 14:47:44 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/04/26 18:00:15 by aboulhaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
	int			is_list;
	struct node	*next;

}	t_node;

t_node	*ft_newnode(t_pswap *stc);
t_node	*node_last(t_node *lst);
void	add_back_node(t_node **lst, t_pswap *stc);
void	add_front_node(t_node **lst, t_pswap *stc);

int		ft_nodeline(t_node *stack);
int		index_min_number(t_node *stack);
int		index_max_number(t_node *stack);
t_node	*best_move(t_pswap*stc, t_node *stack1, t_node *stack2);

char	*check_null(char *str);
void	check_repeat(char *str);
void	ft_join(t_pswap *stc);
void	ft_check_arg(t_pswap *stc);

int		ft_isnumber(char *str);
int		ft_numcmp(const char *s1, const char *s2);

void	ft_error(void);
t_node	*movement_rotation(t_pswap *stc, t_node *stack, char *type);
t_node	*delone(t_node *stack, t_pswap *stc, char *check);
t_node	*movement_swap(t_node **stack, char name_stack);

t_node	*special_case(int ac, t_node *stack_a, t_node *stack_b, t_pswap *stc);
t_node	*sort_three(t_node *stack, t_pswap *stc);

void	ft_pa(t_pswap *stc, t_node **stack1, t_node **stack2);
void	ft_pb(t_pswap *stc, t_node **stack1, t_node **stack2);
void	to_a(t_pswap *stc, t_node **stack1, t_node **stack2);
void	to_b(t_pswap *stc, t_node **stack1, t_node **stack2);
void	part_to_a(t_pswap *stc, t_node **stack2, int line_b);

void	indexing(t_node **stack);
t_pswap	*first_last(t_pswap *stc, t_node *stack, char *type);

#endif