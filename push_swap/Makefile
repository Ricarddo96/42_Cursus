NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror 

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBFT_FLAGS = -L$(LIBFT_DIR) -lft

SRC = push_swap.c ./rules/push_rules.c ./rules/rotate_rules.c ./rules/r_rotate_rules.c ./rules/swap_rules.c utils.c ./turk/cost.c ./turk/cost_utils.c ./turk/main_loop_utils.c ./turk/main_loop.c parse.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re