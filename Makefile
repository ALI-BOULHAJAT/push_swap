NAME = push_swap

SRC = push_swap_M/push_swap.c push_swap_M/ft_isnumber.c push_swap_M/ft_check.c push_swap_M/ft_node.c push_swap_M/ft_movement.c push_swap_M/best_move.c push_swap_M/basic_sort.c push_swap_M/sort_three.c push_swap_M/indexing.c push_swap_M/ft_push.c

SRC_BONUS = push_swap_B/checker.c push_swap_B/ft_check.c push_swap_B/movement.c push_swap_B/node.c push_swap_B/ft_isnumber.c push_swap_B/get_next_line.c push_swap_B/ft_utils.c

CC = cc

OBJECT = $(SRC:.c=.o)

OBJECT_BONUS = $(SRC_BONUS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I.

all: $(NAME)

$(NAME) : $(OBJECT)
	make -C libft/
	gcc libft/libft.a $(CFLAGS) $(OBJECT) -o $(NAME)

bonus : $(OBJECT_BONUS)
	make -C libft/
	gcc libft/libft.a $(CFLAGS) $(OBJECT_BONUS) -o checker

clean:
	make fclean -C libft/
	rm -rf $(OBJECT) $(OBJECT_BONUS)

fclean: clean
	rm -rf $(NAME) checker

re: fclean all

.PHONY : all bonus clean fclean re
