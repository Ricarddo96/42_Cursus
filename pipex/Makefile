# Nombre del ejecutable
NAME = pipex

# Directorio de la libft
LIBFT_DIR = libft

# Archivos fuente de Pipex
SRCS = 	pipex.c \
		aux.c

# Archivos objeto de Pipex
OBJS = $(SRCS:.c=.o)

# Flags de compilación
CC = cc
CFLAGS = -Wall -Werror -Wextra

# Incluir el directorio de la libft para los headers
INCLUDE_DIRS = -I. -I$(LIBFT_DIR)

# Ruta a la librería libft.a
LIBFT_A = $(LIBFT_DIR)/libft.a

# Regla por defecto: compila todo
all: $(NAME)

# Regla para compilar la libft y luego Pipex
$(NAME): $(LIBFT_A) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) -o $(NAME)

# Regla para compilar la libft
$(LIBFT_A):
	@make -sC $(LIBFT_DIR)

# Regla para compilar los archivos .c a .o
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) -c $< -o $@

# Limpiar archivos objeto de Pipex
clean:
	@rm -f $(OBJS)
	@make -sC $(LIBFT_DIR) clean

# Limpiar todos los archivos generados (objetos y ejecutable)
fclean: clean
	@rm -f $(NAME)
	@make -sC $(LIBFT_DIR) fclean

# Recompilar todo desde cero
re: fclean all

# No borrar los archivos intermedios generados por make
.PHONY: all clean fclean re