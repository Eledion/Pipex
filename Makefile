# 🔹 Nombre del ejecutable
NAME = pipex

# 🔹 Compilador y flags de compilación
CC = cc
CFLAGS = -Wall -Wextra -Werror

# 🔹 Directorios
SRC_DIR = src
INCLUDE_DIR = includes
UTILS_DIR = utils

# 🔹 Archivos fuente y objetos
SRC = $(SRC_DIR)/execute_child1.c $(SRC_DIR)/execute_child2.c $(SRC_DIR)/execute_command.c \
      $(SRC_DIR)/find_path.c $(SRC_DIR)/main.c $(SRC_DIR)/pipex.c
UTILS = $(UTILS_DIR)/ft_memcpy.c $(UTILS_DIR)/ft_split.c $(UTILS_DIR)/ft_strdup.c \
        $(UTILS_DIR)/ft_substr.c $(UTILS_DIR)/ft_strlen.c $(UTILS_DIR)/ft_strjoin.c \
        $(UTILS_DIR)/ft_putstr_fd.c
OBJ = $(SRC:.c=.o) $(UTILS:.c=.o)

# 🔹 Regla principal: Compilar el programa
all: $(NAME)

# 🔹 Compilar los archivos fuente y utils
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -I $(INCLUDE_DIR) -o $(NAME)

# 🔹 Generar archivos .o a partir de los .c
%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -c $< -o $@

# 🔹 Eliminar archivos objeto
clean:
	rm -f $(OBJ)

# 🔹 Eliminar archivos objeto y ejecutable
fclean: clean
	rm -f $(NAME)

# 🔹 Recompilar todo desde cero
re: fclean all

# 🔹 No hacer relink innecesario
.PHONY: all clean fclean re