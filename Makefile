# Definición del compilador y opciones
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I includes -I printf -I utils

# Carpeta principal de objetos
OBJ_DIR = obj

# Subdirectorios dentro de obj
OBJ_SUBDIRS = $(OBJ_DIR)/src $(OBJ_DIR)/utils

# Archivos fuente de Pipex
SRC_FILES = src/execute_command.c src/execute_child1.c src/execute_child2.c \
            src/pipex.c src/main.c src/find_path.c

# Archivos fuente de utils
UTILS_FILES = utils/ft_split.c utils/ft_strjoin.c utils/ft_strlen.c utils/ft_strdup.c \
              utils/ft_memcpy.c utils/ft_memmove.c utils/ft_substr.c utils/ft_putstr_fd.c

# Archivos objeto generados en obj/
OBJ_FILES_SRC = $(patsubst src/%.c, $(OBJ_DIR)/src/%.o, $(SRC_FILES))
OBJ_FILES_UTILS = $(patsubst utils/%.c, $(OBJ_DIR)/utils/%.o, $(UTILS_FILES))
OBJS = $(OBJ_FILES_SRC) $(OBJ_FILES_UTILS)

# Nombre del ejecutable
NAME = pipex

# Regla por defecto: compilar Pipex solo si hay cambios
all: check_changes $(NAME)

# Comprobar si hay archivos desactualizados antes de mostrar el banner
check_changes:
	@if ! $(MAKE) --question $(NAME); then \
		echo "==========================================="; \
		echo " 🚀 PIPEX - PROCESO DE COMPILACIÓN 🚀"; \
		echo "-------------------------------------------"; \
		echo " 🔧 Proyecto: Pipex"; \
		echo " 🏆 Desarrollador: DANOGUER "; \
		echo " 📅 Fecha: `date +'%d-%m-%Y %H:%M'`"; \
		echo "==========================================="; \
		echo ""; \
	else \
		echo "✅ No hay cambios. Todo está actualizado."; \
	fi

# Crear carpeta obj y sus subdirectorios antes de compilar cualquier objeto
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)/src $(OBJ_DIR)/utils

# Regla para compilar Pipex
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "✅ Compilación completada correctamente"

# Regla para compilar archivos objeto en obj/src/
$(OBJ_DIR)/src/%.o: src/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Regla para compilar archivos objeto en obj/utils/
$(OBJ_DIR)/utils/%.o: utils/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Limpiar archivos compilados
clean:
	@echo "🧹 Limpiando archivos objeto..."
	rm -f $(OBJS)
	@echo "✅ Limpieza completada con éxito."

# Limpiar todo, incluyendo el binario y la carpeta obj/
fclean: clean
	@echo "🗑️ Eliminando ejecutable y carpeta de compilación..."
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)
	@echo "✅ Fclean completado. Proyecto listo para recompilar desde cero."
	
# Recompilar desde cero
re: fclean all

# PHONY para evitar conflictos con nombres de archivos
.PHONY: all clean fclean re check_changes