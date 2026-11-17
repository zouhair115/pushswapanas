NAME	= push_swap

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRCS	= main.c \
		  parsing/parse_input.c \
		  algorithms/algo_utils.c algorithms/cost.c algorithms/targets.c \
		  algorithms/moves.c algorithms/turk.c algorithms/simple.c \
		  algorithms/medium.c algorithms/select.c algorithms/bench.c \
		  operations/swap_ops.c operations/push_ops.c \
		  operations/rotate_ops.c operations/reverse_ops.c \
		  utils/ft_str.c utils/ft_split.c utils/ft_atoi.c utils/ft_put.c \
		  utils/ft_math.c utils/ft_lst.c utils/stack_utils.c
OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
