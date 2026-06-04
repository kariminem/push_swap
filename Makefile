NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
SRCS =	ins_swap.c \
		ins_push.c \
		ins_rotate.c \
		ins_reverse.c \
		sort_simple.c \
		sort_medium.c \
		sort_complex.c \
		sort_adaptive.c \
		input_parsing.c \
		stack_utils.c \
		bench.c \
		stack_utils_extended.c

OBJS = $(SRCS:.c=.o)

MANDATORY = push_swap.c
MANDATORY_OBJ = push_swap.o

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT) $(MANDATORY)
	cc -Wall -Wextra -Werror $(OBJS) $(MANDATORY) -L$(LIBFT_DIR) -lft -o $(NAME)

clean:
	rm -f $(OBJS)
	rm -f checker
	rm -f $(MANDATORY_OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

bonus: $(OBJS) $(LIBFT)
	cc -Wall -Wextra -Werror $(OBJS) checker_bonus.c -L./libft -lft -o checker


re: fclean all

.PHONY: fclean re clean