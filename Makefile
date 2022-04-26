NAME = push_swap

SRC = push_swap_M/push_swap.c push_swap_M/ft_isnumber.c push_swap_M/ft_check.c push_swap_M/ft_node.c push_swap_M/ft_movement.c push_swap_M/best_move.c push_swap_M/basic_sort.c push_swap_M/sort_three.c push_swap_M/indexing.c push_swap_M/ft_push.c

SRC_BONUS = push_swap_B/checker.c push_swap_B/movement.c push_swap_B/node.c 
CC = gcc

OBJECT = $(SRC:.c=.o)

CFLAGS = -I.

all: $(NAME)

$(NAME) : $(OBJECT)
	make -C libft/
	gcc libft/libft.a $(SRC) -o $(NAME) -g

clean:
	make fclean -C libft/
	rm -rf $(OBJECT)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean re
