NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = main.c \
      parser/parser.c \
      threads/threads.c \
      threads/routine.c \
      utils/utils.c \
      utils/cleanup.c \
      utils/routine_utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -lpthread -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
