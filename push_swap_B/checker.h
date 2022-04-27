/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboulhaj <aboulhaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:10:08 by aboulhaj          #+#    #+#             */
/*   Updated: 2022/04/27 01:53:58 by aboulhaj         ###   ########.fr       */
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
	struct node	*next;

}	t_node;

int		first_last(t_node *stack, char *type);
t_node	*node_last(t_node *lst);
t_node	*delone(t_node *stack, char *check);
void	add_back_node(t_node **lst, int number);
void	add_front_node(t_node **lst, int number);

void	movement_rotation(t_node **stack, char *type);
void	movement_swap(t_node **stack);
void	ft_pa(t_node **stack1, t_node **stack2);
void	ft_pb(t_node **stack1, t_node **stack2);
char	*ft_check_arg(char **av);

int		ft_numcmp(const char *s1, const char *s2);
int		ft_isnumber(char *str);
void	ft_error(void);
int		ft_nodeline(t_node *stack);
t_node	*ft_newnode(int num);

char	*get_next_line(int fd);
void	ft_free(t_node **stack_a, t_node **stack_b);
void	ft_parcing(char *line, t_node **stack_A);

#endif