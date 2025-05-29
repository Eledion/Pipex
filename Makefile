# Definición del compilador y opciones
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I includes -I printf -I utils

# Archivos fuente de Pipex
SRC_FILES = src/execute_command.c src/execute_child1.c src/execute_child2.c \
            src/pipex.c src/main.c src/find_path.c

# Archivos fuente de printf (todos los archivos que mencionaste)
PRINTF_FILES = printf/ft_print_char.c printf/ft_print_hex.c printf/ft_print_int.c \
               printf/ft_print_percent.c printf/ft_print_pointer.c printf/ft_print_string.c \
               printf/ft_print_uint.c printf/ft_printf.c printf/ft_putchar_fd.c printf/ft_putnbr_fd.c

# Archivos fuente de utils
UTILS_FILES = utils/ft_split.c utils/ft_strjoin.c utils/ft_strlen.c utils/ft_strdup.c \
              utils/ft_memcpy.c utils/ft_memmove.c utils/ft_substr.c utils/ft_putstr_fd.c

# Archivos objeto generados a partir de los fuentes
OBJS = $(SRC_FILES:.c=.o) $(PRINTF_FILES:.c=.o) $(UTILS_FILES:.c=.o)

# Nombre del ejecutable
NAME = pipex

# Regla por defecto: compilar Pipex
all: $(NAME)

# Regla para compilar Pipex
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# Regla para compilar archivos objeto
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpiar archivos compilados
clean:
	rm -f $(OBJS)

# Limpiar todo, incluyendo el binario
fclean: clean
	rm -f $(NAME)

# Recompilar desde cero
re: fclean all

# PHONY para evitar conflictos con nombres de archivos
.PHONY: all clean fclean re